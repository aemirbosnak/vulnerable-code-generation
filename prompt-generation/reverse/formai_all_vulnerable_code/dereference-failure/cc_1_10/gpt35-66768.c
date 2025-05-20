//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PACKET_SIZE 4096
#define DEFAULT_TIMEOUT 3
#define DEFAULT_SERVER "8.8.8.8"
#define DEFAULT_PORT 80

/* Function to calculate the time difference between two timeval structures in microseconds */
int timeval_diff(struct timeval *tv1, struct timeval *tv2) {
    return ((tv2->tv_sec - tv1->tv_sec) * 1000000) + (tv2->tv_usec - tv1->tv_usec);
}

/* Function to send a packet */
void send_packet(int sockfd, struct sockaddr_in *addr) {
    char packet[MAX_PACKET_SIZE];
    memset(packet, 0, MAX_PACKET_SIZE); // zero initialize the packet
    
    struct iphdr *ip_header = (struct iphdr*) packet;
    ip_header->version = 4;
    ip_header->ihl = 5;
    ip_header->tos = 0;
    ip_header->tot_len = htons(sizeof(struct iphdr));
    ip_header->id = htons(0);
    ip_header->frag_off = htons(0);
    ip_header->ttl = 64;
    ip_header->protocol = IPPROTO_ICMP;
    ip_header->check = htons(0);
    ip_header->saddr = INADDR_ANY;
    ip_header->daddr = addr->sin_addr.s_addr;
    
    struct timeval start_time;
    gettimeofday(&start_time, NULL); // get current time for measuring round trip time
    
    int bytes_sent = sendto(sockfd, packet, sizeof(struct iphdr), 0, (struct sockaddr *) addr, sizeof(struct sockaddr));
    if (bytes_sent == -1) {
        fprintf(stderr, "Error sending packet\n");
        exit(EXIT_FAILURE);
    }
    
    struct timeval end_time;
    memset(&end_time, 0, sizeof(struct timeval));
    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(sockfd, &read_fds);
    
    struct timeval timeout;
    timeout.tv_sec = DEFAULT_TIMEOUT;
    timeout.tv_usec = 0;
    
    if (select(sockfd+1, &read_fds, NULL, NULL, &timeout) > 0) {
        unsigned char response[MAX_PACKET_SIZE];
        memset(response, 0, MAX_PACKET_SIZE);
        int bytes_received = recvfrom(sockfd, response, sizeof(response), 0, NULL, NULL);
        if (bytes_received == -1) {
            fprintf(stderr, "Error receiving response\n");
            exit(EXIT_FAILURE);
        }
        
        struct timeval current_time;
        gettimeofday(&current_time, NULL);
        int rtt = timeval_diff(&start_time, &current_time);
        printf("Round Trip Time: %d microseconds\n", rtt);
    } else {
        printf("Request Timed Out\n");
    }
}

int main(int argc, char *argv[]) {
    char *server = DEFAULT_SERVER;
    int port = DEFAULT_PORT;
    
    if (argc > 1) {
        server = argv[1];
    }
    
    if (argc > 2) {
        port = atoi(argv[2]);
    }
    
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd == -1) {
        fprintf(stderr, "Error creating socket\n");
        exit(EXIT_FAILURE);
    }
    
    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(struct sockaddr_in));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_addr.s_addr = inet_addr(server);
    dest_addr.sin_port = htons(port);
    
    printf("Testing internet speed to %s:%d\n", server, port);
    for (int i = 0; i < 10; i++) {
        printf("Sending Packet %d...\n", i+1);
        send_packet(sockfd, &dest_addr);
        printf("\n");
        usleep(1000000); // wait 1 second before sending next packet
    }
    
    close(sockfd);
    
    return 0;
}