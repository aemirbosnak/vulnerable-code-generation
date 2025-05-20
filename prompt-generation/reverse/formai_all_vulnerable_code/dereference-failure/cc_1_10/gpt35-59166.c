//FormAI DATASET v1.0 Category: Network Ping Test ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <unistd.h>
#include <netdb.h>
#include <fcntl.h>
#include <time.h>
#include <sys/time.h>

#define BUFFER_SIZE 1024
#define ECHO_REQUEST 8
#define ECHO_REPLY 0

struct icmp_packet {
    u_int8_t type;
    u_int8_t code;
    u_int16_t checksum;
    u_int16_t id;
    u_int16_t sequence;
};

struct icmp_reply {
    struct iphdr ip_header;
    struct icmp_packet icmp_header;
    char data[BUFFER_SIZE - sizeof(struct iphdr) - sizeof(struct icmp_packet)];
};

struct ping_statistics {
    int transmitted_packets;
    int received_packets;
    double latency;
    double min_latency;
    double max_latency;
    double avg_latency;
};

int calculate_checksum(unsigned short *addr, int len) {
    int nleft = len;
    int sum = 0;
    unsigned short *w = addr;
    unsigned short answer = 0;

    while (nleft > 1) {
        sum += *w++;
        nleft -= 2;
    }

    if (nleft == 1) {
        *(unsigned char *)(&answer) = *(unsigned char *)w;
        sum += answer;
    }

    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    answer = ~sum;

    return answer;
}

double get_current_time() {
    struct timeval time;
    gettimeofday(&time, NULL);
    return (double) time.tv_sec + (double) time.tv_usec / 1000000.0;
}

int dns_lookup(char *host_name, struct sockaddr_in *addr) {
    struct hostent *host_info;

    host_info = gethostbyname(host_name);
    if (!host_info) {
        fprintf(stderr, "Error: Cannot resolve hostname %s\n", host_name);
        return -1;
    }

    addr->sin_family = AF_INET;
    addr->sin_addr = *(struct in_addr *) host_info->h_addr;

    return 0;
}

int send_icmp_packet(int sock, struct sockaddr_in *addr, int seq) {
    int packet_len;
    int sent_bytes;
    struct icmp_packet icmp_packet;
    char buffer[BUFFER_SIZE];

    icmp_packet.type = ECHO_REQUEST;
    icmp_packet.code = 0;
    icmp_packet.id = getpid() & 0xFFFF;
    icmp_packet.sequence = seq;
    icmp_packet.checksum = 0;
    memset(buffer, 0, BUFFER_SIZE);
    memcpy(buffer, &icmp_packet, sizeof(struct icmp_packet));
    icmp_packet.checksum = calculate_checksum((unsigned short *) buffer, sizeof(struct icmp_packet));
    memcpy(buffer, &icmp_packet, sizeof(struct icmp_packet));
    packet_len = sizeof(struct icmp_packet);

    sent_bytes = sendto(sock, buffer, packet_len, 0, (struct sockaddr *) addr, sizeof(struct sockaddr));
    if (sent_bytes == -1) {
        perror("Error: Cannot send ICMP packet\n");
        return -1;
    }

    return sent_bytes;
}

