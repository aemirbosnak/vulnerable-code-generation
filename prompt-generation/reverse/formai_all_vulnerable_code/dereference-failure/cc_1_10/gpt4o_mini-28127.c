//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define IMAP_PORT 993
#define BUFFER_SIZE 2048

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void init_ssl() {
    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();
}

SSL_CTX *create_context() {
    SSL_CTX *ctx = SSL_CTX_new(TLS_client_method());
    if (!ctx) handle_error("Unable to create SSL context");
    return ctx;
}

void configure_context(SSL_CTX *ctx) {
    SSL_CTX_set_options(ctx, SSL_OP_NO_SSLv2);
}

void establish_connection(const char *hostname, int port, SSL **ssl, int *sock) {
    struct sockaddr_in server_addr;
    struct hostent *host;

    *sock = socket(AF_INET, SOCK_STREAM, 0);
    if (*sock < 0) handle_error("Socket creation failed");

    host = gethostbyname(hostname);
    if (!host) handle_error("Error getting host");

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    if (connect(*sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        handle_error("Connection to IMAP server failed");

    *ssl = SSL_new(SSL_CTX_new(TLS_client_method()));
    SSL_set_fd(*ssl, *sock);

    if (SSL_connect(*ssl) <= 0) handle_error("SSL connection failed");
}

void send_imap_command(SSL *ssl, const char *command) {
    SSL_write(ssl, command, strlen(command));
    SSL_write(ssl, "\r\n", 2);
}

void read_response(SSL *ssl) {
    char buffer[BUFFER_SIZE];
    int bytes;

    while ((bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes] = '\0';
        printf("%s", buffer);
    }
    if (bytes < 0) {
        handle_error("Failed to read from server");
    }
}

void login(SSL *ssl, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A001 LOGIN \"%s\" \"%s\"", username, password);
    send_imap_command(ssl, command);
    read_response(ssl);
}

void list_mailbox(SSL *ssl) {
    send_imap_command(ssl, "A002 LIST \"\" \"*\"");
    read_response(ssl);
}

void logout(SSL *ssl) {
    send_imap_command(ssl, "A003 LOGOUT");
    read_response(ssl);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    SSL_CTX *ctx;
    SSL *ssl;
    int sock;

    init_ssl();
    ctx = create_context();
    configure_context(ctx);
    
    establish_connection(hostname, IMAP_PORT, &ssl, &sock);
    
    login(ssl, username, password);
    list_mailbox(ssl);
    
    logout(ssl);

    SSL_free(ssl);
    close(sock);
    SSL_CTX_free(ctx);
    EVP_cleanup();
    
    printf("Disconnected from server.\n");
    
    return EXIT_SUCCESS;
}