//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <poll.h>
#include <signal.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);
    int server_fd, conn_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len;
    char buffer[1024];
    int i, nread;

    // Create a socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    // Set up the server's address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    // Bind the socket to the port
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    // Start listening for incoming connections
    if (listen(server_fd, 5) == -1) {
        perror("listen");
        exit(1);
    }

    // Accept incoming connections
    while (1) {
        addr_len = sizeof(client_addr);
        if ((conn_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addr_len)) == -1) {
            perror("accept");
            exit(1);
        }

        // Handle client requests
        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        fgets(buffer, sizeof(buffer), stdin);

        // Send the response to the client
        nread = send(conn_fd, buffer, strlen(buffer), 0);
        if (nread == -1) {
            perror("send");
            exit(1);
        }

        // Close the connection
        close(conn_fd);
    }

    return 0;
}