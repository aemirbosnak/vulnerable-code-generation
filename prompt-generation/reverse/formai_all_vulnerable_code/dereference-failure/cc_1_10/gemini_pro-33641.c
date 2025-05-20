//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: innovative
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define ICMP_ECHO_REQUEST 8
#define ICMP_ECHO_REPLY 0
#define ICMP_HEADER_SIZE 8

struct icmp_echo_request {
    uint8_t type;
    uint8_t code;
    uint16_t checksum;
    uint16_t identifier;
    uint16_t sequence_number;
    uint8_t data[0];
};

struct icmp_echo_reply {
    struct icmp_echo_request request;
    long long int timestamp;
};

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <destination>\n", argv[0]);
        return 1;
    }

    const char *destination = argv[1];
    int socket_fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (socket_fd < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in destination_address;
    memset(&destination_address, 0, sizeof(destination_address));
    destination_address.sin_family = AF_INET;
    destination_address.sin_addr.s_addr = inet_addr(destination);

    struct icmp_echo_request request;
    memset(&request, 0, sizeof(request));
    request.type = ICMP_ECHO_REQUEST;
    request.code = 0;
    request.identifier = getpid();
    request.sequence_number = 0;
    memcpy(request.data, "Hello world!", 12);

    struct timeval start_time;
    gettimeofday(&start_time, NULL);

    int sent_bytes = sendto(socket_fd, &request, sizeof(request), 0, (struct sockaddr *)&destination_address, sizeof(destination_address));
    if (sent_bytes < 0) {
        perror("sendto");
        return 1;
    }

    struct sockaddr_in sender_address;
    socklen_t sender_address_length = sizeof(sender_address);
    struct icmp_echo_reply reply;
    memset(&reply, 0, sizeof(reply));
    int received_bytes = recvfrom(socket_fd, &reply, sizeof(reply), 0, (struct sockaddr *)&sender_address, &sender_address_length);
    if (received_bytes < 0) {
        perror("recvfrom");
        return 1;
    }

    struct timeval end_time;
    gettimeofday(&end_time, NULL);

    if (reply.request.type != ICMP_ECHO_REPLY || reply.request.identifier != request.identifier || reply.request.sequence_number != request.sequence_number) {
        printf("Invalid ICMP echo reply received\n");
        return 1;
    }

    long long int elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000 + (end_time.tv_usec - start_time.tv_usec) / 1000;
    printf("Round-trip time: %lld ms\n", elapsed_time);

    close(socket_fd);
    return 0;
}