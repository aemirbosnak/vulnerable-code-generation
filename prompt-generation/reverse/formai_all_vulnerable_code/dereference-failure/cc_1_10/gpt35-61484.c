//FormAI DATASET v1.0 Category: Client Server Application ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>
#include <openssl/rand.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define PORT 8080
#define MAX_PENDING_CONNECTIONS 5
#define MAX_BUFFER_SIZE 1024

SSL_CTX* init_ssl_ctx(void);
void echo_handler(SSL *ssl);

int main(int argc, char const *argv[]) {

    SSL_CTX *ctx = init_ssl_ctx();

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating server socket!");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address = {0};
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error binding server socket!");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, MAX_PENDING_CONNECTIONS) < 0) {
        perror("Error listening for connections!");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        struct sockaddr_in client_address = {0};
        socklen_t client_addr_len = sizeof(client_address);

        int client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_addr_len);
        if (client_socket < 0) {
            perror("Error accepting client connection!");
            exit(EXIT_FAILURE);
        }

        printf("Client connected from %s:%d...\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        SSL *ssl = SSL_new(ctx);
        SSL_set_fd(ssl, client_socket);

        if (SSL_accept(ssl) <= 0) {
            SSL_shutdown(ssl);
            SSL_free(ssl);
            close(client_socket);
            continue;
        }

        pthread_t thread;
        int *client_sock = malloc(sizeof(int));
        *client_sock = client_socket;

        if (pthread_create(&thread, NULL, (void *)echo_handler, ssl) != 0) {
            perror("Error creating thread for client connection!");
            exit(EXIT_FAILURE);
        }
        pthread_detach(thread);
    }
    close(server_socket);
    SSL_CTX_free(ctx);
    return 0;
}

void echo_handler(SSL *ssl) {
    char buffer[MAX_BUFFER_SIZE];
    int bytes_received;
    while ((bytes_received = SSL_read(ssl, buffer, MAX_BUFFER_SIZE)) > 0) {
        printf("Received from client: %s\n", buffer);
        if (SSL_write(ssl, buffer, bytes_received) != bytes_received) {
            perror("Error sending data to client!");
            break;
        }
        memset(buffer, 0, sizeof(buffer));
    }
    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(SSL_get_fd(ssl));
}

SSL_CTX* init_ssl_ctx(void) {

    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();
    SSL_CTX *ctx = SSL_CTX_new(TLSv1_2_server_method());
    if (!ctx) {
        perror("Error creating SSL context!");
        exit(EXIT_FAILURE);
    }

    if (SSL_CTX_use_certificate_file(ctx, "/path/to/certificate.crt", SSL_FILETYPE_PEM) <= 0) {
        perror("Error loading certificate file!");
        exit(EXIT_FAILURE);
    }

    if (SSL_CTX_use_PrivateKey_file(ctx, "/path/to/private_key.key", SSL_FILETYPE_PEM) <= 0) {
        perror("Error loading private key file!");
        exit(EXIT_FAILURE);
    }

    if (!SSL_CTX_check_private_key(ctx)) {
        perror("Error checking private key!");
        exit(EXIT_FAILURE);
    }

    return ctx;
}