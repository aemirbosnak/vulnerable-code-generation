//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>

typedef struct {
    int sockfd;
    char *host;
    int port;
} email_client;

void email_client_init(email_client *ec, char *host, int port) {
    ec->sockfd = -1;
    ec->host = strdup(host);
    ec->port = port;
}

void email_client_destroy(email_client *ec) {
    if (ec->sockfd != -1) {
        close(ec->sockfd);
    }
    free(ec->host);
}

int email_client_connect(email_client *ec) {
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    char portstr[16];
    sprintf(portstr, "%d", ec->port);

    if (getaddrinfo(ec->host, portstr, &hints, &res) != 0) {
        return -1;
    }

    ec->sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (ec->sockfd == -1) {
        freeaddrinfo(res);
        return -1;
    }

    if (connect(ec->sockfd, res->ai_addr, res->ai_addrlen) != 0) {
        close(ec->sockfd);
        freeaddrinfo(res);
        return -1;
    }

    freeaddrinfo(res);
    return 0;
}

int email_client_send(email_client *ec, char *email) {
    if (write(ec->sockfd, email, strlen(email)) == -1) {
        return -1;
    }
    return 0;
}

int email_client_receive(email_client *ec, char *buf, size_t buflen) {
    int n = read(ec->sockfd, buf, buflen);
    if (n == -1) {
        return -1;
    }
    buf[n] = '\0';
    return n;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s host port email\n", argv[0]);
        return EXIT_FAILURE;
    }

    email_client ec;
    email_client_init(&ec, argv[1], atoi(argv[2]));
    if (email_client_connect(&ec) == -1) {
        perror("email_client_connect");
        email_client_destroy(&ec);
        return EXIT_FAILURE;
    }
    if (email_client_send(&ec, argv[3]) == -1) {
        perror("email_client_send");
        email_client_destroy(&ec);
        return EXIT_FAILURE;
    }

    char buf[1024];
    int n;
    while ((n = email_client_receive(&ec, buf, sizeof(buf))) > 0) {
        printf("%s", buf);
    }
    if (n == -1) {
        perror("email_client_receive");
        email_client_destroy(&ec);
        return EXIT_FAILURE;
    }

    email_client_destroy(&ec);
    return EXIT_SUCCESS;
}