//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

// function to connect to IMAP server and login with given credentials
int login(const char* server, const char* user, const char* pass, int *sockfd) {
    struct addrinfo hints, *result;
    int status;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((status = getaddrinfo(server, "imap", &hints, &result)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        return 1;
    }

    *sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);

    if (*sockfd < 0) {
        fprintf(stderr, "socket error\n");
        return 1;
    }

    if (connect(*sockfd, result->ai_addr, result->ai_addrlen) < 0) {
        fprintf(stderr, "connect error\n");
        return 1;
    }

    freeaddrinfo(result);

    char buf[1024];
    memset(buf, 0, sizeof buf);

    read(*sockfd, buf, sizeof buf);
    printf("%s", buf);

    sprintf(buf, "1 LOGIN %s %s\r\n", user, pass);
    write(*sockfd, buf, strlen(buf));

    memset(buf, 0, sizeof buf);
    read(*sockfd, buf, sizeof buf);
    printf("%s", buf);

    // check if login successful
    if (strstr(buf, "OK LOGIN completed") == NULL) {
        return 1;
    }

    return 0;
}

// function to select a mailbox and retrieve its messages
void retrieve_mailbox(int sockfd) {
    char buf[1024];

    // select INBOX mailbox
    sprintf(buf, "2 SELECT INBOX\r\n");
    write(sockfd, buf, strlen(buf));

    memset(buf, 0, sizeof buf);
    read(sockfd, buf, sizeof buf);
    printf("%s", buf);

    // check if mailbox selection successful
    if (strstr(buf, "OK [READ-WRITE] SELECT completed") == NULL) {
        return;
    }

    // retrieve messages
    sprintf(buf, "3 FETCH 1:* BODY[]\r\n");
    write(sockfd, buf, strlen(buf));

    memset(buf, 0, sizeof buf);
    read(sockfd, buf, sizeof buf);
    printf("%s", buf);

    // print messages to console
    char *msg_start = strstr(buf, "1 FETCH");
    while (msg_start != NULL) {
        char *msg_end = strstr(msg_start, "\r\n");
        *msg_end = '\0';
        printf("%s\n", msg_start);
        msg_start = strstr(msg_end+2, "1 FETCH");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s server user pass\n", argv[0]);
        return 1;
    }

    int sockfd;

    // login to IMAP server
    if (login(argv[1], argv[2], argv[3], &sockfd) != 0) {
        printf("Login failed\n");
        return 1;
    }

    // retrieve and display mailbox messages
    retrieve_mailbox(sockfd);

    // close connection
    write(sockfd, "4 LOGOUT\r\n", strlen("4 LOGOUT\r\n"));
    close(sockfd);

    return 0;
}