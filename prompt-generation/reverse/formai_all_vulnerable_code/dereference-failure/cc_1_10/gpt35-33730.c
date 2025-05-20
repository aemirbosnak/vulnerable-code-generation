//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFSIZE 8192
#define CRLF "\r\n"

void error(char *msg);
int open_socket(char *hostname, char *port);
void send_command(int sockfd, char *command);
void receive_response(int sockfd);
int authenticate(int sockfd, char *username, char *password);
int select_mailbox(int sockfd, char *mailbox);
int fetch_messages(int sockfd, int start, int end);

int main(int argc, char *argv[]) {
    char *hostname = "imap.example.com";
    char *port = "993";
    char *username = "user@example.com";
    char *password = "password123";
    char *mailbox = "INBOX";
    int sockfd;

    // Open socket connection to the IMAP server
    sockfd = open_socket(hostname, port);

    // Authenticate with server
    authenticate(sockfd, username, password);

    // Select mailbox
    select_mailbox(sockfd, mailbox);

    // Fetch all messages
    fetch_messages(sockfd, 1, 0);

    // Close connection
    close(sockfd);

    return 0;
}

void error(char *msg) {
    perror(msg);
    exit(0);
}

int open_socket(char *hostname, char *port) {
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    int rv;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(hostname, port, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    for (p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            continue;
        }

        break;
    }

    if (p == NULL) {
        error("Failed to connect");
    }

    freeaddrinfo(servinfo);

    return sockfd;
}

void send_command(int sockfd, char *command) {
    char buf[BUFSIZE];
    ssize_t nbytes;

    strcat(command, CRLF);

    if (send(sockfd, command, strlen(command), 0) == -1) {
        error("Failed to send command");
    }

    printf("%s", command);
}

void receive_response(int sockfd) {
    char buf[BUFSIZE];
    ssize_t nbytes;

    if ((nbytes = recv(sockfd, buf, BUFSIZE - 1, 0)) == -1) {
        error("Failed to receive response");
    }

    buf[nbytes] = '\0';

    printf("%s", buf);
}

int authenticate(int sockfd, char *username, char *password) {
    char buf[BUFSIZE];

    receive_response(sockfd);

    snprintf(buf, BUFSIZE, "LOGIN %s %s", username, password);
    send_command(sockfd, buf);

    receive_response(sockfd);

    return 0;
}

int select_mailbox(int sockfd, char *mailbox) {
    char buf[BUFSIZE];

    snprintf(buf, BUFSIZE, "SELECT %s", mailbox);
    send_command(sockfd, buf);

    receive_response(sockfd);

    return 0;
}

int fetch_messages(int sockfd, int start, int end) {
    int i;
    char buf[BUFSIZE];

    if (end == 0) {
        snprintf(buf, BUFSIZE, "FETCH %d:*", start);
    } else {
        snprintf(buf, BUFSIZE, "FETCH %d:%d", start, end);
    }

    send_command(sockfd, buf);

    receive_response(sockfd);

    return 0;
}