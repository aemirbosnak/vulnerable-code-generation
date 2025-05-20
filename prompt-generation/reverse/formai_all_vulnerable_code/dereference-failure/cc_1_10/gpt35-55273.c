//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <unistd.h>

#define MAXSIZE 1024

char* receive_server_response(SSL* ssl_client){
    char response[MAXSIZE] = {0};
    char* server_response = NULL;
    int bytes_received = 0;
    bytes_received = SSL_read(ssl_client, response, sizeof(response));

    if (bytes_received > 0){
        server_response = (char*) malloc(bytes_received+1);
        strncpy(server_response, response, bytes_received);
        server_response[bytes_received] = '\0';
    }
    return server_response;
}

SSL *ssl_setup(SSL_CTX *ctx, int sockfd) {
    SSL *ssl;
    ssl = SSL_new(ctx);      /* create new SSL connection state */
    SSL_set_fd(ssl, sockfd);    /* attach the socket descriptor */
    if (SSL_connect(ssl) == -1)   /* perform the connection */
        ERR_print_errors_fp(stderr);
    else
        printf("Connected with %s encryption\n", SSL_get_cipher(ssl));
    return ssl;
}

int main() {

    // initialize variables
    int port = 993;
    char *server_name = "imap.gmail.com";
    char *user = "example@gmail.com";
    char *password = "password";
    char *command = NULL;
    char *response = NULL;
    char buffer[MAXSIZE] = {0};
    int sockfd;
    struct hostent *he;
    struct sockaddr_in server_addr;
    SSL_CTX *ctx;
    SSL *ssl_client;

    // create socket
    if ((he = gethostbyname(server_name)) == NULL) {
        perror("Failed to resolve server name");
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Failed to create socket");
        exit(1);
    }

    // set up server address
    memset(&server_addr, 0, sizeof(server_addr)); /* Zero out structure */
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *((struct in_addr *) he->h_addr);

    // connect to server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Failed to connect to server");
        exit(1);
    }

    // initilize SSL library
    SSL_library_init();

    // create SSL context
    ctx = SSL_CTX_new(TLSv1_2_client_method());

    // create SSL connection
    ssl_client = ssl_setup(ctx, sockfd);

    // authenticate with server
    response = receive_server_response(ssl_client);
    printf("%s\n", response);
    free(response);

    // log in with user credentials
    command = "a001 LOGIN ";
    strcat(buffer, command);
    strcat(buffer, user);
    strcat(buffer, " ");
    strcat(buffer, password);
    strcat(buffer, "\r\n");

    SSL_write(ssl_client, buffer, strlen(buffer));

    response = receive_server_response(ssl_client);
    printf("%s\n", response);
    free(response);

    // select mailbox to access
    command = "a002 SELECT INBOX\r\n";
    SSL_write(ssl_client, command, strlen(command));

    response = receive_server_response(ssl_client);
    printf("%s\n", response);
    free(response);

    // search through mailbox for specific emails
    command = "a003 SEARCH SUBJECT \"Hello, World!\" UNSEEN\r\n";
    SSL_write(ssl_client, command, strlen(command));

    response = receive_server_response(ssl_client);
    printf("%s\n", response);
    free(response);

    // close the SSL connection
    SSL_shutdown(ssl_client);
    SSL_free(ssl_client);
    SSL_CTX_free(ctx);
    close(sockfd);

    return 0;
}