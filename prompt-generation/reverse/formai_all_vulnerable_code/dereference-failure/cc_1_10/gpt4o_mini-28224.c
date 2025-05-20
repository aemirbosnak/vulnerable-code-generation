//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SERVER "imap.example.com"
#define PORT 993
#define BUFFER_SIZE 1024

void init_openssl() {
    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();
}

void cleanup_openssl() {
    EVP_cleanup();
}

SSL_CTX *create_context() {
    SSL_CTX *ctx;
    ctx = SSL_CTX_new(TLS_client_method());
    if (!ctx) {
        perror("Unable to create SSL context");
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
    return ctx;
}

void configure_context(SSL_CTX *ctx) {
    // Load the trust store, if needed.
    // SSL_CTX_load_verify_locations(ctx, "path/to/cacert.pem", NULL);
}

int connect_to_server(const char *server, int port) {
    int sock;
    struct sockaddr_in server_addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, server, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    return sock;
}

void send_ssl_message(SSL *ssl, const char *msg) {
    if (SSL_write(ssl, msg, strlen(msg)) <= 0) {
        perror("SSL write failed");
    }
}

void receive_ssl_message(SSL *ssl, char *buffer, int size) {
    int bytes = SSL_read(ssl, buffer, size - 1);
    if (bytes < 0) {
        perror("SSL read failed");
    } else {
        buffer[bytes] = '\0'; // Null-terminate the received message
    }
}

void fetch_mailboxes(SSL *ssl) {
    char buffer[BUFFER_SIZE];

    send_ssl_message(ssl, "A001 LOGIN username password\r\n");
    receive_ssl_message(ssl, buffer, sizeof(buffer));
    printf("Login response: %s\n", buffer);

    send_ssl_message(ssl, "A002 LIST \"\" \"*\"\r\n");
    receive_ssl_message(ssl, buffer, sizeof(buffer));
    printf("Mailbox list response: %s\n", buffer);
}

int main() {
    SSL_CTX *ctx;
    SSL *ssl;
    int sock;

    init_openssl();
    ctx = create_context();
    configure_context(ctx);

    sock = connect_to_server(SERVER, PORT);
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock);
    
    if (SSL_connect(ssl) <= 0) {
        ERR_print_errors_fp(stderr);
    } else {
        printf("Connected to the server securely!\n");
        fetch_mailboxes(ssl);
    }

    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sock);
    SSL_CTX_free(ctx);
    cleanup_openssl();

    return 0;
}