//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>

#define PORT 143
#define BUFFER_SIZE 1024

// Function to create a socket and connect to an IMAP server
int connect_to_imap_server(const char *server) {
    int sock;
    struct sockaddr_in server_addr;
    struct hostent *host;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    // Get server info
    host = gethostbyname(server);
    if (host == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    // Set up server struct
    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)host->h_addr, (char *)&server_addr.sin_addr.s_addr, host->h_length);
    server_addr.sin_port = htons(PORT);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    return sock;
}

// Function to send a command to the IMAP server
void send_command(int sock, const char *cmd) {
    write(sock, cmd, strlen(cmd));
    write(sock, "\r\n", 2);
}

// Function to read server response
void read_response(int sock) {
    char buffer[BUFFER_SIZE];
    int n;

    while ((n = read(sock, buffer, BUFFER_SIZE - 1)) > 0) {
        buffer[n] = '\0'; // null-terminate the string
        printf("%s", buffer);
    }
}

// Authentication with the IMAP server
void authenticate(int sock, const char *username, const char *password) {
    char cmd[BUFFER_SIZE];

    sprintf(cmd, "a001 LOGIN %s %s", username, password);
    send_command(sock, cmd);
    read_response(sock);
}

// List mailboxes
void list_mailboxes(int sock) {
    send_command(sock, "a002 LIST \"\" \"*\"");
    read_response(sock);
}

// Fetch emails from a specific mailbox
void fetch_emails(int sock, const char *mailbox) {
    char cmd[BUFFER_SIZE];

    sprintf(cmd, "a003 SELECT \"%s\"", mailbox);
    send_command(sock, cmd);
    read_response(sock);

    // Fetch all emails
    send_command(sock, "a004 FETCH 1:* (ENVELOPE)");
    read_response(sock);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IMAP_SERVER> <USERNAME> <PASSWORD>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *server = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    // Connect to IMAP server
    int sock = connect_to_imap_server(server);

    // Read server greet
    read_response(sock);

    // Authenticate
    authenticate(sock, username, password);

    // List mailboxes
    list_mailboxes(sock);

    // Fetch emails from the inbox
    fetch_emails(sock, "INBOX");

    // Close socket
    close(sock);
    return 0;
}