//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT "993"  // Port for IMAPS
#define MAX_LINE_LENGTH 1024

// Function to establish a secure connection
int create_secure_connection(const char *hostname) {
    int sockfd;
    struct addrinfo hints, *res;
    
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(hostname, PORT, &hints, &res) != 0) {
        perror("getaddrinfo");
        return -1;
    }

    // Create socket
    if ((sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) == -1) {
        perror("socket");
        return -1;
    }

    // Connect to the server
    if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
        close(sockfd);
        perror("connect");
        return -1;
    }

    freeaddrinfo(res);
    return sockfd;
}

// Function to initialize SSL
SSL_CTX* initialize_ssl() {
    SSL_CTX *ctx;
    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();

    ctx = SSL_CTX_new(SSLv23_client_method());
    if (!ctx) {
        ERR_print_errors_fp(stderr);
    }
    return ctx;
}

// Function to perform command with error checking
void send_command(SSL *ssl, const char *command) {
    SSL_write(ssl, command, strlen(command));
    
    char buffer[MAX_LINE_LENGTH];
    int bytes;

    do {
        bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1);
        if (bytes < 1) {
            perror("SSL_read");
            break;
        }
        buffer[bytes] = '\0';
        printf("%s", buffer);
    } while (bytes > 0);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    SSL_CTX *ctx = initialize_ssl();
    if (!ctx) {
        return EXIT_FAILURE;
    }

    int sockfd = create_secure_connection(hostname);
    if (sockfd < 0) {
        SSL_CTX_free(ctx);
        return EXIT_FAILURE;
    }

    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) <= 0) {
        ERR_print_errors_fp(stderr);
    } else {
        printf("Secure connection established with %s\n", hostname);
        
        // Send IMAP commands
        char command[MAX_LINE_LENGTH];

        // Login command
        snprintf(command, sizeof(command), "a001 LOGIN %s %s\r\n", username, password);
        send_command(ssl, command);

        // Select INBOX command
        snprintf(command, sizeof(command), "a002 SELECT INBOX\r\n");
        send_command(ssl, command);

        // Fetch messages
        snprintf(command, sizeof(command), "a003 FETCH 1:* (BODY[HEADER.FIELDS (SUBJECT FROM DATE)])\r\n");
        send_command(ssl, command);

        // Logout command
        snprintf(command, sizeof(command), "a004 LOGOUT\r\n");
        send_command(ssl, command);
    }

    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sockfd);
    SSL_CTX_free(ctx);
    EVP_cleanup();
    return EXIT_SUCCESS;
}