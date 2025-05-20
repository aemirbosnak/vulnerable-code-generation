//FormAI DATASET v1.0 Category: Network Ping Test ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <signal.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>

#define PACKET_MAX_SIZE 65536
#define PING_TIMEOUT 3
#define MAX_TRIES 2

// Struct to hold packet information
typedef struct {
    struct icmphdr hdr;
    char message[PACKET_MAX_SIZE];
} Packet;

int timed_out = 0; // flag to indicate whether there was a timeout during a ping

// Signal handler for timeout
void handle_timeout(int signal) {
    timed_out = 1;
}

// Calculate time difference between two timeval structs in ms
long double time_diff(struct timeval start, struct timeval end) {
    return ((end.tv_sec - start.tv_sec) * 1000.0) + ((end.tv_usec - start.tv_usec) / 1000.0);
}

// Calculate checksum for packet
unsigned short checksum(void *data, size_t len) {
    unsigned short *ptr = (unsigned short *) data;
    unsigned int sum = 0;
    for (; len > 1; len -= 2) {
        sum += *ptr++;
        if (sum & 0x80000000)
            sum = (sum & 0xFFFF) + (sum >> 16);
    }
    if (len == 1)
        sum += *(unsigned char*) ptr;
    while (sum >> 16)
        sum = (sum & 0xFFFF) + (sum >> 16);
    return ~sum;
}

// Send a ping to the specified address
void ping(struct sockaddr_in *addr, int seq_num, int sock_fd) {
    int i;
    Packet packet;
    int packet_size = sizeof(struct icmphdr) + strlen(packet.message) + 1;
    packet.hdr.type = ICMP_ECHO;
    packet.hdr.code = 0;
    packet.hdr.checksum = 0;
    packet.hdr.un.echo.id = getpid();
    packet.hdr.un.echo.sequence = seq_num;
    memset(packet.message, '0', PACKET_MAX_SIZE);
    packet.message[PACKET_MAX_SIZE - 1] = '\0'; // null terminate message to avoid buffer overflow
    packet.hdr.checksum = checksum(&packet, packet_size);
    if (sendto(sock_fd, &packet, packet_size, 0, (struct sockaddr*) addr, sizeof(struct sockaddr)) <= 0) {
        printf("Error sending packet\n");
    }
}

// Receive a ping reply
void receive_ping_reply(int sock_fd, struct sockaddr_in *addr, int seq_num) {
    Packet recv_packet;
    socklen_t addr_len = sizeof(struct sockaddr_in);
    struct timeval start, end;
    timed_out = 0;
    signal(SIGALRM, handle_timeout);
    gettimeofday(&start, NULL);
    // Schedule a timeout signal to be sent after PING_TIMEOUT seconds
    alarm(PING_TIMEOUT);
    if (recvfrom(sock_fd, &recv_packet, PACKET_MAX_SIZE, 0, (struct sockaddr*) addr, &addr_len) < 0) {
        if (timed_out) {
            printf("Timeout\n");
            return;
        } else {
            printf("Error receiving reply\n");
            return;
        }
    } else {
        // Calculate round trip time and print results
        gettimeofday(&end, NULL);
        printf("Reply from %s: bytes=%d time=%.2LFms TTL=%d\n",
               inet_ntoa(addr->sin_addr), PACKET_MAX_SIZE, time_diff(start, end), recv_packet.hdr.un.echo.id);
    }
}

int main(int argc, char *argv[]) {
    int sock_fd, seq_num = 0;
    struct sockaddr_in dest_addr;
    struct hostent *host;
    if (argc < 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }
    // Get host address information
    if ((host = gethostbyname(argv[1])) == NULL) {
        printf("Error resolving hostname\n");
        exit(1);
    }
    // Open socket
    if ((sock_fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        printf("Error opening socket\n");
        exit(1);
    }
    // Set socket options
    const int optval = 1;
    if (setsockopt(sock_fd, IPPROTO_IP, IP_HDRINCL, &optval, sizeof(int)) < 0) {
        printf("Error setting socket options\n");
        exit(1);
    }
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_addr = *((struct in_addr*) host->h_addr);
    printf("Pinging %s with %d bytes of data:\n", inet_ntoa(dest_addr.sin_addr), PACKET_MAX_SIZE);
    // Send ping packets
    while (seq_num < MAX_TRIES) {
        ping(&dest_addr, seq_num++, sock_fd);
        receive_ping_reply(sock_fd, &dest_addr, seq_num);
    }
    close(sock_fd);
    return 0;
}