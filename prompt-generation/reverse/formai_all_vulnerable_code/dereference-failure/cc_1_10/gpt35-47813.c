//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFER_SIZE 1024

int main(int argc, char const *argv[])
{
    if (argc != 4) {
        fprintf(stderr, "Usage: %s hostname port username\n", argv[0]);
        return EXIT_FAILURE;
    }

    SSL_library_init();
    SSL_CTX *ctx = SSL_CTX_new(TLSv1_2_client_method());

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "No such host %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    struct sockaddr_in serv_addr = {0};
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr = *((struct in_addr *)server->h_addr);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    SSL *ssl = SSL_new(ctx);
    if (ssl == NULL) {
        perror("SSL_new");
        return EXIT_FAILURE;
    }

    if (SSL_set_fd(ssl, sockfd) < 0) {
        perror("SSL_set_fd");
        return EXIT_FAILURE;
    }

    if (SSL_connect(ssl) < 0) {
        perror("SSL_connect");
        return EXIT_FAILURE;
    }

    char username[BUFFER_SIZE] = {0};
    sprintf(username, "LOGIN %s %s\r\n", argv[3], "password");
    SSL_write(ssl, username, strlen(username) + 1);

    char buffer[BUFFER_SIZE] = {0};
    SSL_read(ssl, buffer, BUFFER_SIZE - 1);
    printf("%s\n", buffer);

    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);

    return EXIT_SUCCESS;
}