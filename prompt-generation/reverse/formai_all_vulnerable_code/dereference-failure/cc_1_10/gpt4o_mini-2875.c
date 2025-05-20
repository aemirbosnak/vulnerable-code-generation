//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define SMTP_PORT 465 // SMTP over SSL port
#define BUFFER_SIZE 1024

void handleError(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

SSL_CTX *initializeSSLContext() {
    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();

    SSL_CTX *ctx = SSL_CTX_new(SSLv23_client_method());
    if (!ctx) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
    return ctx;
}

void cleanupSSL(SSL_CTX *ctx) {
    SSL_CTX_free(ctx);
    EVP_cleanup();
}

void sendEmail(const char *smtp_server, const char *from, const char *to, const char *subject, const char *body) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;
    SSL_CTX *ctx;
    SSL *ssl;

    // Initialize SSL
    ctx = initializeSSLContext();

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        handleError("Socket creation failed");
    }

    // Get server address
    if ((host = gethostbyname(smtp_server)) == NULL) {
        handleError("Error in getting host");
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handleError("Connection to SMTP server failed");
    }

    // Create SSL connection
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) <= 0) {
        ERR_print_errors_fp(stderr);
        SSL_free(ssl);
        close(sockfd);
        cleanupSSL(ctx);
        exit(EXIT_FAILURE);
    }

    // Send EHLO command
    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "EHLO localhost\r\n");
    SSL_write(ssl, buffer, strlen(buffer));
    SSL_read(ssl, buffer, sizeof(buffer) - 1);
    printf("Server: %s\n", buffer);

    // Mail from
    snprintf(buffer, sizeof(buffer), "MAIL FROM:<%s>\r\n", from);
    SSL_write(ssl, buffer, strlen(buffer));
    SSL_read(ssl, buffer, sizeof(buffer) - 1);
    printf("Server: %s\n", buffer);

    // Recipient
    snprintf(buffer, sizeof(buffer), "RCPT TO:<%s>\r\n", to);
    SSL_write(ssl, buffer, strlen(buffer));
    SSL_read(ssl, buffer, sizeof(buffer) - 1);
    printf("Server: %s\n", buffer);

    // Data
    SSL_write(ssl, "DATA\r\n", 6);
    SSL_read(ssl, buffer, sizeof(buffer) - 1);
    printf("Server: %s\n", buffer);

    // Send email content
    snprintf(buffer, sizeof(buffer), "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    SSL_write(ssl, buffer, strlen(buffer));
    SSL_read(ssl, buffer, sizeof(buffer) - 1);
    printf("Server: %s\n", buffer);

    // Quit the session
    SSL_write(ssl, "QUIT\r\n", 6);
    SSL_read(ssl, buffer, sizeof(buffer) - 1);
    printf("Server: %s\n", buffer);

    // Cleanup
    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sockfd);
    cleanupSSL(ctx);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <smtp_server> <from_email> <to_email> <subject> <body>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *smtp_server = argv[1];
    const char *from_email = argv[2];
    const char *to_email = argv[3];
    const char *subject = argv[4];
    const char *body = argv[5];

    sendEmail(smtp_server, from_email, to_email, subject, body);

    return 0;
}