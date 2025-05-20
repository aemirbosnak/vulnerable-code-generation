//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: immersive
// Welcome to the IMAP Client example program!
// In this program, we'll demonstrate how to connect to an IMAP server
// and fetch emails using the IMAP protocol.
// So let's dive in!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

// Function to connect to an IMAP server
int connect_to_imap_server(char* server_address, int server_port) {
    // Create a socket for connecting to the server
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error creating socket\n");
        exit(1);
    }
    
    // Look up the server's IP address from its hostname
    struct hostent* server = gethostbyname(server_address);
    if (server == NULL) {
        printf("Error resolving hostname\n");
        exit(1);
    }
    
    // Initialize the server address struct
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char*) server->h_addr, (char*) &server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(server_port);
    
    // Connect to the server
    if (connect(sock, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }
    
    return sock;
}

// Function to send a command to the IMAP server
void send_imap_command(int sock, char* command) {
    char buffer[BUFFER_SIZE];
    memset(&buffer, 0, sizeof(buffer));
    
    // Send the command to the server
    snprintf(buffer, BUFFER_SIZE, "%s\r\n", command);
    send(sock, buffer, strlen(buffer), 0);
    
    // Wait for a response from the server
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);
}

// Function to fetch emails from the IMAP server
void fetch_emails(int sock) {
    // Send the command to log in to the mailbox
    send_imap_command(sock, "LOGIN username password");
    
    // Send the command to select the INBOX folder
    send_imap_command(sock, "SELECT INBOX");
    
    // Send the command to fetch all email ids
    send_imap_command(sock, "FETCH 1:* (UID)");
    
    // Send the command to log out
    send_imap_command(sock, "LOGOUT");
}

// Main function to run the program
int main() {
    printf("Welcome to the IMAP Client example program!\n");
    
    // Connect to the IMAP server
    int sock = connect_to_imap_server("imap.gmail.com", 993);
    
    // Fetch emails from the server
    fetch_emails(sock);
    
    // Close the socket
    close(sock);
    
    printf("Thanks for using the IMAP Client example program!\n");
    return 0;
}