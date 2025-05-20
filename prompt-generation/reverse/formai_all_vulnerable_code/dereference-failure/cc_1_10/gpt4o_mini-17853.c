//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define SERVER "pop.example.com"  // Replace with your POP3 server
#define PORT 995                   // POP3 SSL port
#define BUFFER_SIZE 1024

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void ssl_init() {
    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();
}

SSL *create_ssl_connection(int sock) {
    SSL *ssl;
    SSL_CTX *ctx;

    ctx = SSL_CTX_new(SSLv23_client_method());
    if (!ctx) handle_error("SSL_CTX_new");

    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock);

    if (SSL_connect(ssl) <= 0) handle_error("SSL_connect");

    return ssl;
}

void read_email_list(SSL *ssl) {
    char buffer[BUFFER_SIZE];
    SSL_write(ssl, "LIST\r\n", strlen("LIST\r\n"));

    while (1) {
        int bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1);
        if (bytes <= 0) break;

        buffer[bytes] = '\0';
        printf("%s", buffer);
    }
}

void login(SSL *ssl, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "USER %s\r\n", username);
    SSL_write(ssl, command, strlen(command));
    
    // Read response
    char buffer[BUFFER_SIZE];
    int bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1);
    buffer[bytes] = '\0';
    printf("%s", buffer);

    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    SSL_write(ssl, command, strlen(command));
    
    bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1);
    buffer[bytes] = '\0';
    printf("%s", buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *username = argv[1];
    const char *password = argv[2];

    ssl_init();
    
    int sock;
    struct sockaddr_in server_addr;
    struct hostent *host;

    host = gethostbyname(SERVER);
    if (host == NULL) {
        fprintf(stderr, "ERROR: No such host\n");
        exit(EXIT_FAILURE);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) handle_error("socket");

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("connect");
    }

    SSL *ssl = create_ssl_connection(sock);

    // Read server greeting
    char buffer[BUFFER_SIZE];
    int bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1);
    buffer[bytes] = '\0';
    printf("%s", buffer);

    login(ssl, username, password);
    
    printf("Retrieving emails:\n");
    read_email_list(ssl);

    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sock);
    SSL_CTX_free(SSL_get_SSL_CTX(ssl));
    EVP_cleanup();
    
    return 0;
}