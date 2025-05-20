//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <netdb.h>
#include <errno.h>

#define MAX_PACKET_SIZE 65536
#define MAX_RECV_BUF_SIZE 1000
#define MAX_IP_SIZE 60
#define MAX_TCP_SIZE 60
#define MAX_UDP_SIZE 60

#define LOCAL_PORT 8888
#define REMOTE_PORT 80
#define REMOTE_IP "8.8.8.8"

volatile int running;

void handle_signal(int signal)
{
    running = 0;
}

void print_error(char* message)
{
    fprintf(stderr, "[%s] Error: %s (errno=%d)\n", __func__, message, errno);
}

void print_ip_header(struct iphdr* ip_header)
{
    char src_ip[INET_ADDRSTRLEN];
    char dst_ip[INET_ADDRSTRLEN];

    inet_ntop(AF_INET, &ip_header->saddr, src_ip, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &ip_header->daddr, dst_ip, INET_ADDRSTRLEN);

    printf("IP Header:\n");
    printf("  |-IP Version        : %d\n", (unsigned int)ip_header->version);
    printf("  |-IP Header Length  : %d words\n", (unsigned int)ip_header->ihl);
    printf("  |-Type of Service   : %d\n", (unsigned int)ip_header->tos);
    printf("  |-IP Total Length   : %d bytes\n", ntohs(ip_header->tot_len));
    printf("  |-Identification    : %d\n", ntohs(ip_header->id));
    printf("  |-Fragment Offset   : %d bytes\n", (unsigned int)ip_header->frag_off & 0x1FFF);
    printf("  |-Time to Live      : %d\n", (unsigned int)ip_header->ttl);
    printf("  |-Protocol          : %d\n", (unsigned int)ip_header->protocol);
    printf("  |-Checksum          : 0x%04X\n", ntohs(ip_header->check));
    printf("  |-Source Address    : %s\n", src_ip);
    printf("  |-Destination Address : %s\n", dst_ip);
}

void print_tcp_header(struct tcphdr* tcp_header)
{
    printf("TCP Header:\n");
    printf("  |-Source Port       : %d\n", ntohs(tcp_header->source));
    printf("  |-Destination Port  : %d\n", ntohs(tcp_header->dest));
    printf("  |-Sequence Number   : %u\n", ntohl(tcp_header->seq));
    printf("  |-Acknowledge Number : %u\n", ntohl(tcp_header->ack_seq));
    printf("  |-Header Length     : %d words\n", (unsigned int)tcp_header->doff);
    printf("  |-Flags             : ");
    if(tcp_header->urg) printf("U");
    if(tcp_header->ack) printf("A");
    if(tcp_header->psh) printf("P");
    if(tcp_header->rst) printf("R");
    if(tcp_header->syn) printf("S");
    if(tcp_header->fin) printf("F");
    printf("\n");
    printf("  |-Window Size       : %d\n", ntohs(tcp_header->window));
    printf("  |-Checksum          : 0x%04X\n", ntohs(tcp_header->check));
    printf("  |-Urgent Pointer    : %d\n", ntohs(tcp_header->urg_ptr));
}

void print_udp_header(struct udphdr* udp_header)
{
    printf("UDP Header:\n");
    printf("  |-Source Port       : %d\n", ntohs(udp_header->source));
    printf("  |-Destination Port  : %d\n", ntohs(udp_header->dest));
    printf("  |-UDP Length        : %d\n", ntohs(udp_header->len));
    printf("  |-Checksum          : 0x%04X\n", ntohs(udp_header->check));
}

