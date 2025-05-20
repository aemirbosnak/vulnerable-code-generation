//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, newsockfd, n;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    // Initialize server address structure
    memset((char *) &serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(argv[1]));

    // Create socket and bind to port
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for incoming connections...\n");

    while (1) {
        if ((newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &n)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Incoming connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        // Read data from client and send it back
        char buffer[1024];
        memset(buffer, 0, sizeof(buffer));

        while ((n = read(newsockfd, buffer, sizeof(buffer))) > 0) {
            send(newsockfd, buffer, n, 0);
        }

        // Close the connection
        close(newsockfd);
    }

    return 0;
}