//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define PING_DATA_SIZE 64
#define PING_COUNT 4

// Function to create the ICMP packet
void create_icmp_packet(char *packet) {
    memset(packet, 0, PING_DATA_SIZE);
    packet[0] = 8; // ICMP Type: Echo Request
    packet[1] = 0; // Code: 0
    packet[2] = 0; // Checksum high byte
    packet[3] = 0; // Checksum low byte
    packet[4] = htons(getpid()); // Identifier
    packet[5] = 1; // Sequence Number
    // The rest of the packet can be filled with any data
    strcpy(packet + 8, "PING TEST DATA");
}

// Function to calculate the checksum
unsigned short checksum(unsigned short *b, int len) {
    unsigned short word;
    int sum = 0;
    int nleft = len;

    while (nleft > 1) {
        sum += *b++;
        nleft -= 2;
    }
    if (nleft == 1) {
        word = 0;
        *((unsigned char *) &word) = *(unsigned char *) b;
        sum += word;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    return (unsigned short) ~sum;
}

// Recursive function to ping a host
int ping_recursive(const char *host, int count) {
    if (count <= 0) {
        return 0; // Base case: no more pings to send
    }

    int sockfd;
    struct sockaddr_in addr;
    char packet[PING_DATA_SIZE];
    char response[512];

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return -1;
    }

    struct hostent *host_info = gethostbyname(host);
    if (host_info == NULL) {
        perror("Failed to resolve host");
        close(sockfd);
        return -1;
    }

    memcpy(&addr.sin_addr, host_info->h_addr, host_info->h_length);
    addr.sin_family = AF_INET;
    addr.sin_port = 0;

    create_icmp_packet(packet);
    unsigned short packet_checksum = checksum((unsigned short *)packet, PING_DATA_SIZE);
    packet[2] = packet_checksum >> 8; // Set checksum high byte
    packet[3] = packet_checksum & 0xff; // Set checksum low byte

    // Send ICMP packet
    if (sendto(sockfd, packet, PING_DATA_SIZE, 0, (struct sockaddr *)&addr, sizeof(addr)) <= 0) {
        perror("Send failed");
        close(sockfd);
        return -1;
    }

    // Receive ICMP packet
    socklen_t addr_len = sizeof(addr);
    if (recvfrom(sockfd, response, sizeof(response), 0, (struct sockaddr *)&addr, &addr_len) < 0) {
        perror("Receive failed");
        close(sockfd);
        return -1;
    }

    printf("Reply from %s: bytes=%d seq=%d\n", inet_ntoa(addr.sin_addr), PING_DATA_SIZE, PING_COUNT - count + 1);

    close(sockfd);

    // Recursive call for the next ping
    return ping_recursive(host, count - 1);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    const char *host = argv[1];
    printf("Pinging %s with %d packets...\n", host, PING_COUNT);
  
    if (ping_recursive(host, PING_COUNT) == -1) {
        fprintf(stderr, "Ping failed.\n");
        return 1;
    }

    printf("Ping completed.\n");
    return 0;
}