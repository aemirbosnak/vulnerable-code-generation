//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: peaceful
/* Building a POP3 Client Example Program */
/* This program is designed to connect to a POP3 Email server to check for new messages */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server> <port>\n", argv[0]);
        exit(1);
    }

    struct hostent *he;
    if ((he = gethostbyname(argv[1])) == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    int port = atoi(argv[2]);

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *((struct in_addr *)he->h_addr);
    memset(&(server_addr.sin_zero), 0, 8);

    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    char buffer[BUFSIZE];
    memset(buffer, 0, BUFSIZE);

    /* Retrieve server banner */
    recv(sockfd, buffer, BUFSIZE-1, 0);
    printf("%s", buffer);

    /* Authenticate user */
    printf("Username: ");
    char username[BUFSIZE];
    fgets(username, BUFSIZE, stdin);
    username[strcspn(username, "\n")] = '\0';

    send(sockfd, username, strlen(username), 0);
    memset(buffer, 0, BUFSIZE);
    recv(sockfd, buffer, BUFSIZE-1, 0);
    printf("%s", buffer);

    printf("Password: ");
    char password[BUFSIZE];
    fgets(password, BUFSIZE, stdin);
    password[strcspn(password, "\n")] = '\0';

    send(sockfd, password, strlen(password), 0);
    memset(buffer, 0, BUFSIZE);
    recv(sockfd, buffer, BUFSIZE-1, 0);
    printf("%s", buffer);

    /* Retrieve number of messages */
    send(sockfd, "STAT\r\n", 6, 0);
    memset(buffer, 0, BUFSIZE);
    recv(sockfd, buffer, BUFSIZE-1, 0);
    printf("%s", buffer);

    /* Quit session */
    send(sockfd, "QUIT\r\n", 6, 0);
    memset(buffer, 0, BUFSIZE);
    recv(sockfd, buffer, BUFSIZE-1, 0);
    printf("%s", buffer);

    close(sockfd);

    return 0;
}