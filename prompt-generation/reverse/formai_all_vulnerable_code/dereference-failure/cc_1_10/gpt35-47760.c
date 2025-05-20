//FormAI DATASET v1.0 Category: Email Client ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <sys/socket.h>
#include <netdb.h>

// Mail server configuration
#define SERVER_HOST "mail.example.com"
#define SERVER_PORT "993"
#define USERNAME "example@example.com"
#define PASSWORD "password"

#define BUFFER_SIZE 1024

int main() {
    // Initialize OpenSSL library
    SSL_library_init();
    ERR_load_crypto_strings();
    SSL_load_error_strings();

    // Create TCP socket
    struct addrinfo hints, *addr;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    getaddrinfo(SERVER_HOST, SERVER_PORT, &hints, &addr);
    int sockfd = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);

    // Connect to mail server
    connect(sockfd, addr->ai_addr, addr->ai_addrlen);

    // Initialize SSL connection
    SSL_CTX* ssl_ctx = SSL_CTX_new(TLS_client_method());
    SSL* ssl = SSL_new(ssl_ctx);
    SSL_set_fd(ssl, sockfd);
    SSL_connect(ssl);

    // Authenticate user
    char cmd[BUFFER_SIZE];
    sprintf(cmd, "LOGIN %s %s\r\n", USERNAME, PASSWORD);
    SSL_write(ssl, cmd, strlen(cmd));
    memset(cmd, 0, sizeof(cmd));
    SSL_read(ssl, cmd, BUFFER_SIZE);
    if (strncmp(cmd, "OK", 2) != 0) {
        printf("Authentication failed\n");
        return 1;
    }

    // Select inbox
    sprintf(cmd, "SELECT INBOX\r\n");
    SSL_write(ssl, cmd, strlen(cmd));
    memset(cmd, 0, sizeof(cmd));
    SSL_read(ssl, cmd, BUFFER_SIZE);
    if (strncmp(cmd, "OK", 2) != 0) {
        printf("Cannot select inbox\n");
        return 1;
    }

    // Retrieve email messages
    sprintf(cmd, "UID SEARCH ALL\r\n");
    SSL_write(ssl, cmd, strlen(cmd));
    memset(cmd, 0, sizeof(cmd));
    SSL_read(ssl, cmd, BUFFER_SIZE);
    
    // Tokenize response
    char* token = strtok(cmd, " \r\n");
    while (token != NULL) {
        // Search for UID number
        if (isdigit(token[0])) {
            uint32_t uid = atoi(token);
            sprintf(cmd, "UID FETCH %d BODY[HEADER]\r\n", uid);
            SSL_write(ssl, cmd, strlen(cmd));
            memset(cmd, 0, sizeof(cmd));
            SSL_read(ssl, cmd, BUFFER_SIZE);

            printf("Message UID: %d\n", uid);
            printf("%s\n", cmd);
        }

        // Get next token
        token = strtok(NULL, " \r\n");
    }

    // Disconnect from mail server
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ssl_ctx);
    close(sockfd);
    return 0;
}