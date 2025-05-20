//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define MAX_SIZE 1024

SSL_CTX *init_ssl_ctx() {
    SSL_CTX *ctx = SSL_CTX_new(TLS_client_method());
    if (!ctx) {
        fprintf(stderr, "Error creating SSL context.\n");
        abort();
    }
    return ctx;
}

void error(char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {
    SSL_library_init();
    SSL_CTX *ctx = init_ssl_ctx();
    const char *hostname = "mail.example.com";
    const char *port = "995";

    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[MAX_SIZE];
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("Error opening socket.\n");

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr,"Error: no such host\n");
        exit(0);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(port));
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("Error connecting");

    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) < 0) {
        ERR_print_errors_fp(stderr);
        exit(0);
    }

    char *username = "example_username";
    char *password = "example_password";
    char *command = "USER example_username\r\n";
    SSL_write(ssl, command, strlen(command));
    memset(buffer, 0, sizeof(buffer));
    SSL_read(ssl, buffer, sizeof(buffer));
    printf("Server response: %s", buffer);

    command = "PASS example_password\r\n";
    SSL_write(ssl, command, strlen(command));
    memset(buffer, 0, sizeof(buffer));
    SSL_read(ssl, buffer, sizeof(buffer));
    printf("Server response: %s", buffer);

    command = "LIST\r\n";
    SSL_write(ssl, command, strlen(command));
    memset(buffer, 0, sizeof(buffer));
    SSL_read(ssl, buffer, sizeof(buffer));
    printf("Server response: %s", buffer);

    SSL_shutdown(ssl);
    close(sockfd);
    SSL_CTX_free(ctx);
    return 0;
}