int receive_icmp_reply(int sock, struct sockaddr_in *addr, struct icmp_reply *icmp_reply, double start_time) {
    int addr_len = sizeof(struct sockaddr);
    char buffer[BUFFER_SIZE];
    int bytes_received;
    double end_time;

    bytes_received = recvfrom(sock, buffer, BUFFER_SIZE, 0, (struct sockaddr *) addr, (socklen_t *) &addr_len);

    if (bytes_received == -1) {
        perror("Error: Cannot receive ICMP reply\n");
        return -1;
    }

    end_time = get_current_time();
    icmp_reply->ip_header = *(struct iphdr *) buffer;
    memcpy(&icmp_reply->icmp_header, buffer + sizeof(struct iphdr), sizeof(struct icmp_packet));
    memcpy(icmp_reply->data, buffer + sizeof(struct iphdr) + sizeof(struct icmp_packet), bytes_received - sizeof(struct iphdr) - sizeof(struct icmp_packet));
    if (icmp_reply->icmp_header.type == ECHO_REPLY) {
        icmp_reply->icmp_header.checksum = ntohs(icmp_reply->icmp_header.checksum);
        icmp_reply->icmp_header.sequence = ntohs(icmp_reply->icmp_header.sequence);
        icmp_reply->icmp_header.id = ntohs(icmp_reply->icmp_header.id);
        icmp_reply->ip_header.saddr = ntohl(icmp_reply->ip_header.saddr);
        icmp_reply->ip_header.daddr = ntohl(icmp_reply->ip_header.daddr);
        icmp_reply->icmp_header.type = ntohl(icmp_reply->icmp_header.type);
        icmp_reply->icmp_header.code = ntohl(icmp_reply->icmp_header.code);
        icmp_reply->icmp_header.checksum = ntohl(icmp_reply->icmp_header.checksum);
        icmp_reply->icmp_header.sequence = ntohl(icmp_reply->icmp_header.sequence);
        icmp_reply->icmp_header.id = ntohl(icmp_reply->icmp_header.id);
        icmp_reply->icmp_header.checksum = 0;
        if (calculate_checksum((unsigned short *) &icmp_reply->icmp_header, sizeof(struct icmp_packet)) != icmp_reply->icmp_header.checksum) {
            printf("Error: Invalid ICMP packet received\n");
            return -1;
        }

        printf("%d bytes from %s: icmp_seq=%d time=%.3f ms\n", bytes_received - sizeof(struct iphdr) - sizeof(struct icmp_packet),
               inet_ntoa(addr->sin_addr), icmp_reply->icmp_header.sequence, (end_time - start_time) * 1000);

        return bytes_received - sizeof(struct iphdr) - sizeof(struct icmp_packet);
    }

    return -1;
}

int ping(char *host_name, int count, int interval) {
    struct sockaddr_in addr;
    int sock;
    int seq = 0;
    struct icmp_reply icmp_reply;
    struct ping_statistics statistics = {0, 0, 0, 100000, 0, 0}; // Transmit, Received, Timing, Min, Max, Average
    double start_time;

    if (dns_lookup(host_name, &addr) == -1) {
        return -1;
    }

    sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sock == -1) {
        perror("Error: Cannot create socket\n");
        return -1;
    }

    fcntl(sock, F_SETFL, O_NONBLOCK);

    printf("PING %s (%s):\n", host_name, inet_ntoa(addr.sin_addr));

    while (seq < count) {
        statistics.transmitted_packets++;
        start_time = get_current_time();

        if (send_icmp_packet(sock, &addr, seq) < 0) {
            continue;
        }

        if (receive_icmp_reply(sock, &addr, &icmp_reply, start_time) < 0) {
            printf("icmp_seq=%d Request timed out\n", seq);
        } else {
            statistics.received_packets++;
            statistics.latency += (get_current_time() - start_time) * 1000;

            if (statistics.min_latency > (get_current_time() - start_time) * 1000) {
                statistics.min_latency = (get_current_time() - start_time) * 1000;
            }

            if (statistics.max_latency < (get_current_time() - start_time) * 1000) {
                statistics.max_latency = (get_current_time() - start_time) * 1000;
            }
        }

        seq++;
        if (seq == count) {
            break;
        }

        sleep(interval);
    }

    statistics.avg_latency = (double) statistics.latency / statistics.received_packets;

    printf("%d packets transmitted, %d packets received, %.2f%% packet loss\n", statistics.transmitted_packets,
           statistics.received_packets, (double) (statistics.transmitted_packets - statistics.received_packets) / statistics.transmitted_packets * 100);
    printf("Round-trip min/avg/max = %.3f/%.3f/%.3f ms\n", statistics.min_latency, statistics.avg_latency, statistics.max_latency);

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <hostname> [-c count] [-i interval]\n", argv[0]);
        return -1;
    }

    int count = 5;
    int interval = 1;
    int i;

    for (i = 2; i < argc; i++) {
        if (strcmp(argv[i], "-c") == 0 && i + 1 < argc) {
            count = atoi(argv[i + 1]);
            if (count < 1) {
                printf("Error: Invalid count parameter\n");
                return -1;
            }
            i++;
        } else if (strcmp(argv[i], "-i") == 0 && i + 1 < argc) {
            interval = atoi(argv[i + 1]);
            if (interval < 1) {
                printf("Error: Invalid interval parameter\n");
                return -1;
            }
            i++;
        } else {
            printf("Error: Invalid argument %s\n", argv[i]);
            return -1;
        }
    }

    return ping(argv[1], count, interval);
}