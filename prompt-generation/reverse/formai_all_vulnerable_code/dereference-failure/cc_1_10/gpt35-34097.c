//FormAI DATASET v1.0 Category: Network Ping Test ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define PACKET_SIZE 64
#define MAX_WAIT_TIME 5
#define MAX_NO_PACKETS 5

int pack_no = 0;
int sockfd = 0;
char dest_addr_str[INET_ADDRSTRLEN];
struct sockaddr_in dest_addr;
struct sockaddr_in return_addr;
struct icmp* icmp;

void shapeshift(char* data_ptr){
    srand(time(NULL));
    int i;
    for(i=0; i<PACKET_SIZE-sizeof(struct icmphdr); i++){
        data_ptr[i] = rand()%256;
    }
}

unsigned short checksum(unsigned short* ptr, int length){
    unsigned int sum = 0;
    while(length > 1){
        sum += *ptr++;
        length -= 2;
    }
    if(length == 1){
        sum += *(unsigned char*)ptr;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    return (unsigned short)(~sum);
}

int send_packet(){
    pack_no++;
    icmp->icmp_seq = pack_no;
    icmp->icmp_cksum = 0;
    icmp->icmp_cksum = checksum((unsigned short*)icmp, PACKET_SIZE);
    int send_rc = sendto(sockfd, icmp, PACKET_SIZE, 0, (struct sockaddr*)&dest_addr, sizeof(dest_addr));
    if(send_rc < 0){
        perror("sendto");
        return -1;
    }
    return 0;
}

int receive_packet(){
    int socklen = sizeof(struct sockaddr);
    int packetsize = recvfrom(sockfd, icmp, PACKET_SIZE, 0, (struct sockaddr*)&return_addr, (socklen_t*)&socklen);
    if(packetsize < 0){
        perror("recvfrom");
        return -1;
    }
    return 0;
}

double time_diff(struct timeval start, struct timeval end){
    return ((double)(end.tv_sec - start.tv_sec) * 1000.0) + ((double)(end.tv_usec - start.tv_usec) / 1000.0);
}

void ping(){
    int i;
    int recv_count = 0;
    struct timeval start_time;
    struct timeval end_time;
    double rtt[MAX_NO_PACKETS];

    if(inet_pton(AF_INET, dest_addr_str, &dest_addr.sin_addr) <= 0){
        perror("inet_pton");
        return;
    }

    icmp = (struct icmp*)malloc(PACKET_SIZE);
    if(!icmp){
        perror("buffer allocation error");
        return;
    }

    memset(icmp, 0, PACKET_SIZE);
    icmp->icmp_type = ICMP_ECHO;
    icmp->icmp_code = 0;
    icmp->icmp_id = getpid();
    icmp->icmp_cksum = 0;

    shapeshift((char*)icmp + sizeof(struct icmphdr));

    printf("Ping Test to %s\n", dest_addr_str);

    for(i=0; i<MAX_NO_PACKETS; i++){
        if(send_packet() == -1) continue;
        gettimeofday(&start_time, NULL);
        if(receive_packet() == -1) continue;
        gettimeofday(&end_time, NULL);
        double time_diff_ms = time_diff(start_time, end_time);
        rtt[recv_count] = time_diff_ms;
        printf("%d bytes from %s: icmp_req=%d time=%.1f ms\n", PACKET_SIZE, inet_ntoa(return_addr.sin_addr), icmp->icmp_seq, time_diff_ms);
        recv_count++;
        sleep(1);
    }

    if(recv_count > 0){
        printf("\n--- %s ping statistics ---\n", dest_addr_str);
        printf("%d packets transmitted, %d received, %.0f%% packet loss, time %.0fms\n", MAX_NO_PACKETS, recv_count, ((MAX_NO_PACKETS-recv_count) * 100) / MAX_NO_PACKETS, rtt[0]);
    }
}

int main(int argc, char* argv[]){
    if(argc != 2){
        fprintf(stderr, "usage: %s <hostname/ip address>\n", argv[0]);
        exit(1);
    }
    strncpy(dest_addr_str, argv[1], INET_ADDRSTRLEN);
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if(sockfd == -1){
        perror("socket");
        exit(1);
    }
    ping();
    close(sockfd);
    exit(0);
}