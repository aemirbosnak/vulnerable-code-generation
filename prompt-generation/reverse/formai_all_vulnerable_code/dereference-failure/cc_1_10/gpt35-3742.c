//FormAI DATASET v1.0 Category: Email Client ; Style: secure
#define _GNU_SOURCE // Required for secure_getenv()

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define HOST "smtp.gmail.com" // SMTP server hostname
#define PORT 465 // SMTP server port number
#define BUF_SIZE 1024 // maximum message buffer size

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUF_SIZE];
    SSL *ssl;

    // Get email account credentials from environment variables
    char *email = secure_getenv("EMAIL");
    char *password = secure_getenv("PASSWORD");

    // Check if required environment variables are set
    if (email == NULL || password == NULL) {
        fprintf(stderr, "Please set EMAIL and PASSWORD environment variables.\n");
        return 1;
    }

    // Create TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "ERROR: Could not create socket.\n");
        return 1;
    }

    // Lookup SMTP server IP address
    server = gethostbyname(HOST);
    if (server == NULL) {
        fprintf(stderr, "ERROR: Could not resolve server hostname.\n");
        return 1;
    }

    // Initialize socket address structure
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);

    // Establish TCP connection to SMTP server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "ERROR: Could not connect to server.\n");
        return 1;
    }

    // Create SSL/TLS context and connection
    SSL_load_error_strings();
    SSL_library_init();
    SSL_CTX *ctx = SSL_CTX_new(TLSv1_2_client_method());
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) == -1) {
        fprintf(stderr, "ERROR: Could not establish SSL/TLS connection.\n");
        return 1;
    }

    // Send email account credentials
    sprintf(buffer, "AUTH LOGIN\r\n");
    SSL_write(ssl, buffer, strlen(buffer));
    SSL_read(ssl, buffer, BUF_SIZE); // Wait for server response
    sprintf(buffer, "%s\r\n", email);
    SSL_write(ssl, buffer, strlen(buffer));
    SSL_read(ssl, buffer, BUF_SIZE); // Wait for server response
    sprintf(buffer, "%s\r\n", password);
    SSL_write(ssl, buffer, strlen(buffer));
    SSL_read(ssl, buffer, BUF_SIZE); // Wait for server response

    // Send email message
    sprintf(buffer, "MAIL FROM:<%s>\r\n", email);
    SSL_write(ssl, buffer, strlen(buffer));
    SSL_read(ssl, buffer, BUF_SIZE); // Wait for server response
    sprintf(buffer, "RCPT TO:<%s>\r\n", argv[1]); // recipient email address passed as first command line argument
    SSL_write(ssl, buffer, strlen(buffer));
    SSL_read(ssl, buffer, BUF_SIZE); // Wait for server response
    sprintf(buffer, "DATA\r\n");
    SSL_write(ssl, buffer, strlen(buffer));
    SSL_read(ssl, buffer, BUF_SIZE); // Wait for server response

    // Read email message from stdin and send to server
    while (fgets(buffer, BUF_SIZE-1, stdin)) {
        SSL_write(ssl, buffer, strlen(buffer));
        if (strcmp(buffer, ".\n") == 0) // End email message input with period on a line by itself
            break;
    }

    SSL_write(ssl, "\r\n.\r\n", 5); // End email message

    SSL_read(ssl, buffer, BUF_SIZE); // Wait for server response
    SSL_write(ssl, "QUIT\r\n", 6); // Close connection

    // Clean up SSL/TLS resources
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);

    // Close TCP socket
    close(sockfd);

    return 0;
}