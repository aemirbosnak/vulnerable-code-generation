//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname or ip address> <username>\n", argv[0]);
        exit(1);
    }

    // Get the hostname or ip address
    const char *hostname = argv[1];

    // Get the username
    const char *username = argv[2];

    // Create the socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    // Get the host information
    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        error("ERROR, no such host");
    }

    // Set up the server address structure
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy(server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(993);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    // Create the SSL context
    SSL_CTX *ctx = SSL_CTX_new(SSLv23_client_method());
    if (ctx == NULL) {
        error("ERROR creating SSL context");
    }

    // Create the SSL connection
    SSL *ssl = SSL_new(ctx);
    if (ssl == NULL) {
        error("ERROR creating SSL connection");
    }

    // Set up the SSL connection
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) != 1) {
        error("ERROR connecting over SSL");
    }

    // Log into the IMAP server
    char buffer[256];
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "A001 LOGIN %s\r\n", username);
    SSL_write(ssl, buffer, strlen(buffer));

    // Wait for the response
    memset(buffer, 0, sizeof(buffer));
    SSL_read(ssl, buffer, sizeof(buffer));

    // Check if login was successful
    if (strstr(buffer, "OK") == NULL) {
        fprintf(stderr, "ERROR: Login failed\n");
        exit(1);
    }

    // Log out of the IMAP server
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "A002 LOGOUT\r\n");
    SSL_write(ssl, buffer, strlen(buffer));

    // Wait for the response
    memset(buffer, 0, sizeof(buffer));
    SSL_read(ssl, buffer, sizeof(buffer));

    // Check if logout was successful
    if (strstr(buffer, "OK") == NULL) {
        fprintf(stderr, "ERROR: Logout failed\n");
        exit(1);
    }

    // Clean up
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);

    return 0;
}