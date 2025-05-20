//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024
#define IMAP_PORT 993
#define IMAP_SERVER "imap.example.com"  // Change to your IMAP server

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
    send(sockfd, "\r\n", 2, 0);
}

char* receive_response(int sockfd) {
    char *buffer = malloc(BUFFER_SIZE);
    memset(buffer, 0, BUFFER_SIZE);
    
    int received_length = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (received_length < 0) {
        free(buffer);
        error("Error in receiving response");
    }
    
    return buffer;
}

void login(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    
    snprintf(command, sizeof(command), "A001 LOGIN %s %s", username, password);
    send_command(sockfd, command);
    char *response = receive_response(sockfd);
    
    printf("Login Response: %s\n", response);
    free(response);
}

void list_mailboxes(int sockfd) {
    send_command(sockfd, "A002 LIST \"\" \"*\"");
    char *response = receive_response(sockfd);
    
    printf("Mailboxes:\n%s\n", response);
    free(response);
}

void fetch_email(int sockfd, const char *mailbox, int message_number) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A003 FETCH %d BODY[]", message_number);
    send_command(sockfd, command);
    
    char *response = receive_response(sockfd);
    printf("Email Message %d in %s:\n%s\n", message_number, mailbox, response);
    free(response);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Socket creation failed");
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAP_PORT);
    server_addr.sin_addr.s_addr = inet_addr("your.server.ip"); // Substitute server IP

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed");
    }

    // Receive greeting
    char *greeting = receive_response(sockfd);
    printf("Server Greeting: %s\n", greeting);
    free(greeting);
    
    // User credentials
    const char *username = "your_email@example.com";
    const char *password = "your_password";

    // Login to the server
    login(sockfd, username, password);

    // List mailboxes
    list_mailboxes(sockfd);

    // Fetch an email from the inbox
    fetch_email(sockfd, "INBOX", 1); // Fetch the first email

    // Clean up and close connection
    close(sockfd);
    return 0;
}