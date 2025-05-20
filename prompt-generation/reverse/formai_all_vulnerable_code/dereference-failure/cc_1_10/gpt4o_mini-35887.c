//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define PORT 993
#define BUFFER_SIZE 1024
#define MAX_MAILBOXES 100

void handleError(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

SSL_CTX *initializeSSL() {
    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();
    
    SSL_CTX *ctx = SSL_CTX_new(TLS_method());
    if (!ctx) {
        ERR_print_errors_fp(stderr);
        abort();
    }
    return ctx;
}

int createSocket(const char *hostname) {
    struct sockaddr_in server_addr;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        handleError("Socket creation failed");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    
    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        handleError("Invalid address/Address not supported");
    }
    
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        handleError("Connection failed");
    }
    return sock;
}

void imapSendCommand(SSL *ssl, const char *command) {
    SSL_write(ssl, command, strlen(command));
}

void imapReceiveResponse(SSL *ssl, char *response, size_t size) {
    ssize_t bytes = SSL_read(ssl, response, size);
    if (bytes < 0) {
        handleError("Error reading response");
    }
    response[bytes] = '\0'; // Null-terminate the response
}

void listMailboxes(SSL *ssl) {
    char response[BUFFER_SIZE];
    imapSendCommand(ssl, "A001 LIST \"\" \"*\"\r\n");
    imapReceiveResponse(ssl, response, BUFFER_SIZE);
    
    printf("Mailboxes:\n%s\n", response);
}

void login(SSL *ssl, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    
    snprintf(command, sizeof(command), "A0001 LOGIN \"%s\" \"%s\"\r\n", username, password);
    imapSendCommand(ssl, command);
    char response[BUFFER_SIZE];
    imapReceiveResponse(ssl, response, BUFFER_SIZE);
    
    if (strstr(response, "OK") != NULL) {
        printf("Login successful!\n");
    } else {
        printf("Login failed: %s\n", response);
        exit(EXIT_FAILURE);
    }
}

void cleanup(SSL *ssl, SSL_CTX *ctx, int sock) {
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sock);
    EVP_cleanup();
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sock = createSocket(hostname);
    SSL_CTX *ctx = initializeSSL();

    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock);
    
    if (SSL_connect(ssl) <= 0) {
        ERR_print_errors_fp(stderr);
        return EXIT_FAILURE;
    }

    login(ssl, username, password);
    listMailboxes(ssl);
    
    cleanup(ssl, ctx, sock);
    return EXIT_SUCCESS;
}