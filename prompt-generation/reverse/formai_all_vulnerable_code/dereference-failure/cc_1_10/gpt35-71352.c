//FormAI DATASET v1.0 Category: Network Ping Test ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <signal.h>
#include <errno.h>
#include <sys/time.h>

#define PACKETSIZE      64

int sockicmp;
int ttl_exceeded = 0;

void statistics(int data_sent[]) {
    int packets_sent = data_sent[0];
    int packets_received = data_sent[1];
    int packets_lost = packets_sent - packets_received;

    printf("\n----------- Ping Statistics -----------\n");
    printf("%d packets sent, %d packets received, %.2f%% packet loss\n"
           , packets_sent, packets_received, ((float) packets_lost/packets_sent)*100);
}

unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for ( sum = 0; len > 1; len -= 2 )
        sum += *buf++;
    if ( len == 1 )
        sum += *(unsigned char*)buf;
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;

    return result;
}

void intHandler(int dummy) {
    statistics((int[]) {0, 0});
    close(sockicmp);
    exit(0);
}

void handle_sigalarm(int sig) {
    ttl_exceeded = 1;
    signal(sig, SIG_IGN);
}

void send_packet(struct sockaddr_in *target, int packet_no) {
    char packet[PACKETSIZE];
    struct icmp *icmp;
    struct timeval *tval;

    icmp = (struct icmp *) packet;
    icmp->icmp_type = ICMP_ECHO;
    icmp->icmp_code = 0;
    icmp->icmp_id = getpid();
    icmp->icmp_seq = packet_no;
    tval = (struct timeval *) icmp->icmp_data;
    gettimeofday(tval, NULL);
    icmp->icmp_cksum = 0;
    icmp->icmp_cksum = checksum(icmp, PACKETSIZE);

    if (sendto(sockicmp, packet, PACKETSIZE, 0,
               (struct sockaddr *) target, sizeof(*target)) < 0) {
        printf("Error while sending packet to target.\n");
        exit(2);
    }
}

void receive_packet(struct sockaddr_in *target, int packet_no, struct timeval *start) {
    char packet[PACKETSIZE];
    struct iphdr *ip;
    struct timeval *tval_rcv;
    struct icmp *icmp;
    int n;

    ip = (struct iphdr *) packet;
    icmp = (struct icmp *) (packet + sizeof(struct iphdr));
    tval_rcv = (struct timeval *) icmp->icmp_data;
    long elapsed_time = ((int)time(NULL) - start->tv_sec)*1000 + (int)((1000000 + start->tv_usec - tval_rcv->tv_usec) / 1000);

    if ((n = recv(sockicmp, packet, sizeof(packet), 0)) < 0) {
        printf("Error while receiving packet from target.\n");
        exit(2);
    }

    if (icmp->icmp_type == ICMP_ECHOREPLY) {
        printf("%d bytes from %s: icmp_seq=%d time=%ldms\n",
               n, inet_ntoa(target->sin_addr), packet_no, elapsed_time);
    } else if (icmp->icmp_type == ICMP_TIME_EXCEEDED) {
        ttl_exceeded = 1;
        printf("Time Exceeded Message Occurred after %ld ms\n", elapsed_time);
    }
}

int main(int argc, char * argv[]) {
    struct sockaddr_in target;
    struct hostent *host;
    struct sigaction sa;
    struct timeval start;
    struct timeval end;
    socklen_t target_addr_len = sizeof(target);
    int packet_no = 0;
    int data_sent[] = {0, 0};
    char *hostname;
    int timeout = 1;
    int i;

    if (argc != 2) {
        printf("Usage: ./ping <hostname>\n");
        exit(1);
    }

    hostname = argv[1];

    if ((sockicmp = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        printf("Could not create socket.\n");
        exit(2);
    }

    memset(&sa, 0, sizeof(sa));
    sa.sa_flags = 0;
    sa.sa_handler = &handle_sigalarm;

    if (sigaction(SIGALRM, &sa, NULL) < 0) {
        printf("Could not set signal handler.\n");
        exit(2);
    }

    host = gethostbyname(hostname);

    if (!host) {
        printf("Could not resolve hostname %s\n", hostname);
        exit(2);
    }

    printf("Starting ping to %s with %d bytes of data.\n", hostname, PACKETSIZE);

    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_addr = *(struct in_addr *) (host->h_addr);

    while (1) {
        ttl_exceeded = 0;
        packet_no++;

        send_packet(&target, packet_no);
        data_sent[0]++;
        alarm(timeout);

        gettimeofday(&start, NULL);

        while(!ttl_exceeded) {
            if (recvfrom(sockicmp, NULL, 0, MSG_DONTWAIT, (struct sockaddr *)&target, &target_addr_len) > 0) {
                receive_packet(&target, packet_no, &start);
                data_sent[1]++;
                break;
            }
        }

        alarm(0);

        usleep(1000);

        if (packet_no >= 10) {
            statistics(data_sent);
            close(sockicmp);
            exit(0);
        }
    }
    return 0;
}