//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <openssl/ssl.h>

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: pop3_client <hostname> <username> <password>\n");
        return 1;
    }

    char *hostname = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    int rv;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    rv = getaddrinfo(hostname, "pop3", &hints, &servinfo);
    if (rv!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            continue;
        }
        break;
    }

    if (p == NULL || sockfd == -1) {
        fprintf(stderr, "Could not create socket\n");
        return 1;
    }

    SSL_library_init();
    SSL_load_error_strings();
    OpenSSL_add_all_algorithms();

    SSL_CTX *ctx = SSL_CTX_new(SSLv23_client_method());
    if (ctx == NULL) {
        fprintf(stderr, "Could not create SSL context\n");
        return 1;
    }

    SSL *ssl = SSL_new(ctx);
    if (SSL_set_fd(ssl, sockfd) == -1) {
        fprintf(stderr, "Could not set socket to SSL object\n");
        return 1;
    }

    int ret = SSL_connect(ssl);
    if (ret == -1) {
        fprintf(stderr, "Could not connect to server\n");
        return 1;
    }

    printf("Connected to server\n");

    char cmd[256];
    snprintf(cmd, sizeof cmd, "USER %s\r\n", username);
    ret = SSL_write(ssl, cmd, strlen(cmd));
    if (ret == -1) {
        fprintf(stderr, "Could not send command\n");
        return 1;
    }

    snprintf(cmd, sizeof cmd, "PASS %s\r\n", password);
    ret = SSL_write(ssl, cmd, strlen(cmd));
    if (ret == -1) {
        fprintf(stderr, "Could not send command\n");
        return 1;
    }

    ret = SSL_read(ssl, cmd, sizeof cmd);
    if (ret == -1) {
        fprintf(stderr, "Could not read response\n");
        return 1;
    }

    if (strcmp(cmd, "+OK") == 0) {
        printf("Authentication successful\n");
    } else {
        fprintf(stderr, "Authentication failed\n");
        return 1;
    }

    int n;
    char buf[256];
    snprintf(cmd, sizeof cmd, "LIST\r\n");
    ret = SSL_write(ssl, cmd, strlen(cmd));
    if (ret == -1) {
        fprintf(stderr, "Could not send command\n");
        return 1;
    }

    while (1) {
        ret = SSL_read(ssl, buf, sizeof buf);
        if (ret == -1) {
            fprintf(stderr, "Could not read response\n");
            return 1;
        }

        if (ret == 0) {
            break;
        }

        buf[ret] = '\0';

        printf("Message: %s\n", buf);

        if (buf[0] == '-') {
            break;
        }
    }

    snprintf(cmd, sizeof cmd, "RETR 1\r\n");
    ret = SSL_write(ssl, cmd, strlen(cmd));
    if (ret == -1) {
        fprintf(stderr, "Could not send command\n");
        return 1;
    }

    ret = SSL_read(ssl, buf, sizeof buf);
    if (ret == -1) {
        fprintf(stderr, "Could not read response\n");
        return 1;
    }

    if (strcmp(buf, "+OK") == 0) {
        ret = SSL_read(ssl, buf, sizeof buf);
        if (ret == -1) {
            fprintf(stderr, "Could not read response\n");
            return 1;
        }

        printf("Body: %s\n", buf);
    } else {
        fprintf(stderr, "Could not download message\n");
    }

    snprintf(cmd, sizeof cmd, "QUIT\r\n");
    ret = SSL_write(ssl, cmd, strlen(cmd));
    if (ret == -1) {
        fprintf(stderr, "Could not send command\n");
        return 1;
    }

    ret = SSL_read(ssl, buf, sizeof buf);
    if (ret == -1) {
        fprintf(stderr, "Could not read response\n");
        return 1;
    }

    if (strcmp(buf, "+OK") == 0) {
        printf("Bye\n");
    } else {
        fprintf(stderr, "Could not quit\n");
    }

    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);

    close(sockfd);

    return 0;
}