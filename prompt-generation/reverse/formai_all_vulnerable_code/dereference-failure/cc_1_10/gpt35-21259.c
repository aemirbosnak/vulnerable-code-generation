//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <openssl/ssl.h>
#include <openssl/bio.h>
#include <openssl/err.h>

#define SERVER_ADDR "imap.gmail.com"
#define SERVER_PORT "993"

#define BUFFER_SIZE 1024

SSL_CTX *ssl_init() {
    SSL_library_init();
    SSL_load_error_strings();
    OpenSSL_add_all_algorithms();

    SSL_CTX *ctx = SSL_CTX_new(TLSv1_2_client_method());
    if (!ctx) {
        printf("Error: Unable to create SSL context\n");
        return NULL;
    }

    return ctx;
}

int main() {
    char *username, *password, *email_address;

    printf("Enter your email address: ");
    scanf("%ms", &email_address);

    printf("Enter your username: ");
    scanf("%ms", &username);

    printf("Enter your password: ");
    scanf("%ms", &password);

    SSL_CTX *ctx = ssl_init();

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Error: Unable to create socket");
        exit(1);
    }

    struct addrinfo hints, *server_info;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    int rv = getaddrinfo(SERVER_ADDR, SERVER_PORT, &hints, &server_info);
    if (rv != 0) {
        fprintf(stderr, "Error: Unable to get server address information: %s\n", gai_strerror(rv));
        exit(1);
    }

    if (connect(sock, server_info->ai_addr, server_info->ai_addrlen) == -1) {
        perror("Error: Unable to connect to server");
       exit(1);
    }

    SSL *ssl = SSL_new(ctx);
    if (!ssl) {
        printf("Error: Unable to create SSL connection object\n");
        exit(1);
    }

    BIO *io = BIO_new_socket(sock, BIO_NOCLOSE);
    SSL_set_bio(ssl, io, io);

    char buffer[BUFFER_SIZE];

    SSL_connect(ssl);

    BIO_read(io, buffer, sizeof buffer);
    printf("%s", buffer);

    // Login
    snprintf(buffer, sizeof buffer, ". LOGIN %s %s\r\n", username, password);
    SSL_write(ssl, buffer, strlen(buffer));
    BIO_read(io, buffer, sizeof buffer);
    printf("%s", buffer);

    // Select mailbox
    snprintf(buffer, sizeof buffer, ". SELECT INBOX\r\n");
    SSL_write(ssl, buffer, strlen(buffer));
    BIO_read(io, buffer, sizeof buffer);
    printf("%s", buffer);

    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sock);
    freeaddrinfo(server_info);
    free(email_address);
    free(username);
    free(password);

    return 0;
}