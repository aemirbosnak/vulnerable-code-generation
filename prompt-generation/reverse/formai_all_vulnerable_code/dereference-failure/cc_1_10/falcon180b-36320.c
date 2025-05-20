//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <unistd.h>

#define BUF_SIZE 1024

void main() {
    int sockfd;
    struct sockaddr_in servaddr;
    struct hostent *server;
    char username[20];
    char password[20];
    char command[50];
    char response[BUF_SIZE];
    int n;

    printf("Enter POP3 server address: ");
    scanf("%s", server);

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    server = gethostbyname(server);

    if (server == NULL) {
        printf("Error getting server address\n");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;

    bcopy(server->h_addr, &servaddr.sin_addr.s_addr, server->h_length);

    servaddr.sin_port = htons(110);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    sprintf(command, "USER %s", username);

    send(sockfd, command, strlen(command), 0);

    n = recv(sockfd, response, BUF_SIZE, 0);

    response[n] = '\0';

    printf("Server response: %s\n", response);

    sprintf(command, "PASS %s", password);

    send(sockfd, command, strlen(command), 0);

    n = recv(sockfd, response, BUF_SIZE, 0);

    response[n] = '\0';

    printf("Server response: %s\n", response);

    close(sockfd);
}