//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    char recvline[BUFSIZE + 1];
    struct sockaddr_in servaddr;
    struct hostent *he;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname/IP address> <port> <username>\n", argv[0]);
        return 1;
    }

    if ((he = gethostbyname(argv[1])) == NULL) {
        perror("gethostbyname error");
        return 1;
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket error");
        return 1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    servaddr.sin_addr = *((struct in_addr *)he->h_addr);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect error");
        return 1;
    }

    // Login
    char username[100], password[100];
    printf("Username: ");
    fgets(username, 100, stdin);
    username[strcspn(username, "\n")] = 0;
    printf("Password: ");
    fgets(password, 100, stdin);
    password[strcspn(password, "\n")] = 0;

    char buff[BUFSIZE];
    sprintf(buff, "LOGIN %s %s\r\n", username, password);
    send(sockfd, buff, strlen(buff), 0);
    n = recv(sockfd, recvline, BUFSIZE, 0);
    recvline[n] = 0;
    printf("%s", recvline);

    // Select Inbox
    send(sockfd, "SELECT INBOX\r\n", strlen("SELECT INBOX\r\n"), 0);
    n = recv(sockfd, recvline, BUFSIZE, 0);
    recvline[n] = 0;
    printf("%s", recvline);

    // List Messages
    send(sockfd, "FETCH 1:* BODY[]\r\n", strlen("FETCH 1:* BODY[]\r\n"), 0);
    n = recv(sockfd, recvline, BUFSIZE, 0);
    recvline[n] = 0;
    printf("%s", recvline);

    return 0;
}