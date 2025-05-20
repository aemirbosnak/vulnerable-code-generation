//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_HOST_LEN 256
#define MAX_DATA_LEN 64

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    char hostname[MAX_HOST_LEN];
    strncpy(hostname, argv[1], MAX_HOST_LEN);
    int port = atoi(argv[2]);

    struct addrinfo hints, *result, *rp;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    int gai_error = getaddrinfo(hostname, NULL, &hints, &result);
    if (gai_error!= 0) {
        printf("getaddrinfo error: %s\n", gai_strerror(gai_error));
        return 1;
    }

    int sockfd = -1;
    for (rp = result; rp!= NULL; rp = rp->ai_next) {
        sockfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (sockfd == -1) {
            continue;
        }

        if (connect(sockfd, rp->ai_addr, rp->ai_addrlen) == 0) {
            break;
        }

        close(sockfd);
        sockfd = -1;
    }

    if (sockfd == -1) {
        printf("Failed to connect to %s:%d\n", hostname, port);
        return 1;
    }

    char send_data[MAX_DATA_LEN] = "PING";
    send(sockfd, send_data, strlen(send_data), 0);

    char recv_data[MAX_DATA_LEN];
    int bytes_received = recv(sockfd, recv_data, MAX_DATA_LEN, 0);
    if (bytes_received <= 0) {
        printf("Failed to receive data from server\n");
        close(sockfd);
        return 1;
    }

    recv_data[bytes_received] = '\0';
    printf("Received data from server: %s\n", recv_data);

    close(sockfd);
    return 0;
}