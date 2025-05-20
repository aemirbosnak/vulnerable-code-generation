//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

#define BUF_SIZE 1024

int sockfd;

void error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void recv_data() {
    char buf[BUF_SIZE];
    int n = recv(sockfd, buf, BUF_SIZE, 0);
    if (n == -1) {
        error("recv");
    } else if (n == 0) {
        printf("Server closed connection\n");
        exit(EXIT_SUCCESS);
    } else {
        printf("Received %d bytes: %.*s\n", n, n, buf);
    }
}

void send_data(char *msg) {
    int n = send(sockfd, msg, strlen(msg), 0);
    if (n == -1) {
        error("send");
    } else {
        printf("Sent %d bytes: %s\n", n, msg);
    }
}

void init_socket(char *host, char *port) {
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    int status = getaddrinfo(host, port, &hints, &res);
    if (status != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        exit(EXIT_FAILURE);
    }

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        error("socket");
    }

    status = connect(sockfd, res->ai_addr, res->ai_addrlen);
    if (status == -1) {
        error("connect");
    }

    freeaddrinfo(res);
}

void monitor_network_qos() {
    while (1) {
        send_data("ping");
        sleep(1);
        recv_data();
    }
}

void close_socket() {
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *host = argv[1];
    char *port = argv[2];

    init_socket(host, port);

    monitor_network_qos();

    close_socket();

    return 0;
}