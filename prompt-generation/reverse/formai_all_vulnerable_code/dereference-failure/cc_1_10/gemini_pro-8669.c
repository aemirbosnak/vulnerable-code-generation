//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: secure
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define DEFAULT_INTERVAL 600

// Custom error handling function
void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

// Function to check website uptime using SSL
int check_uptime_ssl(const char *hostname, int port, const char *path, int interval) {
    // Initialize OpenSSL library
    SSL_library_init();
    SSL_load_error_strings();

    // Create a new SSL context
    SSL_CTX *ctx = SSL_CTX_new(TLSv1_2_client_method());
    if (ctx == NULL) {
        error("SSL_CTX_new");
    }

    // Create a new SSL connection
    SSL *ssl = SSL_new(ctx);
    if (ssl == NULL) {
        SSL_CTX_free(ctx);
        error("SSL_new");
    }

    // Resolve hostname to IP address
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        error("gethostbyname");
    }

    // Create a new socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        error("socket");
    }

    // Set up socket address structure
    struct sockaddr_in serv_addr;
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    bcopy(host->h_addr_list[0], &serv_addr.sin_addr, host->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        close(sockfd);
        error("connect");
    }

    // Associate SSL connection with the socket
    SSL_set_fd(ssl, sockfd);

    // Perform SSL handshake
    if (SSL_connect(ssl) != 1) {
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        close(sockfd);
        error("SSL_connect");
    }

    // Send HTTP request
    char request[256];
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);
    if (SSL_write(ssl, request, strlen(request)) < 0) {
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        close(sockfd);
        error("SSL_write");
    }

    // Receive HTTP response
    char response[4096];
    int n = SSL_read(ssl, response, sizeof(response) - 1);
    if (n < 0) {
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        close(sockfd);
        error("SSL_read");
    }
    response[n] = '\0';

    // Check HTTP response status code
    char *status_line = strtok(response, "\r\n");
    if (status_line == NULL || strncmp(status_line, "HTTP/1.1 200 OK", 15) != 0) {
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Close SSL connection and socket
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);

    return EXIT_SUCCESS;
}

int main(int argc, char *argv[]) {
    // Check command line arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s hostname [port] [path] [interval]\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Set default values for optional arguments
    int port = 443;
    const char *path = "/";
    int interval = DEFAULT_INTERVAL;

    // Parse optional arguments
    if (argc > 2) {
        port = atoi(argv[2]);
    }
    if (argc > 3) {
        path = argv[3];
    }
    if (argc > 4) {
        interval = atoi(argv[4]);
    }

    // Main loop to check website uptime
    while (true) {
        // Check website uptime
        int status = check_uptime_ssl(argv[1], port, path, interval);

        // Print status message
        if (status == EXIT_SUCCESS) {
            printf("Website is up\n");
        } else {
            printf("Website is down\n");
        }

        // Sleep for specified interval
        sleep(interval);
    }

    return EXIT_SUCCESS;
}