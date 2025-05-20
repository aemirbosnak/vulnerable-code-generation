//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER "smtp.example.com" // Change to your SMTP server
#define PORT 25                     // Replace with appropriate SMTP port
#define BUFFER_SIZE 1024

void handleError(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void sendEmail(const char *from, const char *to, const char *subject, const char *body) {
    int sock;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        handleError("Could not create socket");
    }

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    struct hostent *host = gethostbyname(SERVER);
    if (host == NULL) {
        handleError("Unable to get host");
    }
    memcpy(&server.sin_addr.s_addr, host->h_addr, host->h_length);

    // Connect to remote server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        handleError("Connection failed");
    }
    
    // Receive server's greeting
    read(sock, buffer, BUFFER_SIZE);
    printf("%s", buffer);
    
    // Send EHLO command
    sprintf(buffer, "EHLO localhost\r\n");
    write(sock, buffer, strlen(buffer));
    read(sock, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    // Send MAIL FROM command
    sprintf(buffer, "MAIL FROM:<%s>\r\n", from);
    write(sock, buffer, strlen(buffer));
    read(sock, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    // Send RCPT TO command
    sprintf(buffer, "RCPT TO:<%s>\r\n", to);
    write(sock, buffer, strlen(buffer));
    read(sock, buffer, BUFFER_SIZE);
    printf("%s", buffer);
    
    // Send DATA command
    write(sock, "DATA\r\n", 7);
    read(sock, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    // Send the email headers and body
    sprintf(buffer, "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s\r\n.\r\n", from, to, subject, body);
    write(sock, buffer, strlen(buffer));
    read(sock, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    // Send QUIT command
    write(sock, "QUIT\r\n", 7);
    read(sock, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    // Close the socket
    close(sock);
}

int main() {
    const char *from = "sender@example.com"; // Your email
    const char *to = "receiver@example.com"; // Recipient's email
    const char *subject = "Happy SMTP Testing!";
    const char *body = "Hello! This is a joyful test email sent via a simple SMTP client in C.";
    
    printf("Starting the SMTP Client...\n");
    sendEmail(from, to, subject, body);
    printf("Email sent successfully. Have a great day!\n");

    return 0;
}