//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SMTP_PORT 587
#define BUFFER_SIZE 1024

// Function to display server response
void check_response(int sockfd) {
    char response[BUFFER_SIZE];
    if (recv(sockfd, response, sizeof(response) - 1, 0) < 0) {
        perror("Failed to receive response from server");
        exit(EXIT_FAILURE);
    }
    response[3] = '\0'; // Null-terminate the string
    printf("Server Response: %s\n", response);
}

// Function to construct and send command to SMTP server
void send_command(int sockfd, const char *command) {
    printf("Sending Command: %s", command);
    if (send(sockfd, command, strlen(command), 0) < 0) {
        perror("Failed to send command");
        exit(EXIT_FAILURE);
    }
    check_response(sockfd);
}

// Establish a connection to the SMTP server
int connect_to_smtp_server(const char *hostname) {
    struct sockaddr_in server_addr;
    struct hostent *host;

    // Get host info
    host = gethostbyname(hostname);
    if (host == NULL) {
        perror("Could not resolve hostname");
        exit(EXIT_FAILURE);
    }

    // Creating socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }

    // Filling server information
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    // Connecting to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Could not connect to server");
        exit(EXIT_FAILURE);
    }

    check_response(sockfd);
    return sockfd;
}

// Main SMTP Client functionality
void smtp_client(const char *hostname, const char *from, const char *to, const char *subject, const char *body) {
    int sockfd = connect_to_smtp_server(hostname);
    
    // Starting SMTP session
    send_command(sockfd, "EHLO localhost\r\n");
    
    // Authentication can be implemented here if needed

    // Sending MAIL FROM command
    char mail_from_command[BUFFER_SIZE];
    snprintf(mail_from_command, sizeof(mail_from_command), "MAIL FROM:<%s>\r\n", from);
    send_command(sockfd, mail_from_command);
    
    // Sending RCPT TO command
    char rcpt_to_command[BUFFER_SIZE];
    snprintf(rcpt_to_command, sizeof(rcpt_to_command), "RCPT TO:<%s>\r\n", to);
    send_command(sockfd, rcpt_to_command);
    
    // Sending DATA command
    send_command(sockfd, "DATA\r\n");

    // Sending email headers and body
    char email_data[BUFFER_SIZE];
    snprintf(email_data, sizeof(email_data), "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s\r\n.\r\n", from, to, subject, body);
    send_command(sockfd, email_data);

    // Ending the SMTP session
    send_command(sockfd, "QUIT\r\n");

    // Closing the socket
    close(sockfd);
}

// Main function - entry point for the program
int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <hostname> <from> <to> <subject> <body>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *from = argv[2];
    const char *to = argv[3];
    const char *subject = argv[4];

    // Prepare an example body for the email
    const char *body = "This is a paranoid example of an SMTP client implementation.";

    smtp_client(hostname, from, to, subject, body);

    return 0;
}