//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <openssl/bio.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {

    if(argc != 4) {
        printf("Usage: %s server port email\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *server = argv[1];
    int port = atoi(argv[2]);
    char *email = argv[3];

    SSL_library_init();
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();
    ERR_load_BIO_strings();

    BIO *sock = BIO_new_connect(server);
    BIO_set_conn_port(sock, port);

    if(BIO_do_connect(sock) <= 0) {
        printf("Error connecting to %s:%d\n", server, port);
        BIO_free_all(sock);
        exit(EXIT_FAILURE);
    }

    SSL_CTX *ctx = SSL_CTX_new(TLSv1_2_client_method());
    SSL *ssl = SSL_new(ctx);
    BIO_set_ssl(sock, ssl, BIO_CLOSE);

    if(BIO_do_handshake(sock) <= 0) {
        printf("Error establishing SSL connection to %s:%d\n", server, port);
        BIO_free_all(sock);
        exit(EXIT_FAILURE);
    }

    char *login    = calloc(BUF_SIZE, sizeof(char));
    char *password = calloc(BUF_SIZE, sizeof(char));

    printf("Please enter login for email %s: ", email);
    scanf("%s", login);
    printf("Please enter password for email %s: ", email);
    scanf("%s", password);

    char login_command[BUF_SIZE]; sprintf(login_command, "LOGIN %s %s\r\n", login, password);
    BIO_puts(sock, login_command);

    char response[BUF_SIZE];
    int response_len = 0;
    while(response_len = BIO_read(sock, response, BUF_SIZE)) {
        printf("%.*s", response_len, response);
        if(strstr(response, "OK")) {
            break;
        }
    }

    char select_command[BUF_SIZE]; sprintf(select_command, "SELECT INBOX\r\n");
    BIO_puts(sock, select_command);

    while(response_len = BIO_read(sock, response, BUF_SIZE)) {
        printf("%.*s", response_len, response);
        if(strstr(response, "OK")) {
            break;
        }
    }

    char search_command[BUF_SIZE]; sprintf(search_command, "SEARCH ALL\r\n");
    BIO_puts(sock, search_command);

    while(response_len = BIO_read(sock, response, BUF_SIZE)) {
        printf("%.*s", response_len, response);
        if(strstr(response, "OK")) {
            break;
        }
    }

    BIO_free_all(sock);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    free(login);
    free(password);

    return EXIT_SUCCESS;
}