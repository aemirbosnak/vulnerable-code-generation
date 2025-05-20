//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define PORT 993
#define BUFFSIZE 1024

struct client_info {
    int sockfd;
    SSL *ssl;
    char *username;
    char *password;
    char *mailbox;
};

int connect_to_server(char *hostname, int port) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host_info;

    // Get the host information
    host_info = gethostbyname(hostname);
    if (host_info == NULL) {
        fprintf(stderr, "Error: Could not resolve hostname %s\n", hostname);
        return -1;
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error: Could not create socket");
        return -1;
    }

    // Set the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *(struct in_addr *)host_info->h_addr;

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error: Could not connect to server");
        return -1;
    }

    return sockfd;
}

SSL *create_ssl_context(int sockfd) {
    SSL_CTX *ctx;
    SSL *ssl;

    // Initialize the SSL library
    SSL_library_init();
    SSL_load_error_strings();

    // Create a new SSL context
    ctx = SSL_CTX_new(TLS_client_method());
    if (ctx == NULL) {
        fprintf(stderr, "Error: Could not create SSL context\n");
        return NULL;
    }

    // Create a new SSL object
    ssl = SSL_new(ctx);
    if (ssl == NULL) {
        fprintf(stderr, "Error: Could not create SSL object\n");
        return NULL;
    }

    // Set the socket to use for the SSL connection
    if (SSL_set_fd(ssl, sockfd) == 0) {
        fprintf(stderr, "Error: Could not set SSL socket\n");
        return NULL;
    }

    // Perform the SSL handshake
    if (SSL_connect(ssl) != 1) {
        fprintf(stderr, "Error: Could not perform SSL handshake\n");
        return NULL;
    }

    return ssl;
}

void *client_thread(void *arg) {
    struct client_info *client = (struct client_info *)arg;
    char buff[BUFFSIZE];
    int len;

    // Send the login command
    sprintf(buff, "LOGIN %s %s", client->username, client->password);
    len = strlen(buff);
    if (SSL_write(client->ssl, buff, len) != len) {
        fprintf(stderr, "Error: Could not send login command\n");
        goto cleanup;
    }

    // Receive the login response
    len = SSL_read(client->ssl, buff, BUFFSIZE);
    if (len < 0) {
        fprintf(stderr, "Error: Could not receive login response\n");
        goto cleanup;
    }

    // Check if the login was successful
    if (strncmp(buff, "+OK LOGIN", 9) != 0) {
        fprintf(stderr, "Error: Login failed\n");
        goto cleanup;
    }

    // Send the SELECT command
    sprintf(buff, "SELECT %s", client->mailbox);
    len = strlen(buff);
    if (SSL_write(client->ssl, buff, len) != len) {
        fprintf(stderr, "Error: Could not send select command\n");
        goto cleanup;
    }

    // Receive the SELECT response
    len = SSL_read(client->ssl, buff, BUFFSIZE);
    if (len < 0) {
        fprintf(stderr, "Error: Could not receive select response\n");
        goto cleanup;
    }

    // Check if the SELECT was successful
    if (strncmp(buff, "+OK SELECT", 10) != 0) {
        fprintf(stderr, "Error: SELECT failed\n");
        goto cleanup;
    }

    // Send the SEARCH command
    sprintf(buff, "SEARCH UNSEEN");
    len = strlen(buff);
    if (SSL_write(client->ssl, buff, len) != len) {
        fprintf(stderr, "Error: Could not send search command\n");
        goto cleanup;
    }

    // Receive the SEARCH response
    len = SSL_read(client->ssl, buff, BUFFSIZE);
    if (len < 0) {
        fprintf(stderr, "Error: Could not receive search response\n");
        goto cleanup;
    }

    // Print the search results
    printf("%s", buff);

cleanup:
    // Close the SSL connection
    SSL_shutdown(client->ssl);
    SSL_free(client->ssl);

    // Close the socket
    close(client->sockfd);

    // Free the client info
    free(client->username);
    free(client->password);
    free(client->mailbox);
    free(client);

    return NULL;
}

int main(int argc, char **argv) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password> <mailbox>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    char *username = argv[2];
    char *password = argv[3];
    char *mailbox = argv[4];

    // Create the client info
    struct client_info *client = malloc(sizeof(struct client_info));
    client->sockfd = connect_to_server(hostname, PORT);
    client->ssl = create_ssl_context(client->sockfd);
    client->username = strdup(username);
    client->password = strdup(password);
    client->mailbox = strdup(mailbox);

    // Create the client thread
    pthread_t thread;
    if (pthread_create(&thread, NULL, client_thread, client) != 0) {
        fprintf(stderr, "Error: Could not create client thread\n");
        return 1;
    }

    // Wait for the client thread to finish
    if (pthread_join(thread, NULL) != 0) {
        fprintf(stderr, "Error: Could not join client thread\n");
        return 1;
    }

    return 0;
}