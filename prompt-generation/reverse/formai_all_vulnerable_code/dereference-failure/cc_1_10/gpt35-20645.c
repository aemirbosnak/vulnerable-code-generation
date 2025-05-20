//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define MAX_BUF_SIZE 2048

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: %s <hostname:port>\n", argv[0]);
        return -1;
    }

    // Extract hostname and port from command-line argument
    char *hostname = strtok(argv[1], ":");
    char *port = strtok(NULL, ":");

    // Resolve hostname to IP address
    struct addrinfo hints, *addr;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    getaddrinfo(hostname, port, &hints, &addr);

    // Create socket and connect to the server
    int sockfd = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);
    connect(sockfd, addr->ai_addr, addr->ai_addrlen);

    // Initialize SSL context
    SSL_load_error_strings();
    SSL_library_init();
    SSL_CTX* ctx = SSL_CTX_new(TLSv1_2_client_method());

    // Create SSL connection
    SSL* ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    SSL_connect(ssl);

    // Send request to server
    char *request = "GET / HTTP/1.1\r\nHost: %s:%s\r\n\r\n";
    char buffer[MAX_BUF_SIZE];
    sprintf(buffer, request, hostname, port);
    SSL_write(ssl, buffer, strlen(buffer));

    // Receive response from server
    int bytes_received = SSL_read(ssl, buffer, MAX_BUF_SIZE);
    buffer[bytes_received] = '\0';
    printf("%s\n", buffer);

    // Shutdown SSL connection and free resources
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);

    return 0;
}