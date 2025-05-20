//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>

// Structure to hold the ping request and response data
struct ping_data {
    struct sockaddr_in addr; // Destination address
    long long timestamp; // Timestamp of the request
    long long rtt; // Round-trip time
    char payload[1024]; // Payload data
};

// Function to calculate the checksum of a buffer
unsigned short checksum(const void *buffer, size_t len) {
    unsigned short *words = (unsigned short *)buffer;
    size_t word_count = len / sizeof(unsigned short);

    unsigned long sum = 0;
    for (size_t i = 0; i < word_count; i++) {
        sum += words[i];
    }

    // Add the leftover byte, if any
    if (len % sizeof(unsigned short)) {
        unsigned short last_byte = *(unsigned char *)((unsigned char *)buffer + len - 1);
        sum += last_byte;
    }

    // Fold the sum to 16 bits
    while (sum >> 16) {
        sum = (sum & 0xffff) + (sum >> 16);
    }

    return ~sum;
}

// Function to send a ping request
int send_ping(int sockfd, struct sockaddr_in *addr, char *payload, size_t payload_len) {
    // Create the ping data structure
    struct ping_data data;
    memset(&data, 0, sizeof(data));

    data.addr = *addr;
    data.timestamp = time(NULL);
    memcpy(data.payload, payload, payload_len);

    // Calculate the checksum
    data.rtt = 0;
    unsigned short checksum_value = checksum(&data, sizeof(data));
    data.rtt = checksum_value;

    // Send the ping request
    ssize_t sent_bytes = sendto(sockfd, &data, sizeof(data), 0, (struct sockaddr *)&data.addr, sizeof(data.addr));
    if (sent_bytes < 0) {
        perror("sendto");
        return -1;
    }

    return 0;
}

// Function to receive a ping response
int receive_ping(int sockfd, struct sockaddr_in *addr, char *payload, size_t *payload_len) {
    // Create the ping data structure
    struct ping_data data;
    memset(&data, 0, sizeof(data));

    // Receive the ping response
    socklen_t addr_len = sizeof(data.addr);
    ssize_t recv_bytes = recvfrom(sockfd, &data, sizeof(data), 0, (struct sockaddr *)&data.addr, &addr_len);
    if (recv_bytes < 0) {
        perror("recvfrom");
        return -1;
    }

    // Check the checksum
    unsigned short checksum_value = checksum(&data, sizeof(data));
    if (checksum_value != 0) {
        fprintf(stderr, "Checksum error\n");
        return -1;
    }

    // Copy the payload data
    memcpy(payload, data.payload, recv_bytes - sizeof(data));
    *payload_len = recv_bytes - sizeof(data);

    // Calculate the round-trip time
    data.rtt = time(NULL) - data.timestamp;

    // Print the ping response
    printf("Received ping response from %s: payload size %zu, RTT %lld ms\n", inet_ntoa(data.addr.sin_addr), *payload_len, data.rtt);

    return 0;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <destination IP address> <payload size>\n", argv[0]);
        return 1;
    }

    // Create the socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    // Set the destination address
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(argv[1]);

    // Send the ping request
    char payload[1024];
    size_t payload_len = atoi(argv[2]);
    memset(payload, 0, payload_len);
    for (size_t i = 0; i < payload_len; i++) {
        payload[i] = rand() % 256;
    }
    if (send_ping(sockfd, &addr, payload, payload_len) < 0) {
        return 1;
    }

    // Receive the ping response
    char recv_payload[1024];
    size_t recv_payload_len;
    if (receive_ping(sockfd, &addr, recv_payload, &recv_payload_len) < 0) {
        return 1;
    }

    // Close the socket
    close(sockfd);

    return 0;
}