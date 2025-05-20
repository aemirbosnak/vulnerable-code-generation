//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAXLINE 1024
#define MAXEMAIL 256
#define IMAP_PORT 993

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int open_connection(const char *hostname, int port) {
    struct sockaddr_in server_addr;
    struct hostent *host;
    int sockfd;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        handle_error("Cannot create socket.");

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    if ((host = gethostbyname(hostname)) == NULL)
        handle_error("Unknown host.");

    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        handle_error("Connection failed.");

    return sockfd;
}

void send_command(int sockfd, const char *cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
    send(sockfd, "\r\n", 2, 0); // IMAP requires CRLF
}

void read_response(int sockfd, char *response, size_t size) {
    memset(response, 0, size);
    recv(sockfd, response, size - 1, 0);
}

void authenticate(int sockfd, const char *username, const char *password) {
    char cmd[MAXLINE];

    snprintf(cmd, sizeof(cmd), "A1 LOGIN %s %s", username, password);
    send_command(sockfd, cmd);

    char response[MAXLINE];
    read_response(sockfd, response, sizeof(response));
    printf("Server Response: %s\n", response);
}

void list_mailboxes(int sockfd) {
    send_command(sockfd, "A2 LIST \"\" \"*\"");

    char response[MAXLINE];
    read_response(sockfd, response, sizeof(response));
    printf("Available Mailboxes: %s\n", response);
}

void fetch_mail(int sockfd, const char *mailbox) {
    char cmd[MAXLINE];
    snprintf(cmd, sizeof(cmd), "A3 SELECT \"%s\"", mailbox);
    send_command(sockfd, cmd);

    char response[MAXLINE];
    read_response(sockfd, response, sizeof(response));
    printf("Selected Mailbox: %s\n", response);

    send_command(sockfd, "A4 FETCH 1:* (ENVELOPE)");

    read_response(sockfd, response, sizeof(response));
    printf("Fetched Emails: %s\n", response);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd = open_connection(hostname, IMAP_PORT);

    authenticate(sockfd, username, password);
    list_mailboxes(sockfd);
    
    char mailbox[MAXEMAIL];
    printf("Enter the mailbox you want to access: ");
    fgets(mailbox, sizeof(mailbox), stdin);
    mailbox[strcspn(mailbox, "\n")] = 0;  // Remove newline character

    fetch_mail(sockfd, mailbox);

    close(sockfd);
    return EXIT_SUCCESS;
}