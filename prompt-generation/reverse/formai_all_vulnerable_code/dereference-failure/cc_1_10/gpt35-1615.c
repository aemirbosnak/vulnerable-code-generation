//FormAI DATASET v1.0 Category: Simple Web Server ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdbool.h>

void handle_request(int sock, struct sockaddr_in clnt_addr) {
    char buffer[BUFSIZ];
    ssize_t bytes_read = recv(sock, buffer, BUFSIZ, 0);
    if(bytes_read < 0) {
        perror("Failed to receive request");
        close(sock);
        return;
    }

    // Ensure the received data is a valid http request
    bool valid_request = false;
    if(strncmp(buffer, "GET /", 5) == 0) {
        valid_request = true;
    }

    // Prepare the response
    char *response;
    if(valid_request) {
        response = "HTTP/1.1 200 OK\r\n"
                   "Content-Type: text/html; charset=UTF-8\r\n\r\n"
                   "<html><body><h1>Hello, world!</h1></body></html>";
    } else {
        response = "HTTP/1.1 404 Not Found\r\n"
                   "Content-Type: text/html; charset=UTF-8\r\n\r\n"
                   "<html><body><h1>Page Not Found</h1></body></html>";
    }

    ssize_t bytes_sent = send(sock, response, strlen(response), 0);
    if(bytes_sent < 0) {
        perror("Failed to send response");
        close(sock);
        return;
    }

    // Print client information to console
    char client_addr_str[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(clnt_addr.sin_addr), client_addr_str, INET_ADDRSTRLEN);
    printf("Client %s:%d served.\n", client_addr_str, ntohs(clnt_addr.sin_port));
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if(server_sock < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    int port = atoi(argv[1]);
    struct sockaddr_in serv_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(port),
        .sin_addr = {
            .s_addr = INADDR_ANY
        }
    };

    if(bind(server_sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Failed to bind address to socket");
        exit(EXIT_FAILURE);
    }

    if(listen(server_sock, 5) < 0) {
        perror("Failed to listen for incoming connections");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", port);

    while(true) {
        struct sockaddr_in clnt_addr = {0};
        socklen_t clnt_addr_size = sizeof(clnt_addr);
        int clnt_sock = accept(server_sock, (struct sockaddr *) &clnt_addr, &clnt_addr_size);
        if(clnt_sock < 0) {
            perror("Failed to accept incoming connection");
            continue;
        }

        handle_request(clnt_sock, clnt_addr);
        close(clnt_sock);
    }

    close(server_sock);
    return 0;
}