//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define MAX_SIZE 1024

int main(int argc, char **argv) {

    SSL_CTX *ctx;
    SSL *ssl;
    int sockfd, port;
    char buffer[MAX_SIZE];

    if(argc != 4) {
        printf("Usage: %s <hostname> <port> <username>\n", argv[0]);
        exit(1);
    }

    //get port from command line argument
    port = atoi(argv[2]);

    //create socket
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    //get host from command line argument
    struct hostent *host = gethostbyname(argv[1]);

    //create address structure
    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);
    serveraddr.sin_addr = *((struct in_addr *)host->h_addr);
    memset(&(serveraddr.sin_zero), '\0', 8);

    //connect to server
    if(connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        printf("Error connecting to server: %s\n", strerror(errno));
        exit(1);
    }

    //initialize SSL
    SSL_library_init();
    SSL_load_error_strings();
    OpenSSL_add_all_algorithms();

    //create context
    ctx = SSL_CTX_new(TLSv1_2_client_method());

    //create SSL object
    ssl = SSL_new(ctx);

    //attach SSL object to socket
    SSL_set_fd(ssl, sockfd);

    //establish SSL connection
    if(SSL_connect(ssl) == -1) {
        printf("Error connecting using SSL: %s\n", strerror(errno));
        exit(1);
    }

    //send start command
    sprintf(buffer, "a001 LOGIN %s\r\n", argv[3]);
    SSL_write(ssl, buffer, strlen(buffer));

    //receive response
    SSL_read(ssl, buffer, MAX_SIZE);

    //print response
    printf("%s", buffer);

    //send select command
    sprintf(buffer, "a002 SELECT INBOX\r\n");
    SSL_write(ssl, buffer, strlen(buffer));

    //receive response
    SSL_read(ssl, buffer, MAX_SIZE);

    //print response
    printf("%s", buffer);

    //send search command
    sprintf(buffer, "a003 SEARCH ALL\r\n");
    SSL_write(ssl, buffer, strlen(buffer));

    //receive response
    SSL_read(ssl, buffer, MAX_SIZE);

    //print response
    printf("%s", buffer);

    //send logout command
    sprintf(buffer, "a004 LOGOUT\r\n");
    SSL_write(ssl, buffer, strlen(buffer));

    //receive response
    SSL_read(ssl, buffer, MAX_SIZE);

    //print response
    printf("%s", buffer);

    //shutdown SSL
    SSL_shutdown(ssl);

    //free SSL object
    SSL_free(ssl);

    //free context
    SSL_CTX_free(ctx);

    //close socket
    close(sockfd);

    return 0;
}