//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define IMAP_PORT 993

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];
    if (argc < 2) {
        fprintf(stderr,"usage %s hostname\n", argv[0]);
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);
    serv_addr.sin_port = htons(IMAP_PORT);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    SSL_library_init();
    SSL_CTX *ssl_ctx = SSL_CTX_new(SSLv23_client_method());
    SSL *ssl_conn = SSL_new(ssl_ctx);
    SSL_set_fd(ssl_conn, sockfd);
    int ssl_err = SSL_connect(ssl_conn);
    if (ssl_err <= 0) {
        fprintf(stderr, "SSL Connection error: %d\n", ssl_err);
        ERR_print_errors_fp(stderr);
    }

    n = read(sockfd, buffer, 255);
    if (n < 0)
        error("ERROR reading from socket");
    buffer[n] = '\0';
    printf("%s", buffer);

    printf("Enter username: ");
    bzero(buffer, 256);
    fgets(buffer, 255, stdin);

    char tag[5];
    memset(tag, 0, sizeof(tag));
    sprintf(tag, "A01");
    char cmd[64];
    memset(cmd, 0, sizeof(cmd));
    sprintf(cmd, "%s LOGIN %s password\n", tag, buffer);
    n = SSL_write(ssl_conn, cmd, strlen(cmd));
    if (n < 0)
        error("ERROR writing to socket");
    printf("%s", buffer);

    n = SSL_read(ssl_conn, buffer, sizeof(buffer) - 1);
    buffer[n] = '\0';
    printf("%s", buffer);

    sprintf(cmd, "%s LOGOUT\n", tag);
    n = SSL_write(ssl_conn, cmd, strlen(cmd));
    if (n < 0)
        error("ERROR writing to socket");

    SSL_free(ssl_conn);
    SSL_CTX_free(ssl_ctx);
    close(sockfd);
    return 0;
}