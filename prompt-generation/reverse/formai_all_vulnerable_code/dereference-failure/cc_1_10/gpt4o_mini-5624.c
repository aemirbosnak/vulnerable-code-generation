//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <ctype.h>

#define BUFFER_SIZE 4096
#define SERVER_PORT 993
#define IMAP_COMMAND_LENGTH 512

// Function to establish a connection to the IMAP server
int connect_to_imap_server(const char *hostname) {
    struct sockaddr_in server_address;
    struct hostent *server;
    
    // Get server details
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        return -1;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return -1;
    }

    // Fill server address struct
    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(SERVER_PORT);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("ERROR connecting");
        close(sockfd);
        return -1;
    }
    
    return sockfd;
}

// Function to write command to the server and read response
void send_command(int sockfd, const char* command) {
    char buffer[BUFFER_SIZE];
    
    // Send command
    write(sockfd, command, strlen(command));
    write(sockfd, "\r\n", 2); // IMAP command ending

    // Read response
    bzero(buffer, BUFFER_SIZE);
    read(sockfd, buffer, BUFFER_SIZE - 1);
    printf("Server Response: %s\n", buffer);
}

// Function to authenticate
void authenticate(int sockfd, const char *username, const char *password) {
    char command[IMAP_COMMAND_LENGTH];
    
    // Start authentication
    snprintf(command, sizeof(command), "A001 LOGIN \"%s\" \"%s\"", username, password);
    send_command(sockfd, command);
}

// Function to display mailboxes
void list_mailboxes(int sockfd) {
    char command[IMAP_COMMAND_LENGTH];
    
    // Request list of mailboxes
    snprintf(command, sizeof(command), "A002 LIST \"\" \"*\"");
    send_command(sockfd, command);
}

// Function to fetch email headers from a specific mailbox
void fetch_email_headers(int sockfd, const char *mailbox) {
    char command[IMAP_COMMAND_LENGTH];

    // Select the mailbox
    snprintf(command, sizeof(command), "A003 SELECT \"%s\"", mailbox);
    send_command(sockfd, command);

    // Retrieve the email header
    snprintf(command, sizeof(command), "A004 FETCH 1 BODY.PEEK[HEADER]");
    send_command(sockfd, command);
}

// Function to disconnect from the server
void disconnect(int sockfd) {
    send_command(sockfd, "A005 LOGOUT");
    close(sockfd);
}

int main() {
    char *hostname = "imap.example.com"; // Change to your IMAP server
    char username[100], password[100];
    int sockfd;

    printf("Connecting to IMAP server at %s...\n", hostname);

    // Connect to the server
    sockfd = connect_to_imap_server(hostname);
    if (sockfd < 0) {
        return EXIT_FAILURE;
    }

    // Ask for credentials
    printf("Username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0; // Strip newline
    
    printf("Password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0; // Strip newline

    // Authenticate
    authenticate(sockfd, username, password);

    // List mailboxes
    list_mailboxes(sockfd);

    // Fetch headers from the Inbox
    fetch_email_headers(sockfd, "INBOX");

    // Disconnect
    disconnect(sockfd);

    return EXIT_SUCCESS;
}