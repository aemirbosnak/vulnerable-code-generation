//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ctype.h>

#define IMAP_PORT 993
#define BUFFER_SIZE 1024

void error_handling(char *message) {
    perror(message);
    exit(1);
}

int create_socket(char *host) {
    struct sockaddr_in server_addr;
    struct hostent *host_info;
    int sock;

    host_info = gethostbyname(host);
    if (host_info == NULL)
        error_handling("gethostbyname() error");

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1)
        error_handling("socket() error");

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr = *((struct in_addr *)host_info->h_addr);
    server_addr.sin_port = htons(IMAP_PORT);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
        error_handling("connect() error");

    return sock;
}

void send_command(int sock, const char *command) {
    send(sock, command, strlen(command), 0);
    // Send a CRLF to indicate end of command
    send(sock, "\r\n", 2, 0);
}

void read_response(int sock) {
    char buffer[BUFFER_SIZE];
    int str_len;

    while ((str_len = recv(sock, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[str_len] = 0;
        printf("%s", buffer);
        if (strstr(buffer, "OK") || strstr(buffer, "NO") || strstr(buffer, "BAD")) {
            break; // Response has been given, break out
        }
    }
}

void login(int sock, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "A001 LOGIN %s %s", username, password);
    send_command(sock, command);
    read_response(sock);
}

void logout(int sock) {
    send_command(sock, "A002 LOGOUT");
    read_response(sock);
    close(sock);
}

void list_mailboxes(int sock) {
    send_command(sock, "A003 LIST \"\" \"*\"");
    read_response(sock);
}

void fetch_email(int sock, const char *mailbox, int email_number) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A004 FETCH %d BODY[]", email_number);
    
    send_command(sock, command);
    read_response(sock);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IMAP server> <username> <password>\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    int sock = create_socket(host);

    // Starting the IMAP session
    read_response(sock); // Server greeting

    // Login to the IMAP server
    login(sock, username, password);

    // List available mailboxes
    list_mailboxes(sock);

    // Example: Fetch the first email from the inbox (assuming it exists)
    fetch_email(sock, "INBOX", 1);

    // Logout and close the connection
    logout(sock);

    return 0;
}