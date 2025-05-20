//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int send_email(int socket, const char *email_content) {
    char buffer[BUFFER_SIZE];
    int bytes_sent;

    // Send each line of the email content
    char *line = strtok((char *)email_content, "\n");
    while (line != NULL) {
        bytes_sent = send(socket, line, strlen(line), 0);
        if (bytes_sent < 0) {
            return -1;
        }

        // Add CRLF at the end of each line except the last
        if (strtok(NULL, "\n") != NULL) {
            send(socket, "\r\n", 2, 0);
        }
        line = strtok(NULL, "\n");
    }
    
    // Send ending command (e.g. . for end of data)
    send(socket, "\r\n.\r\n", 5, 0);
    
    // Receive server response
    recv(socket, buffer, sizeof(buffer) - 1, 0);
    buffer[sizeof(buffer) - 1] = '\0'; // Null terminate
    printf("Server response after email: %s", buffer);
    
    return 0;
}

void build_email(const char *from, const char *to, const char *subject, const char *body, char *email_content) {
    sprintf(email_content,
            "From: %s\r\n"
            "To: %s\r\n"
            "Subject: %s\r\n"
            "\r\n"
            "%s\r\n",
            from, to, subject, body);
}

int main(int argc, char *argv[]) {
    if (argc != 6) {
        fprintf(stderr, "Usage: %s <smtp_server> <port> <from_email> <to_email> <subject> <body>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    const char *smtp_server = argv[1];
    int port = atoi(argv[2]);
    const char *from_email = argv[3];
    const char *to_email = argv[4];
    const char *subject = argv[5];
    const char *body = argv[6];
    
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char email_content[BUFFER_SIZE * 2];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    // Set up server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    
    // Convert IP address from text to binary
    if (inet_pton(AF_INET, smtp_server, &server_addr.sin_addr) <= 0) {
        close(sockfd);
        error("Invalid address / Address not supported");
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        close(sockfd);
        error("Connection failed");
    }

    // Receive server greeting
    recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    buffer[sizeof(buffer) - 1] = '\0'; // Null terminate
    printf("Server response: %s", buffer);

    // Send HELO command
    const char *helo_command = "HELO example.com\r\n";
    send(sockfd, helo_command, strlen(helo_command), 0);
    recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    printf("HELO response: %s", buffer);

    // Build the email content
    build_email(from_email, to_email, subject, body, email_content);
    
    // Send MAIL FROM
    char mail_from_command[256];
    sprintf(mail_from_command, "MAIL FROM:<%s>\r\n", from_email);
    send(sockfd, mail_from_command, strlen(mail_from_command), 0);
    recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    printf("MAIL FROM response: %s", buffer);

    // Send RCPT TO
    char rcpt_to_command[256];
    sprintf(rcpt_to_command, "RCPT TO:<%s>\r\n", to_email);
    send(sockfd, rcpt_to_command, strlen(rcpt_to_command), 0);
    recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    printf("RCPT TO response: %s", buffer);

    // Send DATA
    send(sockfd, "DATA\r\n", 7, 0);
    recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    printf("DATA response: %s", buffer);

    // Send the email
    if (send_email(sockfd, email_content) != 0) {
        close(sockfd);
        error("Failed to send email");
    }

    // Send QUIT
    send(sockfd, "QUIT\r\n", 7, 0);
    recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    printf("QUIT response: %s", buffer);

    close(sockfd);
    return EXIT_SUCCESS;
}