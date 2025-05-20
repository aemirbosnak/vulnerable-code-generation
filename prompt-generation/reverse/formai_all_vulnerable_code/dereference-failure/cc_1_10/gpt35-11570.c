//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define SERVER "imap.gmail.com"
#define PORT "993"

int imap_login(SSL *ssl) {
    char buffer[1024];
    ssize_t bytes;
    int separator_found = 0;
    char *ptr;

    // Send login command to server
    SSL_write(ssl, "LOGIN username@gmail.com password\n", strlen("LOGIN username@gmail.com password\n"));
    
    // Read server response
    while ((bytes = SSL_read(ssl, buffer, sizeof(buffer)))) {
        buffer[bytes] = '\0';
        printf("%s", buffer);
        
        // Check if response contains separator char
        if (separator_found == 0) {
            ptr = strchr(buffer, '*');
            if (ptr != NULL) {
                separator_found = 1;
            }
        }

        // Check if response contains OK flag
        if (strstr(buffer, "OK") != NULL) {
            return 1;
        }
    }

    return 0;
}

int main(int argc, char *argv[]) {
    SSL_CTX *ctx;
    SSL *ssl;
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Create SSL context and verify certificate
    SSL_library_init();
    SSL_load_error_strings();
    OpenSSL_add_all_algorithms();
    ctx = SSL_CTX_new(TLS_client_method());
    if (ctx == NULL) {
        printf("Error creating SSL context\n");
        return 1;
    }
    SSL_CTX_set_verify(ctx, SSL_VERIFY_PEER, NULL);

    // Create TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        return 1;
    }

    // Get server hostname
    server = gethostbyname(SERVER);
    if (server == NULL) {
        printf("Error resolving hostname\n");
        return 1;
    }

    // Configure server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(PORT));

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        return 1;
    }

    // Create SSL connection
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) != 1) {
        printf("Error creating SSL connection\n");
        return 1;
    }

    // Login to server
    if (imap_login(ssl) == 0) {
        printf("Error logging in\n");
        return 1;
    }
    
    // Close SSL connection and free resources
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);
    
    return 0;
}