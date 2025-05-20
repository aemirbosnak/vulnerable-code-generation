//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: protected
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFER_SIZE 1024 // Maximum buffer size for message

// Define the server and port
#define SERVER "imap.example.com"
#define PORT "993"

int main(int argc, char **argv) {

    // Check that the correct number of command line arguments have been provided
    if(argc != 3) {
        printf("Usage: %s <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Retrieve command line arguments
    char *username = argv[1];
    char *password = argv[2];

    // Initialize SSL library
    SSL_library_init();

    // Create SSL context
    SSL_CTX *sslcontext = SSL_CTX_new(TLS_client_method());

    if(!sslcontext) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    // Check for valid SSL context
    if(SSL_CTX_set_default_verify_paths(sslcontext) != 1) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Retrieve server IP address
    struct hostent *he = gethostbyname(SERVER);

    // Check for valid server IP address
    if(!he) {
        fprintf(stderr, "Error: Could not resolve %s\n", SERVER);
        exit(EXIT_FAILURE);
    }

    // Initialize server address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = ((struct in_addr *)(he->h_addr))->s_addr;
    server_address.sin_port = htons(atoi(PORT));

    // Connect to server
    if(connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address))) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Attach SSL socket to file descriptor
    SSL *sslsocket = SSL_new(sslcontext);
    SSL_set_fd(sslsocket, sockfd);

    // Establish SSL connection to server
    if(SSL_connect(sslsocket) != 1) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    // Send login details to server
    char buffer[BUFFER_SIZE] = "";
    sprintf(buffer, "LOGIN %s %s\n", username, password);

    if(SSL_write(sslsocket, buffer, strlen(buffer)) <= 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Read server response
    int bytes_received = SSL_read(sslsocket, buffer, BUFFER_SIZE);

    if(bytes_received <= 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Close SSL socket and context
    SSL_shutdown(sslsocket);
    SSL_free(sslsocket);
    SSL_CTX_free(sslcontext);

    // Close socket
    close(sockfd);

    return 0;
}