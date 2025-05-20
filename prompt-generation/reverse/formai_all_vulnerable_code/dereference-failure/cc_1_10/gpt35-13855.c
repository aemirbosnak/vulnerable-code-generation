//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

// Define the server URL and port number (change as appropriate)
#define SERVER_NAME "mail.example.com"
#define SERVER_PORT "993"

// Define the maximum buffer size for reading server responses
#define BUFFER_SIZE 4096

// Define SSL context
SSL_CTX *create_ssl_context() {
    SSL_library_init();
    SSL_load_error_strings();

    SSL_CTX *ssl_ctx = SSL_CTX_new(TLSv1_2_client_method());
    if (!ssl_ctx) {
        perror("Failed to create SSL context");
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    return ssl_ctx;
}

// Connect to the server and return the socket file descriptor
int connect_to_server() {
    struct addrinfo hints, *result, *p;
    int sockfd;

    // Set the hint structure
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;        // IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM;    // TCP

    // Get a list of address structures
    int status = getaddrinfo(SERVER_NAME, SERVER_PORT, &hints, &result);
    if (status != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    for (p = result; p != NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            perror("Socket creation failed");
            continue;
        }

        status = connect(sockfd, p->ai_addr, p->ai_addrlen);
        if (status == -1) {
            close(sockfd);
            perror("Connection failed");
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "Failed to connect to server\n");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(result);

    return sockfd;
}

// Authenticate with the server using username and password
void login(SSL *ssl, char *username, char *password) {
    char buffer[BUFFER_SIZE];

    // Send login command
    snprintf(buffer, BUFFER_SIZE, "LOGIN %s %s\r\n", username, password);
    SSL_write(ssl, buffer, strlen(buffer));

    // Read server response
    SSL_read(ssl, buffer, BUFFER_SIZE);
    printf("%s\n", buffer);
}

// Retrieve a list of mailboxes available on the server
void list_mailboxes(SSL *ssl) {
    char buffer[BUFFER_SIZE];

    // Send list command
    SSL_write(ssl, "LIST \"\" *\r\n", strlen("LIST \"\" *\r\n"));

    // Read server response
    SSL_read(ssl, buffer, BUFFER_SIZE);
    printf("%s\n", buffer);
}

// Select a mailbox and retrieve a list of messages
void select_mailbox(SSL *ssl, char *mailbox) {
    char buffer[BUFFER_SIZE];

    // Send select command
    snprintf(buffer, BUFFER_SIZE, "SELECT %s\r\n", mailbox);
    SSL_write(ssl, buffer, strlen(buffer));

    // Read server response
    SSL_read(ssl, buffer, BUFFER_SIZE);
    printf("%s\n", buffer);
}

// Retrieve the content of a message
void fetch_message(SSL *ssl, int message_number) {
    char buffer[BUFFER_SIZE];

    // Send fetch command
    snprintf(buffer, BUFFER_SIZE, "FETCH %d BODY[TEXT]\r\n", message_number);
    SSL_write(ssl, buffer, strlen(buffer));

    // Read server response
    SSL_read(ssl, buffer, BUFFER_SIZE);
    printf("%s\n", buffer);
}

int main(int argc, char *argv[]) {
    SSL_CTX *ssl_ctx;
    SSL *ssl;
    int sockfd;

    // Create SSL context
    ssl_ctx = create_ssl_context();

    // Connect to server
    sockfd = connect_to_server();

    // Create SSL object and associate with socket file descriptor
    ssl = SSL_new(ssl_ctx);
    SSL_set_fd(ssl, sockfd);

    // Initiate SSL connection
    SSL_connect(ssl);

    // Authenticate with server
    char *username = "myusername";
    char *password = "mypassword";
    login(ssl, username, password);

    // List available mailboxes
    list_mailboxes(ssl);

    // Select a mailbox and retrieve message list
    char *mailbox = "INBOX";
    select_mailbox(ssl, mailbox);

    // Fetch the first message
    int message_number = 1;
    fetch_message(ssl, message_number);

    // Close SSL connection and free SSL context
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ssl_ctx);

    close(sockfd);

    return 0;
}