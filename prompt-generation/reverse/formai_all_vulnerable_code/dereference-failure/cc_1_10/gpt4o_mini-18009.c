//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>

#define IMAP_PORT 993
#define BUFFER_SIZE 1024

// Function to create a socket and connect to the IMAP server
int connect_to_imap_server(const char *hostname) {
    struct sockaddr_in server_addr;
    struct hostent *host;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return -1;
    }

    host = gethostbyname(hostname);
    if (host == NULL) {
        perror("Host lookup failed");
        close(sock);
        return -1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAP_PORT);
    memcpy(&server_addr.sin_addr, host->h_addr_list[0], host->h_length);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to IMAP server failed");
        close(sock);
        return -1;
    }

    return sock;
}

// Function to send and receive data to and from the IMAP server
void communicate_with_server(int sock, const char *command) {
    char buffer[BUFFER_SIZE];

    // Send command to the server
    send(sock, command, strlen(command), 0);
    
    // Receive response from the server
    memset(buffer, 0, BUFFER_SIZE);
    recv(sock, buffer, BUFFER_SIZE - 1, 0);
    printf("Server response: %s\n", buffer);
}

// Function to authenticate to the IMAP server
bool authenticate(int sock, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    // Send LOGIN command
    snprintf(command, sizeof(command), "a001 LOGIN %s %s\r\n", username, password);
    communicate_with_server(sock, command);

    // Verify if login was successful (expect a response ending with OK)
    ssize_t bytes_received = recv(sock, command, sizeof(command) - 1, 0);
    command[bytes_received] = '\0';
    if (strstr(command, "OK")) {
        return true;
    }
    return false;
}

// Function to list the mailboxes
void list_mailboxes(int sock) {
    char command[BUFFER_SIZE];

    // Send LIST command
    snprintf(command, sizeof(command), "a002 LIST \"/\" \"*\"\r\n");
    communicate_with_server(sock, command);
}

// Function to fetch the emails from the specified mailbox
void fetch_emails(int sock, const char *mailbox) {
    char command[BUFFER_SIZE];

    // Send SELECT command for the specified mailbox
    snprintf(command, sizeof(command), "a003 SELECT %s\r\n", mailbox);
    communicate_with_server(sock, command);

    // Send FETCH command for all emails
    snprintf(command, sizeof(command), "a004 FETCH 1:* (ENVELOPE)\r\n");
    communicate_with_server(sock, command);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    // Step 1: Connect to the IMAP server
    int sock = connect_to_imap_server(hostname);
    if (sock < 0) {
        return EXIT_FAILURE;
    }

    // Step 2: Authenticate to the mail server
    if (authenticate(sock, username, password)) {
        printf("Login successful!\n");

        // Step 3: List mailboxes
        list_mailboxes(sock);

        // Step 4: Fetch emails from the INBOX mailbox
        fetch_emails(sock, "INBOX");
    } else {
        printf("Login failed!\n");
    }

    // Step 5: Clean up
    close(sock);
    return EXIT_SUCCESS;
}