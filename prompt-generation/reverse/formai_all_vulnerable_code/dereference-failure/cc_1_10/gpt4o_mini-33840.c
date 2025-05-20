//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SMTP_SERVER "smtp.example.com"
#define SMTP_PORT 587
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

// Create a socket and connect to the SMTP server
int create_smtp_connection(const char* server, int port) {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, server, &server_addr.sin_addr) <= 0) {
        error("ERROR Invalid address or address not supported");
    }

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        error("ERROR Connecting to SMTP server");
    }

    return sockfd;
}

// Send command to SMTP server and receive the response
void send_smtp_command(int sockfd, const char *command) {
    char buffer[BUFFER_SIZE];
    int n;

    write(sockfd, command, strlen(command));
    write(sockfd, "\r\n", 2);
    n = read(sockfd, buffer, sizeof(buffer)-1);
    if (n < 0) {
        error("ERROR reading response from server");
    }
    buffer[n] = '\0'; // Null terminate the buffer
    printf("%s", buffer); // Print the server response
}

// Send an email using SMTP protocol
void send_email(int sockfd, const char* from, const char* to, const char* subject, const char* body) {
    send_smtp_command(sockfd, "HELO localhost");
    send_smtp_command(sockfd, "MAIL FROM: <from@example.com>");
    send_smtp_command(sockfd, "RCPT TO: <to@example.com>");
    send_smtp_command(sockfd, "DATA");
    
    // Prepare the email content
    char email[BUFFER_SIZE];
    snprintf(email, sizeof(email), "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    
    send_smtp_command(sockfd, email);
    send_smtp_command(sockfd, "QUIT");
}

int main() {
    const char* smtp_server = SMTP_SERVER;
    int smtp_port = SMTP_PORT;
    const char* from_address = "from@example.com";
    const char* to_address = "to@example.com";
    const char* email_subject = "Test Email from C SMTP Client";
    const char* email_body = "This is a test email sent using a simple C SMTP client.";

    // Establish an SMTP connection
    int sockfd = create_smtp_connection(smtp_server, smtp_port);
    send_email(sockfd, from_address, to_address, email_subject, email_body);
    
    close(sockfd);
    return 0;
}