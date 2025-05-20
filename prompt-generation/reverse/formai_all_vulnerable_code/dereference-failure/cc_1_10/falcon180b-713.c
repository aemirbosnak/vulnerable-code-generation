//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#define TRUE 1
#define FALSE 0
#define BUFFER_SIZE 1024

// Function prototypes
int create_socket(int port);
void error_handling(char *message);

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int opt = TRUE;
    int addrlen = sizeof(client_addr);

    // Create socket
    server_socket = create_socket(8080);

    // Set socket options
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt));

    while (TRUE) {
        // Accept connection from client
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen);

        // Handle multiple clients
        if (client_socket!= -1) {
            printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

            // Forward data between server and client
            while (TRUE) {
                memset(buffer, 0, BUFFER_SIZE);
                int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

                if (bytes_received <= 0) {
                    if (bytes_received == 0)
                        printf("Connection closed by client\n");
                    else
                        printf("Error: %s\n", strerror(errno));

                    break;
                }

                int bytes_sent = send(server_socket, buffer, bytes_received, 0);

                if (bytes_sent!= bytes_received) {
                    printf("Error: %s\n", strerror(errno));
                    break;
                }
            }

            // Close sockets
            close(client_socket);
            printf("Connection closed\n");
        }
    }

    close(server_socket);
    return 0;
}

int create_socket(int port) {
    int socket_fd;
    struct sockaddr_in server_addr;

    // Create socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_fd == -1) {
        error_handling("socket failed");
    }

    // Set socket options
    int opt = TRUE;
    setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt));

    // Fill server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    // Bind socket to address and port
    if (bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error_handling("bind failed");
    }

    // Start listening for connections
    if (listen(socket_fd, 5) < 0) {
        error_handling("listen failed");
    }

    return socket_fd;
}

void error_handling(char *message) {
    perror(message);
    exit(1);
}