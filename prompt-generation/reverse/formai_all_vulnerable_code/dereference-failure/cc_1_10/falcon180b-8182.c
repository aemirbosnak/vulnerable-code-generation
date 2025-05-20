//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/time.h>
#include <time.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, recv_len;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    char *token = strtok(NULL, " ");
    int i, j, k, n;
    struct hostent *server;

    if (argc < 3) {
        printf("Usage:./a.out <IP Address> <Port Number>\n");
        exit(0);
    }

    portno = atoi(token);
    server = gethostbyname(argv[1]);

    if (server == NULL) {
        printf("No such host\n");
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(0);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr = *((struct in_addr *)server->h_addr);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(0);
    }

    while (1) {
        bzero(buffer, BUFFER_SIZE);
        recv_len = recv(sockfd, buffer, BUFFER_SIZE, 0);

        if (recv_len <= 0) {
            printf("Disconnected from server\n");
            break;
        }

        printf("Received data: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}