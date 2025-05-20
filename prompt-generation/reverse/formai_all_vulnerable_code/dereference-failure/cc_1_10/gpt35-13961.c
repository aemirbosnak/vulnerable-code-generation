//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFER_SIZE 4096

SSL* create_ssl_connection(int sockfd) {
    SSL_CTX* ctx;
    SSL* ssl;
    const SSL_METHOD* method;

    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();
    method = TLS_client_method();
    ctx = SSL_CTX_new(method);

    if (ctx == NULL) {
        perror("Couldn't create SSL context");
        return NULL;
    }

    ssl = SSL_new(ctx);

    if (!ssl) {
        perror("Couldn't create SSL instance");
        return NULL;
    }

    if (SSL_set_fd(ssl, sockfd) <= 0) {
        perror("Couldn't attach socket to SSL");
        return NULL;
    }

    if (SSL_connect(ssl) < 0) {
        perror("Couldn't connect using SSL");
        return NULL;
    }

    return ssl;
}

int main(int argc, char* argv[]) {
    char* hostname;
    char* portnumber;
    char buffer[BUFFER_SIZE];
    struct hostent* server;
    struct sockaddr_in server_address;
    int sockfd, bytes_received;
    SSL* ssl;

    if (argc != 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        return 0;
    }

    hostname = argv[1];
    portnumber = argv[2];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("Error opening socket");
        return 0;
    }

    server = gethostbyname(hostname);

    if (server == NULL) {
        printf("Error: no such host\n");
        return 0;
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    memcpy(&server_address.sin_addr.s_addr, server -> h_addr, server -> h_length);
    server_address.sin_port = htons(atoi(portnumber));

    if (connect(sockfd, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        return 0;
    }

    ssl = create_ssl_connection(sockfd);

    if (!ssl) {
        printf("Error establishing SSL connection\n");
        return 0;
    }

    printf("Connected to server\n");

    SSL_write(ssl, "1 LOGIN username password\n", strlen("1 LOGIN username password\n"));

    memset(buffer, 0, BUFFER_SIZE);

    bytes_received = SSL_read(ssl, buffer, BUFFER_SIZE);

    printf("%s", buffer);

    SSL_write(ssl, "2 SELECT INBOX\n", strlen("2 SELECT INBOX\n"));

    memset(buffer, 0, BUFFER_SIZE);
  
    bytes_received = SSL_read(ssl, buffer, BUFFER_SIZE);
   
    printf("%s", buffer);

    SSL_write(ssl, "3 LOGOUT\n", strlen("3 LOGOUT\n"));

    memset(buffer, 0, BUFFER_SIZE);

    bytes_received = SSL_read(ssl, buffer, BUFFER_SIZE);

    printf("%s", buffer);

    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sockfd);

    return 0;
}