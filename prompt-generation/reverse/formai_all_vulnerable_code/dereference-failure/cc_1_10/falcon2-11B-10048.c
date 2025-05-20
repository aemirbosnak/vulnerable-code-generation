//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd, port_no;
    struct sockaddr_in serv_addr;
    char buffer[1024];
    int bytes_read;

    // Create a socket
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    // Assign local port number
    port_no = atoi(argv[1]);
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port_no);

    // Bind the socket to local address
    if (bind(listen_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    listen(listen_fd, 5);

    while (1) {
        // Accept a connection
        conn_fd = accept(listen_fd, NULL, NULL);
        if (conn_fd < 0) {
            perror("ERROR on accept");
            exit(EXIT_FAILURE);
        }

        // Receive data from client
        bytes_read = recv(conn_fd, buffer, sizeof(buffer), 0);
        if (bytes_read < 0) {
            perror("ERROR reading from socket");
            exit(EXIT_FAILURE);
        }

        printf("Received: %s\n", buffer);

        // Send data back to client
        send(conn_fd, buffer, bytes_read, 0);
        close(conn_fd);
    }

    close(listen_fd);
    return 0;
}