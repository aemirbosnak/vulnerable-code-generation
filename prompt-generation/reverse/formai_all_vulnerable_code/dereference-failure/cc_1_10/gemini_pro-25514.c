//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>

#define BUFSIZE 1024

static void error(const char *msg) {
    perror(msg);
    exit(1);
}

static int create_socket(const char *host, const char *port) {
    struct addrinfo hints, *res;
    int sockfd;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(host, port, &hints, &res) != 0) {
        error("getaddrinfo");
    }

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd < 0) {
        error("socket");
    }

    if (connect(sockfd, res->ai_addr, res->ai_addrlen) < 0) {
        error("connect");
    }

    freeaddrinfo(res);

    return sockfd;
}

static void send_data(int sockfd, const char *data, size_t len) {
    int n;

    n = send(sockfd, data, len, 0);
    if (n < 0) {
        error("send");
    }
}

static void receive_data(int sockfd, char *buf, size_t len) {
    int n;

    n = recv(sockfd, buf, len, 0);
    if (n < 0) {
        error("recv");
    }
}

static void test_qos(int sockfd, const char *data, size_t len, int iterations) {
    struct timeval start, end;
    double elapsed;
    int i;

    for (i = 0; i < iterations; i++) {
        gettimeofday(&start, NULL);

        send_data(sockfd, data, len);

        receive_data(sockfd, NULL, len);

        gettimeofday(&end, NULL);

        elapsed = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;

        printf("%d: %.3f ms\n", i + 1, elapsed);
    }
}

int main(int argc, char **argv) {
    int sockfd;
    char buf[BUFSIZE];

    if (argc < 4) {
        fprintf(stderr, "Usage: %s <host> <port> <data> <iterations>\n", argv[0]);
        exit(1);
    }

    sockfd = create_socket(argv[1], argv[2]);

    memset(buf, 0, sizeof(buf));
    memcpy(buf, argv[3], strlen(argv[3]));

    test_qos(sockfd, buf, strlen(buf), atoi(argv[4]));

    close(sockfd);

    return 0;
}