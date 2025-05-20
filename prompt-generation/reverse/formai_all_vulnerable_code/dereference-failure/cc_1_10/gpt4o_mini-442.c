//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define IMAP_PORT 993
#define BUFFER_SIZE 2048

typedef struct {
    int socket;
    SSL *ssl;
    SSL_CTX *ctx;
} IMAPClient;

void initialize_ssl() {
    SSL_library_init();
    SSL_load_error_strings();
    OpenSSL_add_all_algorithms();
}

IMAPClient *create_imap_client() {
    IMAPClient *client = malloc(sizeof(IMAPClient));
    if (!client) {
        perror("Failed to allocate memory for IMAPClient");
        exit(EXIT_FAILURE);
    }
    client->socket = -1;
    client->ssl = NULL;
    client->ctx = SSL_CTX_new(TLS_client_method());
    if (!client->ctx) {
        ERR_print_errors_fp(stderr);
        free(client);
        exit(EXIT_FAILURE);
    }
    return client;
}

void connect_server(IMAPClient *client, const char *hostname) {
    struct sockaddr_in server_addr;
    struct hostent *host;

    host = gethostbyname(hostname);
    if (!host) {
        herror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    client->socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client->socket < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAP_PORT);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    if (connect(client->socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connect failed");
        close(client->socket);
        exit(EXIT_FAILURE);
    }

    client->ssl = SSL_new(client->ctx);
    SSL_set_fd(client->ssl, client->socket);
    if (SSL_connect(client->ssl) <= 0) {
        ERR_print_errors_fp(stderr);
        close(client->socket);
        exit(EXIT_FAILURE);
    }
}

void send_command(IMAPClient *client, const char *command) {
    SSL_write(client->ssl, command, strlen(command));
}

void receive_response(IMAPClient *client) {
    char buffer[BUFFER_SIZE];
    int bytes;
    
    memset(buffer, 0, BUFFER_SIZE);
    bytes = SSL_read(client->ssl, buffer, BUFFER_SIZE - 1);
    if (bytes < 0) {
        perror("SSL_read failed");
        close(client->socket);
    } else {
        buffer[bytes] = '\0';
        printf("Response: %s\n", buffer);
    }
}

void login(IMAPClient *client, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    snprintf(command, BUFFER_SIZE, "a001 LOGIN %s %s\r\n", username, password);
    send_command(client, command);
    receive_response(client);
}

void list_folders(IMAPClient *client) {
    send_command(client, "a002 LIST \"\" \"*\"\r\n");
    receive_response(client);
}

void logout(IMAPClient *client) {
    send_command(client, "a003 LOGOUT\r\n");
    receive_response(client);
    SSL_shutdown(client->ssl);
    SSL_free(client->ssl);
    close(client->socket);
    SSL_CTX_free(client->ctx);
    free(client);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    initialize_ssl();
    IMAPClient *client = create_imap_client();

    connect_server(client, argv[1]);
    login(client, argv[2], argv[3]);
    list_folders(client);
    logout(client);
    
    return EXIT_SUCCESS;
}