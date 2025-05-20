//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define MAX_MSG_LENGTH 1024
#define MAX_BUFFER_SIZE 4096

int main(int argc, char **argv){
    // Set up socket connection
    int sockfd;
    char buffer[MAX_BUFFER_SIZE], msg[MAX_MSG_LENGTH];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(argv[1]);
    if(server == NULL){
        perror("Error finding hostname");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, '\0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(110);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if(connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0){
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    // Send authentication credentials
    read(sockfd, buffer, MAX_BUFFER_SIZE);
    printf("%s\n", buffer);
    snprintf(msg, MAX_MSG_LENGTH, "USER %s\r\n", argv[2]);
    write(sockfd, msg, strlen(msg));
    read(sockfd, buffer, MAX_BUFFER_SIZE);
    printf("%s\n", buffer);
    snprintf(msg, MAX_MSG_LENGTH, "PASS %s\r\n", argv[3]);
    write(sockfd, msg, strlen(msg));
    read(sockfd, buffer, MAX_BUFFER_SIZE);
    printf("%s\n", buffer);

    // Enable SSL encryption
    SSL_library_init();
    SSL_CTX *ctx = SSL_CTX_new(SSLv23_client_method());
    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    if(SSL_connect(ssl) == -1){
        perror("SSL connection failed");
        exit(EXIT_FAILURE);
    }

    // Retrieve emails
    char *cmd = "RETR 1\r\n";
    write(sockfd, cmd, strlen(cmd));
    read(sockfd, buffer, MAX_BUFFER_SIZE);
    printf("%s\n", buffer);
    SSL_read(ssl, buffer, MAX_BUFFER_SIZE);
    printf("%s\n", buffer);

    // Disconnect
    cmd = "QUIT\r\n";
    write(sockfd, cmd, strlen(cmd));
    read(sockfd, buffer, MAX_BUFFER_SIZE);
    printf("%s\n", buffer);
    SSL_shutdown(ssl);
    close(sockfd);

    return 0;
}