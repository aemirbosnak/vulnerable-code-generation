//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void read_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    printf("Server: %s", buffer);
}

void send_command(int sockfd, const char *cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
    printf("Client: %s", cmd);
    read_response(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <smtp_server> <from_email> <to_email> <email_subject>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *smtp_server = argv[1];
    const char *from_email = argv[2];
    const char *to_email = argv[3];
    const char *email_subject = argv[4];

    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Socket creation failed");
    }

    // Set up the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    
    // Convert server address from text to binary
    if (inet_pton(AF_INET, smtp_server, &server_addr.sin_addr) <= 0) {
        error("Invalid address/ Address not supported");
    }

    // Connect to the SMTP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed");
    }

    read_response(sockfd);
    send_command(sockfd, "HELO localhost\n");
    send_command(sockfd, "MAIL FROM: ");
    send(sockfd, from_email, strlen(from_email), 0);
    send(sockfd, "\n", 1, 0);
    read_response(sockfd);
    
    send_command(sockfd, "RCPT TO: ");
    send(sockfd, to_email, strlen(to_email), 0);
    send(sockfd, "\n", 1, 0);
    read_response(sockfd);
    
    send_command(sockfd, "DATA\n");
    
    // Prepare the email content
    char email_data[BUFFER_SIZE];
    snprintf(email_data, sizeof(email_data),
             "Subject: %s\n"
             "From: %s\n"
             "To: %s\n\n"
             "Hello,\nThis is a test email from my SMTP client.\n.\n",
             email_subject, from_email, to_email);

    send(sockfd, email_data, strlen(email_data), 0);
    read_response(sockfd);
    send_command(sockfd, "QUIT\n");

    close(sockfd);
    return 0;
}