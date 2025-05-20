//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if(argc < 4) {
        fprintf(stderr, "Usage: %s <server> <port> <username>\n", argv[0]);
        exit(-1);
    }

    SSL_library_init();
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();
    SSL_CTX *ctx = SSL_CTX_new(TLSv1_2_client_method());
    if(ctx == NULL) {
        ERR_print_errors_fp(stderr);
        exit(-1);
    }

    const char *server = argv[1];
    int port = atoi(argv[2]);
    const char *username = argv[3];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1) {
        perror("Failed to create socket");
        exit(-1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(server);

    if(connect(sock, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in)) == -1) {
        perror("Failed to connect to server");
        exit(-1);
    }

    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock);
    if(SSL_connect(ssl) == -1) {
        ERR_print_errors_fp(stderr);
        exit(-1);
    }

    char buf[BUF_SIZE];
    size_t bytes_read = SSL_read(ssl, buf, BUF_SIZE);
    buf[bytes_read] = '\0';
    printf("%s", buf);

    snprintf(buf, BUF_SIZE, "1 LOGIN %s password\n", username);
    SSL_write(ssl, buf, strlen(buf));

    bytes_read = SSL_read(ssl, buf, BUF_SIZE);
    buf[bytes_read] = '\0';
    printf("%s", buf);

    srand(time(NULL));
    int uid = rand() % 100000;

    snprintf(buf, BUF_SIZE, "%d UID SEARCH ALL\n", uid++);
    SSL_write(ssl, buf, strlen(buf));

    bytes_read = SSL_read(ssl, buf, BUF_SIZE);
    buf[bytes_read] = '\0';
    printf("%s", buf);

    snprintf(buf, BUF_SIZE, "%d LOGOUT\n", uid++);
    SSL_write(ssl, buf, strlen(buf));

    bytes_read = SSL_read(ssl, buf, BUF_SIZE);
    buf[bytes_read] = '\0';
    printf("%s", buf);

    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sock);

    return 0;
}