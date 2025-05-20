//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define SMTP_PORT 587
#define BUFFER_SIZE 1024

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int create_socket(const char *hostname) {
    struct sockaddr_in server_addr;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) handle_error("Socket creation failed");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        close(sockfd);
        handle_error("Connection failed");
    }
    return sockfd;
}

void smtp_send(int sockfd, const char *msg) {
    if (send(sockfd, msg, strlen(msg), 0) < 0) handle_error("Send failed");
}

void smtp_receive(int sockfd, char *buffer) {
    int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0) handle_error("Receive failed");
    buffer[bytes_received] = '\0';
}

void authenticate(SSL *ssl, const char *username, const char *password) {
    char buffer[BUFFER_SIZE];

    sprintf(buffer, "AUTH LOGIN\r\n");
    smtp_send(SSL_get_fd(ssl), buffer);
    smtp_receive(SSL_get_fd(ssl), buffer);
    printf("Server: %s\n", buffer);

    // Base64 encode username and password
    char encoded_username[BUFFER_SIZE];
    char encoded_password[BUFFER_SIZE];
    snprintf(encoded_username, sizeof(encoded_username), "%s", username); // For simplicity
    snprintf(encoded_password, sizeof(encoded_password), "%s", password);  // For simplicity

    sprintf(buffer, "%s\r\n", encoded_username);
    smtp_send(SSL_get_fd(ssl), buffer);
    smtp_receive(SSL_get_fd(ssl), buffer);
    printf("Server: %s\n", buffer);

    sprintf(buffer, "%s\r\n", encoded_password);
    smtp_send(SSL_get_fd(ssl), buffer);
    smtp_receive(SSL_get_fd(ssl), buffer);
    printf("Server: %s\n", buffer);
}

void send_email(SSL *ssl, const char *from, const char *to, const char *subject, const char *body) {
    char buffer[BUFFER_SIZE];

    sprintf(buffer, "MAIL FROM:<%s>\r\n", from);
    smtp_send(SSL_get_fd(ssl), buffer);
    smtp_receive(SSL_get_fd(ssl), buffer);
    printf("Server: %s\n", buffer);

    sprintf(buffer, "RCPT TO:<%s>\r\n", to);
    smtp_send(SSL_get_fd(ssl), buffer);
    smtp_receive(SSL_get_fd(ssl), buffer);
    printf("Server: %s\n", buffer);

    sprintf(buffer, "DATA\r\n");
    smtp_send(SSL_get_fd(ssl), buffer);
    smtp_receive(SSL_get_fd(ssl), buffer);
    printf("Server: %s\n", buffer);

    sprintf(buffer, "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    smtp_send(SSL_get_fd(ssl), buffer);
    smtp_receive(SSL_get_fd(ssl), buffer);
    printf("Server: %s\n", buffer);
}

int main() {
    const char *smtp_server = "smtp.example.com";  // Replace with your SMTP server
    const char *username = "example@example.com";   // Replace with your email
    const char *password = "yourpassword";           // Replace with your password
    const char *from = "from@example.com";           // Replace with sender email
    const char *to = "to@example.com";               // Replace with recipient email
    const char *subject = "Test Email";
    const char *body = "Hello, this is a test email from a simple SMTP client.";

    int sockfd = create_socket(smtp_server);
    SSL_CTX *ctx = SSL_CTX_new(TLS_client_method());
    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);

    if (SSL_connect(ssl) <= 0) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    smtp_receive(sockfd, buffer);
    printf("Server: %s\n", buffer);

    authenticate(ssl, username, password);
    send_email(ssl, from, to, subject, body);

    sprintf(buffer, "QUIT\r\n");
    smtp_send(SSL_get_fd(ssl), buffer);
    smtp_receive(SSL_get_fd(ssl), buffer);
    printf("Server: %s\n", buffer);

    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);
    return 0;
}