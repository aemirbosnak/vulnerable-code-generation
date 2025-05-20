//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAXLINE 4096

void error(char *msg) {
    perror(msg);
    exit(0);
}

void get_mailbox(int sockfd, char* mailbox) {
    char buffer[MAXLINE];
    bzero(buffer, MAXLINE);
    snprintf(buffer, MAXLINE, "SELECT %s\r\n", mailbox);
    int n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        error("Error writing to socket");
    }
}

void list_subscriptions(int sockfd) {
    int n = write(sockfd, "LSUB \"\" \"*\"\r\n", 14);
    if (n < 0) {
        error("Error writing to socket");
    }

    char buffer[MAXLINE];
    bzero(buffer, MAXLINE);
    while (1) {
        n = read(sockfd, buffer, MAXLINE - 1);
        if (n < 0) {
            error("Error reading from socket");
        }
        if (strstr(buffer, "LSUB")) {
            printf("%s", buffer);
        }
        else if (strstr(buffer, "OK")) {
            break;
        }
    }
}

void quit(int sockfd) {
    int n = write(sockfd, "LOGOUT\r\n", 8);
    if (n < 0) {
        error("Error writing to socket");
    }
    close(sockfd);
    exit(0);
}

void imap_client(int sockfd) {
    char buffer[MAXLINE];
    bzero(buffer, MAXLINE);
    printf("Welcome to the IMAP client. Enter \"help\" for a list of commands.\n");

    while (1) {
        printf("IMAP> ");
        fgets(buffer, MAXLINE, stdin);
        strtok(buffer, "\n");

        if (strcmp(buffer, "quit") == 0) {
            quit(sockfd);
        }
        else if (strcmp(buffer, "help") == 0) {
            printf("Available commands:\n");
            printf("get_mailbox <mailbox>\n");
            printf("list_subscriptions\n");
            printf("quit\n");
        }
        else if (strncmp(buffer, "get_mailbox", 11) == 0) {
            char* mailbox = strtok(buffer + 12, "\n");
            if (mailbox == NULL) {
                printf("Error: must specify a mailbox.\n");
                continue;
            }
            get_mailbox(sockfd, mailbox);
        }
        else if (strcmp(buffer, "list_subscriptions") == 0) {
            list_subscriptions(sockfd);
        }
        else {
            printf("Invalid command. Enter \"help\" for a list of commands.\n");
        }
    }
}

int main(int argc, char **argv) {
    int sockfd, n;
    char recvline[MAXLINE + 1];
    struct sockaddr_in servaddr;
    struct hostent *hptr;

    if (argc != 3) {
        error("usage: <program name> <ip or hostname> <port>");
    }

    if ((hptr = gethostbyname(argv[1])) == NULL) {
        printf("gethostbyname error for host: %s: %s\n", argv[1], hstrerror(h_errno));
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Error creating socket");
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    bcopy(hptr->h_addr, &servaddr.sin_addr, hptr->h_length);

    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        error("Error connecting to server");
    }

    char buffer[MAXLINE];
    bzero(buffer, MAXLINE);
    n = read(sockfd, buffer, MAXLINE - 1);
    if (n < 0) {
        error("Error reading from socket");
    }
    printf("%s", buffer);

    imap_client(sockfd);

    exit(0);
}