//MISTRAL-7B DATASET v1.0 Category: Email Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define PORT 12345
#define MAXLINE 80
#define BUFLEN 1024

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[MAXLINE], cmd[MAXLINE], *token;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) die("socket");

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
        die("connect");

    printf("Welcome to the Email Client v1.0\n");
    printf("Type 'quit' to exit.\n");

    while (1) {
        bzero(buffer, MAXLINE);
        printf("> ");
        fgets(buffer, MAXLINE, stdin);
        buffer[strlen(buffer) - 1] = '\0';

        strcpy(cmd, buffer);
        token = strtok(cmd, " ");

        if (strcasecmp(token, "SEND") == 0) {
            token = strtok(NULL, " ");
            if (!token) {
                printf("To: <email@example.com>\nSubject: <subject>\n\nBody:\n");
                fgets(buffer, MAXLINE, stdin);
                send(sockfd, buffer, strlen(buffer), 0);
            } else {
                strcpy(buffer, token);
                strcat(buffer, ": ");
                fgets(buffer + strlen(buffer), MAXLINE - strlen(buffer) - 1, stdin);

                send(sockfd, buffer, strlen(buffer), 0);

                printf("Email to %s sent successfully.\n", buffer);
            }
        } else if (strcasecmp(token, "RECEIVE") == 0) {
            recv(sockfd, buffer, BUFLEN, 0);
            printf("%s", buffer);
        } else if (strcasecmp(token, "LIST") == 0) {
            recv(sockfd, buffer, BUFLEN, 0);
            printf("%s", buffer);
        } else if (strcasecmp(token, "DELET") == 0) {
            token = strtok(NULL, " ");
            char num[10];
            strcpy(num, token);
            int index = atoi(num) - 1;

            send(sockfd, &index, sizeof(index), 0);
            recv(sockfd, buffer, BUFLEN, 0);
            printf("%s", buffer);
        } else if (strcasecmp(token, "QUIT") == 0) {
            close(sockfd);
            exit(0);
        }
    }

    return 0;
}