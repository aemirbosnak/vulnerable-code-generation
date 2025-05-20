//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUF_SIZE 1024

/* Function to connect to the IMAP server */
int connect_to_server(const char *servername, const char *port) {
    int sockfd;
    struct addrinfo hints, *result, *rp;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;    /* Allow IPv4 or IPv6 */
    hints.ai_socktype = SOCK_STREAM; /* Stream socket */
    hints.ai_flags = 0;

    if (getaddrinfo(servername, port, &hints, &result) != 0) {
        perror("getaddrinfo");
        exit(EXIT_FAILURE);
    }

    /* Try each address until a successful connection is made */
    for (rp = result; rp != NULL; rp = rp->ai_next) {
        sockfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (sockfd == -1) {
            continue;
        }

        if (connect(sockfd, rp->ai_addr, rp->ai_addrlen) != -1) {
            break;
        }

        close(sockfd);
    }

    if (rp == NULL) {
        fprintf(stderr, "Could not connect to %s:%s\n", servername, port);
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(result);

    return sockfd;
}

/* Function to send IMAP command to the server */
int send_command(int sockfd, const char *cmd, char *response) {
    int num_bytes;
    char buf[BUF_SIZE] = {0};

    num_bytes = sprintf(buf, "%s\r\n", cmd);
    if (send(sockfd, buf, num_bytes, 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    if (recv(sockfd, response, BUF_SIZE, 0) == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    return 0;
}

/* Main function */
int main(int argc, char *argv[]) {
    SSL_CTX *ctx;
    SSL *ssl;
    const char *servername;
    const char *port = "993";
    int sockfd;
    char response[BUF_SIZE] = {0};

    /* Check if servername has been provided */
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <server>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Initialize OpenSSL */
    SSL_library_init();
    SSL_load_error_strings();

    /* Create a new SSL context object */
    ctx = SSL_CTX_new(TLS_client_method());
    if (ctx == NULL) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    /* Connect to the server */
    servername = argv[1];
    sockfd = connect_to_server(servername, port);

    /* Create an SSL stream object to communicate with the server */
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) != 1) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    /* Send an IMAP command to the server */
    send_command(sockfd, "A001 LOGIN myusername mypassword", response);
    printf("%s\n", response);

    /* Send another IMAP command */
    send_command(sockfd, "A002 SELECT INBOX", response);
    printf("%s\n", response);

    /* Clean up */
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);

    return 0;
}