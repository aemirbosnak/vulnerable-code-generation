//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int receive_response(SSL *ssl, char *buf) {
    int bytes_received, total_bytes_received = 0;
    do {
        bytes_received = SSL_read(ssl, buf, BUFFER_SIZE);
        buf[bytes_received] = '\0';
        printf("%s", buf);
        total_bytes_received += bytes_received;
    } while (bytes_received > 0);
    return total_bytes_received;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s hostname port username\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    char *port = argv[2];
    char *username = argv[3];

    // Open connection to IMAP server
    struct addrinfo hints, *server_info;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    if (getaddrinfo(hostname, port, &hints, &server_info) != 0) {
        perror("getaddrinfo");
        return 1;
    }

    int server_fd = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol);
    if (server_fd == -1) {
        perror("socket");
        return 1;
    }

    if (connect(server_fd, server_info->ai_addr, server_info->ai_addrlen) == -1) {
        perror("connect");
        return 1;
    }

    SSL_library_init();
    OpenSSL_add_all_algorithms();
    SSL_CTX *ssl_ctx = SSL_CTX_new(TLSv1_2_client_method());
    if (ssl_ctx == NULL) {
        perror("SSL_CTX_new");
        return 1;
    }

    SSL *ssl = SSL_new(ssl_ctx);
    if (ssl == NULL) {
        perror("SSL_new");
        return 1;
    }

    if (SSL_set_fd(ssl, server_fd) == 0) {
        perror("SSL_set_fd");
        return 1;
    }

    if (SSL_connect(ssl) == -1) {
        perror("SSL_connect");
        return 1;
    }

    // Login
    char login_command[BUFFER_SIZE];
    sprintf(login_command, "a001 LOGIN %s\r\n", username);
    SSL_write(ssl, login_command, strlen(login_command));

    char response[BUFFER_SIZE];
    receive_response(ssl, response);

    if (strstr(response, "OK") == NULL) {
        printf("Login failed. Response from server:\n%s", response);
        return 1;
    }

    // Select inbox
    char inbox_command[BUFFER_SIZE] = "a002 SELECT INBOX\r\n";
    SSL_write(ssl, inbox_command, strlen(inbox_command));

    receive_response(ssl, response);

    if (strstr(response, "OK") == NULL) {
        printf("Selecting inbox failed. Response from server:\n%s", response);
        return 1;
    }

    // Fetch unread messages
    char fetch_command[BUFFER_SIZE] = "a003 FETCH 1:* (FLAGS BODY[HEADER.FIELDS (SUBJECT FROM)])\r\n";
    SSL_write(ssl, fetch_command, strlen(fetch_command));

    receive_response(ssl, response);

    if (strstr(response, "OK") == NULL) {
        printf("Fetching messages failed. Response from server:\n%s", response);
        return 1;
    }

    // Logout
    char logout_command[BUFFER_SIZE] = "a004 LOGOUT\r\n";
    SSL_write(ssl, logout_command, strlen(logout_command));

    receive_response(ssl, response);

    if (strstr(response, "OK") == NULL) {
        printf("Logout failed. Response from server:\n%s", response);
        return 1;
    }

    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(server_fd);

    return 0;
}