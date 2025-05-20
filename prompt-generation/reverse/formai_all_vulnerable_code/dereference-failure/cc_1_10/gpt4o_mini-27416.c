//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <errno.h>

#define MAX_BUFFER 1024
#define IMAP_PORT 993 // Default IMAP over SSL port
#define SERVER "imap.cyberpunkmail.com"

// Function to strip newlines from the end of a string
void strip_newline(char *s) {
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }
}

// Function to create a secure socket for IMAP
int create_secure_socket() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    return sock;
}

// Function to connect to the IMAP server
void connect_to_imap_server(int sock) {
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAP_PORT);
    inet_pton(AF_INET, SERVER, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to IMAP server failed");
        close(sock);
        exit(EXIT_FAILURE);
    }
}

// Function to send a command to the server
void send_command(int sock, const char *command) {
    send(sock, command, strlen(command), 0);
}

// Function to read server response
void read_response(int sock, char *buffer) {
    int bytes_received = recv(sock, buffer, MAX_BUFFER-1, 0);
    if (bytes_received < 0) {
        perror("Error reading from server");
        close(sock);
        exit(EXIT_FAILURE);
    }
    buffer[bytes_received] = '\0'; // Null-terminate the buffer
}

// Function to log in to the IMAP server
void imap_login(int sock, const char *username, const char *password) {
    char buffer[MAX_BUFFER];
    
    // Sending login command
    char command[MAX_BUFFER];
    snprintf(command, sizeof(command), "A001 LOGIN %s %s\r\n", username, password);
    send_command(sock, command);
    read_response(sock, buffer);
    printf("Server response: %s\n", buffer);
}

// Function to fetch the list of mailboxes
void fetch_mailboxes(int sock) {
    char buffer[MAX_BUFFER];
    char command[] = "A002 LIST \"\" \"*\"\r\n";
    
    send_command(sock, command);
    read_response(sock, buffer);
    printf("Mailboxes:\n%s\n", buffer);
}

// Function to handle the cyberpunk interface
void cyberpunk_interface(int sock) {
    char username[MAX_BUFFER];
    char password[MAX_BUFFER];

    printf("Welcome to Cyber Mail - Neon IMAP Client\n");
    printf("Username: ");
    fgets(username, sizeof(username), stdin);
    strip_newline(username);
    
    printf("Password: ");
    fgets(password, sizeof(password), stdin);
    strip_newline(password);
    
    imap_login(sock, username, password);
    fetch_mailboxes(sock);
}

// Entry point of the application
int main() {
    int sock = create_secure_socket();
    connect_to_imap_server(sock);
    
    cyberpunk_interface(sock);
    
    close(sock);
    printf("Disconnected. Stay safe in the neon-lit shadows.\n");
    return 0;
}