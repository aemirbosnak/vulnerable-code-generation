//FormAI DATASET v1.0 Category: Network Ping Test ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/select.h>
#include <sys/time.h>

#define BUFSIZE 1500
#define DEFAULT_COUNT 5
#define DEFAULT_INTERVAL 1

// Global variables
int total_send = 0, total_recv = 0, max_rtt = 0, min_rtt = 1000000;
double total_rtt = 0.0;

// Function to calculate IP checksum
unsigned short checksum(unsigned short *buf, int len) {
    unsigned long sum = 0;
    for (; len > 1; len -= 2)
        sum += *buf++;
    if (len == 1)
        sum += *(unsigned char*) buf;
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    return (unsigned short)(~sum);
}

// Function to handle the SIGALRM signal
void handler(int sig) {
    printf("ping timeout\n");
}

// Function to send one ICMP request packet
void send_icmp_request(int sock, struct sockaddr_in *dst_addr, int seq) {
    // Create an ICMP request packet
    char send_buf[BUFSIZE];
    memset(send_buf, 0, BUFSIZE);
    struct icmp *icmp_hdr = (struct icmp*) send_buf;
    icmp_hdr->icmp_type = ICMP_ECHO;
    icmp_hdr->icmp_code = 0;
    icmp_hdr->icmp_id = getpid();
    icmp_hdr->icmp_seq = seq;
    memset(icmp_hdr->icmp_data, 'a', sizeof(icmp_hdr->icmp_data));
    icmp_hdr->icmp_cksum = checksum((unsigned short*)icmp_hdr, sizeof(struct icmp));

    // Send the packet
    total_send++;
    if (sendto(sock, send_buf, sizeof(struct icmp), 0, (struct sockaddr*) dst_addr, sizeof(struct sockaddr)) < 0) {
        perror("sendto failed");
        exit(EXIT_FAILURE);
    }

    // Start the timer
    alarm(1);
}

// Function to receive one ICMP reply packet
int recv_icmp_reply(int sock, int seq, struct sockaddr_in *src_addr) {
    // Receive the packet
    char recv_buf[BUFSIZE];
    memset(recv_buf, 0, BUFSIZE);
    socklen_t addrlen = sizeof(struct sockaddr);
    if (recvfrom(sock, recv_buf, sizeof(recv_buf), 0, (struct sockaddr*) src_addr, &addrlen) < 0) {
        perror("recvfrom failed");
        exit(EXIT_FAILURE);
    }

    // Check if the packet is an ICMP reply packet
    struct ip *ip_hdr = (struct ip*) recv_buf;
    int ip_hdr_len = ip_hdr->ip_hl * 4;
    struct icmp *icmp_hdr = (struct icmp*) (recv_buf + ip_hdr_len);
    if (icmp_hdr->icmp_type != ICMP_ECHOREPLY || icmp_hdr->icmp_id != getpid() || icmp_hdr->icmp_seq != seq) {
        return 0;
    }

    // Stop the timer
    alarm(0);

    // Print the result and update the statistics
    struct timeval *send_time = (struct timeval*) icmp_hdr->icmp_data;
    struct timeval recv_time;
    gettimeofday(&recv_time, NULL);
    int rtt = (recv_time.tv_sec - send_time->tv_sec) * 1000 + (recv_time.tv_usec - send_time->tv_usec) / 1000;
    printf("%d bytes from %s: icmp_seq=%d ttl=%d time=%d ms\n", ntohs(ip_hdr->ip_len), inet_ntoa(src_addr->sin_addr), seq, ip_hdr->ip_ttl, rtt);
    total_recv++;
    total_rtt += rtt;
    if (rtt > max_rtt)
        max_rtt = rtt;
    if (rtt < min_rtt)
        min_rtt = rtt;

    return 1;
}

// Function to ping a host
void ping(int sock, char *host, int count, int interval) {
    // Resolve the target hostname to IP address
    struct hostent *he;
    if ((he = gethostbyname(host)) == NULL) {
        herror("gethostbyname failed");
        exit(EXIT_FAILURE);
    }
    struct in_addr **addr_list = (struct in_addr**)he->h_addr_list;
    char ip_str[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, addr_list[0], ip_str, INET_ADDRSTRLEN);
    printf("PING %s (%s) %d bytes of data.\n", host, ip_str, sizeof(struct icmp));

    // Loop to send and receive packets
    int seq = 1;
    while (count == 0 || count > 0) {
        send_icmp_request(sock, (struct sockaddr_in*)he->h_addr_list[0], seq);
        seq++;

        // Wait for the reply or timeout
        fd_set readfds;
        struct timeval timeout;
        FD_ZERO(&readfds);
        FD_SET(sock, &readfds);
        timeout.tv_sec = interval;
        timeout.tv_usec = 0;
        int sel_res = select(sock+1, &readfds, NULL, NULL, &timeout);
        if (sel_res < 0) {
            perror("select failed");
            exit(EXIT_FAILURE);
        } else if (sel_res == 0) {
            printf("ping timeout\n");
            continue;
        } else {
            struct sockaddr_in src_addr;
            if (recv_icmp_reply(sock, seq-1, &src_addr)) {
                if (count > 0)
                    count--;
            }
        }

        // Sleep for the specified interval
        sleep(interval);
    }

    // Print the ping statistics
    printf("\n--- %s ping statistics ---\n", host);
    printf("%d packets transmitted, %d packets received, %.1f%% packet loss\n", total_send, total_recv, 100.0*(total_send-total_recv)/total_send);
    if (total_recv > 0)
        printf("round-trip min/avg/max = %d/%.1f/%d ms\n", min_rtt, total_rtt/total_recv, max_rtt);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <hostname> [count] [interval]\n", argv[0]);
        return EXIT_FAILURE;
    }
    char *hostname = argv[1];
    int count = DEFAULT_COUNT;
    int interval = DEFAULT_INTERVAL;
    if (argc >= 3)
        count = atoi(argv[2]);
    if (argc >= 4)
        interval = atoi(argv[3]);

    // Create a new socket to send and receive ICMP packets
    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sock < 0) {
        perror("socket failed");
        return EXIT_FAILURE;
    }

    // Set the signal handler for the SIGALRM signal
    signal(SIGALRM, handler);

    // Call the ping function
    ping(sock, hostname, count, interval);

    // Close the socket
    close(sock);

    return EXIT_SUCCESS;
}