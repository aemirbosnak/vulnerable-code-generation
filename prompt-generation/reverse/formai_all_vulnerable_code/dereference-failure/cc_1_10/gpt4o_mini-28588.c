//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define SMTP_SERVER "smtp.example.com"
#define SMTP_PORT 587
#define BUFFER_SIZE 1024

void initialize_ssl() {
    SSL_load_error_strings();   
    OpenSSL_add_ssl_algorithms();
}

void cleanup_ssl() {
    EVP_cleanup();
}

SSL *connect_to_server(const char *hostname, int port) {
    SSL_CTX *ctx;
    SSL *ssl;
    int server;
    struct sockaddr_in addr;
    struct hostent *host;

    initialize_ssl();

    ctx = SSL_CTX_new(TLS_client_method());
    if (!ctx) {
        perror("Unable to create SSL context");
        cleanup_ssl();
        exit(EXIT_FAILURE);
    }

    host = gethostbyname(hostname);
    if (!host) {
        perror("Cannot resolve hostname");
        exit(EXIT_FAILURE);
    }

    server = socket(AF_INET, SOCK_STREAM, 0);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr = *((struct in_addr *)host->h_addr);
    
    if (connect(server, (struct sockaddr*)&addr, sizeof(addr)) != 0) {
        perror("Unable to connect");
        exit(EXIT_FAILURE);
    }

    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, server);
    
    if (SSL_connect(ssl) <= 0) {
        ERR_print_errors_fp(stderr);
    } else {
        printf("Successfully connected and SSL handshake completed!\n");
    }

    return ssl;
}

void smtp_send_command(SSL *ssl, const char *cmd) {
    char buffer[BUFFER_SIZE];
    SSL_write(ssl, cmd, strlen(cmd));
    SSL_write(ssl, "\r\n", 2);
    
    int bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1);
    buffer[bytes] = '\0';
    printf("Response: %s", buffer);
}

void send_email(SSL *ssl) {
    printf("\nSending email...\n");
    
    smtp_send_command(ssl, "EHLO localhost");
    smtp_send_command(ssl, "MAIL FROM:<you@example.com>");
    smtp_send_command(ssl, "RCPT TO:<friend@example.com>");
    smtp_send_command(ssl, "DATA");
    
    smtp_send_command(ssl, "Subject: Test Email from C SMTP Client");
    smtp_send_command(ssl, "This is a test email sent from a C program.");
    smtp_send_command(ssl, "."); // End of the email data

    smtp_send_command(ssl, "QUIT");
    printf("Email Sent! Hooray!\n");
}

int main() {
    printf("Welcome to the Happy SMTP Client!\n");

    SSL *ssl = connect_to_server(SMTP_SERVER, SMTP_PORT);

    send_email(ssl);

    SSL_free(ssl);
    cleanup_ssl();

    return 0;
}