//FormAI DATASET v1.0 Category: Network Ping Test ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <signal.h>

#define PACKET_SIZE         64
#define MAX_WAIT_TIME       5
#define MAX_NO_OF_PACKETS   3

struct icmp_packet {
    struct icmphdr header;
    char data[PACKET_SIZE - sizeof(struct icmphdr)];
};

struct ping_statistics {
    int total_packets_sent;
    int packets_received;
    time_t start_time;
    time_t end_time;
    float min_rtt;
    float max_rtt;
    float avg_rtt;
    float total_rtt;
};

int sockfd;
int packets_received = 0;
struct sockaddr_in target_addr;
char sendpacket[PACKET_SIZE];
char recvpacket[PACKET_SIZE];
struct ping_statistics stats;

void interruption_handler(int signo) {
    exit(1);
}

unsigned short calculate_checksum(unsigned short *paddr, int len) {
    unsigned int sum = 0;
    unsigned short answer = 0;
    unsigned short *addr = paddr;
    int nleft = len;

    while (nleft > 1) {
        sum += *addr++;
        nleft -= 2;
    }

    if (nleft == 1) {
        *(unsigned char *)(&answer) = *(unsigned char *)addr;
        sum += answer;
    }

    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    answer = ~sum;

    return answer;
}

void send_packet(int sequence_number) {
    struct icmp_packet packet;

    packet.header.type = ICMP_ECHO;
    packet.header.code = 0;
    packet.header.un.echo.id = getpid() & 0xFFFF;
    packet.header.un.echo.sequence = sequence_number;
    memset(packet.data, sequence_number, sizeof(packet.data));
    packet.header.checksum = calculate_checksum((unsigned short *)&packet, sizeof(packet));

    if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&target_addr, sizeof(target_addr)) == -1) {
        perror("sendto() failed");
    }

    stats.total_packets_sent++;
}

float get_rtt(struct timespec *sent_time) {
    struct timespec received_time;
    clock_gettime(CLOCK_MONOTONIC, &received_time);
    long elapsed_time = (received_time.tv_sec - sent_time->tv_sec) * 1000 + (received_time.tv_nsec - sent_time->tv_nsec) / 1000000.0;
    return elapsed_time;
}

void receive_packet() {
    struct icmp_packet packet;
    struct sockaddr_in sender_addr;
    int sender_addr_len = sizeof(sender_addr);
    int packet_len;

    if ((packet_len = recvfrom(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&sender_addr, &sender_addr_len)) == -1) {
        fprintf(stderr, "recvfrom() failed: %s", strerror(errno));
        return;
    }

    if (packet_len < sizeof(struct icmphdr)) {
        fprintf(stderr, "received packet too small (%d bytes)", packet_len);
        return;
    }

    if (packet.header.type == ICMP_ECHOREPLY) {
        packets_received++;

        float elapsed_time = get_rtt((struct timespec *)packet.data);
        stats.total_rtt += elapsed_time;

        if (elapsed_time < stats.min_rtt || stats.min_rtt == 0) {
            stats.min_rtt = elapsed_time;
        }

        if (elapsed_time > stats.max_rtt) {
            stats.max_rtt = elapsed_time;
        }

        printf("%d bytes from %s: icmp_seq=%d ttl=%d time=%.3f ms\n", packet_len, inet_ntoa(sender_addr.sin_addr), packet.header.un.echo.sequence, packet.header.un.echo.id, elapsed_time);
    }
}

void print_statistics() {
    stats.end_time = time(NULL);
    float average_rtt = stats.total_rtt / packets_received;

    printf("\n--- %s ping statistics ---\n", inet_ntoa(target_addr.sin_addr));
    printf("%d packets transmitted, %d received, %d%% packet loss, time %dms\n", stats.total_packets_sent, packets_received, (int)(100.0 * (stats.total_packets_sent - packets_received) / stats.total_packets_sent), (int)(1000 * (stats.end_time - stats.start_time)));
    printf("rtt min/avg/max = %.3f/%.3f/%.3f ms\n", stats.min_rtt, average_rtt, stats.max_rtt);
}

void ping(const char *ip_address) {
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd == -1) {
        perror("socket() failed");
        exit(1);
    }

    struct hostent *host = gethostbyname(ip_address);
    if (host == NULL) {
        fprintf(stderr, "gethostbyname() failed: %s", hstrerror(h_errno));
        exit(1);
    }

    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    memcpy(&target_addr.sin_addr, host->h_addr_list[0], host->h_length);

    int i = 0;
    while (i < MAX_NO_OF_PACKETS) {
        send_packet(i);
        receive_packet();
        i++;

        if (i == MAX_NO_OF_PACKETS) {
            print_statistics();
        }

        sleep(1);
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    signal(SIGINT, interruption_handler);

    stats.start_time = time(NULL);
    ping(argv[1]);

    return 0;
}