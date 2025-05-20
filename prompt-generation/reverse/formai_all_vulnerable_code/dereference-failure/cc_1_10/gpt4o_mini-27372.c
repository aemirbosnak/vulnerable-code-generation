//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(int sockfd, const char *cmd, const char *response) {
    char buffer[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);

    // Send the command to the SMTP server
    if (send(sockfd, cmd, strlen(cmd), 0) < 0) {
        error("Sending command failed");
    }

    // Receive the response from the server
    if (recv(sockfd, buffer, BUFFER_SIZE - 1, 0) < 0) {
        error("Receiving response failed");
    }

    // Print the response
    printf("Server: %s", buffer);
    if (strncmp(buffer, response, 3) != 0) {
        fprintf(stderr, "Unexpected response: %s\n", buffer);
        exit(EXIT_FAILURE);
    }
}

void connect_to_smtp_server(const char *hostname) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error creating socket");
    }

    // Get server details
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "No such host: %s\n", hostname);
        exit(EXIT_FAILURE);
    }

    // Prepare server address
    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(SMTP_PORT);

    // Connect to the SMTP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection to server failed");
    }

    printf("Connected to SMTP server %s\n", hostname);

    // SMTP communication begins
    char buffer[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    printf("Server: %s", buffer); // Welcome message

    // EHLO command
    send_command(sockfd, "EHLO localhost\r\n", "250");

    // Mail command
    send_command(sockfd, "MAIL FROM:<sender@example.com>\r\n", "250");

    // RCPT command
    send_command(sockfd, "RCPT TO:<recipient@example.com>\r\n", "250");

    // DATA command
    send_command(sockfd, "DATA\r\n", "354");

    // Email message
    const char *email_body = "Subject: Test Email\r\n"
                             "This is a test email.\r\n"
                             ".\r\n"; // End of data

    // Send the email
    if (send(sockfd, email_body, strlen(email_body), 0) < 0) {
        error("Sending email failed");
    }
    // Final confirmation
    send_command(sockfd, "\r\n", "250");

    // Quit command
    send_command(sockfd, "QUIT\r\n", "221");

    // Close the socket
    close(sockfd);
    printf("Disconnected from SMTP server.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <SMTP server hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *smtp_server = argv[1];
    connect_to_smtp_server(smtp_server);

    return 0;
}