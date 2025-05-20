//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define MAX_BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    // Check if user has entered all command line arguments
    if (argc < 4) {
        printf("USAGE: %s IMAP_SERVER PORT USERNAME PASSWORD\n", argv[0]);
        exit(1);
    }

    // Define variables
    int sock;
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in server;
    struct hostent *host;
    SSL_CTX *ctx;
    SSL *ssl;

    // Initialize SSL
    SSL_library_init();
    ctx = SSL_CTX_new(TLSv1_2_client_method());

    // Set up TCP socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Get host
    host = gethostbyname(argv[1]);
    if (host == NULL) {
        perror("ERROR getting host");
        exit(1);
    }

    // Set up server address
    memset((char *) &server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    memcpy(&server.sin_addr.s_addr, host->h_addr, host->h_length);

    // Connect to the server
    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Initialize SSL connection
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock);
    if (SSL_connect(ssl) != 1) {
        perror("ERROR SSL connection");
        exit(1);
    }

    // Send login command
    char login_command[MAX_BUFFER_SIZE];
    sprintf(login_command, "LOGIN %s %s", argv[3], argv[4]);
    SSL_write(ssl, login_command, strlen(login_command));

    // Read response
    int read_size = SSL_read(ssl, buffer, MAX_BUFFER_SIZE);
    buffer[read_size] = '\0';
    printf("%s\n", buffer);

    // Close connection
    SSL_shutdown(ssl);
    close(sock);
    SSL_free(ssl);
    SSL_CTX_free(ctx);

    return 0;
}