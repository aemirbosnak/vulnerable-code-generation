//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define SERVER "imap.example.com"
#define PORT "993"
#define USERNAME "your_email@example.com"
#define PASSWORD "your_password"

// Function to handle OpenSSL errors
void handle_openssl_error() {
    ERR_print_errors_fp(stderr);
    abort();
}

// Function to create a TCP connection to the server
int create_tcp_connection(const char *hostname, const char *port) {
    struct addrinfo hints, *res;
    int sockfd;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(hostname, port, &hints, &res) != 0) {
        perror("getaddrinfo");
        return -1;
    }

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    if (connect(sockfd, res->ai_addr, res->ai_addrlen) != 0) {
        perror("connect");
        close(sockfd);
        return -1;
    }

    freeaddrinfo(res);
    return sockfd;
}

// Function to connect to the IMAP server
SSL *connect_imap(const char *hostname, const char *port) {
    int sockfd;
    SSL_CTX *ctx;
    SSL *ssl;

    SSL_library_init();
    OpenSSL_add_ssl_algorithms();
    ctx = SSL_CTX_new(SSLv23_client_method());
    if (!ctx) handle_openssl_error();

    sockfd = create_tcp_connection(hostname, port);
    if(sockfd < 0) return NULL;

    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) <= 0) handle_openssl_error();

    return ssl;
}

// Function to send a command and receive a response
void send_command(SSL *ssl, const char *command) {
    SSL_write(ssl, command, strlen(command));
    char buffer[1024];
    int bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1);
    buffer[bytes] = '\0';
    printf("Response: %s\n", buffer);
}

// Function to log in to the IMAP server
void login(SSL *ssl, const char *username, const char *password) {
    char command[256];
    snprintf(command, sizeof(command), "A001 LOGIN \"%s\" \"%s\"\r\n", username, password);
    send_command(ssl, command);
}

// Function to fetch and print mailboxes
void list_mailboxes(SSL *ssl) {
    send_command(ssl, "A002 LIST \"\" \"*\"\r\n");
}

// Cleanup function
void cleanup(SSL_CTX *ctx, SSL *ssl, int sockfd) {
    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sockfd);
    SSL_CTX_free(ctx);
    EVP_cleanup();
}

int main() {
    SSL *ssl;
    SSL_CTX *ctx;

    ssl = connect_imap(SERVER, PORT);
    if (!ssl) {
        fprintf(stderr, "Failed to connect to IMAP server.\n");
        return EXIT_FAILURE;
    }

    // Login to the IMAP server
    login(ssl, USERNAME, PASSWORD);
    
    // Fetch and display mailboxes
    list_mailboxes(ssl);

    // Cleanup resources
    cleanup(ctx, ssl, SSL_get_fd(ssl));

    return 0;
}