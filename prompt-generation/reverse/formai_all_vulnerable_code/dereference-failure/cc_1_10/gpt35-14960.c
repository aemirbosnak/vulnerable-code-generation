//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define MAXSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAXSIZE];
    char username[MAXSIZE], password[MAXSIZE];
    SSL_CTX *ctx;
    SSL *ssl;

    if (argc < 3) {
        fprintf(stderr,"usage: %s hostname port\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR: no such host\n");
        exit(EXIT_FAILURE);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "ERROR: cannot create socket\n");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char *)&serv_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "ERROR: cannot connect to server\n");
        exit(EXIT_FAILURE);
    }

    // initialize SSL
    SSL_library_init();
    ctx = SSL_CTX_new(TLSv1_2_client_method());
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);

    // create secure connection
    if (SSL_connect(ssl) < 0) {
        fprintf(stderr, "ERROR: cannot establish secure connection\n");
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    printf("Enter username: ");
    fgets(username, MAXSIZE, stdin);
    printf("Enter password: ");
    fgets(password, MAXSIZE, stdin);

    // send authentication credentials
    sprintf(buffer, "USER %s", username);
    SSL_write(ssl, buffer, strlen(buffer));
    memset(buffer, 0, MAXSIZE);

    sprintf(buffer, "PASS %s", password);
    SSL_write(ssl, buffer, strlen(buffer));
    memset(buffer, 0, MAXSIZE);

    // list all email messages
    SSL_write(ssl, "LIST\r\n", 6);
    memset(buffer, 0, MAXSIZE);
    SSL_read(ssl, buffer, MAXSIZE);
    printf("%s\n", buffer);

    // retrieve first email message
    sprintf(buffer, "RETR %d\r\n", 1);
    SSL_write(ssl, buffer, strlen(buffer));
    memset(buffer, 0, MAXSIZE);
    SSL_read(ssl, buffer, MAXSIZE);
    printf("%s\n", buffer);

    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);
    return 0;
}