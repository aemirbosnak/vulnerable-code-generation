//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <sys/time.h>

#define MAX_PACKET_SIZE 65535

// Function to calculate the time difference
double timediff(struct timeval t1, struct timeval t2)
{
    return ((t2.tv_sec - t1.tv_sec) * 1000000) + (t2.tv_usec - t1.tv_usec);
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        exit(1);
    }

    char *ip = argv[1];
    struct hostent *host = gethostbyname(ip);

    if (!host) {
        printf("Unable to resolve hostname %s\n", ip);
        exit(1);
    }

    // create socket
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // set socket options
    int on = 1;
    if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &on, sizeof(on)) < 0) {
        perror("setsockopt");
        exit(1);
    }

    // setup destination socket address
    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_addr = *(struct in_addr *)host->h_addr_list[0];

    char packet[MAX_PACKET_SIZE];
    memset(packet, 0, sizeof(packet));

    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);

    // send packet to destination address
    if (sendto(sockfd, packet, sizeof(packet), 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) < 0) {
        perror("sendto");
        exit(1);
    }

    // receive packet from destination address
    struct sockaddr_in src_addr;
    socklen_t src_addr_len;
    char recv_buf[MAX_PACKET_SIZE];
    memset(recv_buf, 0, sizeof(recv_buf));
    recvfrom(sockfd, recv_buf, sizeof(recv_buf), 0, (struct sockaddr *)&src_addr, &src_addr_len);

    gettimeofday(&end_time, NULL);

    double rtt = timediff(start_time, end_time);
    printf("Round trip time: %.2f ms\n", rtt / 1000);

    // close socket
    close(sockfd);

    return 0;
}