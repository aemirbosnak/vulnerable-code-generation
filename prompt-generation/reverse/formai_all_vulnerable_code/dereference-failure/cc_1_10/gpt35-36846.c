//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define HOSTNAME "imap.gmail.com" // replace it with your IMAP server hostname or IP address
#define PORT "993" // standard IMAP SSL port
#define MAXLEN 1024

/**
 * Connects to the IMAP server using SSL
 * @returns SSL socket or NULL on failure
 */
SSL *ssl_connect(const char *hostname, const char *port)
{
    int status;
    struct addrinfo hints, *servinfo, *p;
    int sockfd;
    SSL_CTX *ctx;
    SSL *ssl;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((status = getaddrinfo(hostname, port, &hints, &servinfo)) != 0) 
    {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        return NULL;
    }

    // iterate through all the results and connect to the first we can
    for(p = servinfo; p != NULL; p = p->ai_next) 
    {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) 
        {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) 
        {
            close(sockfd);
            perror("connect");
            continue;
        }

        break;
    }

    if (p == NULL) 
    {
        fprintf(stderr, "failed to connect\n");
        return NULL;
    }

    freeaddrinfo(servinfo); // all done with this structure

    // initialize SSL library
    SSL_library_init();
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();

    // create SSL context
    ctx = SSL_CTX_new(TLS_client_method());
    if (!ctx) 
    {
        ERR_print_errors_fp(stderr);
        return NULL;
    }

    // set up SSL connection
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);

    // perform the SSL/TLS handshake with the server
    if (SSL_connect(ssl) != 1) 
    {
        ERR_print_errors_fp(stderr);
        return NULL;
    }

    return ssl;
}

/**
 * Sends a command to the server and reads the response
 * @returns 0 on success, -1 on failure
 */
int send_command(SSL *ssl, const char *command)
{
    char response[MAXLEN];
    int len;

    // send command
    if (SSL_write(ssl, command, strlen(command)) <= 0) 
    {
        fprintf(stderr, "send failed\n");
        return -1;
    }

    // read response
    while ((len = SSL_read(ssl, response, MAXLEN-1)) > 0) 
    {
        response[len] = '\0';
        printf("%s", response);

        // end of response
        if (response[len-1] == '\n') 
        {
            break;
        }
    }

    return 0;
}

int main()
{
    SSL *ssl;
    char command[MAXLEN];

    // connect to IMAP server
    ssl = ssl_connect(HOSTNAME, PORT);
    if (!ssl) 
    {
        fprintf(stderr, "failed to connect to server\n");
        return -1;
    }

    // read initial response
    if (send_command(ssl, "CAPABILITY\n") == -1) 
    {
        fprintf(stderr, "error reading response\n");
        SSL_shutdown(ssl);
        SSL_free(ssl);
        return -1;
    }

    // login
    printf("username: ");
    fgets(command, MAXLEN, stdin);
    printf("password: ");
    fgets(command+strlen(command), MAXLEN-strlen(command), stdin);
    snprintf(command+strlen(command), MAXLEN-strlen(command), "%s", "LOGIN\n");

    if (send_command(ssl, command) == -1) 
    {
        fprintf(stderr, "error logging in\n");
        SSL_shutdown(ssl);
        SSL_free(ssl);
        return -1;
    }

    // list mailboxes
    if (send_command(ssl, "LIST \"\" \"*\"\n") == -1) 
    {
        fprintf(stderr, "error listing mailboxes\n");
        SSL_shutdown(ssl);
        SSL_free(ssl);
        return -1;
    }

    // select mailbox
    printf("select mailbox: ");
    fgets(command, MAXLEN, stdin);
    snprintf(command+strlen(command), MAXLEN-strlen(command), "%s", "SELECT\n");

    if (send_command(ssl, command) == -1) 
    {
        fprintf(stderr, "error selecting mailbox\n");
        SSL_shutdown(ssl);
        SSL_free(ssl);
        return -1;
    }

    // search for messages
    if (send_command(ssl, "SEARCH ALL\n") == -1) 
    {
        fprintf(stderr, "error searching for messages\n");
        SSL_shutdown(ssl);
        SSL_free(ssl);
        return -1;
    }

    // logout
    if (send_command(ssl, "LOGOUT\n") == -1) 
    {
        fprintf(stderr, "error logging out\n");
        SSL_shutdown(ssl);
        SSL_free(ssl);
        return -1;
    }

    // clean up
    SSL_shutdown(ssl);
    SSL_free(ssl);

    return 0;
}