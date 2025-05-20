//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080
#define MAX_CONNECTIONS 10

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[1024];

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("www.example.com");
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed. Error");
        exit(EXIT_FAILURE);
    }

    while (1) {
        if ((n = recv(sockfd, buffer, 1024, 0)) < 0) {
            perror("recv failed");
            exit(EXIT_FAILURE);
        }
        printf("Received %s\n", buffer);

        if (n == 0) {
            printf("Connection closed by peer\n");
            break;
        }
    }

    close(sockfd);
    return 0;
}