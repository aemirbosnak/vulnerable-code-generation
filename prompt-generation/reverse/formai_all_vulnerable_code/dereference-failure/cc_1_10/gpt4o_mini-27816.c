//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void initialize_ssl() {
    SSL_load_error_strings();
    SSL_library_init();
}

SSL_CTX* create_context() {
    const SSL_METHOD *method;
    SSL_CTX *ctx;

    method = SSLv23_client_method();
    ctx = SSL_CTX_new(method);
    if (!ctx) {
        handle_error("Unable to create SSL context");
    }
    
    return ctx;
}

void configure_context(SSL_CTX *ctx) {
    SSL_CTX_set_ecdh_auto(ctx, 1);
    
    if (SSL_CTX_use_certificate_file(ctx, "cert.pem", SSL_FILETYPE_PEM) <= 0) {
        handle_error("Unable to load certificate");
    }

    if (SSL_CTX_use_PrivateKey_file(ctx, "key.pem", SSL_FILETYPE_PEM) <= 0) {
        handle_error("Unable to load private key");
    }
}

int connect_to_server(const char *hostname, int port) {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        handle_error("Unable to create socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        close(sockfd);
        handle_error("Unable to connect to server");
    }

    return sockfd;
}

void send_command(SSL *ssl, const char *command) {
    SSL_write(ssl, command, strlen(command));
}

void read_response(SSL *ssl) {
    char buffer[BUFFER_SIZE];
    int bytes;

    while ((bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes] = 0; // null-terminate
        printf("%s", buffer);
    }
}

void list_mailboxes(SSL *ssl) {
    send_command(ssl, "* LIST \"\" \"*\"\r\n");
    read_response(ssl);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <port> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    int port = atoi(argv[2]);
    const char *username = argv[3];
    const char *password = argv[4];

    initialize_ssl();
    SSL_CTX *ctx = create_context();
    configure_context(ctx);

    int sockfd = connect_to_server(hostname, port);
    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);

    if (SSL_connect(ssl) <= 0) {
        ERR_print_errors_fp(stderr);
        goto end;
    }
    
    // Send login command
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "a001 LOGIN \"%s\" \"%s\"\r\n", username, password);
    send_command(ssl, command);
    read_response(ssl);

    // List mailboxes
    list_mailboxes(ssl);

end:
    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sockfd);
    SSL_CTX_free(ctx);
    EVP_cleanup();
    return EXIT_SUCCESS;
}