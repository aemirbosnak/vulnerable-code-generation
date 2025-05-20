//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <sys/socket.h>

// Constants
#define BUFSIZE 1024

// Function Declarations
int connect_to_server(const char* hostname, const char* port);
SSL* init_openssl();
void cleanup_openssl(SSL_CTX* ctx);
SSL_CTX* create_context();
void configure_context(SSL_CTX* ctx);
int send_request(SSL* ssl, const char* request);
int recv_response(SSL* ssl, char* response, int size);

// Main function
int main()
{
    // Variables
    char hostname[] = "imap.gmail.com";
    char port[] = "993";
    int sockfd;
    SSL* ssl;
    SSL_CTX* ctx;
    char request[BUFSIZE];
    char response[BUFSIZE];

    // Connect to server
    sockfd = connect_to_server(hostname, port);
    if (sockfd == -1) {
        fprintf(stderr, "ERROR: Failed to connect to server.\n");
        exit(EXIT_FAILURE);
    }

    // Initialize SSL
    SSL_library_init();
    ctx = create_context();
    configure_context(ctx);
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) != 1) {
        fprintf(stderr, "ERROR: Failed to establish SSL connection.\n");
        cleanup_openssl(ctx);
        exit(EXIT_FAILURE);
    }

    // Send LOGIN command
    sprintf(request, "LOGIN %s %s\r\n", "username@gmail.com", "password");
    if (send_request(ssl, request) == -1) {
        fprintf(stderr, "ERROR: Failed to send request.\n");
        SSL_shutdown(ssl);
        cleanup_openssl(ctx);
        exit(EXIT_FAILURE);
    }

    // Receive response
    if (recv_response(ssl, response, BUFSIZE) == -1) {
        fprintf(stderr, "ERROR: Failed to receive response.\n");
        SSL_shutdown(ssl);
        cleanup_openssl(ctx);
        exit(EXIT_FAILURE);
    }
    printf("%s\n", response);

    // Close connection and cleanup
    SSL_shutdown(ssl);
    cleanup_openssl(ctx);
    close(sockfd);

    return 0;
}

// Connect to server
int connect_to_server(const char* hostname, const char* port)
{
    // Variables
    struct addrinfo hints, *res, *p;
    int sockfd;

    // Set hints
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    // Get address info
    if (getaddrinfo(hostname, port, &hints, &res) != 0) {
        fprintf(stderr, "ERROR: Failed to get address info.\n");
        return -1;
    }

    // Loop through address info and connect to first possible address
    for (p = res; p != NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) != -1) {
            break;
        }

        close(sockfd);
    }

    // Cleanup and return
    freeaddrinfo(res);
    if (p == NULL) {
        fprintf(stderr, "ERROR: Failed to connect to server.\n");
        return -1;
    }
    return sockfd;
}

// Initialize OpenSSL
SSL* init_openssl()
{
    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();
    return SSL_new(SSLv23_method());
}

// Cleanup OpenSSL
void cleanup_openssl(SSL_CTX* ctx)
{
    SSL_CTX_free(ctx);
    EVP_cleanup();
}

// Create SSL context
SSL_CTX* create_context()
{
    const SSL_METHOD* method;
    SSL_CTX* ctx;

    method = SSLv23_method();
    ctx = SSL_CTX_new(method);
    if (ctx == NULL) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    return ctx;
}

// Configure SSL context
void configure_context(SSL_CTX* ctx)
{
    SSL_CTX_set_options(
        ctx,
        SSL_OP_NO_SSLv2 |
        SSL_OP_NO_SSLv3 |
        SSL_OP_NO_COMPRESSION
    );
}

// Send request
int send_request(SSL* ssl, const char* request)
{
    int len, result;

    len = strlen(request);
    result = SSL_write(ssl, request, len);

    if (result <= 0) {
        return -1;
    }

    return 0;
}

// Receive response
int recv_response(SSL* ssl, char* response, int size)
{
    int len, result;
    char* p = response;

    len = size - 1;
    while (len > 0) {
        result = SSL_read(ssl, p, len);

        if (result <= 0) {
            break;
        }

        p += result;
        len -= result;
    }

    *p = '\0';

    if (result < 0) {
        return -1;
    }

    return 0;
}