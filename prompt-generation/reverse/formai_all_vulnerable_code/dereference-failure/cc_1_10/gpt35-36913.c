//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int port = 12345;
    char *ip_address = "127.0.0.1";
    char message[BUFFER_SIZE];

    // Parse command line arguments
    int arg;
    for (arg = 1; arg < argc; arg++) {
        if (strcmp(argv[arg], "-p") == 0) {
            port = atoi(argv[arg + 1]);
            arg++;
        } else if (strcmp(argv[arg], "-i") == 0) {
            ip_address = argv[arg + 1];
            arg++;
        } else {
            printf("Unknown option: %s\n", argv[arg]);
            exit(EXIT_FAILURE);
        }
    }

    // Create socket
    int socket_fd;
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip_address);
    server_addr.sin_port = htons(port);

    // Establish connection
    int conn_res;
    conn_res = connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (conn_res < 0) {
        perror("Failed to establish connection");
        exit(EXIT_FAILURE);
    }

    // Read message from server
    if (read(socket_fd, message, BUFFER_SIZE) < 0) {
        perror("Failed to read message from server");
        exit(EXIT_FAILURE);
    }

    printf("Received message: %s\n", message);

    // Send message to server
    sprintf(message, "Hello, server!");
    if (send(socket_fd, message, strlen(message), 0) < 0) {
        perror("Failed to send message to server");
        exit(EXIT_FAILURE);
    }

    printf("Sent message: %s\n", message);

    close(socket_fd);
    exit(EXIT_SUCCESS);
}