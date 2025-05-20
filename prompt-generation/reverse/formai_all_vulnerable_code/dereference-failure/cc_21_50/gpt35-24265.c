//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 993

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_address> <username>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    SSL_library_init();
    SSL_CTX *context = SSL_CTX_new(TLSv1_2_client_method());

    if (!context) {
        fprintf(stderr, "Error creating SSL context: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    SSL *ssl = SSL_new(context);

    if (!ssl) {
        fprintf(stderr, "Error creating SSL structure: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_fd < 0) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    struct hostent *server = gethostbyname(argv[1]);

    if (!server) {
        fprintf(stderr, "Error resolving server address: %s\n", hstrerror(h_errno));
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    memcpy(&server_address.sin_addr.s_addr, server->h_addr, server->h_length);
    server_address.sin_port = htons(SERVER_PORT);

    if (connect(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        fprintf(stderr, "Error connecting to server: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (SSL_set_fd(ssl, socket_fd) < 0) {
        fprintf(stderr, "Error setting up SSL connection: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (SSL_connect(ssl) != 1) {
        fprintf(stderr, "Error establishing SSL connection: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    int bytes_read;
    char *username = strdup(argv[2]);

    snprintf(buffer, sizeof(buffer), "LOGIN %s password\n", username);
    SSL_write(ssl, buffer, strlen(buffer));

    while (true) {
        bytes_read = SSL_read(ssl, buffer, sizeof(buffer) - 1);
        if (bytes_read <= 0) {
            if (bytes_read == 0) {
                printf("Server closed connection.\n");
            } else {
                fprintf(stderr, "Error reading from server: %s\n", strerror(errno));
            }
            break;
        }
        buffer[bytes_read] = '\0';
        printf("Server: %s", buffer);
        if (strstr(buffer, "OK LOGIN Completed") != NULL) {
            break;
        }
    }

    if (bytes_read < 0) {
        SSL_shutdown(ssl);
        close(socket_fd);
        printf("Client exiting due to error.\n");
        exit(EXIT_FAILURE);
    }

    snprintf(buffer, sizeof(buffer), "SELECT INBOX\n");
    SSL_write(ssl, buffer, strlen(buffer));

    while (true) {
        bytes_read = SSL_read(ssl, buffer, sizeof(buffer) - 1);
        if (bytes_read <= 0) {
            if (bytes_read == 0) {
                printf("Server closed connection.\n");
            } else {
                fprintf(stderr, "Error reading from server: %s\n", strerror(errno));
            }
            break;
        }
        buffer[bytes_read] = '\0';
        printf("Server: %s", buffer);
        if (strstr(buffer, "OK SELECT completed") != NULL) {
            break;
        }
    }

    if (bytes_read < 0) {
        SSL_shutdown(ssl);
        close(socket_fd);
        printf("Client exiting due to error.\n");
        exit(EXIT_FAILURE);
    }

    snprintf(buffer, sizeof(buffer), "FETCH 1 BODY[HEADER]\n");
    SSL_write(ssl, buffer, strlen(buffer));

    while (true) {
        bytes_read = SSL_read(ssl, buffer, sizeof(buffer) - 1);
        if (bytes_read <= 0) {
            if (bytes_read == 0) {
                printf("Server closed connection.\n");
            } else {
                fprintf(stderr, "Error reading from server: %s\n", strerror(errno));
            }
            break;
        }
        buffer[bytes_read] = '\0';
        printf("Server: %s", buffer);
        if (strstr(buffer, "OK FETCH completed") != NULL) {
            break;
        }
    }

    if (bytes_read < 0) {
        SSL_shutdown(ssl);
        close(socket_fd);
        printf("Client exiting due to error.\n");
        exit(EXIT_FAILURE);
    }

    SSL_shutdown(ssl);
    close(socket_fd);
    printf("Client exiting successfully.\n");
    exit(EXIT_SUCCESS);
}