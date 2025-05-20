//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

int main() {
    SSL_CTX *ctx;
    SSL *ssl;
    int sockfd, port;
    struct sockaddr_in servaddr;
    char *hostname;
    char buf[1024];
    int n;

    // Initialize OpenSSL.
    SSL_library_init();
    SSL_load_error_strings();
    
    // Create a new SSL context.
    ctx = SSL_CTX_new(TLS_client_method());
    if (ctx == NULL) {
        ERR_print_errors_fp(stderr);
        exit(1);
    }
    
    // Create a new SSL structure for the connection.
    ssl = SSL_new(ctx);
    if (ssl == NULL) {
        ERR_print_errors_fp(stderr);
        exit(1);
    }

    // Get the hostname and port from the user.
    printf("Hostname: ");
    hostname = strtok(fgets(buf, sizeof(buf), stdin), "\n");
    printf("Port: ");
    port = atoi(strtok(fgets(buf, sizeof(buf), stdin), "\n"));

    // Create a new socket.
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Connect to the server.
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr.s_addr = inet_addr(hostname);
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Associate the SSL structure with the socket.
    SSL_set_fd(ssl, sockfd);

    // Perform the SSL handshake.
    if (SSL_connect(ssl) < 0) {
        ERR_print_errors_fp(stderr);
        exit(1);
    }

    // Send a command to the server.
    n = SSL_write(ssl, "LOGIN username password\r\n", strlen("LOGIN username password\r\n"));
    if (n < 0) {
        ERR_print_errors_fp(stderr);
        exit(1);
    }

    // Receive the response from the server.
    n = SSL_read(ssl, buf, sizeof(buf));
    if (n < 0) {
        ERR_print_errors_fp(stderr);
        exit(1);
    }

    // Print the response to the console.
    printf("%s\n", buf);

    // Close the connection.
    SSL_shutdown(ssl);
    close(sockfd);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    return 0;
}