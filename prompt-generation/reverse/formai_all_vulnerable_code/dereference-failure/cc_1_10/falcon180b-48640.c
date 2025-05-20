//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFER_SIZE 1024

int main() {
    SSL_CTX *ctx;
    SSL *ssl;
    int sd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    SSL_library_init();
    OpenSSL_add_all_algorithms();
    ctx = SSL_CTX_new(SSLv23_client_method());
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, 0);
    SSL_set_mode(ssl, SSL_MODE_ENABLE_PARTIAL_WRITE);

    if (SSL_connect(ssl)!= 1) {
        ERR_print_errors_fp(stdout);
        exit(1);
    }

    if (getaddrinfo("example.com", "443", NULL, &server_addr)!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(errno));
        exit(1);
    }

    sd = socket(server_addr.sin_family, SOCK_STREAM, 0);
    if (sd == -1) {
        fprintf(stderr, "socket: %s\n", strerror(errno));
        exit(1);
    }

    if (connect(sd, (struct sockaddr *)&server_addr, sizeof(server_addr))!= 0) {
        fprintf(stderr, "connect: %s\n", strerror(errno));
        exit(1);
    }

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        bytes_read = SSL_read(ssl, buffer, BUFFER_SIZE - 1);
        if (bytes_read <= 0) {
            if (SSL_get_error(ssl, bytes_read) == SSL_ERROR_ZERO_RETURN) {
                break;
            } else {
                ERR_print_errors_fp(stdout);
                exit(1);
            }
        }
        printf("%s", buffer);
    }

    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sd);

    return 0;
}