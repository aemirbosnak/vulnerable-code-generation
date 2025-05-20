//FormAI DATASET v1.0 Category: Network Ping Test ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX_PACKET_SIZE 1024
#define PING_TIMEOUT 1
#define MAX_PINGS 10

struct PingPacket {
    uint16_t seq_num;
    uint16_t length;
    struct timeval send_time;
};

struct PongPacket {
    uint16_t seq_num;
    uint16_t length;
    struct timeval recv_time;
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    struct addrinfo* servinfo;
    struct addrinfo hints = {
        .ai_family = AF_INET,
        .ai_socktype = SOCK_DGRAM,
        .ai_protocol = IPPROTO_UDP,
    };

    int result = getaddrinfo(argv[1], NULL, &hints, &servinfo);
    if (result != 0) {
        fprintf(stderr, "Failed to get address info for %s: %s\n", 
        	argv[1], gai_strerror(result));
        exit(1);
    }

    struct sockaddr_in* sock = (struct sockaddr_in*) servinfo->ai_addr;

    int sock_fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock_fd == -1) {
        perror("Failed to create socket");
        exit(1);
    }

    printf("Pinging %s...\n", argv[1]);
    for (int i = 1; i <= MAX_PINGS; i++) {
        struct PingPacket packet = {
            .seq_num = i,
            .length = sizeof(struct PingPacket),
        };

        gettimeofday(&packet.send_time, NULL);

        size_t num_bytes = sendto(sock_fd, &packet, sizeof(packet),
            0, (struct sockaddr*) sock, sizeof(struct sockaddr));
        if (num_bytes < sizeof(packet)) {
            perror("Failed to send full packet");
            continue;
        }

        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(sock_fd, &read_fds);

        struct timeval timeout = {
            .tv_sec = PING_TIMEOUT,
            .tv_usec = 0,
        };

        result = select(sock_fd + 1, &read_fds, NULL, NULL, &timeout);
        if (result == -1) {
            perror("Error in select()");
            continue;
        } else if (result == 0) {
            printf("Ping %d timeout\n", i);
            continue;
        }

        struct PongPacket pong;
        struct sockaddr_in addr;
        socklen_t addr_len = sizeof(struct sockaddr_in);

        num_bytes = recvfrom(sock_fd, &pong, sizeof(pong),
            0, (struct sockaddr*) &addr, &addr_len);

        if (num_bytes == -1) {
            perror("Error during recvfrom()");
            continue;
        } else if (pong.seq_num != i) {
            printf("Received ping with incorrect sequence number\n");
            continue;
        }

        struct timeval end_time;
        gettimeofday(&end_time, NULL);

        double elapsed_time = ((double) (end_time.tv_sec - 
                               packet.send_time.tv_sec)) +
            ((double) (end_time.tv_usec - packet.send_time.tv_usec))/1000000.0;

        struct in_addr ip_addr = addr.sin_addr;
        char ip_str[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &ip_addr, ip_str, INET_ADDRSTRLEN);

        printf("Ping %d: Received reply from %s in %lf seconds\n",
               i, ip_str, elapsed_time);

        sleep(1);
    }

    freeaddrinfo(servinfo);

    return 0;
}