//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/crypto.h>
#include <openssl/x509.h>
#include <openssl/pem.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    int ret, sock_fd;
    char buffer[MAX_BUFFER_SIZE] = {0};
    struct sockaddr_in server_addr;
    struct hostent *host;
    SSL_CTX *ctx;
    SSL *ssl;
    
    // Create SSL context
    SSL_library_init();
    ctx = SSL_CTX_new(SSLv23_client_method());
    
    // Load trust store
    if(!SSL_CTX_load_verify_locations(ctx, "cacert.pem", NULL)) {
        printf("Error Loading trust-store\n");
        exit(1);
    }
    
    // Create socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_fd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set server details
    host = gethostbyname("imap.gmail.com");
    if(!host) {
        printf("Error resolving hostname\n");
        exit(1);
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(993);
    server_addr.sin_addr = *((struct in_addr *)host->h_addr);
    memset(&(server_addr.sin_zero), '\0', 8);

    // Connect to server
    ret = connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr));
    if(ret < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }
    
    // Create SSL connection
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock_fd);
    ret = SSL_connect(ssl);
    if(ret != 1) {
        printf("Error creating SSL connection\n");
        exit(1);
    }
    
    // Login
    SSL_write(ssl, "a001 LOGIN user@example.com password\n", strlen("a001 LOGIN user@example.com password\n"));
    SSL_read(ssl, buffer, MAX_BUFFER_SIZE);
    printf("%s", buffer);
    
    // Select inbox
    SSL_write(ssl, "a002 SELECT INBOX\n", strlen("a002 SELECT INBOX\n"));
    SSL_read(ssl, buffer, MAX_BUFFER_SIZE);
    printf("%s", buffer);
    
    // Logout
    SSL_write(ssl, "a003 LOGOUT\n", strlen("a003 LOGOUT\n"));
    SSL_read(ssl, buffer, MAX_BUFFER_SIZE);
    printf("%s", buffer);
    
    // Close connection
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sock_fd);
    
    return 0;
}