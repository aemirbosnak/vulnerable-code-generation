//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define MAX_BUFF 1024
#define IMAP_PORT 143

int main(int argc, char *argv[]) 
{
    if (argc < 4) {
        printf("Usage: %s server username password\n", argv[0]);
        exit(1);
    }
    
    int sock_fd;
    struct sockaddr_in server_addr;
    struct hostent *server;
    SSL_CTX *ssl_ctx;
    SSL *ssl;
    char buff[MAX_BUFF];
    
    //Creating a TCP Socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    //Resolving server IP address
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }
    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&server_addr.sin_addr.s_addr,
         server->h_length);
    server_addr.sin_port = htons(IMAP_PORT);

    //Connecting to the server
    if (connect(sock_fd,(struct sockaddr *)&server_addr,sizeof(server_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    //Initialize SSL library   
    SSL_library_init();
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();
    ssl_ctx = SSL_CTX_new(TLSv1_2_client_method());
    if (!ssl_ctx) {
        printf("ERROR: Unable to create SSL context\n");
        exit(1);
    }

    //Create an SSL socket object
    ssl = SSL_new(ssl_ctx);
    if (!ssl) {
        printf("ERROR: Unable to create SSL socket\n");
        exit(1);
    }

    //Attach the socket to the SSL descriptor
    SSL_set_fd(ssl, sock_fd);

    //Handshake with the server
    if (SSL_connect(ssl) <= 0) {
        printf("ERROR: Unable to establish SSL connection\n");
        exit(1);
    }

    //Clear the input buffer
    bzero(buff, MAX_BUFF);

    //Read the welcome message from the server
    SSL_read(ssl, buff, MAX_BUFF);
    printf("%s", buff);

    //Authenticate with username and password
    snprintf(buff, MAX_BUFF, ". login %s %s\n", argv[2], argv[3]);
    SSL_write(ssl, buff, strlen(buff));
    bzero(buff, MAX_BUFF);
    SSL_read(ssl, buff, MAX_BUFF);
    printf("%s", buff);
    
    //Display the number of messages in the inbox
    SSL_write(ssl, ". STATUS INBOX (messages)\n", 27);
    bzero(buff, MAX_BUFF);
    SSL_read(ssl, buff, MAX_BUFF);
    printf("%s", buff);

    //Logout and close the SSL socket
    SSL_write(ssl, ". logout\n", 9);
    SSL_shutdown(ssl);  
    SSL_free(ssl);
    SSL_CTX_free(ssl_ctx);
    
    //Close the TCP socket
    close(sock_fd);

    return 0;
}