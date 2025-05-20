//FormAI DATASET v1.0 Category: Socket programming ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <openssl/rand.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

/**
 * Initialize SSL context with certificate and private key
 * Return: SSL context
 */
SSL_CTX* InitCTX() {
    SSL_CTX *ctx;
    char cert_file[] = "/path/to/certificate/file";
    char key_file[] = "/path/to/private_key/file";
    ctx = SSL_CTX_new(SSLv23_server_method());
    
    SSL_CTX_set_ecdh_auto(ctx, 1);
    
    if (SSL_CTX_use_certificate_file(ctx, cert_file, SSL_FILETYPE_PEM) <= 0) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
    
    if (SSL_CTX_use_PrivateKey_file(ctx, key_file, SSL_FILETYPE_PEM) <= 0 ) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
    
    return ctx;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <port_number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    SSL_CTX *ctx;
    SSL *ssl;
    int server_socket, client_socket, port_number, returning_value, opt = 1;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len = sizeof(client_address);

    // Create TCP socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Error setting socket options");
        exit(EXIT_FAILURE);
    }

    // Fill server address structure
    memset(&server_address, 0, sizeof(server_address));
    port_number = atoi(argv[1]);
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port_number);

    // Bind socket to server address
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) != 0) {
        perror("Error listening for connection");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", port_number);

    // Initialize SSL context
    SSL_library_init();
    ctx = InitCTX();

    // Accept and handle incoming connections
    while (1) {
        // Accept incoming connection
        client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_len);
        if (client_socket == -1) {
            perror("Error accepting connection");
            exit(EXIT_FAILURE);
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Create new SSL connection
        ssl = SSL_new(ctx);
        SSL_set_fd(ssl, client_socket);

        // Perform SSL handshake
        returning_value = SSL_accept(ssl);
        if (returning_value <= 0) {
            perror("Error performing SSL handshake");
            ERR_print_errors_fp(stderr);
            SSL_shutdown(ssl);
            SSL_free(ssl);
            close(client_socket);
            continue;
        }

        printf("SSL handshake successful\n");

        // Receive and send data
        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            returning_value = SSL_read(ssl, buffer, BUFFER_SIZE);

            if (returning_value < 0) {
                perror("Error receiving data");
                ERR_print_errors_fp(stderr);
                break;
            } else if (returning_value == 0) {
                printf("Connection closed by client\n");
                break;
            } else {
                printf("Received message: %s\n", buffer);
                SSL_write(ssl, buffer, strlen(buffer));
                printf("Sent message: %s\n", buffer);
            }
        }

        // Shutdown SSL connection
        SSL_shutdown(ssl);
        SSL_free(ssl);
        close(client_socket);
    }

    // Clean up SSL context
    SSL_CTX_free(ctx);

    return 0;
}