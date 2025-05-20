//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    SSL_CTX *ctx;
    SSL *ssl;
    int sockfd, port;
    char *server_address, *username, *password;
    char buffer[BUFFER_SIZE];
    struct hostent *he;
    struct sockaddr_in server;

    // validate command line arguments
    if (argc != 4) {
        printf("Usage: %s <server_address> <port_number> <username>\n", argv[0]);
        exit(1);
    }

    server_address = argv[1];
    port = atoi(argv[2]);
    username = argv[3];
    password = getpass("Enter Password:");

    // create TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // get hostname by IP address
    if ((he = gethostbyname(server_address)) == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    // initialize server struct
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    memcpy(&server.sin_addr, he->h_addr_list[0], he->h_length);

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect");
        exit(1);
    }

    // initialize OpenSSL library
    SSL_library_init();
    SSL_load_error_strings();
    OpenSSL_add_all_algorithms();

    // create SSL context
    if ((ctx = SSL_CTX_new(SSLv23_client_method())) == NULL) {
        ERR_print_errors_fp(stderr);
        exit(1);
    }

    // disable SSLv2 and SSLv3
    SSL_CTX_set_options(ctx, SSL_OP_NO_SSLv2 | SSL_OP_NO_SSLv3);

    // create SSL connection object
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);

    // initiate SSL handshake
    if (SSL_connect(ssl) == -1) {
        ERR_print_errors_fp(stderr);
        exit(1);
    }

    // authenticate the user
    SSL_write(ssl, "USER username\r\n", strlen("USER username\r\n"));
    SSL_read(ssl, buffer, BUFFER_SIZE);
    // check response code
    if (buffer[0] != '+') {
        printf("Invalid username.\n");
        exit(1);
    }

    SSL_write(ssl, "PASS password\r\n", strlen("PASS password\r\n"));
    SSL_read(ssl, buffer, BUFFER_SIZE);
    // check response code
    if (buffer[0] != '+') {
        printf("Invalid password.\n");
        exit(1);
    }

    // list all emails
    SSL_write(ssl, "LIST\r\n", strlen("LIST\r\n"));
    SSL_read(ssl, buffer, BUFFER_SIZE);

    // print email list
    printf(buffer);

    // close SSL connection
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);

    // close TCP socket
    close(sockfd);

    return 0;
}