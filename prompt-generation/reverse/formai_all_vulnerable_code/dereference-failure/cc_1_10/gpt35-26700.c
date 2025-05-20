//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFER_SIZE 1024

// Function to connect to the IMAP server using SSL
int connect_ssl(char* server, char* port) {
    SSL_CTX* sslctx;
    SSL* ssl;
    struct addrinfo* servinfo;
    int sockfd;

    // Initialize OpenSSL library
    SSL_library_init();
    SSL_load_error_strings();
    sslctx = SSL_CTX_new(TLS_client_method());

    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Get server information
    getaddrinfo(server, port, NULL, &servinfo);

    // Connect to the server
    connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen);

    // Establish SSL connection
    ssl = SSL_new(sslctx);
    SSL_set_fd(ssl, sockfd);
    SSL_connect(ssl);

    return sockfd;
}

// Function to send a command to the IMAP server
void send_command(int sockfd, char* command) {
    // Send command to server
    write(sockfd, command, strlen(command));
    printf(">>> %s", command);

    // Wait for response from server
    char buffer[BUFFER_SIZE];
    int received;
    do {
        received = read(sockfd, buffer, BUFFER_SIZE);
        buffer[received] = '\0';
        printf("%s", buffer);
    } while (received > 0 && buffer[strlen(buffer)-1] != '\n');
}

int main(int argc, char** argv) {
    if (argc != 4) {
        printf("Usage: %s <server> <port> <username>\n", argv[0]);
        return 1;
    }

    char* server = argv[1];
    char* port = argv[2];
    char* username = argv[3];

    // Connect to server using SSL
    int sockfd = connect_ssl(server, port);

    // Send login command and print response
    char login_command[BUFFER_SIZE];
    sprintf(login_command, "a LOGIN %s \"\"\n", username);
    send_command(sockfd, login_command);

    // Send select command for the inbox folder and print response
    char select_command[] = "b SELECT INBOX\n";
    send_command(sockfd, select_command);

    // Send logout command and print response
    char logout_command[] = "c LOGOUT\n";
    send_command(sockfd, logout_command);

    // Close socket
    close(sockfd);

    return 0;
}