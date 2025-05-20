//FormAI DATASET v1.0 Category: Network Ping Test ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#define ICMP_HDR_SIZE 8
#define ICMP_PROTO 1
#define PACKET_SIZE 64
#define MAX_WAIT_TIMEOUT 3
#define MAX_SEND_TIMEOUT 1

int cont = 0;

// ICMP Packet Structure
struct icmp_packet{
    uint8_t type;
    uint8_t code;
    uint16_t check_sum;
    uint32_t data;
};

// Calculates checksum for given data
uint16_t chksum(void *b, int len){
    uint16_t *buf = b;
    uint16_t *bufend = b + len;
    uint32_t sum = 0;
    while (buf < bufend)
        sum += *buf++;
    if (len & 1)
        sum += *(uint8_t *)bufend;
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    return (uint16_t)(~sum);
}

// Signal Handler
void sig_handler(int sig){
    if(sig == SIGINT){
        cont = 1;
    }
}

// ICMP Echo Request
int send_icmp_echo(int sockfd, struct sockaddr_in *srv_addr){
    struct icmp_packet icmp_pkt;
    int pkt_size = sizeof(struct icmp_packet);
    memset(&icmp_pkt, 0, pkt_size);
    icmp_pkt.type = ICMP_PROTO;
    icmp_pkt.code = 0;
    icmp_pkt.check_sum = chksum(&icmp_pkt, pkt_size);
    icmp_pkt.data = cont;

    if(sendto(sockfd, (void *)&icmp_pkt, pkt_size, 0, 
        (struct sockaddr *)srv_addr, sizeof(struct sockaddr_in)) < 0){
        perror("sendto");
        return -1;
    }
    return 0;
}

// Ping utility
int network_ping(const char *host){
    int sockfd, ret = 0, recv_len = 0;
    char buffer[PACKET_SIZE];
    struct sockaddr_in srv_addr;
    struct hostent *hp;
    struct timeval tv;

    sockfd = socket(PF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0){
        perror("socket");
        return -1;
    }

    hp = gethostbyname(host);
    if (hp == NULL){
        fprintf(stderr, "Unknown host %s\n", host);
        return -1;
    }

    memset(&srv_addr, 0, sizeof(srv_addr));
    srv_addr.sin_family = AF_INET;
    srv_addr.sin_addr = *((struct in_addr *)hp->h_addr);

    // Send packet for n times
    while(!cont){
        if(send_icmp_echo(sockfd, &srv_addr) < 0){
            ret = -1;
            break;
        }

        // Wait for response
        tv.tv_sec = MAX_WAIT_TIMEOUT;
        tv.tv_usec = 0;
        fd_set readfds;
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);
        int select_ret = select(sockfd+1, &readfds, NULL, NULL, &tv);
        if(select_ret < 0){
            perror("select");
            ret = -1;
            break;
        }
        else if(select_ret == 0){
            printf("*\n");
            ret = 0;
            continue;
        }

        // Read packet
        memset(buffer, 0, PACKET_SIZE);
        struct sockaddr_in r_addr;
        socklen_t r_addr_len = sizeof(r_addr);
        recv_len = recvfrom(sockfd, buffer, PACKET_SIZE, 0, 
            (struct sockaddr *)&r_addr, &r_addr_len);
        if(recv_len < 0){
            perror("recvfrom");
            ret = -1;
            break;
        }

        // Check if packet was sent by this program
        uint32_t data;
        struct icmp_packet *icmpp = (struct icmp_packet *)buffer;
        memcpy(&data, &icmpp->data, sizeof(data));
        if(data != cont){
            printf("*\n");
            ret = 0;
            continue;
        }

        // Print success
        struct timeval *tvp;
        double rtt;
        tvp = (struct timeval *) ((char*)buffer + ICMP_HDR_SIZE);
        rtt = (tvp->tv_sec * 1000.0) + (tvp->tv_usec / 1000.0);
        printf("Response received from %s: icmp_seq=%d time=%.3fms\n", 
            inet_ntoa(r_addr.sin_addr), cont, rtt);
        
        // Wait before sending next packet
        usleep(MAX_SEND_TIMEOUT*1000);
    }

    close(sockfd);
    return ret;
}

int main(int argc, char **argv){
    if(argc < 2){
        printf("Usage: %s <host>\n", argv[0]);
        exit(0);
    }

    signal(SIGINT, sig_handler);

    printf("Starting ping requests to %s. Press CTRL+C to stop\n", argv[1]);
    while(1){
        if(network_ping(argv[1]) < 0){
            printf("Ping failed to %s\n", argv[1]);
            exit(-1);
        }
        sleep(1);
    }

    return 0;
}