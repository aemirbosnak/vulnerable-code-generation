//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define HOSTNAME "www.example.com"
#define PORT "443"
#define REQUEST_BODY "This is a request body."

// Initialize OpenSSL and create an SSL context.
void init_openssl_library(void) {
    SSL_load_error_strings();
    SSL_library_init();
    OpenSSL_add_all_algorithms();
}

// Establish a secure connection to the server.
SSL* establish_secure_connection(int socket_descriptor) {
    SSL_CTX* ssl_context = SSL_CTX_new(TLSv1_2_client_method());
    SSL* ssl_connection = SSL_new(ssl_context);
    SSL_set_fd(ssl_connection, socket_descriptor);

    if (SSL_connect(ssl_connection) == -1) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    return ssl_connection;
}

// Send a HTTP request and get the response.
void send_http_request(SSL* ssl_connection) {
    const char* request_template =
        "GET / HTTP/1.1\r\n"
        "Host: %s\r\n"
        "Content-Length: %lu\r\n\r\n"
        "%s";

    char request_body[1024];
    sprintf(request_body, request_template, HOSTNAME, strlen(REQUEST_BODY), REQUEST_BODY);

    SSL_write(ssl_connection, request_body, strlen(request_body));

    char response[1024];
    SSL_read(ssl_connection, response, sizeof(response)); // read the response here
    printf("%s\n", response);
}

// Close the SSL connection and cleanup OpenSSL library.
void cleanup_openssl_library(SSL* ssl_connection) {
    SSL_shutdown(ssl_connection);
    SSL_free(ssl_connection);
    ERR_free_strings();
    EVP_cleanup();
    SSL_CTX_free(SSL_CTX_new(TLSv1_2_client_method()));
}

int main() {
    struct hostent* server_host = gethostbyname(HOSTNAME);
    int socket_descriptor = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr = *((struct in_addr*)server_host->h_addr_list[0]);
    server_address.sin_port = htons(atoi(PORT));

    // Connect to the server.
    if (connect(socket_descriptor, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Unable to connect to the server.");
        return EXIT_FAILURE;
    }

    init_openssl_library();

    // Establish a secure connection and send the HTTP request.
    SSL* ssl_connection = establish_secure_connection(socket_descriptor);
    send_http_request(ssl_connection);

    cleanup_openssl_library(ssl_connection);
    close(socket_descriptor);

    return EXIT_SUCCESS;
}