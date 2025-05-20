//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PING_SIZE 56

void my_ping(char *host) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char sendline[PING_SIZE];
    char recvline[PING_SIZE];
    struct timeval start, end;
    double timetaken;

    // Create a raw socket for ICMP
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set the ICMP header
    memset(sendline, 0, PING_SIZE);
    sendline[0] = 8; // ICMP type (echo request)
    sendline[1] = 0; // ICMP code
    sendline[2] = 0; // ICMP checksum (will be calculated later)
    sendline[3] = 0; // ICMP identifier
    sendline[4] = 0; // ICMP sequence number

    // Calculate the ICMP checksum
    sendline[2] = calculate_icmp_checksum(sendline, PING_SIZE);

    // Resolve the hostname
    struct hostent *host_info = gethostbyname(host);
    if (host_info == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    // Set the destination address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(0);
    memcpy(&servaddr.sin_addr, host_info->h_addr, host_info->h_length);

    // Send the ICMP packet
    gettimeofday(&start, NULL);
    n = sendto(sockfd, sendline, PING_SIZE, 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (n < 0) {
        perror("sendto");
        exit(EXIT_FAILURE);
    }

    // Wait for the response
    n = recvfrom(sockfd, recvline, PING_SIZE, 0, NULL, NULL);
    if (n < 0) {
        perror("recvfrom");
        exit(EXIT_FAILURE);
    }

    // Calculate the time taken
    gettimeofday(&end, NULL);
    timetaken = (end.tv_sec - start.tv_sec) * 1000.0;
    timetaken += (end.tv_usec - start.tv_usec) / 1000.0;

    // Print the results
    printf("Reply from %s: bytes=%d time=%.3f ms\n", host, n, timetaken);

    // Close the socket
    close(sockfd);
}

int calculate_icmp_checksum(unsigned char *buf, int len) {
    unsigned long sum = 0;
    int i;

    for (i = 0; i < len; i += 2) {
        sum += (unsigned short)(buf[i] << 8 | buf[i + 1]);
    }

    while (sum >> 16) {
        sum = (sum & 0xFFFF) + (sum >> 16);
    }

    return ~sum;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s hostname\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    my_ping(argv[1]);

    exit(EXIT_SUCCESS);
}