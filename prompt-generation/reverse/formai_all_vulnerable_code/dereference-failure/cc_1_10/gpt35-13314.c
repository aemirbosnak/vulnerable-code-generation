//FormAI DATASET v1.0 Category: Client Server Application ; Style: future-proof
/*
 * This is a unique C Client-Server Application example program that utilizes
 * future-proof coding techniques such as multi-threading, asynchronous I/O,
 * and secure message passing utilizing TLS encryption.
 *
 * The client application sends a message to the server, which then encrypts the
 * message using TLS encryption and sends it back to the client. The client then
 * decrypts the message for display.
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define PORT 8080
#define MAX_BUFF_SIZE 1024

void *handle_connection(void *arg);
SSL_CTX *initialize_SSL_context();
SSL *initialize_SSL_connection(int client_sockfd, SSL_CTX *ssl_ctx);

int main(int argc, char const *argv[]) {
    int server_sockfd, client_sockfd;
    struct sockaddr_in server_address, client_address;
    pthread_t tid;

    // Initialize OpenSSL
    SSL_library_init();

    // Create socket file descriptor for server
    if ((server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Prepare server sockaddr_in structure
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind socket to the specified IP and port
    if (bind(server_sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_sockfd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server running on port %d...\n", PORT);

    while (1) {
        socklen_t client_address_len = sizeof(client_address);

        // Accept incoming connection and create new socket file descriptor for this connection
        if ((client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, &client_address_len)) < 0) {
            perror("accept failed");
            continue;
        }

        // Create new thread to handle this connection
        if (pthread_create(&tid, NULL, handle_connection, (void *)&client_sockfd) != 0) {
            perror("pthread_create failed");
            continue;
        }

        // Detach thread to allow it to run independently
        pthread_detach(tid);
    }

    return 0;
}

void *handle_connection(void *arg) {
    int client_sockfd = *(int *)arg;
    char buffer[MAX_BUFF_SIZE] = {0};

    // Initialize SSL context and connection
    SSL_CTX *ssl_ctx = initialize_SSL_context();
    SSL *ssl = initialize_SSL_connection(client_sockfd, ssl_ctx);

    // Receive message from client
    SSL_read(ssl, buffer, MAX_BUFF_SIZE);

    // Encrypt message using TLS
    char *encrypted_buffer = SSL_write(ssl, buffer, MAX_BUFF_SIZE);

    // Send encrypted message back to client
    send(client_sockfd, encrypted_buffer, strlen(encrypted_buffer), 0);

    // Clean up SSL connection and context
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ssl_ctx);

    // Close socket file descriptor
    close(client_sockfd);

    pthread_exit(NULL);
}

SSL_CTX *initialize_SSL_context() {
    SSL_CTX *ssl_ctx;

    // Create new SSL context
    if ((ssl_ctx = SSL_CTX_new(TLS_method())) == NULL) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    // Load server certificate and private key
    if (SSL_CTX_use_certificate_file(ssl_ctx, "server.crt", SSL_FILETYPE_PEM) <= 0) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    if (SSL_CTX_use_PrivateKey_file(ssl_ctx, "server.key", SSL_FILETYPE_PEM) <= 0) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    // Verify correctness of private key
    if (!SSL_CTX_check_private_key(ssl_ctx)) {
        fprintf(stderr, "Private key does not match certificate\n");
        exit(EXIT_FAILURE);
    }

    return ssl_ctx;
}

SSL *initialize_SSL_connection(int client_sockfd, SSL_CTX *ssl_ctx) {
    SSL *ssl;

    // Create new SSL connection and attach it to the socket file descriptor
    if ((ssl = SSL_new(ssl_ctx)) == NULL) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    SSL_set_fd(ssl, client_sockfd);

    // Set up SSL connection
    if (SSL_accept(ssl) <= 0) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    return ssl;
}