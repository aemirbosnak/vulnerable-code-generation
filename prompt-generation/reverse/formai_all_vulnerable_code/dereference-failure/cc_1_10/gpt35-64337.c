//FormAI DATASET v1.0 Category: Network Ping Test ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>

#define PACKETSIZE  64
#define MAXHOSTNAMELEN  128
#define MAXTRIES 4
#define MAXTIMEOUT 4

/* A simple structure to hold the time and sequence number
 * of each packet sent/received. */
struct packet {
    struct timeval tv;
    int seq;
};

/* Some global variables */
char *hostname = NULL;
int sockfd = -1;
struct sockaddr_in target_addr;
int seq = 0;
struct packet packets[MAXTRIES];
int n_packets = 0;

/* A function to calculate the 1's complement checksum */
unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2)
        sum += *buf++;
    if (len == 1)
        sum += *(unsigned char *) buf;
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

/* A function to send a ping packet */
void send_ping(int seq) {
    struct icmp *icmp = NULL;
    char packet[PACKETSIZE];
    int packet_size = 0;

    icmp = (struct icmp *) packet;
    icmp->icmp_type = ICMP_ECHO;
    icmp->icmp_code = 0;
    icmp->icmp_id = getpid();
    icmp->icmp_seq = seq;
    memset(&icmp->icmp_data, 0xa5, PACKETSIZE - sizeof(struct icmphdr));
    icmp->icmp_cksum = 0;
    icmp->icmp_cksum = checksum(icmp, PACKETSIZE);
    packet_size = ICMP_MINLEN + PACKETSIZE - sizeof(struct icmphdr);
    sendto(sockfd, packet, packet_size, 0, (struct sockaddr *) &target_addr, sizeof(target_addr));
}

/* A function to receive a ping packet */
int recv_ping(int timeout) {
    fd_set readfds;
    struct timeval tv;
    int n;
    socklen_t len = sizeof(target_addr);
    char packet[PACKETSIZE];

    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);

    tv.tv_sec = timeout;
    tv.tv_usec = 0;

    n = select(sockfd + 1, &readfds, NULL, NULL, &tv);
    if (n == -1) {
        perror("select");
        return 0;
    }
    if (n == 0) {
        return 0;
    }

    n = recvfrom(sockfd, packet, PACKETSIZE, 0, (struct sockaddr *) &target_addr, &len);
    if (n == -1) {
        perror("recvfrom");
        return 0;;
    }
    return 1;
}

/* A function to print the results of the ping test */
void print_results() {
    int n_received = 0;
    int i;
    float avg_rtt = 0.0;
    float max_rtt = 0.0;
    float min_rtt = MAXTIMEOUT * 1.0;

    for (i = 0; i < n_packets; i++) {
        if (packets[i].tv.tv_sec == 0 && packets[i].tv.tv_usec == 0) {
            continue;
        }
        n_received++;
        float rtt = packets[i].tv.tv_sec * 1000.0 + (packets[i].tv.tv_usec / 1000.0);
        if (rtt > max_rtt) {
            max_rtt = rtt;
        }
        if (rtt < min_rtt) {
            min_rtt = rtt;
        }
        avg_rtt += rtt;
    }

    if (n_received == 0) {
        printf("No packets received\n");
    } else {
        avg_rtt /= n_received;
        printf("%d packets transmitted, %d packets received, %d%% packet loss\n", n_packets, n_received,
               (int) ((n_packets - n_received) * 100 / n_packets));
        printf("round-trip min/avg/max = %.3f/%.3f/%.3f ms\n", min_rtt, avg_rtt, max_rtt);
    }
}

/* The main function */
int main(int argc, char *argv[]) {
    struct hostent *host = NULL;
    int i = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    hostname = argv[1];

    /* Create a raw socket */
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    /* Get the address of the host */
    host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Unknown host: %s\n", hostname);
        exit(EXIT_FAILURE);
    }

    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = *(unsigned long *) (host->h_addr_list[0]);
    target_addr.sin_port = 0;

    printf("PING %s (%s):\n", hostname, inet_ntoa(target_addr.sin_addr));

    /* Send and receive packets */
    for (i = 0; i < MAXTRIES; i++) {
        int timeout = 1;
        int success = 0;

        n_packets++;
        packets[i].seq = seq++;
        packets[i].tv.tv_sec = 0;
        packets[i].tv.tv_usec = 0;

        send_ping(packets[i].seq);

        while (timeout <= MAXTIMEOUT) {
            success = recv_ping(timeout);
            if (success) {
                break;
            } else {
                timeout++;
            }
        }

        if (success) {
            if (timeout == 1) {
                printf("  Reply from %s: icmp_seq=%d time=<1ms\n",
                       inet_ntoa(target_addr.sin_addr), packets[i].seq);
            } else {
                float rtt = (timeout * 1000.0);
                printf("  Reply from %s: icmp_seq=%d time=%.3f ms\n",
                       inet_ntoa(target_addr.sin_addr), packets[i].seq, rtt);
                packets[i].tv.tv_sec = timeout;
                packets[i].tv.tv_usec = (rtt - packets[i].tv.tv_sec * 1000.0) * 1000.0;
            }
        } else {
            printf("  Request timed out.\n");
        }
    }

    /* Print the results */
    print_results();

    /* Close the socket */
    close(sockfd);

    return 0;
}