int main(int argc, char** argv)
{
    int local_socket;
    struct sockaddr_in local_addr;
    struct sockaddr_in remote_addr;
    struct hostent* remote_host;
    char send_buf[MAX_PACKET_SIZE];
    unsigned char recv_buf[MAX_RECV_BUF_SIZE];
    char ip_header_buf[MAX_IP_SIZE];
    char tcp_header_buf[MAX_TCP_SIZE];
    char udp_header_buf[MAX_UDP_SIZE];
    struct iphdr* ip_header;
    struct tcphdr* tcp_header;
    struct udphdr* udp_header;
    int send_result;
    int recv_result;
    socklen_t remote_addr_len;
    int ip_header_len;
    int tcp_header_len;
    int udp_header_len;
    float packet_loss_prob = 0.1;
    unsigned int num_packets_sent = 0;
    unsigned int num_packets_lost = 0;
    unsigned int num_packets_received = 0;
    float avg_rtt = -1.0;
    struct timespec last_packet_sent_time;
    struct timespec last_packet_received_time;
    struct timespec current_time;
    int time_diff_sec;
    int time_diff_ns;
    int time_diff_ms;
    float packet_delay;
    float max_packet_delay = -1.0;
    float min_packet_delay = -1.0;

    // Initialize local address structure
    memset(&local_addr, 0, sizeof(local_addr));
    local_addr.sin_family = AF_INET;
    local_addr.sin_addr.s_addr = INADDR_ANY;
    local_addr.sin_port = htons(LOCAL_PORT);

    // Initialize remote address structure
    memset(&remote_addr, 0, sizeof(remote_addr));
    remote_addr.sin_family = AF_INET;
    remote_host = gethostbyname(REMOTE_IP);
    remote_addr.sin_addr.s_addr = *((unsigned long*)remote_host->h_addr_list[0]);
    remote_addr.sin_port = htons(REMOTE_PORT);

    // Create local socket
    local_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (local_socket == -1) {
        print_error("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Bind socket to local address
    if (bind(local_socket, (struct sockaddr*)&local_addr, sizeof(local_addr)) == -1) {
        print_error("Failed to bind socket");
        exit(EXIT_FAILURE);
    }

    // Register signal handlers
    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);

    // Send and receive packets until interrupted
    running = 1;
    clock_gettime(CLOCK_MONOTONIC, &last_packet_sent_time);
    while (running) {
        // Send packet
        memset(send_buf, 0, sizeof(send_buf));
        send_result = 0;
        if ((float)rand() / RAND_MAX > packet_loss_prob) {
            send_result = sendto(local_socket, send_buf, sizeof(send_buf), 0, (struct sockaddr*)&remote_addr, sizeof(remote_addr));
        }
        if (send_result == -1) {
            print_error("Failed to send packet");
            exit(EXIT_FAILURE);
        }
        num_packets_sent++;
        clock_gettime(CLOCK_MONOTONIC, &last_packet_sent_time);

        // Receive packet
        memset(recv_buf, 0, sizeof(recv_buf));
        memset(ip_header_buf, 0, sizeof(ip_header_buf));
        memset(tcp_header_buf, 0, sizeof(tcp_header_buf));
        memset(udp_header_buf, 0, sizeof(udp_header_buf));
        recv_result = recvfrom(local_socket, recv_buf, sizeof(recv_buf), MSG_WAITALL, (struct sockaddr*)&remote_addr, &remote_addr_len);
        if (recv_result == -1) {
            print_error("Failed to receive packet");
            exit(EXIT_FAILURE);
        }

        // Parse IP header
        ip_header = (struct iphdr*)recv_buf;
        strncpy(ip_header_buf, (char*)ip_header, MAX_IP_SIZE);
        ip_header_len = ip_header->ihl * 4;

        // Parse TCP or UDP header, depending on protocol
        if (ip_header->protocol == IPPROTO_TCP) {
            tcp_header = (struct tcphdr*)(recv_buf + ip_header_len);
            strncpy(tcp_header_buf, (char*)tcp_header, MAX_TCP_SIZE);
            tcp_header_len = tcp_header->doff * 4;
        } else if (ip_header->protocol == IPPROTO_UDP) {
            udp_header = (struct udphdr*)(recv_buf + ip_header_len);
            strncpy(udp_header_buf, (char*)udp_header, MAX_UDP_SIZE);
            udp_header_len = sizeof(struct udphdr);
        }

        // Print packet headers
        printf("Packet #%u:\n", num_packets_received + 1);
        print_ip_header(ip_header);
        if (ip_header->protocol == IPPROTO_TCP) {
            print_tcp_header(tcp_header);
        } else if (ip_header->protocol == IPPROTO_UDP) {
            print_udp_header(udp_header);
        }

        // Compute packet delay
        clock_gettime(CLOCK_MONOTONIC, &current_time);
        time_diff_sec = current_time.tv_sec - last_packet_sent_time.tv_sec;
        time_diff_ns = current_time.tv_nsec - last_packet_sent_time.tv_nsec;
        time_diff_ms = time_diff_sec * 1000 + time_diff_ns / 1000000;
        packet_delay = (float)time_diff_ms / 2.0;
        if (min_packet_delay == -1.0 || packet_delay < min_packet_delay) {
            min_packet_delay = packet_delay;
        }
        if (max_packet_delay == -1.0 || packet_delay > max_packet_delay) {
            max_packet_delay = packet_delay;
        }

        // Update statistics
        num_packets_received++;
        avg_rtt = (avg_rtt * (num_packets_received - num_packets_lost - 1) + (float)time_diff_ms) / (num_packets_received - num_packets_lost);
    }

    // Print summary statistics
    printf("\n");
    printf("Summary:\n");
    printf("  Total packets sent     : %u\n", num_packets_sent);
    printf("  Total packets lost     : %u\n", num_packets_lost);
    printf("  Total packets received : %u\n", num_packets_received);
    printf("  Packet loss rate       : %.2f%%\n", (float)num_packets_lost / num_packets_sent * 100.0);
    printf("  Average RTT            : %.2f ms\n", avg_rtt);
    printf("  Maximum packet delay   : %.2f ms\n", max_packet_delay);
    printf("  Minimum packet delay   : %.2f ms\n", min_packet_delay);

    // Clean up
    close(local_socket);

    return EXIT_SUCCESS;
}