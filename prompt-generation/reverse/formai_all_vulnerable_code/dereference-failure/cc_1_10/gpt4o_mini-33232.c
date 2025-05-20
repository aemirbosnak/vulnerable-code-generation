//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <netdb.h>
#include <sys/socket.h>

#define SERVER_PORT 993
#define BUFFER_SIZE 1024

SSL_CTX *initialize_context() {
    SSL_METHOD *method;
    SSL_CTX *ctx;

    method = SSLv23_client_method();
    ctx = SSL_CTX_new(method);
    if (!ctx) {
        ERR_print_errors_fp(stderr);
        abort();
    }
    return ctx;
}

int connect_to_server(const char *hostname, int port) {
    struct sockaddr_in server_addr;
    struct hostent *host = gethostbyname(hostname);
    if (!host) {
        perror("gethostbyname");
        exit(1);
    }
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);
    
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }
    return sock;
}

void cleanup(SSL *ssl, SSL_CTX *ctx, int sock) {
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sock);
}

void process_response(char *response) {
    printf("Server response: %s\n", response);
}

void send_command(SSL *ssl, const char *cmd) {
    SSL_write(ssl, cmd, strlen(cmd));
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    SSL_read(ssl, buffer, BUFFER_SIZE - 1);
    process_response(buffer);
}

void authenticate(SSL *ssl, const char *user, const char *password) {
    char cmd[BUFFER_SIZE];
    sprintf(cmd, "A001 LOGIN %s %s\r\n", user, password);
    send_command(ssl, cmd);
}

void list_folders(SSL *ssl) {
    send_command(ssl, "A002 LIST \"\" \"*\"\r\n");
}

void count_messages(SSL *ssl, const char *folder) {
    char cmd[BUFFER_SIZE];
    sprintf(cmd, "A003 SELECT \"%s\"\r\n", folder);
    send_command(ssl, cmd);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IMAP server> <username> <password>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    const char *user = argv[2];
    const char *password = argv[3];

    SSL_CTX *ctx = initialize_context();
    int sock = connect_to_server(hostname, SERVER_PORT);
    
    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock);
    
    if (SSL_connect(ssl) != 1) {
        ERR_print_errors_fp(stderr);
        cleanup(ssl, ctx, sock);
        exit(1);
    }

    authenticate(ssl, user, password);
    list_folders(ssl);

    // Clean up
    cleanup(ssl, ctx, sock);
    return 0;
}