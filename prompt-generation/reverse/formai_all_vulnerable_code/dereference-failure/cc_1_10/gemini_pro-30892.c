//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX_HOPS            30
#define MAX_PACKET_SIZE     64
#define MAX_RETRIES         3
#define QOS_PORT            (2000)

struct qos_packet {
    uint8_t  ttl;
    uint8_t  packet_id;
    uint32_t timestamp;
    uint8_t  data[MAX_PACKET_SIZE];
};

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <destination_ip> <num_packets>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int num_packets = atoi(argv[2]);
    if (num_packets < 1) {
        fprintf(stderr, "Number of packets must be greater than 0\n");
        return EXIT_FAILURE;
    }

    struct sockaddr_in dest_addr;
    inet_pton(AF_INET, argv[1], &dest_addr.sin_addr);
    dest_addr.sin_port = htons(QOS_PORT);

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket()");
        return EXIT_FAILURE;
    }

    struct qos_packet packet;
    memset(&packet, 0, sizeof(packet));

    for (int i = 1; i <= num_packets; i++) {
        packet.ttl = i;
        packet.packet_id = i;
        packet.timestamp = (uint32_t) time(NULL);

        // Send the packet
        if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) == -1) {
            perror("sendto()");
            continue;
        }

        // Receive the response
        struct sockaddr_in src_addr;
        socklen_t src_addr_len = sizeof(src_addr);
        struct qos_packet response;
        memset(&response, 0, sizeof(response));

        // Retry a few times if we don't receive a response
        int retries = 0;
        while (recvfrom(sockfd, &response, sizeof(response), 0, (struct sockaddr *)&src_addr, &src_addr_len) <= 0) {
            if (retries++ >= MAX_RETRIES) {
                printf("Failed to receive response from %s\n", inet_ntoa(src_addr.sin_addr));
                break;
            }
        }

        // Calculate the round-trip time
        uint32_t rtt = (uint32_t) time(NULL) - response.timestamp;

        // Print the results
        printf("Packet %d: TTL=%d, RTT=%d ms, Destination=%s\n", packet.packet_id, packet.ttl, rtt, inet_ntoa(src_addr.sin_addr));
    }

    close(sockfd);
    return EXIT_SUCCESS;
}