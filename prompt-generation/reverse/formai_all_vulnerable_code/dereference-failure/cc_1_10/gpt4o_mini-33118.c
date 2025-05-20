//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER "smtp.example.com" // replace with your SMTP server
#define PORT 587
#define BUFFER_SIZE 1024

void check_response(int sockfd, const char* expected_response) {
    char response[BUFFER_SIZE];
    recv(sockfd, response, sizeof(response) - 1, 0);
    response[sizeof(response) - 1] = '\0'; // ensuring null-termination
    
    printf("%s", response);

    if (strncmp(response, expected_response, 3) != 0) {
        fprintf(stderr, "Unexpected response from server: %s\n", response);
        close(sockfd);
        exit(EXIT_FAILURE);
    }
}

int main() {
    struct sockaddr_in server_addr;
    int sockfd;
    
    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error creating socket\n");
        exit(EXIT_FAILURE);
    }
    
    // Fill server information
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    
    // Get server IP address
    struct hostent* host = gethostbyname(SERVER);
    if (host == NULL) {
        fprintf(stderr, "Could not resolve hostname: %s\n", SERVER);
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);
    
    // Connect to the SMTP server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Connection failed\n");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    
    // Check server greeting
    check_response(sockfd, "220");
    
    // EHLO command
    const char* ehlo_command = "EHLO localhost\r\n";
    send(sockfd, ehlo_command, strlen(ehlo_command), 0);
    check_response(sockfd, "250");
    
    // STARTTLS command
    const char* starttls_command = "STARTTLS\r\n";
    send(sockfd, starttls_command, strlen(starttls_command), 0);
    check_response(sockfd, "220");
    
    // WARNING: Handling of TLS is omitted here to maintain paranoia.
    // In real implementation, you'd want to implement TLS securely.
    fprintf(stderr, "TLS implementation is critical for security. Please implement TLS.\n");
    
    const char* auth_command = "AUTH LOGIN\r\n";
    send(sockfd, auth_command, strlen(auth_command), 0);
    check_response(sockfd, "334");
    
    // Username
    const char* username = "yourbase64username==\r\n"; // replace accordingly
    send(sockfd, username, strlen(username), 0);
    check_response(sockfd, "334");
    
    // Password
    const char* password = "yourbase64password==\r\n"; // replace accordingly
    send(sockfd, password, strlen(password), 0);
    check_response(sockfd, "235");
    
    // MAIL FROM
    const char* from_command = "MAIL FROM:<you@example.com>\r\n"; // replace accordingly
    send(sockfd, from_command, strlen(from_command), 0);
    check_response(sockfd, "250");
    
    // RCPT TO
    const char* to_command = "RCPT TO:<recipient@example.com>\r\n"; // replace accordingly
    send(sockfd, to_command, strlen(to_command), 0);
    check_response(sockfd, "250");
    
    // DATA
    const char* data_command = "DATA\r\n";
    send(sockfd, data_command, strlen(data_command), 0);
    check_response(sockfd, "354");
    
    // Email content
    const char* email_content = "Subject: Test Email\r\n"
                                "From: you@example.com\r\n"
                                "To: recipient@example.com\r\n"
                                "\r\n"
                                "This is a test email sent from the paranoid SMTP client.\r\n"
                                ".\r\n"; // Note the dot to end email data
    
    send(sockfd, email_content, strlen(email_content), 0);
    check_response(sockfd, "250");
    
    // Quit command
    const char* quit_command = "QUIT\r\n";
    send(sockfd, quit_command, strlen(quit_command), 0);
    check_response(sockfd, "221");

    printf("Email sent successfully!\n");
    
    close(sockfd);
    return 0;
}