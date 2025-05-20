//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd, port_num;
    struct sockaddr_in server_addr, client_addr;
    int addr_len;

    // Create a socket for listening
    if ((listen_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    // Set up the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    // Bind the socket to the address
    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Start listening for connections
    if (listen(listen_fd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    // Wait for a connection
    if ((conn_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &addr_len)) < 0) {
        perror("accept");
        exit(1);
    }

    // Print a message when a connection is received
    printf("Connected to %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // Close the socket
    close(listen_fd);
    close(conn_fd);

    return 0;
}