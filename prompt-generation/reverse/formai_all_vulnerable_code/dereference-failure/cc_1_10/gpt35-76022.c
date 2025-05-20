//FormAI DATASET v1.0 Category: Network Ping Test ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>

#define PACKET_SIZE     128
#define PING_TIMEOUT    2 
#define PING_INTERVAL   1

unsigned short checksum(void *b, int len){
    unsigned short *buf = b;
    unsigned int sum=0;
    unsigned short result;

    for(sum=0;len>1;len-=2){
        sum += *buf++;
    }
    if (len==1){
        sum += *(unsigned char*) buf;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

int ping(const char *host){
    struct addrinfo hints, *addr_list;
    struct sockaddr_in *addr;
    char ipstr[16];
    int socket_fd, ttl=255, rcv_timeout=1000, pack_sent=0, pack_received=0;
    fd_set readfds;
    struct timeval timeout;
    struct timeval tv_begin, tv_end, tv_interval;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_RAW;
    hints.ai_protocol = IPPROTO_ICMP;

    int rc = getaddrinfo(host, NULL, &hints, &addr_list);
    if (rc != 0) {
        return -1;
    }

    addr = (struct sockaddr_in *)addr_list->ai_addr;
    inet_ntop(AF_INET, &addr->sin_addr, ipstr, sizeof ipstr);

    socket_fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (socket_fd < 0) {
        return -1;
    }

    while(1){
        pack_sent++;
        struct icmp *icmp_pack;
        char packet[PACKET_SIZE];

        icmp_pack = (struct icmp*) packet;
        icmp_pack->icmp_type = ICMP_ECHO;
        icmp_pack->icmp_code = 0;
        icmp_pack->icmp_id = getpid() & 0xFFFF;
        icmp_pack->icmp_seq = pack_sent & 0xFFFF;
        icmp_pack->icmp_cksum = 0;
        icmp_pack->icmp_cksum = checksum(packet, PACKET_SIZE);

        sendto(socket_fd, packet, PACKET_SIZE, 0, (struct sockaddr *)addr, sizeof(*addr));

        gettimeofday(&tv_begin,NULL);

        FD_ZERO(&readfds);
        FD_SET(socket_fd,&readfds);
        timeout.tv_sec = PING_TIMEOUT;
        timeout.tv_usec = 0;

        int ret = select(socket_fd+1, &readfds, NULL, NULL, &timeout);

        if (ret < 0) {
            return -1;
        }
        else if(ret == 0) {
            printf("No response for ping request.\n");
        }
        else{
            char buff[PACKET_SIZE];
            int addr_len = sizeof(struct sockaddr_in);
            ssize_t size_icmp_reply = recvfrom(socket_fd, buff, PACKET_SIZE, 0, (struct sockaddr*)addr, (socklen_t *)&addr_len);

            gettimeofday(&tv_end,NULL);

            if(size_icmp_reply<0){
                printf("Error receiving ICMP response.\n");
            }
            else{
                struct iphdr *ip_hdr = (struct iphdr*) buff;
                struct icmp *icmp_hdr = (struct icmp*) (buff + (ip_hdr->ihl << 2));
                if(icmp_hdr->icmp_type == ICMP_ECHOREPLY){
                    pack_received++;
                    timersub(&tv_end,&tv_begin,&tv_interval);
                    printf("%d bytes of data from %s: icmp_seq=%d ttl=%d time=%ld.%06lds\n",
                           PACKET_SIZE, ipstr, pack_received, ttl, (long int)tv_interval.tv_sec, (long int)tv_interval.tv_usec);
                    sleep(PING_INTERVAL);
                }
                else{
                    printf("Invalid ICMP type received.\n");
                }
            }
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    if(argc < 2){
        printf("Usage: ./ping <hostname>\n");
        exit(1);
    }
    ping(argv[1]);
    return 0;
}