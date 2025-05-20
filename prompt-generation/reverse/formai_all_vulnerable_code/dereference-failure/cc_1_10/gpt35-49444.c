//FormAI DATASET v1.0 Category: Network Ping Test ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <time.h>

#define PACKET_SIZE 64
#define TIMEOUT_SEC 1
#define MAX_HOPS 30

// Function to calculate the checksum of a packet
unsigned short checksum(unsigned short *ptr, int len) {
    unsigned long sum = 0;
    while (len > 1) {
        sum += *ptr++;
        len -= 2;
    }
    if (len == 1)
        sum += *(unsigned char*) ptr;
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    return ~sum;
}

// Function to print a happy message indicating success
void print_happy_message(const char* msg) {
    printf(":) %s :D\n", msg);
}

// Function to print a sad message indicating failure
void print_sad_message(const char* msg) {
    printf(":( %s :( \n", msg);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(struct sockaddr_in));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (dest_addr.sin_addr.s_addr == INADDR_NONE) {
        struct hostent *he = gethostbyname(argv[1]);
        if (he == NULL) {
            print_sad_message("Invalid IP address or hostname!");
            exit(EXIT_FAILURE);
        }
        memcpy(&dest_addr.sin_addr.s_addr, he->h_addr_list[0], he->h_length);
    }

    printf("Pinging %s...\n", argv[1]);

    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    char packet[PACKET_SIZE];
    memset(packet, 0, sizeof(packet));
    struct icmp *icmp_packet = (struct icmp*) packet;
    icmp_packet->icmp_type = ICMP_ECHO;
    icmp_packet->icmp_code = 0;
    icmp_packet->icmp_id = getpid() & 0xFFFF;
    icmp_packet->icmp_seq = 0;
    icmp_packet->icmp_cksum = checksum((unsigned short *) icmp_packet, PACKET_SIZE);

    struct timespec start_time, end_time;
    struct timeval timeout = { TIMEOUT_SEC, 0 };
    int counter = 0;
    int hops = 1;

    while (hops <= MAX_HOPS) {
        setsockopt(sockfd, IPPROTO_IP, IP_TTL, &hops, sizeof(hops));
        if (sendto(sockfd, packet, sizeof(packet), 0, (struct sockaddr *) &dest_addr, sizeof(dest_addr)) < 0) {
            perror("sendto() failed");
            exit(EXIT_FAILURE);
        }

        printf("%d. ", hops);

        clock_gettime(CLOCK_MONOTONIC, &start_time);
        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(sockfd, &read_fds);
        int ready = select(sockfd + 1, &read_fds, NULL, NULL, &timeout);
        if (ready == 0) {
            printf("*\n"); // No response from the remote host
            hops++;
            counter = 0;
            continue;
        } else if (ready < 0) {
            perror("select() failed");
            exit(EXIT_FAILURE);
        }

        int bytes_recvd;
        socklen_t addr_len = sizeof(dest_addr);
        if ((bytes_recvd = recvfrom(sockfd, packet, sizeof(packet), 0, (struct sockaddr *)&dest_addr, &addr_len)) < 0) {
            perror("recvfrom() failed");
            exit(EXIT_FAILURE);
        }

        clock_gettime(CLOCK_MONOTONIC, &end_time);
        double duration = (end_time.tv_sec - start_time.tv_sec) * 1000 + (end_time.tv_nsec - start_time.tv_nsec) / 1000000.0;

        struct iphdr *ip_packet = (struct iphdr*) packet;
        struct icmp *icmp_packet_resp = (struct icmp*) (packet + (ip_packet->ihl * 4));
        if (icmp_packet_resp->icmp_type == ICMP_ECHOREPLY) {
            printf("%.1f ms\n", duration);
            print_happy_message("Packet sent and received successfully!");
            exit(EXIT_SUCCESS);
        } else {
            printf("*\n"); // Response packet not an ECHO reply
        }

        counter++;
        if (counter == 3) {
            hops++;
            counter = 0;
        }
    }

    print_sad_message("Max hop count reached.");
    return 0;
}