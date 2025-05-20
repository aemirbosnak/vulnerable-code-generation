//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#include <openssl/ssl.h>
#include <openssl/err.h>

#define SERVER_PORT 993
#define BUFFER_SIZE 1024

SSL_CTX *ssl_ctx;
SSL *ssl;

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <server> <username> <password>\n", argv[0]);
        return 1;
    }

    char *server = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    SSL_library_init();
    OpenSSL_add_all_algorithms();
    ssl_ctx = SSL_CTX_new(SSLv23_client_method());

    if (ssl_ctx == NULL) {
        printf("Error creating SSL context\n");
        return 1;
    }

    SSL_CTX_set_default_verify_paths(ssl_ctx);

    ssl = SSL_new(ssl_ctx);
    SSL_set_fd(ssl, 0);
    SSL_set_mode(ssl, SSL_MODE_AUTO_RETRY);

    if (SSL_connect(ssl) <= 0) {
        printf("Error connecting to server\n");
        return 1;
    }

    char *login_data = malloc(strlen(username) + strlen(password) + 10);
    sprintf(login_data, "LOGIN %s %s\r\n", username, password);

    send(SSL_get_fd(ssl), login_data, strlen(login_data), 0);
    free(login_data);

    char buffer[BUFFER_SIZE];
    while (1) {
        int bytes_received = recv(SSL_get_fd(ssl), buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Error receiving data\n");
            break;
        }

        buffer[bytes_received] = 0;
        printf("%s", buffer);
    }

    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ssl_ctx);

    return 0;
}