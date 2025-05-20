//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[])
{
    char server_address[MAX_BUF_SIZE];
    char username[MAX_BUF_SIZE];
    char password[MAX_BUF_SIZE];

    printf("Enter server address: ");
    fgets(server_address, sizeof(server_address), stdin);
    server_address[strcspn(server_address, "\n")] = 0;

    printf("Enter username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0;

    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;

    // create socket
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    int status = getaddrinfo(server_address, "imaps", &hints, &res);
    if (status != 0)
    {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(EXIT_FAILURE);
    }
    int sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    // connect to server
    if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1)
    {
        fprintf(stderr, "connect error");
        exit(EXIT_FAILURE);
    }

    // secure connection using SSL/TLS
    SSL_library_init();
    SSL_CTX *ctx = SSL_CTX_new(SSLv23_client_method());
    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    SSL_connect(ssl);

    // login to server
    char buf[MAX_BUF_SIZE];
    char command[MAX_BUF_SIZE];
    snprintf(command, MAX_BUF_SIZE, "tag1 LOGIN %s %s\r\n", username, password);
    SSL_write(ssl, command, strlen(command));
    SSL_read(ssl, buf, sizeof(buf));

    // select inbox
    snprintf(command, MAX_BUF_SIZE, "tag2 SELECT INBOX\r\n");
    SSL_write(ssl, command, strlen(command));
    SSL_read(ssl, buf, sizeof(buf));

    // fetch emails
    snprintf(command, MAX_BUF_SIZE, "tag3 FETCH 1:10 (BODY[])\r\n");
    SSL_write(ssl, command, strlen(command));
    SSL_read(ssl, buf, sizeof(buf));

    // output email body
    printf("%s", buf);

    // logout and quit
    snprintf(command, MAX_BUF_SIZE, "tag4 LOGOUT\r\n");
    SSL_write(ssl, command, strlen(command));
    SSL_read(ssl, buf, sizeof(buf));

    SSL_shutdown(ssl);
    close(sockfd);
    SSL_free(ssl);
    SSL_CTX_free(ctx);

    return EXIT_SUCCESS;
}