//FormAI DATASET v1.0 Category: Network Ping Test ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>

#define PACKET_SIZE 64
#define MAX_HOP 30
#define MAX_WAIT_TIME 5

#define ERROR -1
#define SUCCESS 0

char *dns_lookup(char *addr_host, struct sockaddr_in *addr_con) {
    struct hostent *host_entity;
    char *ip = (char *)malloc(NI_MAXHOST*sizeof(char));
    memset(ip, 0, NI_MAXHOST*sizeof(char));
    if((host_entity = gethostbyname(addr_host)) == NULL){
        return NULL;
    }
    strcpy(ip, inet_ntoa(*(struct in_addr *)host_entity->h_addr));
    //filling up address structure
    (*addr_con).sin_family = host_entity->h_addrtype;
    (*addr_con).sin_port = htons(0);
    (*addr_con).sin_addr.s_addr = *(long*)host_entity->h_addr;
    return ip;
}

// find the checksum of packet
unsigned short int checksum(unsigned short int *buffer, int size) {
    unsigned int sum = 0;
    for(sum = 0; size > 1; size -= 2)
        sum += *buffer++;
    // if left over bytes, add value of one byte
    if(size == 1)
        sum += *(unsigned char*)buffer;
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    return (~sum);
}

// make icmp packet
int pack_packet(int pack_no, char *packet) {
    int i = 0;
    // set icmp message type to 8 for ping
    struct icmp *icmp_hdr = (struct icmp*) packet;
    icmp_hdr->icmp_type = ICMP_ECHO;
    icmp_hdr->icmp_code = 0;
    icmp_hdr->icmp_seq = pack_no;
    icmp_hdr->icmp_id = getpid();
    for(i = 0; i < PACKET_SIZE; i++)
        icmp_hdr->icmp_data[i] = i+'0';
    icmp_hdr->icmp_cksum = checksum((unsigned short int *) icmp_hdr, PACKET_SIZE);
    return SUCCESS;
}

// send packet for given TTL
int send_packet(int ttl_val, int sockfd, char *ip_addr, struct sockaddr_in addr_con) {
    char packet[PACKET_SIZE];
    memset(packet, 0, sizeof(packet));
    if(pack_packet(ttl_val, packet) == ERROR) {
        perror("Error - Packet formation failed\n");
        return ERROR;
    }
    if(sendto(sockfd, packet, PACKET_SIZE, 0, (struct sockaddr*)&addr_con, sizeof(addr_con)) <= 0) {
        perror("Error - Packet sending failed\n");
        return ERROR;
    }
    return SUCCESS;
}

// receive packet
int receive_packet(int sockfd, struct sockaddr_in *addr_con) {
    char buffer[PACKET_SIZE];

    int addr_len = sizeof((*addr_con));
    if(recvfrom(sockfd, buffer, PACKET_SIZE, 0, (struct sockaddr*)addr_con, &addr_len) <= 0) {
        perror("Error - Packet receiving failed\n");
        return ERROR;
    }
    return SUCCESS;
}

// print ping statistics
void print_stats(int ttl_val, char *ip) {
    printf("Reached %s [%s] in %d hops\n", ip, inet_ntoa(*((struct in_addr*)ip)), ttl_val);
}

// perform ping test
void ping(char *ip_addr) {
    int sockfd, ttl_val = 0, timeout = 0, curr_hop = 0, ret_val = 0;
    char *hostname;
    struct sockaddr_in addr_con;

    printf("Starting ping test for %s\n", ip_addr);

    hostname = dns_lookup(ip_addr, &addr_con);
    if(hostname == NULL) {
        printf("Error - DNS Lookup failed\n");
        return;
    }

    addr_con.sin_family = AF_INET;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if(sockfd < 0) {
        perror("Error - Socket creation failed\n");
        return;
    }

    // set TTL for IP packets
    ret_val = setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl_val, sizeof(ttl_val));
    if(ret_val != 0) {
        perror("Error - Unable to set TTL value\n");
        return;
    }

    // set timeout for receiving packets
    struct timeval timeout_val;
    timeout_val.tv_sec = MAX_WAIT_TIME;
    timeout_val.tv_usec = 0;
    ret_val = setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout_val, sizeof(timeout_val));
    if(ret_val < 0) {
        perror("Error - Unable to set socket options\n");
        return;
    }

    for (curr_hop = 1; curr_hop < MAX_HOP; curr_hop++) {

        ttl_val = curr_hop;
        ret_val = setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl_val, sizeof(ttl_val));
        if(ret_val != 0) {
            perror("Error - Unable to set TTL value\n");
            return;
        }

        printf("%d. ", curr_hop);

        // send packet with given TTL
        ret_val = send_packet(ttl_val, sockfd, ip_addr, addr_con);
        if(ret_val != 0)
            continue;

        // receive packet
        ret_val = receive_packet(sockfd, &addr_con);
        if(ret_val != 0)
            continue;

        print_stats(curr_hop, hostname);

        // quit the loop if we reach the destination
        if(strcmp(inet_ntoa(addr_con.sin_addr), ip_addr) == 0)
            break;
    }
    return;
}

int main(int argc, char **argv) {
    if(argc != 2) {
        printf("Usage: %s <IP_address>\n",argv[0]);
        return ERROR;
    }
    ping(argv[1]);
    return SUCCESS;
}