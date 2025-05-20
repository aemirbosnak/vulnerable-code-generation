//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    SSL_CTX *ctx;
    SSL *ssl;
    BIO *bio;
    int sock;
    int err;
    char buffer[BUFFER_SIZE];
    char cmd[BUFFER_SIZE];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Initialize OpenSSL library
    SSL_library_init();
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();

    // Initialize SSL context
    ctx = SSL_CTX_new(TLSv1_2_client_method());
    if (!ctx) {
        fprintf(stderr, "Unable to create SSL context\n");
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    // Create TCP socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Unable to create socket");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    struct hostent *server = gethostbyname(argv[1]);
    struct sockaddr_in serv_addr;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));
    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Unable to connect to server");
        exit(EXIT_FAILURE);
    }

    // Associate SSL with socket
    bio = BIO_new_socket(sock, BIO_NOCLOSE);
    ssl = SSL_new(ctx);
    SSL_set_bio(ssl, bio, bio);

    // Connect SSL
    if (SSL_connect(ssl) <= 0) {
        fprintf(stderr, "Unable to connect SSL to server\n");
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    // Login to IMAP server
    printf("Username: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    snprintf(cmd, sizeof(cmd), "LOGIN %s ", buffer);
    SSL_write(ssl, cmd, strlen(cmd));
    printf("Password: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    snprintf(cmd, sizeof(cmd), "%s\r\n", buffer);
    SSL_write(ssl, cmd, strlen(cmd));
    SSL_read(ssl, buffer, BUFFER_SIZE);
    if (strncmp(buffer, "OK", 2) != 0) {
        fprintf(stderr, "Login failed: %s\n", buffer);
        exit(EXIT_FAILURE);
    }
    printf("Login successful\n");

    // List available mailbox
    SSL_write(ssl, "LIST \"\" \"*\"\r\n", 13);
    printf("Available mailboxes:\n");
    while ((err = SSL_read(ssl, buffer, BUFFER_SIZE)) > 0) {
        buffer[err] = '\0';
        printf("%s", buffer);
    }

    // Logout and close SSL connection
    SSL_write(ssl, "LOGOUT\r\n", 8);
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sock);

    return 0;
}