//FormAI DATASET v1.0 Category: Network Ping Test ; Style: recursive
#include <stdio.h>             // for standard input/output
#include <netinet/in.h>        // for sockaddr_in, htons, INADDR_ANY
#include <netinet/ip_icmp.h>   // for ICMP header
#include <arpa/inet.h>         // for inet_ntoa
#include <netdb.h>             // for gethostbyname
#include <string.h>            // for memset
#include <sys/socket.h>        // for socket, setsockopt, recvfrom
#include <sys/time.h>          // for gettimeofday
#include <unistd.h>            // for usleep

#define BUFSIZE 4096           // maximum buffer size
#define ICMP_ECHO 8            // echo request type for ICMP packet
#define ICMP_ECHOREPLY 0       // echo reply type for ICMP packet

int sockfd;                    // socket file descriptor
struct sockaddr_in sender;     // sender address
int sequence;                  // sequence number of ping packet
char buffer[BUFSIZE];          // buffer to store data

// Function to calculate checksum of ICMP packet data
unsigned short chksum(unsigned short *data, int len) {
    unsigned int sum = 0;
    for (int i = 0; i < len/2; i++) {
        sum += data[i];
    }
    if (len % 2 == 1) {
        sum += ((unsigned short) *((u_char *)data + len - 1)) << 8;
    }
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    return ~sum;
}

// Function to send ICMP echo request packet to host
void send_ping(char *host) {
    struct hostent *he;
    he = gethostbyname(host);
    if (he == NULL) {
        perror("gethostbyname");
        return;
    }

    struct icmphdr icmp;
    icmp.type = ICMP_ECHO;
    icmp.code = 0;
    icmp.checksum = 0;
    icmp.un.echo.id = getpid() & 0xFFFF;
    icmp.un.echo.sequence = sequence++;

    memset(buffer, 0, BUFSIZE);
    memcpy(buffer, &icmp, sizeof(struct icmphdr));
    icmp.checksum = chksum((unsigned short *) &buffer, sizeof(struct icmphdr));
    memcpy(buffer, &icmp, sizeof(struct icmphdr));

    if (sendto(sockfd, buffer, sizeof(struct icmphdr), 0, (struct sockaddr *)&sender, sizeof(sender)) == -1) {
        perror("sendto");
    }
}

// Function to receive ICMP echo reply packet from host
void recv_ping(int timeout) {
    unsigned char buf[BUFSIZE];
    struct timeval tv;
    tv.tv_sec = timeout;
    tv.tv_usec = 0;
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);
    if (select(sockfd+1, &readfds, NULL, NULL, &tv) <= 0) {
        printf("Request timed out.\n");
        return;
    }
    socklen_t len = sizeof(sender);
    if (recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&sender, &len) == -1) {
        perror("recvfrom");
        return;
    }
    struct icmphdr *icmp = (struct icmphdr *) buf;
    if (icmp->type == ICMP_ECHOREPLY) {
        printf("Reply from %s: icmp_seq=%d ttl=%d\n", inet_ntoa(sender.sin_addr), icmp->un.echo.sequence, ntohs(sender.sin_port));
    }
}

// Function to perform recursive ping until stopped
void ping(char *host, int timeout, int count) {
    if (count == 0) {
        return;
    }
    send_ping(host);
    recv_ping(timeout);
    sleep(1);
    ping(host, timeout, count-1);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s hostname timeout count\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;

    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) == -1) {
        perror("setsockopt");
        return 1;
    }

    memset(&sender, 0, sizeof(sender));
    sender.sin_family = AF_INET;
    sender.sin_addr.s_addr = INADDR_ANY;

    ping(argv[1], atoi(argv[2]), atoi(argv[3]));

    close(sockfd);
    return 0;
}