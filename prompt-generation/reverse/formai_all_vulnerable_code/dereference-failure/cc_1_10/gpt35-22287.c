//FormAI DATASET v1.0 Category: Network Ping Test ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <sys/time.h>


#define PACKET_SIZE     64
#define ICMP_HDR_SIZE   8
#define ALIGN_AMOUNT    4
#define SEQUENCE_NUM    12345


struct icmphdr {
    uint8_t type;        /* type of message, always 8 for echo request */
    uint8_t code;        /* type sub-code */
    uint16_t checksum;   /* one's complement of icmp message (with this header)*/
    uint16_t id;         /* sequence number for the ping */
    uint16_t seq_num;    /* sequence number for ping */
};


struct packet {
    struct icmphdr hdr;
    char msg[PACKET_SIZE - ICMP_HDR_SIZE];
};


typedef struct ping_result_t {
    double min_rtt;
    double max_rtt;
    double avg_rtt;
    int packets_sent;
    int packets_received;
} ping_result;


char* hostname_to_ip(const char* hostname) {
    struct hostent* host;
    struct in_addr **addr_list;
    char* ip = NULL;

    if ((host = gethostbyname(hostname)) == NULL) {
        perror("Error: Invalid hostname");
        exit(1);
    }

    addr_list = (struct in_addr**) host->h_addr_list;
    for (int i = 0; addr_list[i] != NULL; i++) {
        ip = inet_ntoa(*addr_list[i]);
    }
    return ip;
}


uint16_t checksum(void* data, int len) {
    uint32_t sum = 0;
    uint16_t* ptr = data;

    while (len > 1) {
        sum += *ptr++;
        len -= 2;
    }

    if (len) {
        sum += *(uint8_t*) ptr;
    }

    while (sum >> 16) {
        sum = (sum & 0xffff) + (sum >> 16);
    }

    return ~sum;
}


void usage() {
    printf("Usage: ./myping [-t timeout] [hostname/IP]\n");
}


ping_result send_pings(char* target_ip, int timeout) {
    uint8_t ttl = 64;
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl));

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = 0;
    inet_pton(AF_INET, target_ip, &addr.sin_addr);

    ping_result results = {0, 0, 0, 0, 0};
    struct timeval tv_sent, tv_recv;
    struct packet pckt;
    int sequences_sent = 0;  // keep track of how many sequences are sent
    double sum_rtt = 0;

    int flags_before = fcntl(sockfd, F_GETFL, 0);
    fcntl(sockfd, F_SETFL, flags_before | O_NONBLOCK);

    while (sequences_sent < 5) {  // stop sending after 5 packets
        pckt.hdr.type = 8;      // icmp echo request
        pckt.hdr.code = 0;
        pckt.hdr.checksum = 0;
        pckt.hdr.id = getpid() & 0xFFFF;
        pckt.hdr.seq_num = sequences_sent++;

        gettimeofday(&tv_sent, NULL);
        memcpy(pckt.msg, &tv_sent, sizeof(tv_sent));
        pckt.hdr.checksum = checksum(&pckt, sizeof(pckt));

        ssize_t bytes_sent = sendto(sockfd, &pckt, sizeof(pckt), 0,
                                    (struct sockaddr*) &addr, sizeof(addr));
        if (bytes_sent <= 0) {
            continue;
        }

        results.packets_sent++;

        char buffer[PACKET_SIZE];
        int bytes_received = recvfrom(sockfd, buffer, sizeof(buffer), 0, NULL, NULL);
        if (bytes_received > 0) {
            gettimeofday(&tv_recv, NULL);

            struct packet* recv_packet = (struct packet*) buffer;
            double rtt_msec = (tv_recv.tv_sec - tv_sent.tv_sec) * 1000.0;
            rtt_msec += (tv_recv.tv_usec - tv_sent.tv_usec) / 1000.0;

            if (results.min_rtt == 0 || rtt_msec < results.min_rtt) {
                results.min_rtt = rtt_msec;
            }

            if (rtt_msec > results.max_rtt) {
                results.max_rtt = rtt_msec;
            }

            sum_rtt += rtt_msec;
            results.packets_received++;
        }

        usleep(timeout * 1000);
    }

    fcntl(sockfd, F_SETFL, flags_before);  // reset flags

    if (results.packets_received > 0) {
        results.avg_rtt = sum_rtt / results.packets_received;
    }

    close(sockfd);
    return results;
}


int main(int argc, char* argv[]) {
    if (argc == 1 || argc > 3) {
        usage();
        exit(1);
    }

    char* target_ip = NULL;  // default to localhost
    int timeout = 1000;  // default to 1 second

    if (argc == 2) {
        target_ip = hostname_to_ip(argv[1]);
    }
    else {
        if (strcmp(argv[1], "-t") != 0) {
            usage();
            exit(1);
        }
        timeout = atoi(argv[2]);
        target_ip = hostname_to_ip(argv[3]);
    }

    ping_result results = send_pings(target_ip, timeout);

    printf("Ping statistics for %s\n", target_ip);
    printf("Total packets sent: %d, received: %d\n", results.packets_sent,
           results.packets_received);
    if (results.packets_received == 0) {
        printf("No packets were received.\n");
        exit(1);
    }
    printf("Minimum RTT: %.2fms, Maximum RTT: %.2fms, Average RTT: %.2fms\n",
           results.min_rtt, results.max_rtt, results.avg_rtt);

    return 0;
}