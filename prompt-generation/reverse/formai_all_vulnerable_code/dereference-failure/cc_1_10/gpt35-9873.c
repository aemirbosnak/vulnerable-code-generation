//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAXLINE 4096

void err_quit(const char *message)
{
    printf("%s", message);
    exit(1);
}

int OpenConnection(const char *hostname, int port)
{
    int sockfd;
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        err_quit("Failed to create socket.\n");

    /* Get host IP address */
    struct hostent *he;
    if((he = gethostbyname(hostname)) == NULL)
        err_quit("Failed to get host by name.\n");

    /* Initialize server address */
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    memcpy(&servaddr.sin_addr, he->h_addr_list[0], he->h_length);

    /* Connect to server */
    if(connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0)
        err_quit("Failed to connect.\n");

    return sockfd;
}

int main(int argc, char **argv)
{
    int sockfd, n;
    char recvline[MAXLINE + 1];
    SSL_CTX *ctx;
    SSL *ssl;

    /* Create SSL Context */
    SSL_library_init();
    ctx = SSL_CTX_new(SSLv23_client_method());

    /* Load Trusted CA Certificates */
    if(!SSL_CTX_load_verify_locations(ctx, "/etc/ssl/certs/ca-bundle.crt", NULL))
        err_quit("Failed to load CA certificates.\n");

    /* Connect to IMAP Server */
    sockfd = OpenConnection("imap.gmail.com", 993);

    /* Create SSL Connection */
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);

    /* Handshake */
    if(SSL_connect(ssl) == -1)
        err_quit("SSL handshake failed.\n");
    else
        printf("SSL Handshake successful.\n");

    /* Login */
    SSL_write(ssl, "1 LOGIN username password\r\n", strlen("1 LOGIN username password\r\n"));
    n = SSL_read(ssl, recvline, MAXLINE);
    recvline[n] = '\0';
    printf("%s", recvline);

    /* Logout */
    SSL_write(ssl, "1 LOGOUT\r\n", strlen("1 LOGOUT\r\n"));
    n = SSL_read(ssl, recvline, MAXLINE);
    recvline[n] = '\0';
    printf("%s", recvline);

    /* Shutdown SSL */
    SSL_shutdown(ssl);
    SSL_free(ssl);

    /* Clean Up */
    SSL_CTX_free(ctx);
    close(sockfd);

    return 0;
}