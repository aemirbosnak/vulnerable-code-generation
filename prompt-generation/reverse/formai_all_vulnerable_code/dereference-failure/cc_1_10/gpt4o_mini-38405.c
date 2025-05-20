//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define SERVER "imap.example.com"
#define PORT "993"
#define BUFFER_SIZE 1024

// Function prototypes
int connect_to_imap(const char *server, const char *port);
void send_command(int sockfd, const char *command);
void read_response(int sockfd);
void login(int sockfd, const char *username, const char *password);
void list_mailboxes(int sockfd);
void fetch_email(int sockfd, const char *mailbox);

int main() {
    int sockfd;
    const char *username = "user@example.com";
    const char *password = "password";

    sockfd = connect_to_imap(SERVER, PORT);
    if (sockfd < 0) {
        fprintf(stderr, "Failed to connect to IMAP server: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    login(sockfd, username, password);
    list_mailboxes(sockfd);
    fetch_email(sockfd, "INBOX");

    close(sockfd);
    return EXIT_SUCCESS;
}

// Connect to IMAP server
int connect_to_imap(const char *server, const char *port) {
    struct addrinfo hints, *res;
    int sockfd;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC; // IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if (getaddrinfo(server, port, &hints, &res) != 0) {
        perror("getaddrinfo");
        return -1;
    }

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd < 0) {
        perror("socket");
        freeaddrinfo(res);
        return -1;
    }

    if (connect(sockfd, res->ai_addr, res->ai_addrlen) != 0) {
        perror("connect");
        close(sockfd);
        freeaddrinfo(res);
        return -1;
    }

    freeaddrinfo(res);
    return sockfd;
}

// Send command to the server
void send_command(int sockfd, const char *command) {
    write(sockfd, command, strlen(command));
    write(sockfd, "\r\n", 2);
}

// Read response from the server
void read_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int n;

    while ((n = read(sockfd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
        if (strstr(buffer, "BYE") != NULL) {
            break; // server closed connection
        }
    }
}

// Login to the IMAP server
void login(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "a001 LOGIN %s %s", username, password);
    send_command(sockfd, command);
    read_response(sockfd);
}

// List available mailboxes
void list_mailboxes(int sockfd) {
    send_command(sockfd, "a002 LIST \"\" \"*\"");
    read_response(sockfd);
}

// Fetch emails from a specified mailbox
void fetch_email(int sockfd, const char *mailbox) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "a003 SELECT %s", mailbox);
    send_command(sockfd, command);
    read_response(sockfd);

    send_command(sockfd, "a004 FETCH 1:* (ENVELOPE)");
    read_response(sockfd);
}