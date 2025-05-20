//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main() {
    int server_fd, new_socket, port_num;
    struct sockaddr_in server_addr, client_addr;
    struct hostent *server;
    int opt = 1;
    char buffer[1024];
    int yes = 1;

    // Set up socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(int)) == -1) {
        perror("setsockopt");
        return 1;
    }

    // Initialize server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        return 1;
    }

    // Set up server address
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        return 1;
    }
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    // Bind server socket to port 80
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        return 1;
    }

    // Start listening
    if (listen(server_fd, 5) == -1) {
        perror("listen");
        return 1;
    }

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t*)&port_num)) == -1) {
            perror("accept");
            return 1;
        }

        // Read client request
        printf("Reading request...\n");
        if (read(new_socket, buffer, sizeof(buffer)) == -1) {
            perror("read");
            return 1;
        }

        // Send response
        printf("Sending response...\n");
        if (write(new_socket, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\nHello, World!\r\n", 72) == -1) {
            perror("write");
            return 1;
        }

        // Close connection
        printf("Closing connection...\n");
        close(new_socket);
    }

    return 0;
}