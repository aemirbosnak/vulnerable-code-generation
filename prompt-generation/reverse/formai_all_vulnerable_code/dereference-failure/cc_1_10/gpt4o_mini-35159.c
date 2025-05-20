//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFSIZE 1024
#define SERVER "imap.example.com"  // Replace with your IMAP server
#define PORT 993

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int connect_to_server(const char *server, int port) {
    struct sockaddr_in server_addr;
    struct hostent *host;
    int sockfd;

    host = gethostbyname(server);
    if (host == NULL) {
        handle_error("gethostbyname");
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        handle_error("socket");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("connect");
    }

    return sockfd;
}

void send_command(int sockfd, const char *cmd, char *response) {
    write(sockfd, cmd, strlen(cmd));
    write(sockfd, "\r\n", 2);
    read(sockfd, response, BUFSIZE);
}

void login(int sockfd, const char *username, const char *password) {
    char response[BUFSIZE];
    char login_cmd[BUFSIZE];

    snprintf(login_cmd, sizeof(login_cmd), "A001 LOGIN \"%s\" \"%s\"", username, password);
    send_command(sockfd, login_cmd, response);

    printf("Login Response: %s\n", response);
}

void list_mailboxes(int sockfd) {
    char response[BUFSIZE];
    const char *list_cmd = "A002 LIST \"\" \"*\"";  // List all mailboxes
    send_command(sockfd, list_cmd, response);

    printf("Mailboxes:\n%s\n", response);
}

void fetch_email(int sockfd, const char *mailbox) {
    char response[BUFSIZE];
    char fetch_cmd[BUFSIZE];

    snprintf(fetch_cmd, sizeof(fetch_cmd), "A003 SELECT \"%s\"", mailbox);
    send_command(sockfd, fetch_cmd, response);
    printf("Selection Response: %s\n", response);

    snprintf(fetch_cmd, sizeof(fetch_cmd), "A004 FETCH 1 BODY[]");
    send_command(sockfd, fetch_cmd, response);
    printf("Email Body:\n%s\n", response);
}

void logout(int sockfd) {
    char response[BUFSIZE];
    const char *logout_cmd = "A005 LOGOUT";
    send_command(sockfd, logout_cmd, response);
    printf("Logout Response: %s\n", response);
}

int main() {
    int sockfd;
    const char *username = "your_email@example.com"; // Replace with your email
    const char *password = "your_password"; // Replace with your password

    sockfd = connect_to_server(SERVER, PORT);
    printf("Connected to server %s on port %d\n", SERVER, PORT);

    login(sockfd, username, password);
    list_mailboxes(sockfd);
    fetch_email(sockfd, "INBOX"); // Fetch email from INBOX
    logout(sockfd);

    close(sockfd);
    return 0;
}