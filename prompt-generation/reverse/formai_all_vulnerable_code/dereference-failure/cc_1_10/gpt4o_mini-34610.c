//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

typedef struct {
    int socket;
    char *smtp_server;
    int smtp_port;
    char *username;
    char *password;
} client_info_t;

void *handle_client(void *arg);
void smtp_send_email(client_info_t *client_info, const char *recipient, const char *subject, const char *body);
void initialize_openssl();
SSL_CTX *create_context();
void cleanup_openssl();
void handle_errors();

int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    pthread_t threads[MAX_CLIENTS];
    int client_count = 0;

    initialize_openssl();
    SSL_CTX *ctx = create_context();

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port 8080...\n");

    while (client_count < MAX_CLIENTS) {
        new_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (new_socket < 0) {
            perror("Accept failed");
            continue;
        }

        client_info_t *client_info = malloc(sizeof(client_info_t));
        client_info->socket = new_socket;
        client_info->smtp_server = "smtp.example.com"; // Replace with actual SMTP server
        client_info->smtp_port = 587; // Replace with actual SMTP port
        client_info->username = "your_email@example.com"; // Replace with actual username
        client_info->password = "your_password"; // Replace with actual password

        if (pthread_create(&threads[client_count], NULL, handle_client, (void *)client_info) != 0) {
            perror("Failed to create thread");
            free(client_info);
        }

        client_count++;
    }

    for (int i = 0; i < client_count; i++) {
        pthread_join(threads[i], NULL);
    }

    close(server_socket);
    cleanup_openssl();

    return 0;
}

void *handle_client(void *arg) {
    client_info_t *client_info = (client_info_t *)arg;
    char recipient[BUFFER_SIZE], subject[BUFFER_SIZE], body[BUFFER_SIZE];

    printf("Client connected: %d\n", client_info->socket);
    write(client_info->socket, "Enter recipient: ", 17);
    read(client_info->socket, recipient, BUFFER_SIZE);
    recipient[strcspn(recipient, "\n")] = '\0'; // Remove newline

    write(client_info->socket, "Enter subject: ", 15);
    read(client_info->socket, subject, BUFFER_SIZE);
    subject[strcspn(subject, "\n")] = '\0'; // Remove newline

    write(client_info->socket, "Enter message body: ", 20);
    read(client_info->socket, body, BUFFER_SIZE);
    body[strcspn(body, "\n")] = '\0'; // Remove newline

    smtp_send_email(client_info, recipient, subject, body);

    close(client_info->socket);
    free(client_info);
    return NULL;
}

void smtp_send_email(client_info_t *client_info, const char *recipient, const char *subject, const char *body) {
    SSL *ssl;
    int result;
    char buffer[BUFFER_SIZE];

    // Create a new SSL connection
    SSL_CTX *ctx = SSL_CTX_new(TLS_client_method());
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, client_info->socket);
    
    if (SSL_connect(ssl) <= 0) {
        handle_errors();
        return;
    }

    // SMTP conversation
    snprintf(buffer, sizeof(buffer), "EHLO localhost\r\n");
    SSL_write(ssl, buffer, strlen(buffer));
    SSL_read(ssl, buffer, sizeof(buffer));

    snprintf(buffer, sizeof(buffer), "AUTH LOGIN\r\n");
    SSL_write(ssl, buffer, strlen(buffer));
    SSL_read(ssl, buffer, sizeof(buffer));

    // Send username and password
    snprintf(buffer, sizeof(buffer), "%s\r\n", client_info->username);
    SSL_write(ssl, buffer, strlen(buffer));
    SSL_read(ssl, buffer, sizeof(buffer));

    snprintf(buffer, sizeof(buffer), "%s\r\n", client_info->password);
    SSL_write(ssl, buffer, strlen(buffer));
    SSL_read(ssl, buffer, sizeof(buffer));

    snprintf(buffer, sizeof(buffer), "MAIL FROM:<%s>\r\n", client_info->username);
    SSL_write(ssl, buffer, strlen(buffer));
    SSL_read(ssl, buffer, sizeof(buffer));

    snprintf(buffer, sizeof(buffer), "RCPT TO:<%s>\r\n", recipient);
    SSL_write(ssl, buffer, strlen(buffer));
    SSL_read(ssl, buffer, sizeof(buffer));

    snprintf(buffer, sizeof(buffer), "DATA\r\n");
    SSL_write(ssl, buffer, strlen(buffer));
    SSL_read(ssl, buffer, sizeof(buffer));

    snprintf(buffer, sizeof(buffer), "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    SSL_write(ssl, buffer, strlen(buffer));
    SSL_read(ssl, buffer, sizeof(buffer));

    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    SSL_write(ssl, buffer, strlen(buffer));
    SSL_read(ssl, buffer, sizeof(buffer));

    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
}

void initialize_openssl() {
    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();
}

SSL_CTX *create_context() {
    const SSL_METHOD *method;
    SSL_CTX *ctx;

    method = TLS_client_method();
    ctx = SSL_CTX_new(method);
    if (!ctx) {
        handle_errors();
    }
    return ctx;
}

void cleanup_openssl() {
    EVP_cleanup();
}

void handle_errors() {
    ERR_print_errors_fp(stderr);
    abort();
}