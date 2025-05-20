//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SMTP_PORT 587
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_command(int sockfd, const char *cmd, char *response) {
    write(sockfd, cmd, strlen(cmd));
    write(sockfd, "\r\n", 2);
    read(sockfd, response, BUFFER_SIZE);
}

void smtp_auth(int sockfd, const char *username, const char *password) {
    char response[BUFFER_SIZE];
    char auth_cmd[BUFFER_SIZE];

    // EHLO command
    send_command(sockfd, "EHLO localhost", response);
    printf("%s", response);

    // Start TLS
    send_command(sockfd, "STARTTLS", response);
    printf("%s", response);

    // Base64 encode username and password
    char *b64_user = (char *) malloc(BUFFER_SIZE);
    char *b64_pass = (char *) malloc(BUFFER_SIZE);
    
    // A very simple base64 encoding function (for demonstration purposes!)
    snprintf(b64_user, BUFFER_SIZE, "encoded_%s", username);
    snprintf(b64_pass, BUFFER_SIZE, "encoded_%s", password); 

    // Authenticate
    snprintf(auth_cmd, BUFFER_SIZE, "AUTH LOGIN\r\n");
    send_command(sockfd, auth_cmd, response);
    printf("%s", response);

    send_command(sockfd, b64_user, response);
    printf("%s", response);
    
    send_command(sockfd, b64_pass, response);
    printf("%s", response);

    free(b64_user);
    free(b64_pass);
}

void smtp_send_email(int sockfd, const char *from, const char *to, const char *subject, const char *body) {
    char response[BUFFER_SIZE];
    char mail_cmd[BUFFER_SIZE];

    snprintf(mail_cmd, BUFFER_SIZE, "MAIL FROM:<%s>\r\n", from);
    send_command(sockfd, mail_cmd, response);
    printf("%s", response);

    snprintf(mail_cmd, BUFFER_SIZE, "RCPT TO:<%s>\r\n", to);
    send_command(sockfd, mail_cmd, response);
    printf("%s", response);

    send_command(sockfd, "DATA", response);
    printf("%s", response);

    // Send email body
    write(sockfd, body, strlen(body));
    write(sockfd, "\r\n.\r\n", 5);
    read(sockfd, response, BUFFER_SIZE);
    printf("%s", response);
}

int main() {
    int sockfd;
    struct sockaddr_in server;
    struct hostent *host;
    
    const char *smtp_server = "smtp.example.com"; // Replace with the actual SMTP server
    const char *username = "user@example.com"; // Your email
    const char *password = "password"; // Your password

    const char *from = "user@example.com";
    const char *to = "recipient@example.com";
    const char *subject = "Hello from SMTP Client";
    const char *body = "Subject: Hello from SMTP Client\r\n\r\nThis is a test email sent from a C SMTP client!";

    // Creating socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    host = gethostbyname(smtp_server);
    if (host == NULL) 
        error("ERROR, no such host");

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    memcpy(&server.sin_addr.s_addr, host->h_addr, host->h_length);
    server.sin_port = htons(SMTP_PORT);

    // Connecting to the SMTP server
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0)
        error("ERROR connecting");

    char response[BUFFER_SIZE];
    read(sockfd, response, BUFFER_SIZE);
    printf("%s", response);

    // Authenticate
    smtp_auth(sockfd, username, password);

    // Send email
    smtp_send_email(sockfd, from, to, subject, body);

    // Quit the session
    send_command(sockfd, "QUIT", response);
    printf("%s", response);

    close(sockfd);
    return 0;
}