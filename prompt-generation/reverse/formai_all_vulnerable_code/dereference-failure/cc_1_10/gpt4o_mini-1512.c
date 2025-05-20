//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: genius
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define SMTP_PORT 25

void send_command(int sock, const char *command) {
    char buffer[BUFFER_SIZE];
    write(sock, command, strlen(command));
    write(sock, "\r\n", 2);
    read(sock, buffer, BUFFER_SIZE);
    printf("%s", buffer);
}

int main() {
    int sock;
    struct sockaddr_in server_address;

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    // Define server_address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SMTP_PORT);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1"); // Change to your SMTP server IP

    // Connect to SMTP server
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection to SMTP server failed");
        return EXIT_FAILURE;
    }

    // Read server greeting
    char buffer[BUFFER_SIZE];
    read(sock, buffer, BUFFER_SIZE);
    printf("Server: %s", buffer);

    // Send EHLO command
    send_command(sock, "EHLO localhost");

    // Send MAIL FROM
    send_command(sock, "MAIL FROM:<sender@example.com>");

    // Send RCPT TO
    send_command(sock, "RCPT TO:<recipient@example.com>");

    // Send DATA
    send_command(sock, "DATA");
    
    // Prepare the email content
    char email_content[BUFFER_SIZE];
    snprintf(email_content, sizeof(email_content),
             "Subject: Test Email\r\n"
             "This is a test email sent from a simple C SMTP client.\r\n"
             ".\r\n");  // Note the dot on a new line to indicate the end of data

    // Send email content
    write(sock, email_content, strlen(email_content));
    
    // Read and print response
    read(sock, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    // Send QUIT command to close connection
    send_command(sock, "QUIT");

    // Clean up and close socket
    close(sock);
    return EXIT_SUCCESS;
}