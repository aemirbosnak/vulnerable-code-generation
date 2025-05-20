//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>

#define IMAP_PORT 993
#define BUFFER_SIZE 1024
#define CMD_LOGIN "LOGIN"
#define CMD_SELECT "SELECT"
#define CMD_LOGOUT "LOGOUT"

void error_handling(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int create_socket(const char *hostname) {
    struct sockaddr_in server_addr;
    struct hostent *host_entry;

    host_entry = gethostbyname(hostname);
    if (host_entry == NULL) {
        error_handling("Failed to resolve hostname");
    }

    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        error_handling("Error creating socket");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAP_PORT);
    memcpy(&server_addr.sin_addr.s_addr, host_entry->h_addr, host_entry->h_length);

    if (connect(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        error_handling("Connection failed");
    }

    return sock_fd;
}

void communicate_with_server(int sock_fd, const char *command, char *response) {
    send(sock_fd, command, strlen(command), 0);
    recv(sock_fd, response, BUFFER_SIZE - 1, 0);
    response[BUFFER_SIZE - 1] = '\0'; // Ensure null termination
}

void login(int sock_fd, const char *username, const char *password) {
    char response[BUFFER_SIZE];

    // Send LOGIN command
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "%s \"%s\" \"%s\"\r\n", CMD_LOGIN, username, password);
    communicate_with_server(sock_fd, command, response);
    printf("Response: %s\n", response);
}

void select_mailbox(int sock_fd, const char *mailbox) {
    char response[BUFFER_SIZE];

    // Send SELECT command
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "%s \"%s\"\r\n", CMD_SELECT, mailbox);
    communicate_with_server(sock_fd, command, response);
    printf("Response: %s\n", response);
}

void logout(int sock_fd) {
    char response[BUFFER_SIZE];

    // Send LOGOUT command
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "%s\r\n", CMD_LOGOUT);
    communicate_with_server(sock_fd, command, response);
    printf("Response: %s\n", response);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sock_fd = create_socket(hostname);
    printf("Connected to IMAP server: %s\n", hostname);

    login(sock_fd, username, password);
    select_mailbox(sock_fd, "INBOX");

    // Paranoid: Explicitly instructing to log out before closing the connection.
    logout(sock_fd);
    
    // Close the socket securely
    if (close(sock_fd) < 0) {
        error_handling("Failed to close socket");
    }
    
    printf("Disconnected from IMAP server\n");
    return EXIT_SUCCESS;
}