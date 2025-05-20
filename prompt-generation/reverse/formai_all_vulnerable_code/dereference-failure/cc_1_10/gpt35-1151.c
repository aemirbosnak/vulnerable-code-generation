//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFSIZE 1024

int create_socket(char *server, int port);
SSL_CTX* create_ssl_context();
void print_error_and_exit(const char *msg);

int main(int argc, char **argv)
{
    if(argc != 4)
    {
        printf("Usage: %s <server> <port> <username>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *server = argv[1];
    int port = atoi(argv[2]);
    char *username = argv[3];

    int sockfd = create_socket(server, port);

    SSL_CTX *ctx = create_ssl_context();
    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);

    if(SSL_connect(ssl) == -1)
        print_error_and_exit("SSL_connect failed");

    char buffer[BUFFSIZE] = {0};
    int len;
    char *tag;

    len = SSL_read(ssl, buffer, BUFFSIZE);
    if(len <= 0)
        print_error_and_exit("Error reading from server");

    printf("%s", buffer);

    // Send login command
    tag = "A001";
    snprintf(buffer, sizeof(buffer), "%s LOGIN %s \"\"\r\n", tag, username);
    SSL_write(ssl, buffer, strlen(buffer));

    len = SSL_read(ssl, buffer, BUFFSIZE);
    if(len <= 0)
        print_error_and_exit("Error reading from server");

    printf("%s", buffer);

    SSL_shutdown(ssl);
    close(sockfd);
    SSL_free(ssl);
    SSL_CTX_free(ctx);

    exit(EXIT_SUCCESS);
}

int create_socket(char *server, int port)
{
    int sockfd;
    struct addrinfo hints, *res, *p;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM; // Use TCP

    char portstr[6];
    snprintf(portstr, sizeof(portstr), "%d", port);

    if(getaddrinfo(server, portstr, &hints, &res) != 0)
        print_error_and_exit("getaddrinfo failed");

    for(p = res; p != NULL; p = p->ai_next)
    {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if(sockfd == -1)
            continue;

        if(connect(sockfd, p->ai_addr, p->ai_addrlen) != -1)
            break;

        close(sockfd);
    }

    if(p == NULL)
        print_error_and_exit("Unable to connect to server");

    freeaddrinfo(res);
    return sockfd;
}

SSL_CTX* create_ssl_context()
{
    SSL_CTX *ctx = SSL_CTX_new(TLS_client_method());

    if(ctx == NULL)
        print_error_and_exit("SSL_CTX_new failed");

    SSL_CTX_set_options(ctx, SSL_OP_NO_SSLv2 | SSL_OP_NO_SSLv3 | SSL_OP_NO_TLSv1 | SSL_OP_NO_TLSv1_1);

    return ctx;
}

void print_error_and_exit(const char *msg)
{
    fprintf(stderr, "%s\n", msg);
    ERR_print_errors_fp(stderr);
    exit(EXIT_FAILURE);
}