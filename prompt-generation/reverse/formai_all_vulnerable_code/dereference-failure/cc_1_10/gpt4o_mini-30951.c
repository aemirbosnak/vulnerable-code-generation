//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024
#define SERVER "smtp.example.com" // Replace with a valid SMTP server

// Function to create socket and connect to the SMTP server
int connect_to_smtp_server(const char *server, int port) {
    int sockfd;
    struct sockaddr_in server_address;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = inet_addr(server);

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to SMTP server");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Function to send command to the SMTP server and retrieve response
void send_smtp_command(int sockfd, const char *command) {
    char buffer[BUFFER_SIZE];
    // Send command to the server
    write(sockfd, command, strlen(command));
    write(sockfd, "\r\n", 2);
    
    // Read response from server
    memset(buffer, 0, BUFFER_SIZE);
    read(sockfd, buffer, BUFFER_SIZE - 1);
    printf("SMTP Response: %s", buffer);
}

// Main function demonstrating the SMTP client
int main() {
    int sockfd;
    const char *recipient = "recipient@example.com"; // Replace with the recipient's email
    const char *sender = "sender@example.com"; // Replace with the sender's email
    const char *subject = "SMTP Test Email";
    const char *body = "This is a test email sent using a custom SMTP client.";

    // Connect to the SMTP server
    sockfd = connect_to_smtp_server(SERVER, SMTP_PORT);
    printf("Connected to SMTP server.\n");

    // Initialize the SMTP session
    send_smtp_command(sockfd, "HELO localhost");
    send_smtp_command(sockfd, "MAIL FROM:<sender@example.com>");
    send_smtp_command(sockfd, "RCPT TO:<recipient@example.com>");
    
    // Send email data
    send_smtp_command(sockfd, "DATA");
    char data_buffer[BUFFER_SIZE];
    snprintf(data_buffer, BUFFER_SIZE, "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s\r\n.", sender, recipient, subject, body);
    write(sockfd, data_buffer, strlen(data_buffer));
    
    // Complete the DATA command
    send_smtp_command(sockfd, ".");
    
    // End the session
    send_smtp_command(sockfd, "QUIT");

    // Close the socket
    close(sockfd);
    printf("Disconnected from SMTP server.\n");
    
    return 0;
}