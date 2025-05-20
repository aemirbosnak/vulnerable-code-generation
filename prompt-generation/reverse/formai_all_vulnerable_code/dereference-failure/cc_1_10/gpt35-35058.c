//FormAI DATASET v1.0 Category: Simple Web Server ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define PORT 8080
#define BUFSIZE 1024

void handle_request(int client_fd) {
    char buffer[BUFSIZE] = {0};

    int bytes_received = recv(client_fd, buffer, BUFSIZE, 0); // Read request from client
    if (bytes_received < 0) {
        perror("Error reading request");
        return;
    }

    char response[BUFSIZE] = {0};
    snprintf(response, BUFSIZE, "HTTP/1.1 200 OK\r\n"
                                "Content-Type: text/html\r\n"
                                "Connection: close\r\n\r\n"
                                "<html><body><h1>Hello, World!</h1></body></html>\r\n");
    int bytes_sent = send(client_fd, response, strlen(response), 0); // Send response to client
    if (bytes_sent < 0) {
        perror("Error sending response");
    }

    close(client_fd); // Close client socket
}

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");
        return -1;
    }

    if (fcntl(server_fd, F_SETFL, O_NONBLOCK) == -1) {
        perror("Error setting socket to non-blocking");
        return -1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        return -1;
    }

    if (listen(server_fd, 16) < 0) {
        perror("Error listening on socket");
        return -1;
    }

    while (1) {
        client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addr_len);
        if (client_fd == -1) {
            if (errno != EWOULDBLOCK && errno != EAGAIN) {
                perror("Error accepting client connection");
                return -1;
            }
        } else {
            handle_request(client_fd);
        }
    }

    return 0;
}