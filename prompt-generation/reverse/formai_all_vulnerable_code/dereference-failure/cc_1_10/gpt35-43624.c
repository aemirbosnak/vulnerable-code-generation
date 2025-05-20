//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    // initialize SSL library
    SSL_load_error_strings();
    SSL_library_init();

    // read command line arguments
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server> <port> <username>", argv[0]);
        return EXIT_FAILURE;
    }
    char *server = argv[1];
    char *port = argv[2];
    char *username = argv[3];

    // create TCP socket
    struct addrinfo hints, *server_info;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    int status = getaddrinfo(server, port, &hints, &server_info);
    if (status != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        return EXIT_FAILURE;
    }
    int sockfd = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // connect to the server
    status = connect(sockfd, server_info->ai_addr, server_info->ai_addrlen);
    if (status == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // create SSL context and SSL object
    SSL_CTX *ctx = SSL_CTX_new(TLS_method());
    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);

    // establish SSL connection
    status = SSL_connect(ssl);
    if (status <= 0) {
        ERR_print_errors_fp(stderr);
        return EXIT_FAILURE;
    }

    // login to the server
    char buffer[MAX_BUFFER_SIZE];
    sprintf(buffer, "1 LOGIN %s\n", username);
    SSL_write(ssl, buffer, strlen(buffer));
    SSL_read(ssl, buffer, MAX_BUFFER_SIZE);
    printf("%s", buffer);

    // select the inbox
    sprintf(buffer, "1 SELECT INBOX\n");
    SSL_write(ssl, buffer, strlen(buffer));
    SSL_read(ssl, buffer, MAX_BUFFER_SIZE);
    printf("%s", buffer);

    // search for messages
    sprintf(buffer, "1 SEARCH ALL\n");
    SSL_write(ssl, buffer, strlen(buffer));
    SSL_read(ssl, buffer, MAX_BUFFER_SIZE);
    printf("%s", buffer);

    // select the first message returned by the search
    char message_number[10];
    sscanf(buffer, "* SEARCH %s", message_number);
    sprintf(buffer, "1 SELECT %s\n", message_number);
    SSL_write(ssl, buffer, strlen(buffer));
    SSL_read(ssl, buffer, MAX_BUFFER_SIZE);
    printf("%s", buffer);

    // fetch the message body
    sprintf(buffer, "1 FETCH 1 BODY[TEXT]\n");
    SSL_write(ssl, buffer, strlen(buffer));
    int bytes_received = SSL_read(ssl, buffer, MAX_BUFFER_SIZE);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // logout and close connection
    sprintf(buffer, "1 LOGOUT\n");
    SSL_write(ssl, buffer, strlen(buffer));
    SSL_shutdown(ssl);
    close(sockfd);

    return EXIT_SUCCESS;
}