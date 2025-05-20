//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define SERVER "imap.gmail.com"
#define PORT "993"

int main()
{
    SSL_CTX *ctx;
    SSL *ssl;
    int sockfd;
    struct addrinfo hints, *servinfo;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    // Get server info
    if (getaddrinfo(SERVER, PORT, &hints, &servinfo) != 0)
    {
        fprintf(stderr, "Error getting address info\n");
        exit(EXIT_FAILURE);
    }

    // Create socket
    sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
    if (sockfd == -1)
    {
        fprintf(stderr, "Error creating socket\n");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen) == -1)
    {
        fprintf(stderr, "Error connecting to server\n");
        exit(EXIT_FAILURE);
    }

    // Initialize SSL
    SSL_library_init();
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();
    ctx = SSL_CTX_new(TLSv1_2_client_method());
    if (ctx == NULL)
    {
        fprintf(stderr, "Error creating SSL context\n");
        exit(EXIT_FAILURE);
    }
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) != 1)
    {
        fprintf(stderr, "Error creating SSL connection\n");
        exit(EXIT_FAILURE);
    }

    // Login
    char user[64], pass[64], command[1024], response[4096];
    printf("Enter email address: ");
    scanf("%s", user);
    printf("Enter password: ");
    scanf("%s", pass);
    sprintf(command, "LOGIN %s %s", user, pass);
    SSL_write(ssl, command, strlen(command));
    SSL_read(ssl, response, sizeof response);
    printf("%s\n", response);

    // List all the emails
    SSL_write(ssl, "LIST INBOX", strlen("LIST INBOX"));
    SSL_read(ssl, response, sizeof response);
    printf("%s\n", response);

    // Get the first email
    SSL_write(ssl, "FETCH 1 BODY[]", strlen("FETCH 1 BODY[]"));
    SSL_read(ssl, response, sizeof response);
    printf("%s\n", response);

    // Logout
    SSL_write(ssl, "LOGOUT", strlen("LOGOUT"));
    SSL_read(ssl, response, sizeof response);
    printf("%s\n", response);

    // Clean up
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    freeaddrinfo(servinfo);
    close(sockfd);

    return 0;
}