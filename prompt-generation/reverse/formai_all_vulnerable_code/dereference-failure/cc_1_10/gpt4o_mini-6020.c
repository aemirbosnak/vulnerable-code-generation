//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define IMAP_PORT 993
#define BUFFER_SIZE 1024

// Function prototypes
int create_socket(const char *hostname, int port);
int imap_login(int sock, const char *username, const char *password);
int fetch_emails(int sock);
void close_connection(int sock);
void imap_command(int sock, const char *command, char *response);
void handle_error(const char *message);

int main() {
    // Server details
    const char *imap_server = "imap.example.com";
    const char *username = "user@example.com";
    const char *password = "yourpassword";  
    
    // Curious message
    printf("Welcome to the IMAP Client, where your emails await in digital space!\n");

    // Create a socket to connect to the IMAP server
    int sock = create_socket(imap_server, IMAP_PORT);
    
    // Login to the IMAP server
    if (imap_login(sock, username, password) != 0) {
        close_connection(sock);
        return EXIT_FAILURE;
    }

    // Fetch emails and display them
    if (fetch_emails(sock) < 0) {
        close_connection(sock);
        return EXIT_FAILURE;
    }

    // Close the connection
    close_connection(sock);
    return EXIT_SUCCESS;
}

int create_socket(const char *hostname, int port) {
    struct sockaddr_in server_addr;
    int sockfd;
    struct hostent *host_info;
    
    host_info = gethostbyname(hostname);
    if (host_info == NULL) {
        handle_error("Hostname resolution failed");
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        handle_error("Error creating socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr, host_info->h_addr, host_info->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection to IMAP server failed");
    }
    
    printf("Connected to the IMAP server.\n");
    return sockfd;
}

int imap_login(int sock, const char *username, const char *password) {
    char response[BUFFER_SIZE];
    char command[BUFFER_SIZE];

    // Login command
    snprintf(command, sizeof(command), "a001 LOGIN %s %s\r\n", username, password);
    imap_command(sock, command, response);
    
    // Check response for login success
    if (strstr(response, "OK") == NULL) {
        printf("Login failed: %s\n", response);
        return -1;
    }
    
    printf("Logged in successfully.\n");
    return 0;
}

int fetch_emails(int sock) {
    char response[BUFFER_SIZE];
    char command[BUFFER_SIZE];

    // Select the inbox
    snprintf(command, sizeof(command), "a002 SELECT INBOX\r\n");
    imap_command(sock, command, response);
    
    // Check response
    if (strstr(response, "OK") == NULL) {
        printf("Failed to select inbox: %s\n", response);
        return -1;
    }

    // Search for all emails
    snprintf(command, sizeof(command), "a003 SEARCH ALL\r\n");
    imap_command(sock, command, response);
    
    // Display email IDs
    printf("Emails found: %s\n", response);
    
    // Display details of each email (mockup)
    char *email_id = strtok(response, " ");
    while (email_id != NULL) {
        snprintf(command, sizeof(command), "a004 FETCH %s BODY[HEADER]\r\n", email_id);
        imap_command(sock, command, response);
        printf("Email %s details: %s\n\n", email_id, response);
        email_id = strtok(NULL, " ");
    }

    return 0;
}

void imap_command(int sock, const char *command, char *response) {
    // Send command to the server
    send(sock, command, strlen(command), 0);

    // Receive the response from the server
    recv(sock, response, BUFFER_SIZE, 0);
    printf("Server Response: %s\n", response);
}

void close_connection(int sock) {
    close(sock);
    printf("Connection closed. Have a great day!\n");
}

void handle_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}