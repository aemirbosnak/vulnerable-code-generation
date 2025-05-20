//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 993

// Enum to represent potential states
typedef enum {
    DISCONNECTED,
    CONNECTED,
    AUTHENTICATED
} client_state;

// Structure to hold IMAP client information
typedef struct {
    int sockfd;
    SSL *ssl;
    SSL_CTX *ctx;
    client_state state;
    char imap_server[256];
} IMAPClient;

// Function prototypes
void initialize_ssl();
IMAPClient* create_client(const char* server);
void cleanup_client(IMAPClient* client);
void connect_to_server(IMAPClient* client);
void authenticate(IMAPClient* client, const char* username, const char* password);
void send_command(IMAPClient* client, const char* command);
void receive_response(IMAPClient* client);
void display_help();
void handle_imap_commands(IMAPClient* client);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <IMAP server> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char* imap_server = argv[1];
    const char* username = argv[2];
    const char* password = argv[3];

    initialize_ssl();

    IMAPClient* client = create_client(imap_server);
    connect_to_server(client);
    authenticate(client, username, password);

    handle_imap_commands(client);
    cleanup_client(client);
    return EXIT_SUCCESS;
}

void initialize_ssl() {
    SSL_library_init();
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();
    ERR_load_SSL_strings();
}

IMAPClient* create_client(const char* server) {
    IMAPClient* client = malloc(sizeof(IMAPClient));
    strncpy(client->imap_server, server, sizeof(client->imap_server));
    client->sockfd = -1;
    client->ssl = NULL;
    client->ctx = SSL_CTX_new(SSLv23_client_method());
    client->state = DISCONNECTED;
    return client;
}

void cleanup_client(IMAPClient* client) {
    if (client->ssl) SSL_free(client->ssl);
    if (client->ctx) SSL_CTX_free(client->ctx);
    if (client->sockfd != -1) close(client->sockfd);
    free(client);
}

void connect_to_server(IMAPClient* client) {
    struct sockaddr_in server_addr;
    client->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, client->imap_server, &server_addr.sin_addr);
    
    if (connect(client->sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    client->ssl = SSL_new(client->ctx);
    SSL_set_fd(client->ssl, client->sockfd);
    
    if (SSL_connect(client->ssl) <= 0) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
    
    printf("Connected to %s\n", client->imap_server);
    client->state = CONNECTED;
}

void authenticate(IMAPClient* client, const char* username, const char* password) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A001 LOGIN %s %s\r\n", username, password);
    send_command(client, command);
    receive_response(client);
    client->state = AUTHENTICATED;
}

void send_command(IMAPClient* client, const char* command) {
    SSL_write(client->ssl, command, strlen(command));
}

void receive_response(IMAPClient* client) {
    char buffer[BUFFER_SIZE] = {0};
    int bytes = SSL_read(client->ssl, buffer, sizeof(buffer) - 1);
    buffer[bytes] = '\0';
    printf("Server Response: %s\n", buffer);
}

void display_help() {
    printf("Available commands:\n");
    printf("1. LIST\n");
    printf("2. SELECT <mailbox>\n");
    printf("3. FETCH <mailbox>\n");
    printf("4. LOGOUT\n");
}

void handle_imap_commands(IMAPClient* client) {
    char command[BUFFER_SIZE];
    display_help();
    while (1) {
        printf("Enter IMAP command: ");
        if (fgets(command, sizeof(command), stdin) == NULL) break;
        
        if (strncmp(command, "LOGOUT", 6) == 0) {
            send_command(client, "A002 LOGOUT\r\n");
            receive_response(client);
            break;
        } else {
            send_command(client, "A100 ");
            strcat(command, "\r\n"); // Add the IMAP line ending
            send_command(client, command);
            receive_response(client);
        }
    }
}