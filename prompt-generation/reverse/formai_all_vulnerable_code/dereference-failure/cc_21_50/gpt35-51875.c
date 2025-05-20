//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define IMAP_PORT 993
#define BUFFER_SIZE 1024

int main(int argc, char **argv)
{
    if (argc != 4) {
        printf("Usage: %s server username password\n", argv[0]);
        return 1;
    }

    const char *server = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    // Create a TCP socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 2;
    }

    // Resolve the server hostname to its IP address
    struct hostent *he = gethostbyname(server);
    if (!he) {
        perror("gethostbyname");
        return 3;
    }

    // Connect to the IMAP server
    struct sockaddr_in addr = {
        .sin_family = AF_INET,
        .sin_port = htons(IMAP_PORT),
    };
    memcpy(&addr.sin_addr, he->h_addr_list[0], he->h_length);

    int ret = connect(sockfd, (struct sockaddr *)&addr, sizeof addr);
    if (ret == -1) {
        perror("connect");
        return 4;
    }

    // Initialize OpenSSL
    SSL_load_error_strings();
    SSL_library_init();

    // Create an SSL context
    SSL_CTX *ctx = SSL_CTX_new(TLSv1_2_client_method());
    if (!ctx) {
        perror("SSL_CTX_new");
        return 5;
    }

    // Create an SSL connection from the socket and the context
    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);

    ret = SSL_connect(ssl);
    if (ret != 1) {
        ERR_print_errors_fp(stderr);
        return 6;
    }

    // Send the login command to the server
    char buffer[BUFFER_SIZE];
    ret = snprintf(buffer, BUFFER_SIZE, "LOGIN %s %s\n", username, password);
    if (ret < 0 || ret >= BUFFER_SIZE) {
        printf("Error: buffer length exceeded\n");
        return 7;
    }

    ret = SSL_write(ssl, buffer, strlen(buffer));
    if (ret < 0) {
        perror("SSL_write");
        return 8;
    }

    // Wait for the server's response
    ret = SSL_read(ssl, buffer, BUFFER_SIZE-1);
    if (ret < 0) {
        perror("SSL_read");
        return 9;
    }
    buffer[ret] = '\0';
    printf("Server response: %s", buffer);

    // Send the select command to the server
    ret = snprintf(buffer, BUFFER_SIZE, "SELECT INBOX\n");
    if (ret < 0 || ret >= BUFFER_SIZE) {
        printf("Error: buffer length exceeded\n");
        return 10;
    }

    ret = SSL_write(ssl, buffer, strlen(buffer));
    if (ret < 0) {
        perror("SSL_write");
        return 11;
    }

    // Wait for the server's response
    ret = SSL_read(ssl, buffer, BUFFER_SIZE-1);
    if (ret < 0) {
        perror("SSL_read");
        return 12;
    }
    buffer[ret] = '\0';
    printf("Server response: %s", buffer);

    // Send the list command to the server
    ret = snprintf(buffer, BUFFER_SIZE, "LIST \"\" *\n");
    if (ret < 0 || ret >= BUFFER_SIZE) {
        printf("Error: buffer length exceeded\n");
        return 13;
    }

    ret = SSL_write(ssl, buffer, strlen(buffer));
    if (ret < 0) {
        perror("SSL_write");
        return 14;
    }

    // Wait for the server's response
    ret = SSL_read(ssl, buffer, BUFFER_SIZE-1);
    if (ret < 0) {
        perror("SSL_read");
        return 15;
    }
    buffer[ret] = '\0';
    printf("Server response: %s", buffer);

    // Send the logout command to the server
    ret = snprintf(buffer, BUFFER_SIZE, "LOGOUT\n");
    if (ret < 0 || ret >= BUFFER_SIZE) {
        printf("Error: buffer length exceeded\n");
        return 16;
    }

    ret = SSL_write(ssl, buffer, strlen(buffer));
    if (ret < 0) {
        perror("SSL_write");
        return 17;
    }

    // Wait for the server's response
    ret = SSL_read(ssl, buffer, BUFFER_SIZE-1);
    if (ret < 0) {
        perror("SSL_read");
        return 18;
    }
    buffer[ret] = '\0';
    printf("Server response: %s", buffer);

    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);

    return 0;
}