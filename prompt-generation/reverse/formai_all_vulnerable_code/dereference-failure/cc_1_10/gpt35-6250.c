//FormAI DATASET v1.0 Category: Client Server Application ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define FAIL    -1
#define BUFFER_SIZE 1024

int open_connection(const char *hostname, int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

SSL_CTX* init_ssl_ctx(void) {
    SSL_library_init();
    SSL_load_error_strings();

    const SSL_METHOD *meth = TLS_client_method();
    SSL_CTX *ctx = SSL_CTX_new(meth);

    if (!ctx) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    return ctx;
}

void destroy_ssl_ctx(SSL_CTX *ctx) {
    SSL_CTX_free(ctx);
}

SSL* open_ssl_connection(SSL_CTX *ctx, int sockfd) {
    SSL *ssl = SSL_new(ctx);

    if (!ssl) {
        fprintf(stderr, "ERROR creating SSL\n");
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    SSL_set_fd(ssl, sockfd);

    if (SSL_connect(ssl) != 1) {
        fprintf(stderr, "ERROR connecting SSL\n");
        ERR_print_errors_fp(stderr);
        SSL_free(ssl);
        exit(EXIT_FAILURE);
    }

    return ssl;
}

void close_ssl_connection(SSL *ssl) {
    SSL_shutdown(ssl);
    SSL_free(ssl);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    int port = atoi(argv[2]);

    SSL_CTX *ctx = init_ssl_ctx();

    int sockfd = open_connection(hostname, port);
    SSL *ssl = open_ssl_connection(ctx, sockfd);

    char buffer[BUFFER_SIZE];

    // client sends a message to server
    memset(buffer, 0, sizeof(buffer));
    snprintf(buffer, sizeof(buffer)-1, "Hello, server! This is client.");

    SSL_write(ssl, buffer, strlen(buffer));

    // server replies with a message
    memset(buffer, 0, sizeof(buffer));
    SSL_read(ssl, buffer, sizeof(buffer)-1);

    printf("Server's reply: %s\n", buffer);

    close_ssl_connection(ssl);
    destroy_ssl_ctx(ctx);

    close(sockfd);

    return 0;
}