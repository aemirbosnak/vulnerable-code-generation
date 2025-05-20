//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void initialize_ssl() {
    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();
}

void cleanup_ssl() {
    EVP_cleanup();
}

SSL_CTX *create_context() {
    const SSL_METHOD *method;
    SSL_CTX *ctx;

    method = SSLv23_method();
    ctx = SSL_CTX_new(method);
    if (!ctx) {
        perror("Unable to create SSL context");
        exit(EXIT_FAILURE);
    }
    return ctx;
}

void connect_to_server(const char *hostname, const char *port, SSL **ssl, SSL_CTX *ctx) {
    struct addrinfo hints, *res;
    int sock;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(hostname, port, &hints, &res) != 0) {
        perror("getaddrinfo");
        exit(EXIT_FAILURE);
    }

    for (struct addrinfo *p = res; p != NULL; p = p->ai_next) {
        sock = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sock == -1) {
            perror("socket");
            continue;
        }
        
        if (connect(sock, p->ai_addr, p->ai_addrlen) == -1) {
            close(sock);
            perror("connect");
            continue;
        }
        break;
    }

    if (res == NULL) {
        fprintf(stderr, "Failed to connect to server\n");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(res);
    
    *ssl = SSL_new(ctx);
    SSL_set_fd(*ssl, sock);
    if (SSL_connect(*ssl) <= 0) {
        ERR_print_errors_fp(stderr);
    }
}

void send_command(SSL *ssl, const char *command) {
    SSL_write(ssl, command, strlen(command));
}

void read_response(SSL *ssl) {
    char buffer[BUFFER_SIZE];
    int bytes;

    memset(buffer, 0, sizeof(buffer));
    bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1);
    if (bytes > 0) {
        buffer[bytes] = '\0';
        printf("%s", buffer);
    } else {
        ERR_print_errors_fp(stderr);
    }
}

void list_mailboxes(SSL *ssl) {
    send_command(ssl, "A001 LIST \"\" \"*\"\r\n");
    read_response(ssl);
}

void logout(SSL *ssl) {
    send_command(ssl, "A002 LOGOUT\r\n");
    read_response(ssl);
}

int main() {
    SSL_CTX *ctx;
    SSL *ssl;
    const char *hostname = "imap.example.com";  // Replace with actual IMAP server
    const char *port = "993";                    // IMAP over SSL port

    // Initialize SSL Library
    initialize_ssl();
    ctx = create_context();

    // Connect to the server
    connect_to_server(hostname, port, &ssl, ctx);
    
    // Greet server
    read_response(ssl);

    // Login to IMAP server
    send_command(ssl, "A000 LOGIN \"username\" \"password\"\r\n");  // Provide your credentials
    read_response(ssl);

    // List mailboxes
    list_mailboxes(ssl);

    // Logout
    logout(ssl);

    // Clean up and exit peacefully
    SSL_free(ssl);
    close(SSL_get_fd(ssl));
    SSL_CTX_free(ctx);
    cleanup_ssl();

    printf("Connection closed peacefully. Thank you for using the IMAP client.\n");
    return 0;
}