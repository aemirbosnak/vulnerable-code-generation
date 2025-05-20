//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main() {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char buffer[1025];
    int maxi;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error opening socket");
        exit(1);
    }

    server = gethostbyname("localhost");

    if (server == NULL) {
        printf("Error finding host");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;

    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    portno = 8080;

    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        bzero(buffer, 1025);

        maxi = read(sockfd, buffer, 1024);

        if (maxi < 0) {
            printf("Error reading from server");
            exit(1);
        }

        buffer[maxi] = '\0';

        printf("%s", buffer);
    }

    return 0;
}