//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define MAX_BUFFER_SIZE 4096
#define SERVER_ADDRESS "imap.gmail.com"
#define SERVER_PORT 993

int main() {
    int sockfd, bytes_recv;
    char recv_buffer[MAX_BUFFER_SIZE];

    // Connect to server
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);
    server_address.sin_port = htons(SERVER_PORT);

    sockfd = socket(PF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket: %s\n", strerror(errno));
        return -1;
    }
    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Error connecting to server: %s\n", strerror(errno));
        return -1;
    }

    // SSL setup
    SSL_CTX *ssl_context;
    SSL *ssl;
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();
    ssl_context = SSL_CTX_new(TLS_client_method());
    if (ssl_context == NULL) {
        printf("Error creating SSL context\n");
        return -1;
    }
    ssl = SSL_new(ssl_context);
    if (ssl == NULL) {
        printf("Error creating SSL object\n");
        return -1;
    }
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) <= 0) {
        ERR_print_errors_fp(stderr);
        return -1;
    }

    // Send IMAP commands
    char send_buffer[MAX_BUFFER_SIZE];
    sprintf(send_buffer, "a001 LOGIN username@gmail.com password\r\n");
    SSL_write(ssl, send_buffer, strlen(send_buffer));
    bytes_recv = SSL_read(ssl, recv_buffer, sizeof(recv_buffer));
    printf("%.*s", bytes_recv, recv_buffer);

    sprintf(send_buffer, "a002 SELECT INBOX\r\n");
    SSL_write(ssl, send_buffer, strlen(send_buffer));
    bytes_recv = SSL_read(ssl, recv_buffer, sizeof(recv_buffer));
    printf("%.*s", bytes_recv, recv_buffer);

    sprintf(send_buffer, "a003 FETCH 1:* RFC822\r\n");
    SSL_write(ssl, send_buffer, strlen(send_buffer));
    while ((bytes_recv = SSL_read(ssl, recv_buffer, sizeof(recv_buffer))) > 0) {
        printf("%.*s", bytes_recv, recv_buffer);
    }

    sprintf(send_buffer, "a004 LOGOUT\r\n");
    SSL_write(ssl, send_buffer, strlen(send_buffer));
    bytes_recv = SSL_read(ssl, recv_buffer, sizeof(recv_buffer));
    printf("%.*s", bytes_recv, recv_buffer);

    // Close connection
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ssl_context);
    close(sockfd);

    return 0;
}