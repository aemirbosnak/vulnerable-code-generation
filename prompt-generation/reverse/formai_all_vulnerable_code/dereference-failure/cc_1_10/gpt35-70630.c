//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<openssl/ssl.h>
#include<openssl/err.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>

#define BUF_SIZE 1024

int main(int argc, char **argv)
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUF_SIZE];
    char username[100], password[100];

    // Check arguments
    if (argc < 3) {
       printf("Usage: %s hostname port\n", argv[0]);
       exit(EXIT_FAILURE);
    }

    // Initialize OpenSSL
    SSL_library_init();
    SSL_CTX *ctx = SSL_CTX_new(TLS_client_method());

    // Initialize socket parameters
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    // Lookup hostname
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    // Set server address parameters
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // Connect to server
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    // Initialize SSL connection on socket
    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) <= 0) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    // Read server response
    bzero(buffer,BUF_SIZE);
    n = SSL_read(ssl,buffer,BUF_SIZE-1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Authenticate with server using username and password
    printf("Enter username: ");
    fgets(username, 100, stdin);
    username[strlen(username)-1] = '\0';
    printf("Enter password: ");
    fgets(password, 100, stdin);
    password[strlen(password)-1] = '\0';

    // Send authentication information to server
    bzero(buffer, BUF_SIZE);
    snprintf(buffer, BUF_SIZE, "LOGIN %s %s", username, password);
    n = SSL_write(ssl, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(EXIT_FAILURE);
    }

    // Read server response
    bzero(buffer,BUF_SIZE);
    n = SSL_read(ssl,buffer,BUF_SIZE-1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Close SSL connection and socket
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);
    return 0;
}