//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    int sockfd, new_fd, portno, n;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Assign socket to server port
    portno = atoi(argv[1]);
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind socket to port
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    listen(sockfd, 5);

    while (1) {
        // Accept incoming connection
        new_fd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &n);
        if (new_fd < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Receive message from client
        bzero(buffer, 1024);
        n = recv(new_fd, buffer, 1024, 0);
        if (n < 0) {
            perror("recv failed");
            exit(EXIT_FAILURE);
        }

        // Broadcast message to other clients
        for (int i = 0; i < 5; i++) {
            send(sockfd, buffer, n, 0);
        }

        // Close connection
        close(new_fd);
    }

    return 0;
}