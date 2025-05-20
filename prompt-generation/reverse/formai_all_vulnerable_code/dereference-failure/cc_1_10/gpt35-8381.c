//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int create_socket(char* server_name, int port_num) {
    struct sockaddr_in server_address;
    struct hostent *server;
    int sockfd;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Failed to create socket.\n");
        return -1;
    }
    server = gethostbyname(server_name);
    if (server == NULL) {
        printf("Error: No such host.\n");
        return -1;
    }
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(server->h_addr_list[0]);
    server_address.sin_port = htons(port_num);
    if (connect(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        printf("Error: Failed to connect.\n");
        return -1;
    }
    return sockfd;
}

void receive_data(SSL *ssl) {
    char buffer[BUFFER_SIZE];
    int amount;
    memset(buffer, '\0', BUFFER_SIZE);
    amount = SSL_read(ssl, buffer, BUFFER_SIZE-1);
    if (amount > 0) {
        printf("%s", buffer);
    }
    return;
}

int main(int argc, char *argv[]) {
    SSL_CTX *ctx;
    SSL *ssl;
    int sockfd;
    char buffer[BUFFER_SIZE];
    char username[50], password[50];
    char* server_name, *username_base64, *password_base64;
    int port_num;

    // Check command line arguments
    if (argc != 4) {
        printf("Usage: %s <server_name> <port_num> <username>\n", argv[0]);
        return -1;
    }
    server_name = argv[1];
    port_num = atoi(argv[2]);
    strcpy(username, argv[3]);

    // Get password from user
    printf("Please enter your password: ");
    scanf("%s",password);

    // Initialize SSL library
    SSL_library_init();
    SSL_load_error_strings();
    OpenSSL_add_all_algorithms();

    ctx = SSL_CTX_new(SSLv23_client_method());
    if (ctx == NULL) {
        printf("Error: Failed to create SSL_CTX object.\n");
        return -1;
    }

    // Create socket
    sockfd = create_socket(server_name, port_num);
    if (sockfd == -1) {
        printf("Error: Failed to create socket.\n");
        return -1;
    }

    // Attach socket to SSL object
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);

    // Connect to SSL server
    if (SSL_connect(ssl) < 0) {
        printf("Error: Failed to connect to SSL server.\n");
        return -1;
    }

    // Prepare login string
    sprintf(buffer, "a001 LOGIN %s %s\r\n", username, password);
    SSL_write(ssl, buffer, strlen(buffer));

    // Receive welcome message
    receive_data(ssl);

    // Logout and close connection
    SSL_write(ssl, "a002 LOGOUT\r\n", strlen("a002 LOGOUT\r\n"));
    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sockfd);
    SSL_CTX_free(ctx);

    return 0;
}