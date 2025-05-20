//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int socket_fd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[256];

    // Create a socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Assign local port number
    portno = 2121;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(socket_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    // Listen for incoming connections
    listen(socket_fd, 5);

    printf("Waiting for incoming connection\n");
    socket_fd = accept(socket_fd, (struct sockaddr *) NULL, NULL);
    printf("Connected with client\n");

    // Receive data from client
    bzero(buffer, sizeof(buffer));
    n = read(socket_fd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("Received %d bytes from client: %s\n", n, buffer);

    // Send data back to client
    sprintf(buffer, "Hello, FTP client!\n");
    write(socket_fd, buffer, strlen(buffer));
    printf("Sent data back to client\n");

    // Close socket
    close(socket_fd);
    printf("Closed socket\n");

    return 0;
}