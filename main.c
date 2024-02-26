#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <signal.h>
#include "http_parser/http_parser.h"
#include "util/util.h"

#define PORT 8080
#define BACKLOG 10

char *remove_search_params(http_request_t *request) {
    for (int i = 0;; i++) {
        if (request->path[i] == '?') {
            return copy_substring(request->path, 0, i);
        }
        if (request->path[i] == '\0')
            return request->path;
    }
}

int sockfd;

void sigint_handler(int _) {
    printf("Received SIGINT. Closing socket...\n");
    close(sockfd);
    exit(0); // Or use another exit code if needed
}

int main() {
    signal(SIGINT, sigint_handler);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Failed to create socket");
        exit(1);
    }

    // Bind the socket to an address and port
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Failed to bind to socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sockfd, BACKLOG) == -1) {
        perror("Failed to listen to connection");
        exit(1);
    }

    printf("Server listening on port %d\n", PORT);

    for (;;) {
        char buffer[65535];
        // Accept connection
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int connection_sockfd = accept(sockfd, (struct sockaddr*)&client_addr, &client_len);
        if (connection_sockfd == -1) {
            perror("Failed to accept connection from client");
            exit(1);
        }

        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(client_addr.sin_addr), client_ip, INET_ADDRSTRLEN);
        printf("Accepted new connection from cleint %s\n", client_ip);

        // Read data from the client
        int bytes_received = read(connection_sockfd, buffer, sizeof(buffer));
        if (bytes_received == -1) {
            perror("Failed to read buffer");
            exit(1);
        }
        buffer[bytes_received] = '\0'; // Add null termination

        printf("Buffer: \n%s\n", buffer);

        http_request_t request = parse_http(buffer, sizeof(buffer));
        request.path = remove_search_params(&request);

        // Close connection
        close(connection_sockfd);
    }
}

// TODO:
// 1. Remove search params from path ++
// 2. Access file based on path
// 3. Forge reply http response
// 4. Support HTTP/1.1 and HTTP/2.0
// 5. Path security
// 6. Content type support
// 7. Configuration options like cors
// 8. DDoS protection, Invalid requests protection.
// 9. Multi threading