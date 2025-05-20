//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define MAX_BUFF_SIZE 4096

// Connect to host
int connect_to_host(const char *hostname, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == -1) {
        fprintf(stderr, "Could not create socket\n");
        exit(EXIT_FAILURE);
    }

    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Could not resolve hostname: %s\n", hostname);
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    memcpy(&addr.sin_addr.s_addr, host->h_addr, host->h_length);

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        fprintf(stderr, "Could not connect to host: %s on port: %d\n", hostname, port);
        exit(EXIT_FAILURE);
    }

    return sock;
}

// Initialize SSL
SSL_CTX *init_ssl(void) {
    SSL_library_init();
    SSL_load_error_strings();

    SSL_CTX *ctx = SSL_CTX_new(SSLv23_client_method());
    if (ctx == NULL) {
        fprintf(stderr, "Could not initialize SSL\n");
        exit(EXIT_FAILURE);
    }

    return ctx;
}

// Connect to host over SSL
SSL *ssl_connect(const char *hostname, int port, SSL_CTX *ctx) {
    int sock = connect_to_host(hostname, port);

    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock);

    if (SSL_connect(ssl) == -1) {
        fprintf(stderr, "Could not connect over SSL to host: %s on port: %d\n", hostname, port);
        exit(EXIT_FAILURE);
    }

    return ssl;
}

// Read from socket
int read_socket(int sock, char *buffer, int max_len) {
    memset(buffer, 0, max_len);

    int total_bytes_read = 0;
    int bytes_read = read(sock, buffer, max_len);
    while (bytes_read > 0) {
        total_bytes_read += bytes_read;
        bytes_read = read(sock, buffer + total_bytes_read, max_len - total_bytes_read);
    }

    return total_bytes_read;
}

// Write to socket
void write_socket(int sock, const char *buffer, int len) {
    int total_bytes_written = 0;
    int bytes_written = 0;

    while (total_bytes_written < len) {
        bytes_written = write(sock, buffer + total_bytes_written, len - total_bytes_written);
        if (bytes_written == -1) {
            fprintf(stderr, "Could not write to socket\n");
            exit(EXIT_FAILURE);
        }

        total_bytes_written += bytes_written;
    }
}

// Send command to server
void send_command(SSL *ssl, const char *command) {
    char buffer[MAX_BUFF_SIZE] = {0};
    sprintf(buffer, "%s", command);

    write_socket(SSL_get_fd(ssl), buffer, strlen(buffer));
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s HOSTNAME USERNAME PASSWORD\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    SSL_CTX *ctx = init_ssl();
    SSL *ssl = ssl_connect(hostname, 993, ctx);

    // Login
    send_command(ssl, "LOGIN ");
    send_command(ssl, username);
    send_command(ssl, " ");
    send_command(ssl, password);
    send_command(ssl, "\r\n");

    // Check for successful login
    char buffer[MAX_BUFF_SIZE] = {0};
    read_socket(SSL_get_fd(ssl), buffer, MAX_BUFF_SIZE);
    if (strstr(buffer, "OK") == NULL) {
        fprintf(stderr, "Could not login to account: %s\n", username);
        exit(EXIT_FAILURE);
    }

    // Check mailbox status
    send_command(ssl, "STATUS INBOX (MESSAGES UNSEEN)\r\n");
    read_socket(SSL_get_fd(ssl), buffer, MAX_BUFF_SIZE);

    // Parse mailbox status
    char *messages_ptr = strstr(buffer, "MESSAGES");
    char *unseen_ptr = strstr(buffer, "UNSEEN");

    if (messages_ptr != NULL && unseen_ptr != NULL) {
        int messages = atoi(messages_ptr + strlen("MESSAGES"));
        int unseen = atoi(unseen_ptr + strlen("UNSEEN"));

        printf("You have %d messages.", messages);

        if (unseen > 0) {
            printf(" %d of them are unread.\n", unseen);
        } else {
            printf("\n");
        }
    }

    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);

    return EXIT_SUCCESS;
}