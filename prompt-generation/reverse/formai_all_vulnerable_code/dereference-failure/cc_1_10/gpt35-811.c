//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <server> <email> <password>\n", argv[0]);
        return 1;
    }

    char *server = argv[1];
    char *user = argv[2];
    char *pass = argv[3];

    // Get address info
    struct addrinfo hints = {0};
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    struct addrinfo *address_info;
    int result = getaddrinfo(server, "993", &hints, &address_info);

    if (result) {
        printf("Error getting address info: %s\n", gai_strerror(result));
        return 1;
    }

    // Connect to server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    result = connect(sockfd, address_info->ai_addr, address_info->ai_addrlen);

    if (result) {
        printf("Error connecting to server: %s\n", strerror(errno));
        return 1;
    }

    // Start SSL
    SSL_load_error_strings();
    SSL_library_init();
    SSL_CTX *ssl_ctx = SSL_CTX_new(SSLv23_client_method());
    SSL *ssl = SSL_new(ssl_ctx);
    SSL_set_fd(ssl, sockfd);
    result = SSL_connect(ssl);

    if (result != 1) {
        printf("Error starting SSL: %s\n", ERR_error_string(ERR_get_error(), NULL));
        return 1;
    }

    // Login
    char buffer[BUFFER_SIZE];
    int len = SSL_read(ssl, buffer, BUFFER_SIZE);
    buffer[len] = '\0';
    printf("%s", buffer);

    sprintf(buffer, "a001 LOGIN %s %s\r\n", user, pass);
    SSL_write(ssl, buffer, strlen(buffer));

    len = SSL_read(ssl, buffer, BUFFER_SIZE);
    buffer[len] = '\0';
    printf("%s", buffer);

    // List inbox
    sprintf(buffer, "a002 LIST \"\" \"*\"\r\n");
    SSL_write(ssl, buffer, strlen(buffer));

    len = SSL_read(ssl, buffer, BUFFER_SIZE);
    buffer[len] = '\0';
    printf("%s", buffer);

    // Logout
    sprintf(buffer, "a003 LOGOUT\r\n");
    SSL_write(ssl, buffer, strlen(buffer));

    len = SSL_read(ssl, buffer, BUFFER_SIZE);
    buffer[len] = '\0';
    printf("%s", buffer);

    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ssl_ctx);
    freeaddrinfo(address_info);
    close(sockfd);

    return 0;
}