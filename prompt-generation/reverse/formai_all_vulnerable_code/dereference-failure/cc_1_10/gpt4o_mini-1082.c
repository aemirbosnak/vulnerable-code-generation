//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>

// IMAP commands
#define IMAP_LOGIN "1 LOGIN "
#define IMAP_LOGOUT "2 LOGOUT"
#define IMAP_SELECT "3 SELECT "
#define IMAP_FETCH "4 FETCH "
#define IMAP_LOGGING "5 LOGGING"

// Function prototypes
void connect_to_imap(const char *hostname, int port);
void login_to_imap(int sockfd, const char *username, const char *password);
void select_mailbox(int sockfd, const char *mailbox);
void fetch_email(int sockfd, int email_id);
void logout_from_imap(int sockfd);
void recursive_fetch(int sockfd, int start_id, int end_id);
void process_email(int sockfd, int email_id);
void print_response(const char *response);

// Global socket file descriptor
int sockfd;

// Main function
int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <hostname> <port> <username> <password>\n", argv[0]);
        return 1;
    }

    const char *hostname = argv[1];
    int port = atoi(argv[2]);
    const char *username = argv[3];
    const char *password = argv[4];

    connect_to_imap(hostname, port);
    login_to_imap(sockfd, username, password);
    select_mailbox(sockfd, "INBOX");
    
    // Recursive fetch for demonstration, let's fetch first 5 emails
    recursive_fetch(sockfd, 1, 5);

    logout_from_imap(sockfd);
    return 0;
}

// Connect to IMAP server
void connect_to_imap(const char *hostname, int port) {
    struct sockaddr_in server;
    struct hostent *host;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    host = gethostbyname(hostname);
    if (host == NULL) {
        perror("Unknown host");
        exit(EXIT_FAILURE);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    memcpy(&server.sin_addr.s_addr, host->h_addr, host->h_length);
    server.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connection to server failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to IMAP server %s:%d\n", hostname, port);
}

// Login to IMAP
void login_to_imap(int sockfd, const char *username, const char *password) {
    char command[256];
    snprintf(command, sizeof(command), "%s%s %s\r\n", IMAP_LOGIN, username, password);
    send(sockfd, command, strlen(command), 0);

    char response[1024];
    recv(sockfd, response, sizeof(response), 0);
    print_response(response);
}

// Select a mailbox
void select_mailbox(int sockfd, const char *mailbox) {
    char command[256];
    snprintf(command, sizeof(command), "%s%s\r\n", IMAP_SELECT, mailbox);
    send(sockfd, command, strlen(command), 0);

    char response[1024];
    recv(sockfd, response, sizeof(response), 0);
    print_response(response);
}

// Fetch email recursively
void recursive_fetch(int sockfd, int start_id, int end_id) {
    if (start_id > end_id) {
        return; // Base case for recursion
    }

    process_email(sockfd, start_id); // Process current email
    recursive_fetch(sockfd, start_id + 1, end_id); // Recursive call for next email
}

// Process a single email
void process_email(int sockfd, int email_id) {
    char command[256];
    snprintf(command, sizeof(command), "%s%d BODY[]\r\n", IMAP_FETCH, email_id);
    send(sockfd, command, strlen(command), 0);

    char response[1024];
    recv(sockfd, response, sizeof(response), 0);
    printf("Email %d:\n", email_id);
    print_response(response); // Print the fetched email
}

// Logout from IMAP
void logout_from_imap(int sockfd) {
    send(sockfd, IMAP_LOGOUT, strlen(IMAP_LOGOUT), 0);
    char response[1024];
    recv(sockfd, response, sizeof(response), 0);
    print_response(response);
    close(sockfd);
}

// Print server response
void print_response(const char *response) {
    printf("Response: %s\n", response);
}