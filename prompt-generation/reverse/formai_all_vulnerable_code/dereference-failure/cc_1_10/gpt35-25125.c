//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: peaceful
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUF_SIZE 1024

// Function to handle errors
void handle_error()
{
    printf("Error occurred: %s\n", ERR_error_string(ERR_get_error(), NULL));
    exit(EXIT_FAILURE);
}

// Function to establish SSL connection
SSL* ssl_init(SSL_CTX* ctx, int sockfd)
{
    SSL* ssl;
    ssl = SSL_new(ctx);                 // create new SSL connection
    if (ssl == NULL) handle_error();
    SSL_set_fd(ssl, sockfd);            // set socket file descriptor for SSL connection
    if (SSL_connect(ssl) <= 0) handle_error();          // connect SSL connection to server
    return ssl;                         
}

int main(int argc, char **argv)
{
    char *server, *username, *password;
    int port;
    int sockfd;
    SSL_CTX *ctx;
    SSL *ssl;
    char buf[BUF_SIZE];
    int status;
    char command[BUF_SIZE];
    char response[BUF_SIZE];
    char *ptr;
    int num_bytes;
    FILE *fp;

    // Error handling for input arguments
    if (argc != 5) {
        printf("Usage: %s <server> <port> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Retrieving input arguments
    server = argv[1];
    port = atoi(argv[2]);
    username = argv[3];
    password = argv[4];

    // Initializing SSL library
    SSL_library_init();

    // Creating SSL context
    ctx = SSL_CTX_new(TLSv1_2_client_method());
    if (ctx == NULL) handle_error();

    // Disabling SSL verification
    SSL_CTX_set_verify(ctx, SSL_VERIFY_NONE, NULL);

    // Resolving server address
    struct hostent *he;
    struct in_addr **addr_list;
    if ((he = gethostbyname(server)) == NULL) handle_error();
    addr_list = (struct in_addr **)he->h_addr_list;
    char ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, addr_list[0], ip, INET_ADDRSTRLEN);

    // Creating socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) handle_error();

    // Setting socket address
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    if (inet_pton(AF_INET, ip, &address.sin_addr) <= 0) handle_error();

    // Connecting to server
    if (connect(sockfd, (struct sockaddr *)&address, sizeof(address)) < 0) handle_error();

    // Establishing SSL connection
    ssl = ssl_init(ctx, sockfd);

    // Retrieving server greeting
    num_bytes = SSL_read(ssl, buf, BUF_SIZE);
    buf[num_bytes] = '\0';
    printf("%s", buf);

    // Logging in to server
    sprintf(command, "USER %s\r\n", username);
    SSL_write(ssl, command, strlen(command));
    num_bytes = SSL_read(ssl, response, BUF_SIZE);
    response[num_bytes] = '\0';
    printf("%s", response);

    sprintf(command, "PASS %s\r\n", password);
    SSL_write(ssl, command, strlen(command));
    num_bytes = SSL_read(ssl, response, BUF_SIZE);
    response[num_bytes] = '\0';
    printf("%s", response);

    // Retrieving number of messages
    sprintf(command, "STAT\r\n");
    SSL_write(ssl, command, strlen(command));
    num_bytes = SSL_read(ssl, response, BUF_SIZE);
    response[num_bytes] = '\0';
    printf("%s", response);
    ptr = strtok(response, " ");
    ptr = strtok(NULL, " ");
    int num_msgs = atoi(ptr);

    // Retrieving message headers
    sprintf(command, "LIST\r\n");
    SSL_write(ssl, command, strlen(command));
    num_bytes = SSL_read(ssl, response, BUF_SIZE);
    response[num_bytes] = '\0';
    printf("%s", response);

    // Writing message headers to file
    fp = fopen("messages.txt", "w");
    if (fp == NULL) exit(EXIT_FAILURE);
    fwrite(response, sizeof(char), num_bytes, fp);

    // Retrieving individual messages
    for (int i = 1; i <= num_msgs; i++) {
        sprintf(command, "RETR %d\r\n", i);
        SSL_write(ssl, command, strlen(command));
        num_bytes = SSL_read(ssl, response, BUF_SIZE);
        response[num_bytes] = '\0';

        // Writing individual message to file
        char filename[BUF_SIZE];
        sprintf(filename, "message%d.txt", i);
        fp = fopen(filename, "w");
        if (fp == NULL) exit(EXIT_FAILURE);
        fwrite(response, sizeof(char), num_bytes, fp);
        fclose(fp);
    }

    // Logging out of server
    sprintf(command, "QUIT\r\n");
    SSL_write(ssl, command, strlen(command));
    num_bytes = SSL_read(ssl, response, BUF_SIZE);
    response[num_bytes] = '\0';
    printf("%s", response);

    // Closing SSL connection
    SSL_shutdown(ssl);
    SSL_free(ssl);

    // Closing socket
    close(sockfd);

    return 0;
}