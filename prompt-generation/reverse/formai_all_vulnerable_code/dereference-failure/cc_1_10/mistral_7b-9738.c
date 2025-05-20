//MISTRAL-7B DATASET v1.0 Category: Network Ping Test ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <time.h>

#define MAX_TRIES 3
#define PACKET_LEN 64
#define CHUNK_SIZE 16
#define TIMEOUT 1000
#define BUFFER_SIZE 1024

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int send_packet(int sockfd, const char *address, int port) {
    char buffer[PACKET_LEN];
    int len = PACKET_LEN;
    struct sockaddr_in server_addr;

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, address, &server_addr.sin_addr);
    server_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        return -1;
    }

    send(sockfd, buffer, len, 0);

    close(sockfd);
    return len;
}

int receive_packet(int sockfd) {
    char buffer[BUFFER_SIZE];
    int len = recv(sockfd, buffer, BUFFER_SIZE, 0);

    if (len <= 0) {
        return -1;
    }

    close(sockfd);
    return len;
}

int ping(const char *address, int port) {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    int len, tries = MAX_TRIES;
    long long total_rtt = 0;

    if (sockfd < 0) {
        die("socket failed");
    }

    while (tries > 0) {
        clock_t start = clock();
        len = send_packet(sockfd, address, port);
        clock_t end = clock();

        if (len < 0) {
            --tries;
            continue;
        }

        usleep(random() % TIMEOUT);
        len = receive_packet(sockfd);

        if (len < 0) {
            --tries;
            continue;
        }

        long long rtt = (end - start + (long long)(1000000000 / CLOCKS_PER_SEC)) / 1000;
        total_rtt += rtt;
        printf("Reply from %s:%d: %lld ms\n", address, port, rtt);
        break;
    }

    close(sockfd);
    return total_rtt / MAX_TRIES;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <address> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int rtt = ping(argv[1], atoi(argv[2]));
    if (rtt >= 0) {
        printf("Average RTT: %lld ms\n", rtt);
    } else {
        perror("ping failed");
    }

    return EXIT_SUCCESS;
}