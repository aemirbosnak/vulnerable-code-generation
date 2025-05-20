//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUF_SIZE 1024
#define HOSTNAME "imap.example.com"
#define USERNAME "exampleuser"
#define PASSWORD "examplepassword"

int main(int argc, char *argv[]) {
    // Initialize OpenSSL library
    SSL_library_init();
    SSL_load_error_strings();
    ERR_load_BIO_strings();
    OpenSSL_add_all_algorithms();
    
    // Resolve hostname to IP address
    struct hostent *server = gethostbyname(HOSTNAME);
    if (server == NULL) {
        fprintf(stderr, "Error: Unable to resolve hostname\n");
        return 1;
    }
    char ip[INET6_ADDRSTRLEN];
    inet_ntop(AF_INET, server->h_addr, ip, INET6_ADDRSTRLEN);
    
    // Create TCP socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error opening network socket");
        return 1;
    }
    
    // Connect to IMAP server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(993);
    inet_pton(AF_INET, ip, &server_addr.sin_addr);
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Error connecting to server");
        return 1;
    }
    
    // Initialize SSL context and setup SSL connection
    SSL_CTX* ssl_ctx = SSL_CTX_new(TLS_client_method());
    if (ssl_ctx == NULL) {
        fprintf(stderr, "Error creating SSL context");
        return 1;
    }
    SSL* ssl = SSL_new(ssl_ctx);
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) != 1) {
        fprintf(stderr, "Error establishing SSL connection");
        return 1;
    }
    
    // Login to IMAP server
    char buf[BUF_SIZE];
    SSL_read(ssl, buf, BUF_SIZE);
    fprintf(stdout, "Server: %s", buf);
    memset(buf, 0, BUF_SIZE);
    sprintf(buf, "a001 LOGIN %s %s\n", USERNAME, PASSWORD);
    SSL_write(ssl, buf, strlen(buf));
    SSL_read(ssl, buf, BUF_SIZE);
    fprintf(stdout, "Server: %s", buf);
    memset(buf, 0, BUF_SIZE);
    
    // List available mailboxes
    sprintf(buf, "a002 LIST \"\" *\n");
    SSL_write(ssl, buf, strlen(buf));
    SSL_read(ssl, buf, BUF_SIZE);
    fprintf(stdout, "Server: %s", buf);
    memset(buf, 0, BUF_SIZE);
    
    // Select inbox mailbox
    sprintf(buf, "a003 SELECT INBOX\n");
    SSL_write(ssl, buf, strlen(buf));
    SSL_read(ssl, buf, BUF_SIZE);
    fprintf(stdout, "Server: %s", buf);
    memset(buf, 0, BUF_SIZE);
    
    // Close connection
    SSL_write(ssl, "a004 LOGOUT\n", strlen("a004 LOGOUT\n"));
    SSL_read(ssl, buf, BUF_SIZE);
    fprintf(stdout, "Server: %s", buf);
    SSL_shutdown(ssl);
    
    // Cleanup
    SSL_free(ssl);
    SSL_CTX_free(ssl_ctx);
    close(sockfd);

    return 0;
}