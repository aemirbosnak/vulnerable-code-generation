//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SMTP_SERVER "smtp.example.com"
#define SMTP_PORT 587
#define BUFFER_SIZE 1024

void error_exit(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int send_email(const char *from, const char *to, const char *subject,
               const char *body) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error_exit("Socket creation failed");
    }

    // Define the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    
    // Convert IP address from text to binary form
    if (inet_pton(AF_INET, SMTP_SERVER, &server_addr.sin_addr) <= 0) {
        error_exit("Invalid address/ Address not supported");
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error_exit("Connection Failed");
    }

    // Read server greeting
    read(sock, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Send HELO command
    sprintf(buffer, "HELO localhost\r\n");
    send(sock, buffer, strlen(buffer), 0);
    read(sock, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Send AUTH LOGIN
    sprintf(buffer, "AUTH LOGIN\r\n");
    send(sock, buffer, strlen(buffer), 0);
    read(sock, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Since this is an example, we'll skip the actual username and password
    // In a real-world application, you'd want to encode these in base64 and send them.
    send(sock, "dXNlcm5hbWU=\r\n", strlen("dXNlcm5hbWU=\r\n"), 0); // Placeholder for username (base64 of "username")
    read(sock, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    send(sock, "cGFzc3dvcmQ=\r\n", strlen("cGFzc3dvcmQ=\r\n"), 0); // Placeholder for password (base64 of "password")
    read(sock, buffer, sizeof(buffer));
    printf("Server: %s", buffer);
    
    // Send MAIL FROM
    sprintf(buffer, "MAIL FROM:<%s>\r\n", from);
    send(sock, buffer, strlen(buffer), 0);
    read(sock, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Send RCPT TO
    sprintf(buffer, "RCPT TO:<%s>\r\n", to);
    send(sock, buffer, strlen(buffer), 0);
    read(sock, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Send DATA
    send(sock, "DATA\r\n", strlen("DATA\r\n"), 0);
    read(sock, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Send email headers
    sprintf(buffer, "Subject: %s\r\n", subject);
    send(sock, buffer, strlen(buffer), 0);
    send(sock, "From: ", strlen("From: "), 0);
    send(sock, from, strlen(from), 0);
    send(sock, "\r\n", 2, 0);
    send(sock, "To: ", strlen("To: "), 0);
    send(sock, to, strlen(to), 0);
    send(sock, "\r\n\r\n", 4, 0);

    // Send email body
    send(sock, body, strlen(body), 0);
    send(sock, "\r\n.\r\n", 5, 0); // End of data
    read(sock, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Send QUIT
    send(sock, "QUIT\r\n", strlen("QUIT\r\n"), 0);
    read(sock, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Close the socket
    close(sock);
    return 0;
}

int main() {
    const char *from = "you@example.com";
    const char *to = "recipient@example.com";
    const char *subject = "Test Email";
    const char *body = "This is a test email sent from a C SMTP client.\n\nBest,\nC SMTP Client";

    send_email(from, to, subject, body);
    return 0;
}