//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define IMAP_PORT 993
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int connect_to_imap_server(const char *server) {
    struct sockaddr_in server_addr;
    struct hostent *host;

    host = gethostbyname(server);
    if (host == NULL) {
        error("ERROR: No such host");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);
    server_addr.sin_port = htons(IMAP_PORT);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        error("ERROR opening socket");
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        close(sock);
        error("ERROR connecting to server");
    }

    return sock;
}

void send_command(int sock, const char *command) {
    char buffer[BUFFER_SIZE];

    // Send command
    if (send(sock, command, strlen(command), 0) < 0) {
        error("ERROR sending command");
    }

    // Receive response
    memset(buffer, 0, BUFFER_SIZE);
    recv(sock, buffer, BUFFER_SIZE - 1, 0);
    printf("Response: %s\n", buffer);
}

void login(int sock, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A01 LOGIN %s %s\r\n", username, password);
    send_command(sock, command);
}

void list_mailboxes(int sock) {
    send_command(sock, "A02 LIST \"\" \"*\"\r\n");
}

void fetch_email(int sock, const char *mailbox, int email_number) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A03 FETCH %d BODY[HEADER]\r\n", email_number);
    send_command(sock, command);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <imap-server> <username> <password>\n", argv[0]);
        exit(1);
    }

    const char *server = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sock = connect_to_imap_server(server);
    printf("Connected to IMAP server %s\n", server);

    login(sock, username, password);

    list_mailboxes(sock);
    
    // Fetch example email, ideally you'd get mailbox and count from listing
    fetch_email(sock, "INBOX", 1);

    // Clean-up
    send_command(sock, "A04 LOGOUT\r\n");
    close(sock);

    return 0;
}