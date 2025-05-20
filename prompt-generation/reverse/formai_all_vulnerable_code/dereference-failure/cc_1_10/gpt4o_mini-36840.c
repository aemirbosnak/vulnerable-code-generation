//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER "smtp.example.com"
#define PORT 587
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int connect_to_server(const char *server, int port) {
    struct sockaddr_in server_addr;
    int sockfd;
    struct hostent *host;

    host = gethostbyname(server);
    if (host == NULL) {
        fprintf(stderr, "Could not resolve host %s\n", server);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)host->h_addr, (char *)&server_addr.sin_addr.s_addr, host->h_length);
    server_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("ERROR connecting");
    }

    return sockfd;
}

void send_command(int sockfd, const char *command) {
    char buffer[BUFFER_SIZE];
    int n;

    // Send command
    n = write(sockfd, command, strlen(command));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // Read response
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        error("ERROR reading from socket");
    }

    printf("%s", buffer);
}

void send_email(int sockfd, const char *from, const char *to, const char *subject, const char *body) {
    char command[BUFFER_SIZE];

    // HELO
    sprintf(command, "HELO localhost\r\n");
    send_command(sockfd, command);

    // AUTH LOGIN
    sprintf(command, "AUTH LOGIN\r\n");
    send_command(sockfd, command);

    // Provide Username and Password 
    // Replace 'your_username' and 'your_password' with real credentials, encoded in base64
    sprintf(command, "your_username_base64\r\n");
    send_command(sockfd, command);
    
    sprintf(command, "your_password_base64\r\n");
    send_command(sockfd, command);

    // MAIL FROM
    sprintf(command, "MAIL FROM:<%s>\r\n", from);
    send_command(sockfd, command);

    // RCPT TO
    sprintf(command, "RCPT TO:<%s>\r\n", to);
    send_command(sockfd, command);

    // DATA
    sprintf(command, "DATA\r\n");
    send_command(sockfd, command);

    // Message data
    sprintf(command, "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    send_command(sockfd, command);

    // QUIT
    sprintf(command, "QUIT\r\n");
    send_command(sockfd, command);
}

int main() {
    int sockfd;
    const char *from = "sender@example.com";
    const char *to = "recipient@example.com";
    const char *subject = "Test Email";
    const char *body = "Hello! This is a test email sent using a simple SMTP client in C.";

    sockfd = connect_to_server(SERVER, PORT);

    send_email(sockfd, from, to, subject, body);

    close(sockfd);
    return 0;
}