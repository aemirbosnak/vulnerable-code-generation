//FormAI DATASET v1.0 Category: Network Ping Test ; Style: creative
#include <stdio.h>
#include <netdb.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PING_PKT_SIZ 64
#define MAX_WAIT_TIME 5
#define MAX_NO_OF_RETRY 5

// function to calculate checksum for ICMP packets
unsigned short calculate_checksum(unsigned short *ptr, int nbytes) {
    unsigned long sum;
    unsigned short oddbyte;
    unsigned short answer;

    sum = 0;
    while (nbytes > 1) {
        sum += *ptr++;
        nbytes -= 2;
    }

    if (nbytes == 1) {
        oddbyte = 0;
        *((unsigned char *) &oddbyte) = *(unsigned char *) ptr;
        sum += oddbyte;
    }

    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    answer = (unsigned short) ~sum;

    return answer;
}

// function to resolve host name to IP address
char *resolve_hostname(char *hostname) {
    struct hostent *host;
    struct sockaddr_in addr;

    host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Error - Could not resolve hostname %s\n", hostname);
        return NULL;
    }

    strcpy((char *) &addr.sin_addr, (char *) host->h_addr_list[0]);

    return inet_ntoa(addr.sin_addr);
}

// function to send ICMP echo request and get the response
int ping(char *hostname) {
    int sockfd, i, addr_len, sent_time, recv_time, wait_time;
    struct sockaddr_in addr_ping, addr_recv;
    struct icmp *icmp_hdr;
    char *recv_buf;
    unsigned char send_buf[PING_PKT_SIZ];

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if(sockfd < 0) {
        printf("Error - Could not create socket\n");
        return -1;
    }

    memset(&addr_ping, 0, sizeof(addr_ping));
    addr_ping.sin_family = AF_INET;
    addr_ping.sin_addr.s_addr = inet_addr(resolve_hostname(hostname));

    memset(send_buf, 0, sizeof(send_buf));
    icmp_hdr = (struct icmp *) send_buf;
    icmp_hdr->icmp_type = ICMP_ECHO;
    icmp_hdr->icmp_code = 0;
    icmp_hdr->icmp_id = getpid();
    icmp_hdr->icmp_seq = 0;
    for (i = 0; i < sizeof(send_buf); i++) {
        icmp_hdr->icmp_data[i] = i;
    }
    icmp_hdr->icmp_cksum = calculate_checksum((unsigned short *) icmp_hdr, sizeof(send_buf));

    sent_time = time(NULL);
    if(sendto(sockfd, send_buf, sizeof(send_buf), 0, (struct sockaddr *) &addr_ping, sizeof(addr_ping)) <= 0) {
        printf("Error - Could not send ICMP packet\n");
        return -1;
    }

    recv_buf = (char *) malloc(PING_PKT_SIZ);
    memset(&addr_recv, 0, sizeof(addr_recv));
    addr_len = sizeof(addr_recv);
    while(1) {
        wait_time = MAX_WAIT_TIME * 1000000;
        struct timeval timeout;
        timeout.tv_sec  = MAX_WAIT_TIME;
        timeout.tv_usec = wait_time;
        i = setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
        if(i < 0) {
            printf("Error - Could not set socket options\n");
            return -1;
        }
        if(recvfrom(sockfd, recv_buf, PING_PKT_SIZ, 0, (struct sockaddr *) &addr_recv, &addr_len) <= 0) {
            printf("Error - Packet receive timeout\n");
            return -1;
        }
        icmp_hdr = (struct icmp *) recv_buf;
        if((icmp_hdr->icmp_type == ICMP_ECHOREPLY) && (icmp_hdr->icmp_id == getpid())) {
            recv_time = time(NULL);
            printf("Ping response from %s : time=%d ms\n", hostname, recv_time - sent_time);
            break;
        }
        wait_time--;
        if(wait_time == 0) {
            printf("Error - Maximum wait time exceeded\n");
            return -1;
        }
    }

    close(sockfd);
    return 0;
}

int main(int argc, char **argv) {
    int i, ret;

    if(argc <= 1) {
        printf("Usage: ./ping <hostname>\n");
        return -1;
    }

    for(i = 0; i < MAX_NO_OF_RETRY; i++) {
        printf("Pinging %s [%s]\n", argv[1], resolve_hostname(argv[1]));
        ret = ping(argv[1]);
        if(ret == 0) {
            printf("Ping successful\n");
            break;
        } else {
            printf("Ping failed\n");
        }
    }

    return ret;
}