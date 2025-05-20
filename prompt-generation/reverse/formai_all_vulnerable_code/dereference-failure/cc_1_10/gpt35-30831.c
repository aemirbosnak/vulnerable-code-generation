//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    SSL_CTX *ssl_ctx = NULL;
    SSL *ssl = NULL;
    int sock;
    char buffer[BUFFER_SIZE];
    struct hostent *host;
    struct sockaddr_in server_addr;
    int port = 993; // IMAP server port

    // Check command-line arguments
    if (argc != 2) {
        printf("Usage: %s server\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Set up OpenSSL library
    SSL_load_error_strings();
    SSL_library_init();
    ssl_ctx = SSL_CTX_new(TLSv1_2_client_method());
    if (ssl_ctx == NULL) {
        printf("Error initializing SSL context.\n");
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    // Set options for SSL context
    SSL_CTX_set_options(ssl_ctx, SSL_OP_NO_SSLv2 | SSL_OP_NO_SSLv3 | SSL_OP_NO_COMPRESSION);

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock < 0) {
        printf("Error creating socket.\n");
        exit(EXIT_FAILURE);
    }

    // Get host information and set up server address
    host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("Error getting host.\n");
        exit(EXIT_FAILURE);
    }
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = *((unsigned long *)host->h_addr);
    server_addr.sin_port = htons(port);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server.\n");
        exit(EXIT_FAILURE);
    }

    // Set up SSL connection
    ssl = SSL_new(ssl_ctx);
    SSL_set_fd(ssl, sock);
    if (SSL_connect(ssl) < 1) {
        printf("Error establishing SSL connection.\n");
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    // Send IMAP commands to server and print response
    SSL_write(ssl, "a001 LOGIN username password\r\n", strlen("a001 LOGIN username password\r\n"));
    SSL_read(ssl, buffer, BUFFER_SIZE);
    printf("%s", buffer);
    SSL_write(ssl, "a002 LIST \"\" \"*\"\r\n", strlen("a002 LIST \"\" \"*\"\r\n"));
    SSL_read(ssl, buffer, BUFFER_SIZE);
    printf("%s", buffer);
    SSL_write(ssl, "a003 SELECT INBOX\r\n", strlen("a003 SELECT INBOX\r\n"));
    SSL_read(ssl, buffer, BUFFER_SIZE);
    printf("%s", buffer);
    SSL_write(ssl, "a004 FETCH 1 BODY[]\r\n", strlen("a004 FETCH 1 BODY[]\r\n"));
    SSL_read(ssl, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    // Clean up SSL connection
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ssl_ctx);

    // Close socket
    close(sock);
    
    return 0;
}