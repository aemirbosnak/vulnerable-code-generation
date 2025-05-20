//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <openssl/ssl.h>

#define BUF_SIZE 1024

SSL_CTX *ctx;

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *port = argv[2];

    SSL_library_init();
    SSL_load_error_strings();
    ctx = SSL_CTX_new(SSLv23_client_method());
    if (ctx == NULL) {
        perror("SSL_CTX_new");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(hostname);
    server_addr.sin_port = htons(atoi(port));

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    SSL *ssl = SSL_new(ctx);
    if (ssl == NULL) {
        perror("SSL_new");
        exit(EXIT_FAILURE);
    }

    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) < 0) {
        perror("SSL_connect");
        exit(EXIT_FAILURE);
    }

    char buf[BUF_SIZE];
    snprintf(buf, BUF_SIZE, "A001 LOGIN myusername mypassword\r\n");
    if (SSL_write(ssl, buf, strlen(buf)) < 0) {
        perror("SSL_write");
        exit(EXIT_FAILURE);
    }

    if (SSL_read(ssl, buf, BUF_SIZE) < 0) {
        perror("SSL_read");
        exit(EXIT_FAILURE);
    }

    printf("%s", buf);

    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);

    return EXIT_SUCCESS;
}