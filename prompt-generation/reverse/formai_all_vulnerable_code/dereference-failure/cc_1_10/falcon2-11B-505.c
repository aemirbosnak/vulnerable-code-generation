//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 110
#define MAX_MSG_LENGTH 1024

int main() {
    int sockfd, n;
    struct sockaddr_in serverAddr;
    struct hostent *server;

    char recvBuf[MAX_MSG_LENGTH];
    char sendBuf[MAX_MSG_LENGTH];

    char msg[MAX_MSG_LENGTH] = "USER myemail@example.com\r\n";
    char pass[MAX_MSG_LENGTH] = "mypassword\r\n";

    server = gethostbyname("mail.example.com");
    if (server == NULL) {
        printf("Hostname could not be resolved\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr(server->h_addr_list[0]);

    if (connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Connection failed");
        exit(1);
    }

    send(sockfd, msg, strlen(msg), 0);

    recv(sockfd, recvBuf, MAX_MSG_LENGTH, 0);
    printf("%s\n", recvBuf);

    if (strcmp(recvBuf, "+OK")!= 0) {
        printf("Authentication failed\n");
        exit(1);
    }

    send(sockfd, pass, strlen(pass), 0);

    recv(sockfd, recvBuf, MAX_MSG_LENGTH, 0);
    printf("%s\n", recvBuf);

    send(sockfd, "LIST\r\n", strlen("LIST\r\n"), 0);

    recv(sockfd, recvBuf, MAX_MSG_LENGTH, 0);
    printf("%s\n", recvBuf);

    close(sockfd);
    return 0;
}