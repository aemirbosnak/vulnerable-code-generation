//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFER_SIZE 1024

void initialize_ssl() {
    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();
}

void cleanup_ssl() {
    EVP_cleanup();
}

int create_ssl_connection(SSL **ssl, SSL_CTX **ctx, int sockfd) {
    *ctx = SSL_CTX_new(TLS_client_method());
    if (!*ctx) {
        fprintf(stderr, "Failed to create SSL context\n");
        return -1;
    }

    *ssl = SSL_new(*ctx);
    if (!*ssl) {
        fprintf(stderr, "Failed to create SSL structure\n");
        SSL_CTX_free(*ctx);
        return -1;
    }

    if (SSL_set_fd(*ssl, sockfd) == 0) {
        fprintf(stderr, "Failed to associate SSL with the socket\n");
        SSL_free(*ssl);
        SSL_CTX_free(*ctx);
        return -1;
    }

    if (SSL_connect(*ssl) <= 0) {
        fprintf(stderr, "SSL connection failed\n");
        SSL_free(*ssl);
        SSL_CTX_free(*ctx);
        return -1;
    }

    return 0;
}

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(SSL *ssl, const char *cmd, char *response, size_t resp_size) {
    SSL_write(ssl, cmd, strlen(cmd));
    SSL_write(ssl, "\r\n", 2);

    memset(response, 0, resp_size);
    SSL_read(ssl, response, resp_size - 1);
}

void print_mailboxes(SSL *ssl) {
    char response[BUFFER_SIZE];
    send_command(ssl, "A1 LIST \"\" \"*\"", response, sizeof(response));
    fprintf(stdout, "Mailboxes:\n%s\n", response);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IMAP server> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *server = argv[1];
    int port = atoi(argv[2]);

    initialize_ssl();

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        handle_error("Could not create socket");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, server, &server_addr.sin_addr) <= 0) {
        handle_error("Invalid address/ Address not supported");
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection failed");
    }

    SSL *ssl = NULL;
    SSL_CTX *ctx = NULL;

    if (create_ssl_connection(&ssl, &ctx, sockfd) < 0) {
        close(sockfd);
        cleanup_ssl();
        return EXIT_FAILURE;
    }

    char response[BUFFER_SIZE];
    send_command(ssl, "A0 LOGIN user password", response, sizeof(response));
    fprintf(stdout, "Login Response: %s\n", response);

    print_mailboxes(ssl);

    send_command(ssl, "A2 LOGOUT", response, sizeof(response));
    fprintf(stdout, "Logout Response: %s\n", response);

    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);
    cleanup_ssl();

    return 0;
}