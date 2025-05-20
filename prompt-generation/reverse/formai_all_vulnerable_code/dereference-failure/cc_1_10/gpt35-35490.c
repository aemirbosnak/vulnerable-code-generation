//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
 
#define RECEIVE_BUFFER_SIZE     1024
 
void check_error_ssl(char *msg, SSL *ssl, int r);
void check_error(int r, char *msg);
void open_socket(char *hostname, int port, int *sock, struct sockaddr_in *dest);
 
int main(int argc, char *argv[]) {
    char hostname[100] = "imap.gmail.com";
    char username[100] = "example@gmail.com";
    char password[100] = "password";
    char buffer[RECEIVE_BUFFER_SIZE];
    int port = 993;
    int sock;
    struct sockaddr_in dest;
    SSL_CTX *ctx;
    SSL *ssl;
 
    // Open a socket to the IMAP server
    open_socket(hostname, port, &sock, &dest);
 
    // Initialize the SSL library
    SSL_library_init();
 
    // Create a new SSL context
    ctx = SSL_CTX_new(SSLv23_client_method());
 
    // Create a new SSL connection
    ssl = SSL_new(ctx);
 
    // Associate the SSL connection with the socket and start the SSL handshake
    SSL_set_fd(ssl, sock);
    check_error_ssl("SSL_set_fd", ssl, SSL_connect(ssl));
    printf("Connected to the IMAP server using SSL.\n");
 
    // Receive the server greeting
    check_error_ssl("RECEIVE greeting", ssl, SSL_read(ssl, buffer, RECEIVE_BUFFER_SIZE));
    printf("Received greeting: %s\n", buffer);
 
    // Login
    sprintf(buffer, "LOGIN %s %s", username, password);
    check_error_ssl("SEND LOGIN", ssl, SSL_write(ssl, buffer, strlen(buffer)));
    check_error_ssl("RECEIVE LOGIN", ssl, SSL_read(ssl, buffer, RECEIVE_BUFFER_SIZE));
    printf("Login successful: %s\n", buffer);
 
    // Logout
    check_error_ssl("SEND LOGOUT", ssl, SSL_write(ssl, "LOGOUT", 6));
    check_error_ssl("RECEIVE LOGOUT", ssl, SSL_read(ssl, buffer, RECEIVE_BUFFER_SIZE));
    printf("Logout successful: %s\n", buffer);
 
    // Close the SSL connection and the socket
    SSL_shutdown(ssl);
    close(sock);
 
    return 0;
}
 
void check_error_ssl(char *msg, SSL *ssl, int r) {
    if (r <= 0) {
        switch (SSL_get_error(ssl, r)) {
            case SSL_ERROR_ZERO_RETURN:
                printf("%s: Server closed the connection\n", msg);
                exit(1);
                break;
            case SSL_ERROR_SYSCALL:
                printf("%s: System call error\n", msg);
                exit(1);
                break;
            case SSL_ERROR_SSL:
                printf("%s: SSL protocol error\n", msg);
                exit(1);
                break;
            default:
                printf("%s: Unknown error\n", msg);
                exit(1);
        }
    }
}
 
void check_error(int r, char *msg) {
    if (r < 0) {
        fprintf(stderr, "%s: %s\n", msg, strerror(errno));
        exit(1);
    }
}
 
void open_socket(char *hostname, int port, int *sock, struct sockaddr_in *dest) {
    struct hostent *he;
 
    // Look up the hostname
    he = gethostbyname(hostname);
    if (he == NULL) {
        fprintf(stderr, "Cannot resolve hostname %s\n", hostname);
        exit(1);
    }
 
    // Create a new socket
    *sock = socket(AF_INET, SOCK_STREAM, 0);
    check_error(*sock, "Cannot create socket");
 
    // Fill in the destination IP address and port number
    dest->sin_family = AF_INET;
    dest->sin_port = htons(port);
    dest->sin_addr = *((struct in_addr *)he->h_addr);
    memset(&(dest->sin_zero), '\0', 8);
 
    // Connect to the destination
    check_error(connect(*sock, (struct sockaddr *)dest, sizeof(struct sockaddr)), "Cannot connect");
}