//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <pthread.h>

#define MAX_PACKET_LEN 4096
#define SEND_RATE_LIMIT 200000           // Rate limit for sending packets (bits/sec)

int packet_count = 0;
int total_bytes = 0;

struct ipheader {
    unsigned char       ip_hl:4,        //IP header length
                        ip_v:4;         //IP version
    unsigned char       ip_tos;         //Type of service
    unsigned short int  ip_len;         //Total Length
    unsigned short int  ip_id;          //Identification
    unsigned short int  ip_off;         //Fragment Offset
    unsigned char       ip_ttl;         //Time To Live
    unsigned char       ip_p;           //Protocol
    unsigned short int  ip_sum;         //Checksum
    unsigned int        ip_src;         //Source Address
    unsigned int        ip_dst;         //Destination Address
};

struct tcpheader {
    unsigned short int  th_sport;       //Source Port
    unsigned short int  th_dport;       //Destination Port
    unsigned int        th_seq;         //Sequence Number
    unsigned int        th_ack;         //Acknowledgement Number
    unsigned char       th_x2:4,        //Unused bits
                        th_off:4;       //Data Offset
    unsigned char       th_flags;       //Flags
    unsigned short int  th_win;         //Window
    unsigned short int  th_sum;         //Checksum
    unsigned short int  th_urp;         //Urgent Pointer
};

void print_usage(char *pname) {
    printf("Usage: %s <target IP> <target port> <packet size> <duration (in seconds)>\n", pname);
}

void *send_packets(void *args) {
    int sock;
    struct sockaddr_in server_addr;
    char packet[MAX_PACKET_LEN];
    int packet_size = *(int *)args;
    int send_rate_limit = SEND_RATE_LIMIT;
    int sleep_time = (int)((double)packet_size*(8.0/(double)send_rate_limit)*(double)1000000);  // Calculate sleep time to achieve rate limit

    sock = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
    if (sock == -1) {
        perror("socket() failed ");
        pthread_exit(NULL);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  // Set target IP address
    server_addr.sin_port = htons(80);                      // Set target port

    while (1) {
        memset(packet, 0, MAX_PACKET_LEN);  // Clear packet buffer
        struct ipheader *ip_hdr = (struct ipheader *)packet;
        struct tcpheader *tcp_hdr = (struct tcpheader *)(packet + sizeof(struct ipheader));

        // Set IP header fields
        ip_hdr->ip_v = 4;
        ip_hdr->ip_hl = 5;
        ip_hdr->ip_tos = 0;
        ip_hdr->ip_len = htons(packet_size);
        ip_hdr->ip_id = htons(0);
        ip_hdr->ip_off = htons(0);
        ip_hdr->ip_ttl = 64;
        ip_hdr->ip_p = IPPROTO_TCP;
        ip_hdr->ip_sum = htons(0);
        ip_hdr->ip_src = inet_addr("127.0.0.1");           // Set source IP address
        ip_hdr->ip_dst = server_addr.sin_addr.s_addr;

        // Set TCP header fields
        tcp_hdr->th_sport = htons(4096 + rand()%8192);    // Set random source port number
        tcp_hdr->th_dport = server_addr.sin_port;
        tcp_hdr->th_seq = htonl(rand()%10000);            // Set random sequence number
        tcp_hdr->th_ack = htonl(0);
        tcp_hdr->th_x2 = 0;
        tcp_hdr->th_off = 5;
        tcp_hdr->th_flags = TH_SYN;                       // Set SYN flag
        tcp_hdr->th_win = htons(16384);
        tcp_hdr->th_sum = htons(0);
        tcp_hdr->th_urp = htons(0);

        // Calculate IP header checksum
        int ip_hdr_len = sizeof(struct ipheader);
        unsigned short int *ip_checksum = (unsigned short int *)packet;
        int ip_checksum_len = (ip_hdr->ip_hl * 4) / 2;
        unsigned int ip_sum_calc = 0;
        for (int i=0; i<ip_checksum_len; i++) {
            ip_sum_calc += (unsigned int)(*(ip_checksum++));
        }
        while (ip_sum_calc >> 16) {
            ip_sum_calc = (ip_sum_calc & 0xffff) + (ip_sum_calc >> 16);
        }
        ip_hdr->ip_sum = htons(~ip_sum_calc);

        // Calculate TCP header checksum
        tcp_hdr->th_sum = htons(0);                        // Set TCP checksum field to 0 before calculation
        int tcp_hdr_len = ip_hdr_len + sizeof(struct tcpheader) + packet_size;
        int tcp_checksum_len = tcp_hdr_len / 2;
        unsigned short int *tcp_checksum = (unsigned short int *)packet;
        unsigned int tcp_sum_calc = 0;
        for (int i=0; i<tcp_checksum_len; i++) {
            tcp_sum_calc += (unsigned int)(*(tcp_checksum++));
        }
        while (tcp_sum_calc >> 16) {
            tcp_sum_calc = (tcp_sum_calc & 0xffff) + (tcp_sum_calc >> 16);
        }
        tcp_hdr->th_sum = htons(~tcp_sum_calc);

        sendto(sock, packet, ip_hdr_len + sizeof(struct tcpheader) + packet_size, 0, (const struct sockaddr *)&server_addr, sizeof(server_addr));  // Send packet to target
        packet_count++;
        total_bytes += (int)sizeof(packet);

        usleep(sleep_time);                                // Wait to achieve rate limit
    }
}

void *print_stats(void *args) {
    int duration = *(int *)args;
    time_t start_time = time(NULL);
    int last_packet_count = 0;
    int last_total_bytes = 0;

    while (1) {
        sleep(1);
        int current_packet_count = packet_count;
        int current_total_bytes = total_bytes;
        double elapsed_time = difftime(time(NULL), start_time);
        double packet_rate = (double)(current_packet_count - last_packet_count)/elapsed_time;
        double byte_rate = (double)(current_total_bytes - last_total_bytes)/elapsed_time;
        printf("%d packets sent (%.2f pps), %.2f bytes/sec\n", current_packet_count, packet_rate, byte_rate);

        if (elapsed_time >= duration) {
            pthread_cancel(*((pthread_t *)args + 1));   // Cancel sending thread
            pthread_exit(NULL);
        }

        last_packet_count = current_packet_count;
        last_total_bytes = current_total_bytes;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        print_usage(argv[0]);
        return 1;
    }

    char *target_ip = argv[1];
    int target_port = atoi(argv[2]);
    int packet_size = atoi(argv[3]);
    int duration = atoi(argv[4]);

    pthread_t threads[2];
    int thread_args[1];
    thread_args[0] = packet_size;

    printf("Starting QoS monitor...\n");
    pthread_create(&threads[0], NULL, send_packets, (void *)&thread_args[0]);    // Start sending packets thread
    pthread_create(&threads[1], NULL, print_stats, (void *)&duration);          // Start printing stats thread

    pthread_join(threads[1], NULL);     // Wait for printing thread to terminate
    printf("QoS monitor finished.\n");

    return 0;
}