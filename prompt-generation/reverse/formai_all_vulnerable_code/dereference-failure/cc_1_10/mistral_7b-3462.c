//MISTRAL-7B DATASET v1.0 Category: Network Packet Monitoring ; Style: shape shifting
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define SHAPE_SHIFT 5

typedef struct packet_header {
    u_int16_t hlen;
    u_int16_t protocol;
    u_int32_t source_ip;
    u_int32_t destination_ip;
} packet_header;

typedef struct shape_shifted_packet {
    packet_header header;
    u_int8_t data[1024];
} shape_shifted_packet;

int main(int argc, char **argv) {
    int sockfd, new_sockfd;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;
    int n;
    shape_shifted_packet packet;

    if (argc < 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

    while (1) {
        clilen = sizeof(cli_addr);
        new_sockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

        n = recv(new_sockfd, &packet, sizeof(packet), 0);

        if (n < 0) {
            perror("Error: Could not receive packet");
            close(new_sockfd);
            continue;
        }

        // Shape-shift the packet data
        for (int i = 0; i < n; i++) {
            if (i % SHAPE_SHIFT == 0) {
                packet.data[i] = ~packet.data[i];
            }
        }

        // Send the shape-shifted packet back to the sender
        send(new_sockfd, &packet, n, 0);

        close(new_sockfd);
    }

    close(sockfd);
    return 0;
}