//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define MAX_SIZE 1024

void display_error(char *err){
    fprintf(stderr, "%s\n", err);
    exit(1);
}

int main(int argc, char **argv){
    int port, sockfd;
    char buffer[MAX_SIZE];
    char *username, *password, *hostname;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    SSL_CTX *ssl_ctx;
    SSL *ssl;
    int bytes_received;
    if(argc < 4){
        fprintf(stderr, "Insufficient arguments provided. Please specify usage: %s <username> <password> <hostname> <optional port>\n", argv[0]);
        exit(1);
    }
    username = argv[1];
    password = argv[2];
    hostname = argv[3];
    port = argc == 5 ? atoi(argv[4]) : 993; // default port for imap protocol is 993

    // Creating a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        display_error("ERROR: Unable to create socket.");
    }

    // Getting the target server information
    server = gethostbyname(hostname);
    if(server == NULL){
        display_error("ERROR: Unable to resolve hostname.");
    }

    // Connect to the server
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);
    if(connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
        display_error("ERROR: Connection failed.");
    }

    // Initialize OpenSSL library
    SSL_load_error_strings();
    SSL_library_init();
    ssl_ctx = SSL_CTX_new(TLSv1_2_client_method());
    if(!ssl_ctx){
        display_error("ERROR: SSL context creation failed.");
    }

    // Create SSL session
    ssl = SSL_new(ssl_ctx);
    SSL_set_fd(ssl, sockfd);
    if (!SSL_connect(ssl)){
        display_error("ERROR: SSL connection failed.");
    }

    // Login with credentials
    sprintf(buffer, ". login %s %s\n", username, password);
    SSL_write(ssl, buffer, strlen(buffer));

    // List all mailboxes
    sprintf(buffer, ". list \"\" \"*\"\n");
    SSL_write(ssl, buffer, strlen(buffer));
    bzero(buffer, MAX_SIZE);
    bytes_received = SSL_read(ssl, buffer, MAX_SIZE-1);
    printf("Mailboxes:\n%s\n", buffer);

    // Select mailbox to fetch messages from
    sprintf(buffer, ". select inbox\n");
    SSL_write(ssl, buffer, strlen(buffer));
    bzero(buffer, MAX_SIZE);
    bytes_received = SSL_read(ssl, buffer, MAX_SIZE-1);
    printf("Messages in Inbox:\n%s\n", buffer);

    // Logout
    sprintf(buffer, ". logout\n");
    SSL_write(ssl, buffer, strlen(buffer));

    // Close the SSL connection and socket
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ssl_ctx);
    close(sockfd);

    return 0;
}