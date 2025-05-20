//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SMTP_SERVER "smtp.example.com" // Change this to your SMTP server
#define SMTP_PORT 587
#define USERNAME "your_username"         // SMTP Username
#define PASSWORD "your_password"         // SMTP Password
#define FROM_EMAIL "from@example.com"    // Sender's email
#define TO_EMAIL "to@example.com"        // Recipient's email
#define BUFFER_SIZE 1024

void send_command(int sockfd, const char *cmd, int expected_code, char *response) {
    write(sockfd, cmd, strlen(cmd));
    write(sockfd, "\r\n", 2);
    
    // Read response
    bzero(response, BUFFER_SIZE);
    read(sockfd, response, BUFFER_SIZE);
    
    if (strncmp(response, (const char *)&expected_code, 3) != 0) {
        fprintf(stderr, "Unexpected response: %s\n", response);
        exit(EXIT_FAILURE);
    }
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char response[BUFFER_SIZE];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    // Server configuration
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Localhost, if server is on a different host replace this with IP of SMTP_SERVER

    // Connect to SMTP server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to SMTP server failed");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Read server welcome message
    read(sockfd, response, BUFFER_SIZE);
    printf("SMTP Server Response: %s", response);

    // HELO command
    send_command(sockfd, "HELO localhost", 250, response);
    printf("HELO Response: %s", response);

    // AUTH LOGIN command (Base64 encoding required)
    send_command(sockfd, "AUTH LOGIN", 334, response);
    printf("AUTH LOGIN Response: %s", response);
    send_command(sockfd, "dXNlcm5hbWU=", 334, response); // Base64 for "USERNAME"
    printf("Username Response: %s", response);
    send_command(sockfd, "cGFzc3dvcmQ=", 235, response); // Base64 for "PASSWORD"
    printf("Password Response: %s", response);

    // MAIL FROM command
    char mail_from_cmd[BUFFER_SIZE];
    snprintf(mail_from_cmd, sizeof(mail_from_cmd), "MAIL FROM: <%s>", FROM_EMAIL);
    send_command(sockfd, mail_from_cmd, 250, response);
    printf("MAIL FROM Response: %s", response);

    // RCPT TO command
    char rcpt_to_cmd[BUFFER_SIZE];
    snprintf(rcpt_to_cmd, sizeof(rcpt_to_cmd), "RCPT TO: <%s>", TO_EMAIL);
    send_command(sockfd, rcpt_to_cmd, 250, response);
    printf("RCPT TO Response: %s", response);

    // DATA command
    send_command(sockfd, "DATA", 354, response);
    printf("DATA Response: %s", response);

    // Email content
    const char *email_content = 
        "Subject: Test Email\r\n"
        "From: %s\r\n"
        "To: %s\r\n"
        "\r\n"
        "This is a test email sent from our SMTP client program.\r\n"
        ".\r\n"; // the period signals the end of the data

    char email_buffer[BUFFER_SIZE];
    snprintf(email_buffer, sizeof(email_buffer), email_content, FROM_EMAIL, TO_EMAIL);
    write(sockfd, email_buffer, strlen(email_buffer));

    // Final response after sending data
    read(sockfd, response, BUFFER_SIZE);
    printf("Email Send Response: %s", response);
    
    // QUIT command
    send_command(sockfd, "QUIT", 221, response);
    printf("QUIT Response: %s", response);

    // Close the socket
    close(sockfd);
    return EXIT_SUCCESS;
}