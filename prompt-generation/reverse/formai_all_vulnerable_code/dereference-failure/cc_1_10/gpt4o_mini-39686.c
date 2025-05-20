//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 25  // Default SMTP Port
#define BUFFER_SIZE 1024

void die(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void smtp_connect(int *sockfd, const char *server) {
    struct sockaddr_in server_addr;

    // Create socket
    if ((*sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        die("Socket creation failed");
    }

    struct hostent *host = gethostbyname(server);
    if (host == NULL) {
        die("No such host");
    }

    // Set up server address
    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)host->h_addr, (char *)&server_addr.sin_addr.s_addr, host->h_length);
    server_addr.sin_port = htons(PORT);

    // Connect to server
    if (connect(*sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        die("Connection to server failed");
    }
}

void smtp_send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
}

void smtp_receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int n = read(sockfd, buffer, sizeof(buffer) - 1);
    buffer[n] = '\0'; // Null terminate received data
    printf("%s", buffer);
}

void send_email(int sockfd, const char *from, const char *to, const char *subject, const char *body) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "EHLO localhost\r\n");
    smtp_send_command(sockfd, command);
    smtp_receive_response(sockfd);

    snprintf(command, sizeof(command), "MAIL FROM:<%s>\r\n", from);
    smtp_send_command(sockfd, command);
    smtp_receive_response(sockfd);

    snprintf(command, sizeof(command), "RCPT TO:<%s>\r\n", to);
    smtp_send_command(sockfd, command);
    smtp_receive_response(sockfd);

    snprintf(command, sizeof(command), "DATA\r\n");
    smtp_send_command(sockfd, command);
    smtp_receive_response(sockfd);

    snprintf(command, sizeof(command), "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    smtp_send_command(sockfd, command);
    smtp_receive_response(sockfd);

    snprintf(command, sizeof(command), "QUIT\r\n");
    smtp_send_command(sockfd, command);
    smtp_receive_response(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <SMTP_SERVER> <FROM_EMAIL> <TO_EMAIL> <SUBJECT> <BODY>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *smtp_server = argv[1];
    const char *from_email = argv[2];
    const char *to_email = argv[3];
    const char *subject = argv[4];
    
    int sockfd;
    smtp_connect(&sockfd, smtp_server);
    smtp_receive_response(sockfd); 

    // Prepare email body
    char email_body[BUFFER_SIZE];
    snprintf(email_body, sizeof(email_body), "This is a test email from a C email client.\n");

    // Send email
    send_email(sockfd, from_email, to_email, subject, email_body);

    close(sockfd);
    return 0;
}