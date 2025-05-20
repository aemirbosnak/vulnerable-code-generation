//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

#define MAX_PACKET_LENGTH    4096

int main(int argc, char *argv[]) {

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <IP address> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* ip_address = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton(AF_INET, ip_address, &addr.sin_addr);

    int sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    char packet[MAX_PACKET_LENGTH];
    char reply[MAX_PACKET_LENGTH];
    struct timeval timeout = {3, 0};

    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    while (1) {
        int packet_length = rand() % MAX_PACKET_LENGTH;
        sendto(sockfd, packet, packet_length, 0, (struct sockaddr *) &addr, sizeof(addr));
        int reply_length = recvfrom(sockfd, reply, MAX_PACKET_LENGTH, 0, NULL, NULL);
        if (reply_length >= 0) {
            printf("Packet received. Size: %d bytes.\n", reply_length);
            // analyze reply data to calculate QoS metrics here
        }
    }

    return 0;
}