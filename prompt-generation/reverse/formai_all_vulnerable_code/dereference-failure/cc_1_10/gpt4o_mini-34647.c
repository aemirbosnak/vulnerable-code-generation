//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 25 // SMTP port
#define BUFFER_SIZE 1024
#define EMAIL_SIZE 256

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_email(const char *server, const char *from, const char *to, const char *subject, const char *body) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;

    char buffer[BUFFER_SIZE];
    int bytes;

    host = gethostbyname(server);
    if (host == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)host->h_addr, (char *)&server_addr.sin_addr.s_addr, host->h_length);
    server_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) 
        error("ERROR connecting");

    // Receive Server Greeting
    bzero(buffer, BUFFER_SIZE);
    read(sockfd, buffer, BUFFER_SIZE - 1);
    printf("%s", buffer);

    // Send HELO command
    sprintf(buffer, "HELO %s\r\n", from);
    write(sockfd, buffer, strlen(buffer));
    bzero(buffer, BUFFER_SIZE);
    read(sockfd, buffer, BUFFER_SIZE - 1);
    printf("%s", buffer);

    // Send MAIL FROM command
    sprintf(buffer, "MAIL FROM:<%s>\r\n", from);
    write(sockfd, buffer, strlen(buffer));
    bzero(buffer, BUFFER_SIZE);
    read(sockfd, buffer, BUFFER_SIZE - 1);
    printf("%s", buffer);

    // Send RCPT TO command
    sprintf(buffer, "RCPT TO:<%s>\r\n", to);
    write(sockfd, buffer, strlen(buffer));
    bzero(buffer, BUFFER_SIZE);
    read(sockfd, buffer, BUFFER_SIZE - 1);
    printf("%s", buffer);

    // Send DATA command
    write(sockfd, "DATA\r\n", 7);
    bzero(buffer, BUFFER_SIZE);
    read(sockfd, buffer, BUFFER_SIZE - 1);
    printf("%s", buffer);

    // Send email content
    sprintf(buffer, "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    write(sockfd, buffer, strlen(buffer));
    bzero(buffer, BUFFER_SIZE);
    read(sockfd, buffer, BUFFER_SIZE - 1);
    printf("%s", buffer);

    // Send QUIT command
    write(sockfd, "QUIT\r\n", 7);
    bzero(buffer, BUFFER_SIZE);
    read(sockfd, buffer, BUFFER_SIZE - 1);
    printf("%s", buffer);

    close(sockfd);
}

int main() {
    // Test email parameters
    const char *smtp_server = "smtp.example.com"; // Replace with your SMTP server
    const char *from = "sender@example.com";      // Sender email address
    const char *to = "receiver@example.com";      // Recipient email address
    const char *subject = "Test Email from C Client";
    const char *body = "Hello! This is a test email sent from a C SMTP client.";

    // Send the email
    send_email(smtp_server, from, to, subject, body);

    return 0;
}