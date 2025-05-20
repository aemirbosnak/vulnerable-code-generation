//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAXLINE 1024

int main() {
    /* Initialize socket and connect to server */
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct hostent *server = gethostbyname("imap.example.com");
    if (server == NULL) {
        printf("Error resolving hostname\n");
        exit(1);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(143);
    serv_addr.sin_addr = *((struct in_addr *)server->h_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    /* Login to server */
    char username[MAXLINE];
    char password[MAXLINE];
    printf("Enter username: ");
    fgets(username, MAXLINE, stdin);
    printf("Enter password: ");
    fgets(password, MAXLINE, stdin);
    const char *login_commands[] = {"LOGIN ", username, " ", password, NULL};
    for (int i = 0; login_commands[i]!= NULL; i++) {
        send(sockfd, login_commands[i], strlen(login_commands[i]), 0);
    }

    /* Send SELECT command to select inbox */
    const char *select_commands[] = {"SELECT INBOX", NULL};
    for (int i = 0; select_commands[i]!= NULL; i++) {
        send(sockfd, select_commands[i], strlen(select_commands[i]), 0);
    }

    /* Receive and display messages */
    char buffer[MAXLINE];
    while (fgets(buffer, MAXLINE, stdin)!= NULL) {
        send(sockfd, buffer, strlen(buffer), 0);
        memset(buffer, 0, MAXLINE);
        recv(sockfd, buffer, MAXLINE, 0);
        printf("%s", buffer);
    }

    /* Close connection */
    close(sockfd);

    return 0;
}