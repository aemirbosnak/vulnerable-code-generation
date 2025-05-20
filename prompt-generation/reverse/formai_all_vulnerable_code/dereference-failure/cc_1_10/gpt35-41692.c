//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXLINE 4096

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("usage: ./imap_client <IP address> <port>\n");
        exit(1);
    }

    struct sockaddr_in servaddr;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    servaddr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        printf("Error in connection.\n");
        exit(1);
    }

    char message[MAXLINE];
    char response[MAXLINE];

    read(sockfd, response, MAXLINE);
    printf("%s\n", response);

    // Login Step
    printf("Please enter your username: ");
    fgets(message, MAXLINE, stdin);
    write(sockfd, message, strlen(message));

    printf("Please enter your password: ");
    fgets(message, MAXLINE, stdin);
    write(sockfd, message, strlen(message));

    read(sockfd, response, MAXLINE);
    printf("%s\n", response);

    // List mailboxes Step
    sprintf(message, "LIST \"\" \"*\"\r\n");
    write(sockfd, message, strlen(message));

    read(sockfd, response, MAXLINE);
    printf("%s\n", response);

    // Select mailbox Step
    printf("Please enter the mailbox to select: ");
    fgets(message, MAXLINE, stdin);
    sprintf(message, "SELECT \"%s\"", message);
    write(sockfd, message, strlen(message));

    read(sockfd, response, MAXLINE);
    printf("%s\n", response);

    // Retrieve message Step
    printf("Please enter the message number to retrieve: ");
    fgets(message, MAXLINE, stdin);
    sprintf(message, "FETCH %s BODY[TEXT]\r\n", message);
    write(sockfd, message, strlen(message));

    read(sockfd, response, MAXLINE);
    printf("%s\n", response);

    // Logout Step
    sprintf(message, "LOGOUT\r\n");
    write(sockfd, message, strlen(message));

    read(sockfd, response, MAXLINE);
    printf("%s\n", response);

    close(sockfd);
    return 0;
}