//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define IMAP_PORT 993
#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: could not create socket");
        return EXIT_FAILURE;
    }

    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: could not resolve host name");
        return EXIT_FAILURE;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(IMAP_PORT);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error: could not connect to server");
        return EXIT_FAILURE;
    }

    SSL_library_init();
    SSL_CTX *ssl_ctx = SSL_CTX_new(TLSv1_2_client_method());
    SSL *ssl = SSL_new(ssl_ctx);
    SSL_set_fd(ssl, sockfd);

    if (SSL_connect(ssl) == -1) {
        fprintf(stderr, "Error: could not establish SSL connection");
        ERR_print_errors_fp(stderr);
        return EXIT_FAILURE;
    }

    char buffer[BUFFER_SIZE];
    int bytes_read;

    SSL_write(ssl, "a001 CAPABILITY\n", strlen("a001 CAPABILITY\n"));
    bytes_read = SSL_read(ssl, buffer, BUFFER_SIZE);
    buffer[bytes_read] = '\0';
    printf("%s", buffer);

    SSL_write(ssl, "a002 LOGIN username password\n", strlen("a002 LOGIN username password\n"));
    bytes_read = SSL_read(ssl, buffer, BUFFER_SIZE);
    buffer[bytes_read] = '\0';
    printf("%s", buffer);

    SSL_write(ssl, "a003 SELECT inbox\n", strlen("a003 SELECT inbox\n"));
    bytes_read = SSL_read(ssl, buffer, BUFFER_SIZE);
    buffer[bytes_read] = '\0';
    printf("%s", buffer);

    SSL_write(ssl, "a004 FETCH 1:* (FLAGS BODY[HEADER.FIELDS (FROM SUBJECT DATE)])\n",
              strlen("a004 FETCH 1:* (FLAGS BODY[HEADER.FIELDS (FROM SUBJECT DATE)])\n"));

    bytes_read = SSL_read(ssl, buffer, BUFFER_SIZE);
    buffer[bytes_read] = '\0';
    printf("%s", buffer);

    SSL_write(ssl, "a005 LOGOUT\n", strlen("a005 LOGOUT\n"));
    bytes_read = SSL_read(ssl, buffer, BUFFER_SIZE);
    buffer[bytes_read] = '\0';
    printf("%s", buffer);

    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ssl_ctx);
    close(sockfd);

    return EXIT_SUCCESS;
}