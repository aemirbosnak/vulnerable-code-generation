//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define PORT 4433
#define CERT_FILE "server.pem"
#define KEY_FILE "server.key"
#define CA_FILE "ca.pem"

// Initialize the OpenSSL library
int init_openssl() {
    SSL_library_init();
    SSL_load_error_strings();
    return 1;
}

// Create an SSL context
SSL_CTX *create_ssl_context() {
    SSL_CTX *ctx = NULL;

    // Create a new SSL context
    ctx = SSL_CTX_new(TLSv1_2_server_method());
    if (ctx == NULL) {
        ERR_print_errors_fp(stderr);
        return NULL;
    }

    // Load the server certificate and private key
    if (SSL_CTX_use_certificate_file(ctx, CERT_FILE, SSL_FILETYPE_PEM) <= 0) {
        ERR_print_errors_fp(stderr);
        SSL_CTX_free(ctx);
        return NULL;
    }
    if (SSL_CTX_use_PrivateKey_file(ctx, KEY_FILE, SSL_FILETYPE_PEM) <= 0) {
        ERR_print_errors_fp(stderr);
        SSL_CTX_free(ctx);
        return NULL;
    }

    // Verify client certificates
    if (SSL_CTX_load_verify_locations(ctx, CA_FILE, NULL) <= 0) {
        ERR_print_errors_fp(stderr);
        SSL_CTX_free(ctx);
        return NULL;
    }

    // Set the verification mode to require client authentication
    SSL_CTX_set_verify(ctx, SSL_VERIFY_PEER | SSL_VERIFY_FAIL_IF_NO_PEER_CERT, NULL);

    return ctx;
}

// Create a server socket
int create_server_socket() {
    int sockfd;

    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    // Set the socket options
    int optval = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
        perror("setsockopt");
        close(sockfd);
        return -1;
    }

    // Bind the socket to the specified port
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        close(sockfd);
        return -1;
    }

    // Listen for incoming connections
    if (listen(sockfd, SOMAXCONN) == -1) {
        perror("listen");
        close(sockfd);
        return -1;
    }

    return sockfd;
}

// Accept an incoming connection
int accept_connection(int sockfd, SSL_CTX *ctx) {
    int clientfd;

    // Accept an incoming connection
    struct sockaddr_in cliaddr;
    socklen_t clilen = sizeof(cliaddr);
    clientfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen);
    if (clientfd == -1) {
        perror("accept");
        return -1;
    }

    // Create a new SSL session
    SSL *ssl = SSL_new(ctx);
    if (ssl == NULL) {
        ERR_print_errors_fp(stderr);
        close(clientfd);
        return -1;
    }

    // Associate the SSL session with the client socket
    SSL_set_fd(ssl, clientfd);

    // Perform the SSL handshake
    if (SSL_accept(ssl) <= 0) {
        ERR_print_errors_fp(stderr);
        SSL_free(ssl);
        close(clientfd);
        return -1;
    }

    return clientfd;
}

// Handle an incoming connection
void handle_connection(int clientfd, SSL *ssl) {
    char buffer[1024];
    int nbytes;

    // Receive data from the client
    while ((nbytes = SSL_read(ssl, buffer, sizeof(buffer))) > 0) {
        // Echo the data back to the client
        SSL_write(ssl, buffer, nbytes);
    }

    // Close the SSL session and the client socket
    SSL_free(ssl);
    close(clientfd);
}

int main() {
    // Initialize the OpenSSL library
    if (!init_openssl()) {
        fprintf(stderr, "Failed to initialize OpenSSL\n");
        return EXIT_FAILURE;
    }

    // Create an SSL context
    SSL_CTX *ctx = create_ssl_context();
    if (ctx == NULL) {
        fprintf(stderr, "Failed to create SSL context\n");
        return EXIT_FAILURE;
    }

    // Create a server socket
    int sockfd = create_server_socket();
    if (sockfd == -1) {
        fprintf(stderr, "Failed to create server socket\n");
        SSL_CTX_free(ctx);
        return EXIT_FAILURE;
    }

    // Accept incoming connections
    while (1) {
        int clientfd = accept_connection(sockfd, ctx);
        if (clientfd == -1) {
            fprintf(stderr, "Failed to accept connection\n");
            continue;
        }

        // Handle the incoming connection in a separate thread
        pthread_t tid;
        pthread_create(&tid, NULL, (void *)handle_connection, (void *)clientfd);
    }

    // Close the server socket
    close(sockfd);

    // Free the SSL context
    SSL_CTX_free(ctx);

    return EXIT_SUCCESS;
}