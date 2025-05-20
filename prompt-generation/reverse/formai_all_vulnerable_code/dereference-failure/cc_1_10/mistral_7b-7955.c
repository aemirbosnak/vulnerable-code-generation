//MISTRAL-7B DATASET v1.0 Category: Network Ping Test ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_PACKET_SIZE 64
#define TIMEOUT 500
#define BUFFER_SIZE 256

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname/IP> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char hostname[BUFFER_SIZE];
    strcpy(hostname, argv[1]);

    int port = atoi(argv[2]);

    struct addrinfo hints, *res;
    int error;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;

    error = getaddrinfo(hostname, NULL, &hints, &res);
    if (error != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(error));
        return EXIT_FAILURE;
    }

    int sockfd = socket(res->ai_family, res->ai_socktype, 0);
    freeaddrinfo(res);

    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    char packet[MAX_PACKET_SIZE];
    memset(packet, 0x5A, MAX_PACKET_SIZE);

    struct sockaddr_in target;
    target.sin_family = AF_INET;
    target.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &target.sin_addr);

    int sent = sendto(sockfd, packet, MAX_PACKET_SIZE, 0, (struct sockaddr *)&target, sizeof(target));

    if (sent < 0) {
        perror("sendto");
        close(sockfd);
        return EXIT_FAILURE;
    }

    fd_set master_fds, read_fds;
    FD_ZERO(&master_fds);
    FD_ZERO(&read_fds);

    FD_SET(sockfd, &master_fds);

    struct timeval timeout;
    timeout.tv_sec = TIMEOUT / 1000;
    timeout.tv_usec = (TIMEOUT % 1000) * 1000;

    int result;

    while (1) {
        read_fds = master_fds;
        result = select(FD_SETSIZE, &read_fds, NULL, NULL, &timeout);

        if (result < 0) {
            perror("select");
            close(sockfd);
            return EXIT_FAILURE;
        }

        if (FD_ISSET(sockfd, &read_fds)) {
            socklen_t addr_len = sizeof(struct sockaddr);
            int received = recvfrom(sockfd, packet, MAX_PACKET_SIZE, 0, NULL, &addr_len);

            if (received > 0) {
                printf("Received packet of size %d\n", received);
                break;
            }
        }

        if (timeout.tv_sec == 0 && timeout.tv_usec == 0) {
            printf("Host %s:%d unreachable\n", hostname, port);
            close(sockfd);
            return EXIT_FAILURE;
        }
    }

    close(sockfd);
    printf("Host %s:%d reachable\n", hostname, port);

    return EXIT_SUCCESS;
}