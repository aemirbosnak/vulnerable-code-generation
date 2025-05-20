//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define SMTP_PORT 587
#define POP3_PORT 110
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_email(const char *server, const char *from, const char *to, const char *subject, const char *body) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char message[BUFFER_SIZE * 2];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    struct hostent *server_host = gethostbyname(server);
    if (server_host == NULL)
        error("ERROR, no such host");

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server_host->h_addr, (char *)&server_addr.sin_addr.s_addr, server_host->h_length);
    server_addr.sin_port = htons(SMTP_PORT);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        error("ERROR connecting to SMTP server");

    // SMTP communication
    snprintf(buffer, sizeof(buffer), "HELO localhost\r\n");
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer));
    
    snprintf(buffer, sizeof(buffer), "MAIL FROM: <%s>\r\n", from);
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer));
    
    snprintf(buffer, sizeof(buffer), "RCPT TO: <%s>\r\n", to);
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer));
    
    snprintf(buffer, sizeof(buffer), "DATA\r\n");
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer));
    
    snprintf(message, sizeof(message), "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    write(sockfd, message, strlen(message));
    read(sockfd, buffer, sizeof(buffer));
    
    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    write(sockfd, buffer, strlen(buffer));
    close(sockfd);
}

void receive_emails(const char *server, const char *username, const char *password) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    struct hostent *server_host = gethostbyname(server);
    if (server_host == NULL)
        error("ERROR, no such host");

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server_host->h_addr, (char *)&server_addr.sin_addr.s_addr, server_host->h_length);
    server_addr.sin_port = htons(POP3_PORT);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        error("ERROR connecting to POP3 server");

    // POP3 communication
    read(sockfd, buffer, sizeof(buffer));
    
    snprintf(buffer, sizeof(buffer), "USER %s\r\n", username);
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer));
    
    snprintf(buffer, sizeof(buffer), "PASS %s\r\n", password);
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer));
    
    snprintf(buffer, sizeof(buffer), "LIST\r\n");
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer));
    
    printf("Emails:\n%s\n", buffer);

    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    write(sockfd, buffer, strlen(buffer));
    close(sockfd);
}

int main() {
    const char *smtp_server = "smtp.example.com";
    const char *pop3_server = "pop.example.com";
    const char *username = "your_email@example.com";
    const char *password = "your_email_password";
    
    const char *from = "sender@example.com";
    const char *to = "recipient@example.com";
    const char *subject = "Test Email";
    const char *body = "Hello, this is a test email from a C program.";

    send_email(smtp_server, from, to, subject, body);
    receive_emails(pop3_server, username, password);
    
    return 0;
}