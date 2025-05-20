//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

/* IMAP commands */
typedef enum {
    LOGIN = 0,
    SELECT = 1,
    FETCH = 2,
    LOGOUT = 3
} imap_command;

int init_socket(char *hostname, int port) {
    int sockfd;
    struct hostent *server;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(hostname);
    if (server == NULL) {
        perror("Error: Host not found");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

int send_command(int sockfd, imap_command command, char *arg) {
    char buffer[1024] = {0};
    char *cmd = NULL;
    int n;

    switch (command) {
        case LOGIN:
            cmd = "LOGIN";
            break;
        case SELECT:
            cmd = "SELECT";
            break;
        case FETCH:
            cmd = "FETCH";
            break;
        case LOGOUT:
            cmd = "LOGOUT";
            break;
        default:
            fprintf(stderr, "Error: Unknown command\n");
            exit(EXIT_FAILURE);
    }

    if (arg != NULL) {
        snprintf(buffer, sizeof(buffer), "%s %s\r\n", cmd, arg);
    } else {
        snprintf(buffer, sizeof(buffer), "%s\r\n", cmd);
    }

    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error writing to socket");
        exit(EXIT_FAILURE);
    }

    return n;
}

void read_response(int sockfd, char *buffer, int size) {
    int n;

    memset(buffer, 0, size);
    n = read(sockfd, buffer, size - 1);
    if (n < 0) {
        perror("Error reading from socket");
        exit(EXIT_FAILURE);
    }
}

/* Entry point of program */
int main(int argc, char *argv[]) {
    SSL_CTX *ctx;
    SSL *ssl;
    int sockfd;
    char buffer[1024] = {0};

    /* Initialize OpenSSL */
    SSL_load_error_strings();
    SSL_library_init();
    OpenSSL_add_all_algorithms();

    /* Create a new SSL context */
    ctx = SSL_CTX_new(SSLv23_client_method());
    if (ctx == NULL) {
        perror("Error creating new SSL context");
        exit(EXIT_FAILURE);
    }

    /* Create a new SSL connection */
    ssl = SSL_new(ctx);
    if (ssl == NULL) {
        perror("Error creating new SSL connection");
        exit(EXIT_FAILURE);
    }

    /* Verify the server's certificate */
    SSL_set_verify(ssl, SSL_VERIFY_PEER, NULL);

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Connect to the IMAP server */
    sockfd = init_socket(argv[1], atoi(argv[2]));  
    SSL_set_fd(ssl, sockfd);  

    if (SSL_connect(ssl) != 1) {
        perror("Error establishing SSL connection");
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    /* Login to the server */
    send_command(sockfd, LOGIN, "user@domain.com password");

    /* Select a mailbox */
    send_command(sockfd, SELECT, "Inbox");

    /* Fetch the first message */
    send_command(sockfd, FETCH, "1 BODY[HEADER.FIELDS (FROM TO SUBJECT)]");

    /* Read the response */
    read_response(sockfd, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    /* Logout from the server */
    send_command(sockfd, LOGOUT, NULL);

    /* Free resources */
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);

    return 0;
}