//FormAI DATASET v1.0 Category: Network Ping Test ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define PING_PKT_S 64
#define PORT_NO 0
#define PING_SLEEP_RATE 1000000
#define RECV_TIMEOUT 1

char* dns_lookup(char* addr_host, struct sockaddr_in* addr_con) {
    struct hostent* host_entity;
    char* ip = (char*)malloc(NI_MAXHOST*sizeof(char));
    int i;

    if ((host_entity = gethostbyname(addr_host)) == NULL) {
        return NULL;
    }

    sprintf(ip, "%d.%d.%d.%d", (unsigned char)host_entity->h_addr_list[0][0],
            (unsigned char)host_entity->h_addr_list[0][1],
            (unsigned char)host_entity->h_addr_list[0][2],
            (unsigned char)host_entity->h_addr_list[0][3]);

    (*addr_con).sin_family = host_entity->h_addrtype;
    (*addr_con).sin_port = htons(PORT_NO);
    (*addr_con).sin_addr.s_addr = *(long*)host_entity->h_addr;

    return ip;
}

uint16_t checksum(void* b, int len) {    
    uint16_t* buf = b;
    uint32_t sum=0;
    uint16_t result;

    for (sum = 0; len > 1; len -= 2) {
        sum += *buf++;
    }

    if (len == 1) {
        sum += *(unsigned char*)buf;
    }

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

int ping_func(char* ip_addr) {
    int sockfd, msg_count = 0, i, addr_len, flag = 1, msg_received_count = 0;

    struct timeval tv_out;
    tv_out.tv_sec = RECV_TIMEOUT;
    tv_out.tv_usec = 0;

    struct sockaddr_in addr_con;

    addr_len = sizeof(addr_con);

    char* reverse_dns;

    char* ip = dns_lookup(ip_addr, &addr_con);

    if (ip == NULL) {
        return 0;
    }

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        printf("Socket file descriptor not received.\n");
        return 0;
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO,
                   (const char*)&tv_out, sizeof(tv_out)) < 0) {
        printf("Error in setting timeout.\n");
        return 0;
    }

    while (msg_count < 3) {
        flag = 1;
        struct icmp* icmp_hdr;
        char msg[PING_PKT_S];

        icmp_hdr = (struct icmp*)msg;

        icmp_hdr->icmp_type = ICMP_ECHO;
        icmp_hdr->icmp_hun.ih_idseq.icd_id = getpid();

        for (i = 0; i < sizeof(msg)-1; i++) {
            icmp_hdr->icmp_data[i] = i+'0';
        }

        icmp_hdr->icmp_cksum = checksum(icmp_hdr, sizeof(msg));

        if (sendto(sockfd, msg, sizeof(msg), 0,
                   (struct sockaddr*)&addr_con, sizeof(addr_con)) <= 0) {
            printf("Packet Sending Failed!\n");
            flag = 0;
        }

        msg_count++;

        if (recvfrom(sockfd, msg, sizeof(msg), 0,
                     (struct sockaddr*)&addr_con, &addr_len) <= 0) {
            printf("Packet receive failed!\n");
        } else {
            struct iphdr* ip_hdr = (struct iphdr*)msg;
            struct sockaddr_in src_addr;
            char buffer[1024];

            memset(buffer, 0, sizeof(buffer));
            memset(&src_addr, 0, sizeof(src_addr));

            src_addr.sin_addr.s_addr = ip_hdr->saddr;

            if (getnameinfo((struct sockaddr*)&src_addr, sizeof(src_addr),
                            buffer, sizeof(buffer), NULL, 0, 0) != 0) {
                printf("Reverse DNS failed!\n");
                reverse_dns = NULL;
            } else {
                printf("%s ", buffer);
                reverse_dns = buffer;
            }

            struct icmp* icmp_hdr = (struct icmp*)(msg + sizeof(struct iphdr));
            if (icmp_hdr->icmp_type == ICMP_ECHOREPLY) {
                printf("Ping Success [%s]\n", reverse_dns);
                msg_received_count++;
            } else {
                printf("Error in packet received\n");
            }
        }

        sleep(1);
    }

    close(sockfd);
    free(ip);

    if (msg_received_count > 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char ip_addr[20];
    int result;

    printf("Enter IP Address to Ping: ");
    scanf("%s", ip_addr);

    printf("Pinging %s...\n", ip_addr);

    result = ping_func(ip_addr);

    if (result) {
        printf("Ping Successful!\n");
    } else {
        printf("Ping Failed.\n");
    }

    return 0;
}