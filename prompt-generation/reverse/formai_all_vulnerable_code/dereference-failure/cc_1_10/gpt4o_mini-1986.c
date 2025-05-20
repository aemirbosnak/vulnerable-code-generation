//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // For sleep
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define SMTP_PORT 25
#define MAX_EMAIL_SIZE 512

void error_handling(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void clear_buffer(char *buffer) {
    memset(buffer, 0, BUFFER_SIZE);
}

int connect_to_smtp(const char *server, int port) {
    struct sockaddr_in server_addr;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sockfd < 0) error_handling("Socket creation failed");

    struct hostent *host = gethostbyname(server);
    if (host == NULL) error_handling("No such host");

    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)host->h_addr, 
          (char *)&server_addr.sin_addr.s_addr, 
          host->h_length);
    server_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error_handling("Connection to SMTP server failed");
    }
    return sockfd;
}

void send_command(int sockfd, const char *command) {
    write(sockfd, command, strlen(command));
    write(sockfd, "\r\n", 2);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    clear_buffer(buffer);
    read(sockfd, buffer, BUFFER_SIZE - 1);
    printf("Server response: %s\n", buffer);
}

static void send_email(int sockfd, const char *sender, const char *recipient, const char *subject, const char *body) {
    char command[BUFFER_SIZE];

    sprintf(command, "MAIL FROM:<%s>", sender);
    send_command(sockfd, command);
    receive_response(sockfd);

    sprintf(command, "RCPT TO:<%s>", recipient);
    send_command(sockfd, command);
    receive_response(sockfd);

    send_command(sockfd, "DATA");
    receive_response(sockfd);

    sprintf(command, "Subject: %s\r\n\r\n%s\r\n.", subject, body);
    send_command(sockfd, command);
    receive_response(sockfd);
}

int main() {
    const char *smtp_server = "smtp.example.com"; // Use a valid SMTP server here
    int sockfd;

    char sender[MAX_EMAIL_SIZE], recipient[MAX_EMAIL_SIZE], subject[MAX_EMAIL_SIZE], body[BUFFER_SIZE];

    printf("Welcome to Your C Email Client!\n");
    printf("Enter your email address: ");
    fgets(sender, MAX_EMAIL_SIZE, stdin);
    sender[strcspn(sender, "\n")] = 0; // Remove newline

    printf("Enter recipient email address: ");
    fgets(recipient, MAX_EMAIL_SIZE, stdin);
    recipient[strcspn(recipient, "\n")] = 0; // Remove newline

    printf("Enter subject of the email: ");
    fgets(subject, MAX_EMAIL_SIZE, stdin);
    subject[strcspn(subject, "\n")] = 0; // Remove newline

    printf("Enter your message: ");
    fgets(body, BUFFER_SIZE, stdin);
    body[strcspn(body, "\n")] = 0; // Remove newline

    printf("Connecting to SMTP server...\n");
    sockfd = connect_to_smtp(smtp_server, SMTP_PORT);
    
    receive_response(sockfd); // Get server greeting

    send_command(sockfd, "HELO your.domain.com"); // Your domain
    receive_response(sockfd);
    
    send_email(sockfd, sender, recipient, subject, body);
    send_command(sockfd, "QUIT");
    receive_response(sockfd);
    
    printf("Email sent successfully!\n");
    close(sockfd);
    return 0;
}