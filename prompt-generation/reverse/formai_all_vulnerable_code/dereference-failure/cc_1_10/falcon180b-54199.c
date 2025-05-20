//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_HOSTNAME_SIZE 256
#define MAX_DATA_SIZE 1024

// Function to print error message and exit program
void error(char *message) {
    perror(message);
    exit(1);
}

// Function to send ICMP echo request packet
void send_icmp_packet(int sockfd, const char *hostname) {
    struct sockaddr_in dest_addr;
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(7); // ICMP protocol port number
    inet_pton(AF_INET, hostname, &dest_addr.sin_addr);

    char data[MAX_DATA_SIZE];
    memset(data, 0, MAX_DATA_SIZE);
    strcpy(data, "PING");

    sendto(sockfd, data, strlen(data), 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
}

// Function to receive ICMP echo reply packet
void receive_icmp_packet(int sockfd, char *hostname) {
    struct sockaddr_in src_addr;
    socklen_t addr_len = sizeof(src_addr);
    char data[MAX_DATA_SIZE];

    memset(data, 0, MAX_DATA_SIZE);
    int bytes_received = recvfrom(sockfd, data, MAX_DATA_SIZE, 0, (struct sockaddr *)&src_addr, &addr_len);

    if (bytes_received > 0) {
        data[bytes_received] = '\0';
        printf("Received ICMP echo reply from %s: %s\n", inet_ntoa(src_addr.sin_addr), data);
    } else {
        printf("No ICMP echo reply received from %s\n", hostname);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) == -1) {
        error("socket");
    }

    char hostname[MAX_HOSTNAME_SIZE];
    strcpy(hostname, argv[1]);

    send_icmp_packet(sockfd, hostname);
    receive_icmp_packet(sockfd, hostname);

    close(sockfd);
    return 0;
}