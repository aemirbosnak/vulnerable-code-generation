//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define PORT 993 // IMAP over SSL

void die(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void send_command(int sockfd, const char *cmd, char *response) {
    if (send(sockfd, cmd, strlen(cmd), 0) == -1) {
        die("send");
    }

    if (recv(sockfd, response, BUFFER_SIZE, 0) == -1) {
        die("recv");
    }
}

void connect_to_server(const char *hostname, int port, int *sockfd) {
    struct sockaddr_in server_addr;
    struct hostent *host;

    if ((host = gethostbyname(hostname)) == NULL) {
        die("gethostbyname");
    }

    *sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (*sockfd == -1) {
        die("socket");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);
    server_addr.sin_port = htons(port);

    if (connect(*sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        die("connect");
    }
}

void login(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    char response[BUFFER_SIZE];

    snprintf(command, sizeof(command), "a001 LOGIN %s %s\r\n", username, password);
    send_command(sockfd, command, response);
    printf("Login response: %s\n", response);
}

void list_mailboxes(int sockfd) {
    char command[BUFFER_SIZE];
    char response[BUFFER_SIZE];

    snprintf(command, sizeof(command), "a002 LIST \"\" \"*\"\r\n");
    send_command(sockfd, command, response);
    printf("Mailbox list response: %s\n", response);
}

void fetch_emails(int sockfd, const char *mailbox) {
    char command[BUFFER_SIZE];
    char response[BUFFER_SIZE];

    snprintf(command, sizeof(command), "a003 SELECT \"%s\"\r\n", mailbox);
    send_command(sockfd, command, response);
    printf("Select mailbox response: %s\n", response);

    snprintf(command, sizeof(command), "a004 FETCH 1:* BODY[]\r\n");
    send_command(sockfd, command, response);
    printf("Fetch emails response: %s\n", response);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *hostname = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    int sockfd;
    connect_to_server(hostname, PORT, &sockfd);

    char response[BUFFER_SIZE];
    send_command(sockfd, "*", response); // Initial connection response

    login(sockfd, username, password);
    list_mailboxes(sockfd);
    fetch_emails(sockfd, "INBOX");

    close(sockfd);
    return 0;
}