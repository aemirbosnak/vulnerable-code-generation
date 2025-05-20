//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>
#include <openssl/ssl.h>
#include <openssl/rand.h>

#define MAX_BUF_SIZE 512

int send_command(SSL* ssl, char cmd[]) {
    char buffer[MAX_BUF_SIZE];
    int bytes_sent = SSL_write(ssl, cmd, strlen(cmd));
    int bytes_received = SSL_read(ssl, buffer, sizeof(buffer));
    printf("%s", buffer);
    return bytes_received;
}

int main() {
    int port = 993;
    char host[] = "imap.gmail.com";
    char username[] = "example@gmail.com";
    char password[] = "example_password";

    SSL_library_init();
    SSL_CTX *sslctx = SSL_CTX_new(SSLv23_client_method());
    if (!sslctx) {
        printf("Error initializing SSL_CTX\n");
        return -1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket: %d\n", errno);
        return -1;
    }

    struct hostent *he = gethostbyname(host);
    if (!he) {
        printf("Hostname resolution failed\n");
        return -1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    memcpy(&addr.sin_addr, he->h_addr_list[0], he->h_length);

    if (connect(sockfd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        printf("Error connecting to %s:%d: %d\n", host, port, errno);
        return -1;
    }

    SSL *ssl = SSL_new(sslctx);
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) != 1) {
        printf("Error establishing SSL connection\n");
        ERR_print_errors_fp(stderr);
        return -1;
    }

    int bytes_received = send_command(ssl, "a001 LOGIN example@gmail.com example_password\r\n");
    if (bytes_received < 1) {
        printf("Error logging in\n");
        return -1;
    }

    bytes_received = send_command(ssl, "a002 SELECT INBOX\r\n");
    if (bytes_received < 1) {
        printf("Error selecting inbox\n");
        return -1;
    }
    
    bytes_received = send_command(ssl, "a003 FETCH 1 BODY[]\r\n");
    if (bytes_received < 1) {
        printf("Error fetching email\n");
        return -1;
    }

    bytes_received = send_command(ssl, "a004 LOGOUT\r\n");
    if (bytes_received < 1) {
        printf("Error logging out\n");
        return -1;
    }

    SSL_free(ssl);
    close(sockfd);
    SSL_CTX_free(sslctx);

    return 0;
}