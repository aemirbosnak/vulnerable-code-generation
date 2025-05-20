//Falcon2-11B DATASET v1.0 Category: Smart home automation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>

#define PORT 8080

void send_message(int sockfd, char *msg, char *dest) {
    int n = write(sockfd, msg, strlen(msg));
    if (n == -1) {
        printf("Write error: %s\n", strerror(errno));
        return;
    }
    printf("Message sent to %s: %s\n", dest, msg);
}

int main() {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    int opt = 1;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Setsockopt error");
        exit(EXIT_FAILURE);
    }

    // Set up server address structure
    memset((char *) &serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind the socket to the address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1) {
        perror("Bind error");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) == -1) {
        perror("Listen error");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Accept a connection
        struct sockaddr_in cli_addr;
        socklen_t clilen = sizeof(cli_addr);
        int newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd == -1) {
            perror("Accept error");
            exit(EXIT_FAILURE);
        }

        // Send message to client
        send_message(newsockfd, "Hello, client!", "localhost");

        // Close the connection
        close(newsockfd);
    }

    close(sockfd);
    return 0;
}