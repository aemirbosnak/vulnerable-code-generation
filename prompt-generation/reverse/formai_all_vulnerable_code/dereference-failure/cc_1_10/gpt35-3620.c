//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUF_SIZE 1024
#define HOSTNAME "imap.gmail.com"
#define PORT "993"

int main()
{
    int sockfd, err;
    struct addrinfo *addr;
    struct addrinfo hints = {
        .ai_family = AF_UNSPEC,
        .ai_socktype = SOCK_STREAM,
    };
    SSL_CTX *ctx;
    SSL *ssl;
    char buf[BUF_SIZE];

    // Initialize OpenSSL
    SSL_library_init();
    SSL_load_error_strings();
    OpenSSL_add_all_algorithms();

    // Get server IP address and create socket
    err = getaddrinfo(HOSTNAME, PORT, &hints, &addr);
    if (err != 0)
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(err));
        return 1;
    }

    sockfd = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);
    if (sockfd == -1)
    {
        perror("socket");
        return 1;
    }

    // Connect to server
    err = connect(sockfd, addr->ai_addr, addr->ai_addrlen);
    if (err == -1)
    {
        perror("connect");
        return 1;
    }

    // Create SSL connection context and establish connection
    ctx = SSL_CTX_new(TLS_client_method());
    if (!ctx)
    {
        fprintf(stderr, "SSL_CTX_new: %s\n", ERR_error_string(ERR_get_error(), NULL));
        return 1;
    }

    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);

    err = SSL_connect(ssl);
    if (err != 1)
    {
        fprintf(stderr, "SSL_connect: %s\n", ERR_error_string(ERR_get_error(), NULL));
        return 1;
    }

    // Authenticate with server
    snprintf(buf, BUF_SIZE, "a001 LOGIN example@gmail.com password\r\n");
    SSL_write(ssl, buf, strlen(buf));

    // Read server response
    memset(buf, 0, BUF_SIZE);
    SSL_read(ssl, buf, BUF_SIZE);

    // Verify successful authentication
    if (strstr(buf, "a001 OK") == NULL)
    {
        fprintf(stderr, "Authentication failed: %s", buf);
        return 1;
    }

    // Request list of mailboxes
    snprintf(buf, BUF_SIZE, "a002 LIST \"\" \"*\"\r\n");
    SSL_write(ssl, buf, strlen(buf));

    // Read server response
    memset(buf, 0, BUF_SIZE);
    SSL_read(ssl, buf, BUF_SIZE);

    // Print mailbox list
    printf("%s", buf);

    // Select mailbox
    snprintf(buf, BUF_SIZE, "a003 SELECT Inbox\r\n");
    SSL_write(ssl, buf, strlen(buf));

    // Read server response
    memset(buf, 0, BUF_SIZE);
    SSL_read(ssl, buf, BUF_SIZE);

    // Print mailbox status
    printf("%s", buf);

    // Logout and close connection
    snprintf(buf, BUF_SIZE, "a004 LOGOUT\r\n");
    SSL_write(ssl, buf, strlen(buf));

    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);

    return 0;
}