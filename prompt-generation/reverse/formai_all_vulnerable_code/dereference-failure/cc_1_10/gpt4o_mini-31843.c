//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SMTP_PORT 587
#define BUFFER_SIZE 1024

void log_event(const char *message) {
    printf("[LOG]: %s\n", message);
}

void connect_to_smtp_server(const char *hostname, int port, int *sockfd) {
    struct sockaddr_in server_addr;
    struct hostent *hostent;

    hostent = gethostbyname(hostname);
    if (hostent == NULL) {
        log_event("Error: Could not resolve SMTP server hostname.");
        exit(EXIT_FAILURE);
    }

    *sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (*sockfd < 0) {
        log_event("Error: Could not create socket.");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr.s_addr, hostent->h_addr_list[0], hostent->h_length);

    if (connect(*sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        log_event("Error: Could not connect to SMTP server.");
        close(*sockfd);
        exit(EXIT_FAILURE);
    }

    log_event("Connected to SMTP server.");
}

void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
    log_event(command);
}

void receive_response(int sockfd, char *buffer) {
    int received_length = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (received_length > 0) {
        buffer[received_length] = '\0';
        printf("[RESPONSE]: %s", buffer);
    } else {
        log_event("Error: Could not receive response.");
    }
}

void authenticate(int sockfd, const char *username, const char *password) {
    char buffer[BUFFER_SIZE];

    // Begin SMTP conversation
    receive_response(sockfd, buffer);

    send_command(sockfd, "EHLO localhost\r\n");
    receive_response(sockfd, buffer);

    // Authenticate
    send_command(sockfd, "AUTH LOGIN\r\n");
    receive_response(sockfd, buffer);
    
    // Send username
    char encoded_username[BUFFER_SIZE];
    sprintf(encoded_username, "%s\r\n", username);
    send_command(sockfd, encoded_username);
    receive_response(sockfd, buffer);
    
    // Send password
    char encoded_password[BUFFER_SIZE];
    sprintf(encoded_password, "%s\r\n", password);
    send_command(sockfd, encoded_password);
    receive_response(sockfd, buffer);
}

void send_email(int sockfd, const char *from, const char *to, const char *subject, const char *body) {
    char buffer[BUFFER_SIZE];

    // Mail From
    send_command(sockfd, "MAIL FROM:<");
    send_command(sockfd, from);
    send_command(sockfd, ">\r\n");
    receive_response(sockfd, buffer);

    // Rcpt To
    send_command(sockfd, "RCPT TO:<");
    send_command(sockfd, to);
    send_command(sockfd, ">\r\n");
    receive_response(sockfd, buffer);

    // Data
    send_command(sockfd, "DATA\r\n");
    receive_response(sockfd, buffer);

    // Headers and Body
    send_command(sockfd, "Subject: ");
    send_command(sockfd, subject);
    send_command(sockfd, "\r\n\r\n");
    send_command(sockfd, body);
    send_command(sockfd, "\r\n.\r\n");
    receive_response(sockfd, buffer);
}

void close_connection(int sockfd) {
    send_command(sockfd, "QUIT\r\n");
    close(sockfd);
    log_event("Connection closed.");
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <smtp_server> <username> <password> <email>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *smtp_server = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];
    const char *to_email = argv[4];

    int sockfd;
    connect_to_smtp_server(smtp_server, SMTP_PORT, &sockfd);
    authenticate(sockfd, username, password);
    send_email(sockfd, username, to_email, "Sherlock Holmes SMTP Test", "Greetings from the Baker Street Consulting Detective.\n\nBest regards,\nSherlock Holmes.");
    close_connection(sockfd);
    
    return 0;
}