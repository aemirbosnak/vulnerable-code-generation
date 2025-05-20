//FormAI DATASET v1.0 Category: Network Ping Test ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define PACKETSIZE 64

/* Checksum function */
unsigned short checksum(void* b, int len) {
    unsigned short* buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2) {
        sum += *buf++;
    }
    if (len == 1) {
        sum += *(unsigned char*)buf;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

/* Main function */
int main(int argc, char** argv) {
    struct sockaddr_in recipient;
    struct icmp* icmp_packet;
    struct timeval time_out, start_time, end_time;
    struct hostent* host;
    fd_set fdset;
    int socket_fd, ttl_value, sequence = 0, packets_received = 0, packets_sent = 0;
    long int total_time = 0;
    char packet[PACKETSIZE];
    char recipient_ip[20];

    /* Check for argument count */
    if (argc != 2) {
        printf("Invalid arguments supplied\nUsage: %s <hostname or IP address>\n", argv[0]);
        exit(1);
    }
    /* Get host information */
    host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("Unable to resolve hostname or IP address\n");
        exit(1);
    }

    /* Convert host address to string */
    inet_ntop(AF_INET, host->h_addr, recipient_ip, INET_ADDRSTRLEN);

    /* Open raw socket for ICMP */
    socket_fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (socket_fd == -1) {
        perror("Failed to create socket");
        exit(1);
    }

    /* Set TTL value */
    ttl_value = 64;
    if (setsockopt(socket_fd, IPPROTO_IP, IP_TTL, &ttl_value, sizeof(int)) != 0) {
        perror("Failed to set TTL value");
        exit(1);
    }

    /* Prepare ICMP packet */
    icmp_packet = (struct icmp*)packet;
    icmp_packet->icmp_type = ICMP_ECHO;
    icmp_packet->icmp_code = 0;
    icmp_packet->icmp_hun.ih_idseq.icd_id = getpid();
    icmp_packet->icmp_hun.ih_idseq.icd_seq = sequence++;
    memset(icmp_packet->icmp_data, 'A', PACKETSIZE - (int)sizeof(struct icmp));

    /* Calculate ICMP packet checksum */
    icmp_packet->icmp_cksum = checksum((unsigned short*)icmp_packet, PACKETSIZE);

    /* Set recipient address */
    bzero(&recipient, sizeof(recipient));
    recipient.sin_family = AF_INET;
    inet_pton(AF_INET, recipient_ip, &(recipient.sin_addr));

    /* Start sending ICMP packets */
    printf("\nPinging %s (%s):\n", argv[1], recipient_ip);

    while (packets_sent < 10) {
        if (sendto(socket_fd, packet, PACKETSIZE, 0, (struct sockaddr*)&recipient, sizeof(recipient)) <= 0) {
            perror("Failed to send ICMP packet");
        } else {
            packets_sent++;
            gettimeofday(&start_time, NULL);
        }

        FD_ZERO(&fdset);
        FD_SET(socket_fd, &fdset);

        /* Set timeout for response */
        time_out.tv_sec = 1;
        time_out.tv_usec = 0;

        if (select(socket_fd + 1, &fdset, NULL, NULL, &time_out) == 1) {
            struct sockaddr_in sender;
            socklen_t sender_len;
            int data_len;
            char data[PACKETSIZE];

            gettimeofday(&end_time, NULL);

            /* Receive response */
            sender_len = sizeof(sender);
            if ((data_len = recvfrom(socket_fd, data, PACKETSIZE, 0, (struct sockaddr*)&sender, &sender_len)) == -1) {
                perror("Failed to receive ICMP packet");
            } else {
                packets_received++;
                total_time += (end_time.tv_sec - start_time.tv_sec) * 1000000 + (end_time.tv_usec - start_time.tv_usec);
                printf("%d bytes from %s: icmp_seq=%d time=%ld ms\n", data_len, recipient_ip, sequence, total_time / 1000);
            }
            usleep(100000);
        } else {
            printf("Request timed out\n");
        }
    }

    /* Calculate packet statistics */
    printf("\n--- %s ping statistics ---\n", argv[1]);
    printf("%d packets transmitted, %d received, %0.0f%% packet loss, time %ld ms\n", packets_sent, packets_received, ((float)(packets_sent - packets_received) / packets_sent) * 100, total_time / 1000);
    close(socket_fd);
    return 0;
}