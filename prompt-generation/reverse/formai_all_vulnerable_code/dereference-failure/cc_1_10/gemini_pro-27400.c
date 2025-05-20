//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>
#include <unistd.h>
#include <openssl/ssl.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd;
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in server_addr;
    struct hostent *server;
    SSL_CTX *ctx;
    SSL *ssl;

    if (argc < 3)
    {
        printf("Usage: %s hostname port\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the hostname and port from the command line arguments
    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Initialize the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Initialize the server address
    server = gethostbyname(hostname);
    if (server == NULL)
    {
        perror("gethostbyname");
        return EXIT_FAILURE;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Initialize the SSL library
    SSL_library_init();

    // Create a new SSL context
    ctx = SSL_CTX_new(TLSv1_2_client_method());
    if (ctx == NULL)
    {
        perror("SSL_CTX_new");
        return EXIT_FAILURE;
    }

    // Create a new SSL object
    ssl = SSL_new(ctx);
    if (ssl == NULL)
    {
        perror("SSL_new");
        return EXIT_FAILURE;
    }

    // Set the file descriptor for the SSL object
    SSL_set_fd(ssl, sockfd);

    // Perform the SSL handshake
    if (SSL_connect(ssl) != 1)
    {
        perror("SSL_connect");
        return EXIT_FAILURE;
    }

    // Send the IMAP command to the server
    char *command = "CAPABILITY\r\n";
    int len = strlen(command);
    if (SSL_write(ssl, command, len) != len)
    {
        perror("SSL_write");
        return EXIT_FAILURE;
    }

    // Read the response from the server
    int bytes_read = SSL_read(ssl, buffer, MAX_BUFFER_SIZE);
    if (bytes_read < 0)
    {
        perror("SSL_read");
        return EXIT_FAILURE;
    }

    // Print the response to the console
    printf("%s", buffer);

    // Close the SSL object
    SSL_free(ssl);

    // Close the SSL context
    SSL_CTX_free(ctx);

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}