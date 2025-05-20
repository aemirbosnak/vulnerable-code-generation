//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 4096

void error(char *msg) {
    perror(msg);
    exit(1);
}

void connectToServer(int* sockfd, char* address, int port) {
    struct sockaddr_in serv_addr;
    *sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (*sockfd < 0)
        error("ERROR opening socket");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(address);
    serv_addr.sin_port = htons(port);

    if (connect(*sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");
}

void receiveResponse(int sockfd, char* response) {
    int n;

    bzero(response, BUFSIZE);
    n = read(sockfd, response, BUFSIZE - 1);

    if (n < 0)
        error("ERROR reading from socket");
}

int main(int argc, char *argv[]) {
    int sockfd, portno;
    char serverAddress[20], username[20], password[20], authString[BUFSIZE], response[BUFSIZE];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <Server Address> <Port>\n", argv[0]);
        exit(0);
    }

    strncpy(serverAddress, argv[1], 19);
    serverAddress[19] = '\0';
    portno = atoi(argv[2]);

    connectToServer(&sockfd, serverAddress, portno);

    receiveResponse(sockfd, response);
    printf("%s\n", response);

    printf("Username: ");
    fgets(username, 19, stdin);
    username[strcspn(username, "\n")] = '\0';

    printf("Password: ");
    fgets(password, 19, stdin);
    password[strcspn(password, "\n")] = '\0';

    snprintf(authString, BUFSIZE, "USER %s\r\nPASS %s\r\n", username, password);
    send(sockfd, authString, strlen(authString), 0);

    receiveResponse(sockfd, response);
    printf("%s\n", response);

    send(sockfd, "LIST\r\n", 6, 0);
    receiveResponse(sockfd, response);
    printf("%s\n", response);

    send(sockfd, "QUIT\r\n", 6, 0);

    receiveResponse(sockfd, response);
    printf("%s\n", response);

    close(sockfd);
    return 0;
}