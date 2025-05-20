//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define HOST "mail.example.com"
#define PORT "993"
#define MAX_BUF_SIZE 4096

int main() {
    // Creating socket
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    getaddrinfo(HOST, PORT, &hints, &servinfo);
    for (p = servinfo; p != NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            perror("socket");
            continue;
        }
        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("connect");
            continue;
        }
        break;
    }
    if (p == NULL) {
        fprintf(stderr, "Failed to connect to server\n");
        exit(EXIT_FAILURE);
    }
    freeaddrinfo(servinfo);

    // Setting up SSL
    SSL_library_init();
    OpenSSL_add_all_algorithms();
    SSL_CTX *ctx = SSL_CTX_new(TLSv1_2_client_method());
    if (!ctx) {
        fprintf(stderr, "Failed to create SSL context\n");
        exit(EXIT_FAILURE);
    }
    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) == -1) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    // Logging in and fetching mails
    char user[] = "username";
    char pass[] = "password";
    char buf[MAX_BUF_SIZE];
    char *tag, *command;
    int bytes_read;
    asprintf(&tag, "A%d", rand() % 1000);
    asprintf(&command, "%s LOGIN %s %s\n", tag, user, pass);
    SSL_write(ssl, command, strlen(command));
    memset(buf, 0, sizeof(buf));
    bytes_read = SSL_read(ssl, buf, sizeof(buf));
    printf("%s\n", buf);

    asprintf(&tag, "A%d", rand() % 1000);
    asprintf(&command, "%s SELECT INBOX\n", tag);
    SSL_write(ssl, command, strlen(command));
    memset(buf, 0, sizeof(buf));
    bytes_read = SSL_read(ssl, buf, sizeof(buf));
    printf("%s\n", buf);

    asprintf(&tag, "A%d", rand() % 1000);
    asprintf(&command, "%s FETCH 1:* BODY[]\n", tag);
    SSL_write(ssl, command, strlen(command));
    while ((bytes_read = SSL_read(ssl, buf, sizeof(buf)))) {
        printf("%.*s", bytes_read, buf);
        memset(buf, 0, sizeof(buf));
    }

    // Closing connection and freeing memory
    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sockfd);
    SSL_CTX_free(ctx);
    return 0;
}