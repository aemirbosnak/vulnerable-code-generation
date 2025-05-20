//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define MAX_BUF_SIZE 4096

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    char buffer[MAX_BUF_SIZE];

    struct hostent *server;
    struct sockaddr_in serv_addr;

    SSL_CTX *ctx;
    SSL *ssl;

    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    SSL_load_error_strings();
    SSL_library_init();

    ctx = SSL_CTX_new(SSLv23_client_method());
    if (!ctx) {
        perror("ERROR initializing SSL context");
        exit(1);
    }

    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);

    if (SSL_connect(ssl) == -1) {
        perror("ERROR connecting SSL");
        exit(1);
    }

    char req[MAX_BUF_SIZE];
    sprintf(req, "GET / HTTP/1.1\r\nHost: %s\r\nUser-Agent: curl/7.64.1\r\nAccept: */*\r\n\r\n", argv[1]);
    if (SSL_write(ssl, req, strlen(req)) == -1) {
        perror("ERROR writing to socket");
        exit(1);
    }

    memset(buffer, 0, MAX_BUF_SIZE);
    while ((n = SSL_read(ssl, buffer, MAX_BUF_SIZE - 1)) > 0) {
        printf("%s", buffer);
        memset(buffer, 0, MAX_BUF_SIZE);
    }
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);

    return 0;
}