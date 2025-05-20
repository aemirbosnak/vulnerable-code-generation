//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SMTP_PORT 587
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int create_socket(char *host) {
    struct sockaddr_in server_addr;
    struct hostent *server;

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(SMTP_PORT);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("ERROR connecting");
    }

    return sockfd;
}

void send_command(int sockfd, const char *cmd) {
    char buffer[BUFFER_SIZE];
    
    write(sockfd, cmd, strlen(cmd));
    write(sockfd, "\r\n", 2);
    
    bzero(buffer, BUFFER_SIZE);
    read(sockfd, buffer, BUFFER_SIZE - 1);
    
    printf("Server response: %s", buffer);
}

void send_email(const char *from, const char *to, const char *subject, const char *body) {
    int sockfd = create_socket("smtp.example.com");

    // Handshake or EHLO
    send_command(sockfd, "EHLO localhost");

    // Authenticate (ADD YOUR AUTHENTICATION HERE)
    send_command(sockfd, "AUTH LOGIN");
    
    // From address
    char from_cmd[BUFFER_SIZE];
    snprintf(from_cmd, sizeof(from_cmd), "MAIL FROM:<%s>", from);
    send_command(sockfd, from_cmd);

    // To address
    char to_cmd[BUFFER_SIZE];
    snprintf(to_cmd, sizeof(to_cmd), "RCPT TO:<%s>", to);
    send_command(sockfd, to_cmd);
    
    // Data command
    send_command(sockfd, "DATA");
    
    // Email content
    char email_body[BUFFER_SIZE];
    snprintf(email_body, sizeof(email_body),
             "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s\r\n.\r\n",
             from, to, subject, body);

    write(sockfd, email_body, strlen(email_body));

    // Ending the DATA command
    bzero(email_body, BUFFER_SIZE);
    read(sockfd, email_body, BUFFER_SIZE - 1);
    printf("Server response: %s", email_body);

    // Quit
    send_command(sockfd, "QUIT");

    close(sockfd);
}

int main() {
    char from[256], to[256], subject[256], body[1024];

    printf("Enter sender email address: ");
    fgets(from, sizeof(from), stdin);
    from[strcspn(from, "\n")] = 0;  // Remove newline character

    printf("Enter recipient email address: ");
    fgets(to, sizeof(to), stdin);
    to[strcspn(to, "\n")] = 0;  // Remove newline character

    printf("Enter email subject: ");
    fgets(subject, sizeof(subject), stdin);
    subject[strcspn(subject, "\n")] = 0;  // Remove newline character

    printf("Enter email body: ");
    fgets(body, sizeof(body), stdin);
    body[strcspn(body, "\n")] = 0;  // Remove newline character

    // Send the email
    send_email(from, to, subject, body);

    return 0;
}