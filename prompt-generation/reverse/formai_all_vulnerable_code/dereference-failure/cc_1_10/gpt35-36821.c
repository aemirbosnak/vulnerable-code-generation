//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/x509v3.h>

// Define constants
#define SERVER_NAME "imap.gmail.com"
#define SERVER_PORT 993
#define BUFFER_SIZE 1024

// Declare functions
int openConnection(char* serverName, int serverPort);
SSL* sslConnect(int socket);
void sslDisconnect(SSL* ssl);
void closeConnection(int socket);

int main() {
    // Open a connection to the IMAP server
    int socketFd = openConnection(SERVER_NAME, SERVER_PORT);
    // Establish an SSL connection
    SSL* ssl = sslConnect(socketFd);
    
    // Send a login command
    char command[BUFFER_SIZE];
    sprintf(command, "A1 LOGIN username@gmail.com password\n");
    SSL_write(ssl, command, strlen(command));
    
    // Receive the response
    char response[BUFFER_SIZE];
    SSL_read(ssl, response, sizeof(response));
    printf("%s", response);
    
    // Send a select command
    sprintf(command, "A2 SELECT INBOX\n");
    SSL_write(ssl, command, strlen(command));
    
    // Receive the response
    SSL_read(ssl, response, sizeof(response));
    printf("%s", response);
    
    // Send a logout command
    sprintf(command, "A3 LOGOUT\n");
    SSL_write(ssl, command, strlen(command));
    
    // Receive the response
    SSL_read(ssl, response, sizeof(response));
    printf("%s", response);
    
    // Close the SSL connection and socket
    sslDisconnect(ssl);
    closeConnection(socketFd);
    
    return 0;
}

// Open a connection to the IMAP server
int openConnection(char* serverName, int serverPort) {
    // Obtain the server's IP address
    struct hostent* server = gethostbyname(serverName);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host\n");
        exit(EXIT_FAILURE);
    }
    
    // Create a socket
    int socketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFd < 0) {
        fprintf(stderr, "Error: unable to create socket\n");
        exit(EXIT_FAILURE);
    }

    // Define the server address
    struct sockaddr_in serverAddress;
    bzero(&serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    bcopy(server->h_addr, &serverAddress.sin_addr.s_addr, server->h_length);
    serverAddress.sin_port = htons(serverPort);

    // Connect to the server
    if (connect(socketFd, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        fprintf(stderr, "Error: unable to connect to server\n");
        exit(EXIT_FAILURE);
    }
    
    return socketFd;
}

// Establish an SSL connection
SSL* sslConnect(int socket) {
    SSL_library_init();
    SSL_load_error_strings();
    OpenSSL_add_all_algorithms();
    SSL_CTX* sslContext = SSL_CTX_new(SSLv23_client_method());
    SSL* ssl = SSL_new(sslContext);
    SSL_set_fd(ssl, socket);
    if (SSL_connect(ssl) == -1) {
        fprintf(stderr, "Error: unable to establish SSL connection\n");
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
    X509* serverCertificate = SSL_get_peer_certificate(ssl);
    if (serverCertificate != NULL) {
        X509_free(serverCertificate);
    }
    return ssl;
}

// Disconnect an SSL connection
void sslDisconnect(SSL* ssl) {
    SSL_shutdown(ssl);
    SSL_free(ssl);
}

// Close a socket connection
void closeConnection(int socket) {
    close(socket);
}