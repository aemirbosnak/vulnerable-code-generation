//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAXLINE 1024

// Function to create and connect a socket
int create_socket(const char *server_ip, int port) {
    int sockfd;
    struct sockaddr_in server_addr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Function to send a command to the server and receive a response
void send_command(int sockfd, const char *command) {
    char buffer[MAXLINE];
    send(sockfd, command, strlen(command), 0);
    recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    printf("Response: %s", buffer);
}

// Function to send an email
void send_email(int sockfd, const char *from, const char *to, const char *subject, const char *body) {
    send_command(sockfd, "HELO localhost\r\n");
    send_command(sockfd, "MAIL FROM:<");
    send_command(sockfd, from);
    send_command(sockfd, ">\r\n");
    send_command(sockfd, "RCPT TO:<");
    send_command(sockfd, to);
    send_command(sockfd, ">\r\n");
    send_command(sockfd, "DATA\r\n");

    char email[MAXLINE];
    snprintf(email, sizeof(email), "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    send_command(sockfd, email);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <SMTP server IP> <port> <from> <to>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *server_ip = argv[1];
    int port = atoi(argv[2]);
    const char *from = argv[3];
    const char *to = argv[4];
    const char *subject = "Test Subject";
    const char *body = "This is a test email body.";

    int sockfd = create_socket(server_ip, port);
    
    send_email(sockfd, from, to, subject, body);
    
    send_command(sockfd, "QUIT\r\n"); // Terminate the connection

    close(sockfd);
    return 0;
}