//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORT 21

int main() {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        return EXIT_FAILURE;
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        perror("Error getting host by name");
        return EXIT_FAILURE;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting");
        return EXIT_FAILURE;
    }

    printf("Connected to server\n");

    while (1) {
        printf("Enter command: ");
        bzero(buffer, 256);
        fgets(buffer, 255, stdin);

        if (strncmp(buffer, "QUIT", 4) == 0) {
            break;
        }

        if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
            perror("Error sending data");
            return EXIT_FAILURE;
        }

        bzero(buffer, 256);
        if (recv(sockfd, buffer, 255, 0) < 0) {
            perror("Error receiving data");
            return EXIT_FAILURE;
        }

        printf("%s", buffer);
    }

    close(sockfd);
    return EXIT_SUCCESS;
}