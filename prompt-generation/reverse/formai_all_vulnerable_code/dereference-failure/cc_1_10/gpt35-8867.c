//FormAI DATASET v1.0 Category: Network Ping Test ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>

#define PING_SIZE 64
#define PING_WAIT_TIME 1

struct icmp_packet {
    uint8_t type;
    uint8_t code;
    uint16_t checksum;
    uint16_t id;
    uint16_t sequence;
    struct timeval timestamp;
};

unsigned short calc_checksum(unsigned short *addr, int len);

int main(int argc, char **argv) {

    if (argc < 2) {
        printf("Usage: %s <host>\n", argv[0]);
        return 1;
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = 0;
    inet_aton(argv[1], &address.sin_addr);

    struct hostent *host = gethostbyname(argv[1]);
    if (!host) {
        printf("Error: Could not resolve hostname.\n");
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        printf("Error: socket() failed.\n");
        return 1;
    }

    int ttl = 64;
    if (setsockopt(sockfd, IPPROTO_IP, IP_TTL, (const char*)&ttl, sizeof(ttl)) < 0) {
        printf("Error: Unable to set socket option.\n");
        return 1;
    }

    int sequence = 0, transmitted = 0, received = 0;
    const char *hostname = host->h_name;
    char buf[1024] = {0};

    struct timeval start, end;
    double rtt;
    double max = -1000, min = 1000, total = 0;

    // Send ICMP ECHO REQUEST
    while (transmitted < 4) {
        struct icmp_packet packet;
        memset(&packet, 0, sizeof(packet));
        packet.type = 8;
        packet.code = 0;
        packet.id = getpid();
        packet.sequence = sequence++;
        gettimeofday(&packet.timestamp, NULL);
        packet.checksum = calc_checksum((unsigned short*)&packet, sizeof(packet));

        int sent = sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr*)&address, sizeof(address));
        if (sent < 0) {
            printf("Error: Could not send packet.\n");
            continue;
        }

        printf("%d bytes from %s [%s] icmp_seq=%d ttl=%d time=%f ms\n", sent, hostname, inet_ntoa(address.sin_addr), transmitted, ttl, rtt);

        transmitted++;

        // Wait for PING_WAIT_TIME seconds for a response
        struct timeval timeout;
        timeout.tv_sec = PING_WAIT_TIME;
        timeout.tv_usec = 0;

        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(sockfd, &read_fds);

        int ready = select(sockfd + 1, &read_fds, NULL, NULL, &timeout);
        if (ready == -1) {
            printf("Error: Select() failed.\n");
            break;
        } else if (ready == 0) {
            printf("Request timed out.\n");
            continue;
        } else {
            // Receive ICMP ECHO RESPONSE
            struct sockaddr_in from;
            socklen_t fromlen = sizeof(from);
            int recv = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr*)&from, &fromlen);
            if (recv < 0) {
                printf("Error: Could not receive packet.\n");
                continue;
            }

            gettimeofday(&end, NULL);
            struct icmp_packet *response = (struct icmp_packet*)buf;
            if (response->type == 0 && response->id == getpid() && response->sequence == sequence-1) {
                received++;
                timersub(&end, &response->timestamp, &end);
                rtt = (double)end.tv_sec * 1000.0 + (double)end.tv_usec / 1000.0;
                total += rtt;
                if (rtt < min) {
                    min = rtt;
                } 
                if (rtt > max) {
                    max = rtt;
                }
            }
        }
        sleep(1);
    }

    printf("\n--- %s ping statistics ---\n", hostname);
    printf("%d packets transmitted, %d packets received, %d%% packet loss\n", transmitted, received, (transmitted - received) * 100 / transmitted);
    if (received) {
        printf("round-trip min/avg/max = %f/%f/%f ms\n", min, total/received, max);
    }

    close(sockfd);

    return 0;
}

unsigned short calc_checksum(unsigned short *addr, int len) {
    int sum = 0;
    unsigned short checksum = 0;
    while (len > 1) {
        sum += *addr++;
        len -= 2;
    }
    if (len == 1) {
        sum += *((unsigned char*)addr);
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    checksum = ~sum;
    return checksum;
}