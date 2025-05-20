//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define POP3_PORT "995" // Secure POP3 port
#define BUFFER_SIZE 1024

void print_error(char *error_message)
{
    fprintf(stderr, "%s\n", error_message);
    exit(1);
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        print_error("Usage: ./pop3client <hostname> <username>");
    }

    char *hostname = argv[1];
    char *username = argv[2];

    struct hostent *hp = gethostbyname(hostname);
    if (!hp) {
        print_error("Error: Host not found!");
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd < 0) {
        print_error("Error: Failed to create socket!");
    }

    // Set up the server address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(POP3_PORT));
    memcpy(&server_address.sin_addr.s_addr, hp->h_addr, hp->h_length);

    // Connect to server
    if (connect(sockfd, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        print_error("Error: Failed to connect to server!");
    }

    SSL_library_init();
    SSL_load_error_strings();

    // Set up SSL context
    SSL_CTX *ssl_ctx;
    SSL *ssl;
    ssl_ctx = SSL_CTX_new(TLS_client_method());
    if (!ssl_ctx) {
        print_error("Error: Failed to create SSL context");
    }

    // Set SSL options
    SSL_CTX_set_options(ssl_ctx, SSL_OP_NO_SSLv2 | SSL_OP_NO_SSLv3 | SSL_OP_NO_COMPRESSION);

    // Attach the SSL session to the socket descriptor
    ssl = SSL_new(ssl_ctx);
    SSL_set_fd(ssl, sockfd);

    // Initiate SSL handshake
    if (SSL_connect(ssl) <= 0) {
        print_error("Error: Failed to initiate SSL handshake!");
    }

    // Receive initial server response
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));
    SSL_read(ssl, buffer, sizeof(buffer));
    printf("%s", buffer);

    // Send USER command
    char user_message[BUFFER_SIZE];
    snprintf(user_message, sizeof(user_message), "USER %s\r\n", username);
    SSL_write(ssl, user_message, strlen(user_message));

    // Receive server response to USER command
    memset(buffer, 0, sizeof(buffer));
    SSL_read(ssl, buffer, sizeof(buffer));
    printf("%s", buffer);

    // Prompt user for password
    char password[BUFFER_SIZE];
    printf("Password: ");
    fgets(password, sizeof(password), stdin);

    // Strip newline character from password
    password[strcspn(password, "\n")] = 0;

    // Send PASS command
    char pass_message[BUFFER_SIZE];
    snprintf(pass_message, sizeof(pass_message), "PASS %s\r\n", password);
    SSL_write(ssl, pass_message, strlen(pass_message));

    // Receive server response to PASS command
    memset(buffer, 0, sizeof(buffer));
    SSL_read(ssl, buffer, sizeof(buffer));
    printf("%s", buffer);

    // Close SSL connection and socket
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ssl_ctx);
    close(sockfd);

    return 0;
}