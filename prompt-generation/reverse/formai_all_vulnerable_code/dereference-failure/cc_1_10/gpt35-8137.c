//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int open_connection(const char *hostname, const char *port) {
    int sockfd = 0;
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(hostname, port, &hints, &res) != 0) {
        fprintf(stderr, "Failed to resolve hostname %s\n", hostname);
        return -1;
    }

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd < 0) {
        fprintf(stderr, "Failed to create socket\n");
        return -1;
    }

    if (connect(sockfd, res->ai_addr, res->ai_addrlen) != 0) {
        fprintf(stderr, "Failed to connect to %s:%s\n", hostname, port);
        close(sockfd);
        return -1;
    }

    freeaddrinfo(res);
    return sockfd;
}

int main() {
    SSL_CTX *ctx = NULL;
    SSL *ssl = NULL;
    int sockfd = 0, err = 0, bytes = 0;
    char buffer[BUFFER_SIZE] = {0};

    // Replace these with your own email server hostname and port
    const char *hostname = "imap.example.com";
    const char *port = "993";

    // Initialize OpenSSL
    SSL_library_init();
    ctx = SSL_CTX_new(TLS_client_method());
    if (ctx == NULL) {
        fprintf(stderr, "Failed to create SSL context\n");
        return EXIT_FAILURE;
    }

    // Connect to the IMAP server
    sockfd = open_connection(hostname, port);
    if (sockfd < 0) {
        SSL_CTX_free(ctx);
        return EXIT_FAILURE;
    }

    // Connect the SSL object with the socket
    ssl = SSL_new(ctx);
    if (ssl == NULL) {
        fprintf(stderr, "Failed to create SSL object\n");
        close(sockfd);
        SSL_CTX_free(ctx);
        return EXIT_FAILURE;
    }

    SSL_set_fd(ssl, sockfd);
    err = SSL_connect(ssl);
    if (err != 1) {
        fprintf(stderr, "Failed to establish SSL connection\n");
        SSL_shutdown(ssl);
        SSL_free(ssl);
        close(sockfd);
        SSL_CTX_free(ctx);
        return EXIT_FAILURE;
    }

    // Read the server greeting
    bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1);
    if (bytes < 0) {
        fprintf(stderr, "Failed to read server greeting\n");
        SSL_shutdown(ssl);
        SSL_free(ssl);
        close(sockfd);
        SSL_CTX_free(ctx);
        return EXIT_FAILURE;
    } else {
        printf("Server greeting: %s\n", buffer);
    }

    // Send log in command
    bytes = SSL_write(ssl, "a001 login username password\n", strlen("a001 login username password\n"));
    if (bytes < 0) {
        fprintf(stderr, "Failed to send login command\n");
        SSL_shutdown(ssl);
        SSL_free(ssl);
        close(sockfd);
        SSL_CTX_free(ctx);
        return EXIT_FAILURE;
    } else {
        printf("Sending login command: %s\n", "a001 login username password");
    }

    // Read the server response to login command
    bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1);
    if (bytes < 0) {
        fprintf(stderr, "Failed to read server response to login command\n");
        SSL_shutdown(ssl);
        SSL_free(ssl);
        close(sockfd);
        SSL_CTX_free(ctx);
        return EXIT_FAILURE;
    } else {
        printf("Server response to login command: %s\n", buffer);
    }

    // Send select command to select the inbox
    bytes = SSL_write(ssl, "a002 SELECT Inbox\n", strlen("a002 SELECT Inbox\n"));
    if (bytes < 0) {
        fprintf(stderr, "Failed to send select command\n");
        SSL_shutdown(ssl);
        SSL_free(ssl);
        close(sockfd);
        SSL_CTX_free(ctx);
        return EXIT_FAILURE;
    } else {
        printf("Sending select command: %s\n", "a002 SELECT Inbox");
    }

    // Read the server response to select command
    bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1);
    if (bytes < 0) {
        fprintf(stderr, "Failed to read server response to select command\n");
        SSL_shutdown(ssl);
        SSL_free(ssl);
        close(sockfd);
        SSL_CTX_free(ctx);
        return EXIT_FAILURE;
    } else {
        printf("Server response to select command: %s\n", buffer);
    }

    // Send logout command
    bytes = SSL_write(ssl, "a003 logout\n", strlen("a003 logout\n"));
    if (bytes < 0) {
        fprintf(stderr, "Failed to send logout command\n");
        SSL_shutdown(ssl);
        SSL_free(ssl);
        close(sockfd);
        SSL_CTX_free(ctx);
        return EXIT_FAILURE;
    } else {
        printf("Sending logout command: %s\n", "a003 logout");
    }

    // Read the server response to logout command
    bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1);
    if (bytes < 0) {
        fprintf(stderr, "Failed to read server response to logout command\n");
        SSL_shutdown(ssl);
        SSL_free(ssl);
        close(sockfd);
        SSL_CTX_free(ctx);
        return EXIT_FAILURE;
    } else {
        printf("Server response to logout command: %s\n", buffer);
    }

    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sockfd);
    SSL_CTX_free(ctx);

    return EXIT_SUCCESS;
}