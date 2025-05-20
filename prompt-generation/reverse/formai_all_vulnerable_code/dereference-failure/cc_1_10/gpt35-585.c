//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: ephemeral
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/time.h>

#define BUFSIZE 65535

struct timeval last_time; //This will store the timestamp of the previous packet
int pkt_count = 0; //This will keep track of the number of packets
double last_rate = 0; //This will store the previous rate
double curr_rate = 0; //This will store the current rate
char* interface = NULL; //This will store the name of the interface to capture packet on


//This function will be called for each packet sniffed from the network
void process_packet(unsigned char *buffer, int size)
{
    struct iphdr *iph = (struct iphdr*)buffer; //Extract IP header from packet

    if (iph->protocol == IPPROTO_TCP) { //If TCP protocol layer
        struct tcphdr *tcph = (struct tcphdr *)(buffer + iph->ihl * 4); //Extract TCP header
        int tcph_len = tcph->doff * 4; //Calculate TCP header length

        char* src_ip = inet_ntoa(*(struct in_addr *)&iph->saddr);
        char* dst_ip = inet_ntoa(*(struct in_addr *)&iph->daddr);
        int src_port = ntohs(tcph->source);
        int dst_port = ntohs(tcph->dest);

        printf("TCP    %s:%d --> %s:%d (%d bytes)\n", src_ip, src_port, dst_ip, dst_port, size);

        //Update packet count and timestamp
        pkt_count++;
        struct timeval curr_time;
        gettimeofday(&curr_time, NULL);

        //Calculate time elapsed since last packet
        double time_elapsed = (curr_time.tv_sec - last_time.tv_sec) + (curr_time.tv_usec - last_time.tv_usec)/1000000.0;

        //If at least 1 second has passed since last packet, calculate new rate and print it
        if (time_elapsed >= 1) {
            curr_rate = pkt_count / time_elapsed;

            if (last_rate != 0) {
                printf("Current rate: %lf pps, Change: %lf%%\n", curr_rate, (curr_rate - last_rate)/last_rate * 100);
            } else {
                printf("Current rate: %lf pps\n", curr_rate);
            }

            pkt_count = 0;
            last_rate = curr_rate;
            last_time = curr_time;
        }

    } else if (iph->protocol == IPPROTO_UDP) { //If UDP protocol layer
        struct udphdr *udph = (struct udphdr *)(buffer + iph->ihl * 4); //Extract UDP header
        int udph_len = sizeof(udph);

        char* src_ip = inet_ntoa(*(struct in_addr *)&iph->saddr);
        char* dst_ip = inet_ntoa(*(struct in_addr *)&iph->daddr);
        int src_port = ntohs(udph->source);
        int dst_port = ntohs(udph->dest);

        printf("UDP    %s:%d --> %s:%d (%d bytes)\n", src_ip, src_port, dst_ip, dst_port, size);

    } else if (iph->protocol == IPPROTO_ICMP) { //If ICMP protocol layer
        char* src_ip = inet_ntoa(*(struct in_addr *)&iph->saddr);
        char* dst_ip = inet_ntoa(*(struct in_addr *)&iph->daddr);

        printf("ICMP   %s --> %s (%d bytes)\n", src_ip, dst_ip, size);

    } else {
        printf("OTHER  Protocol: %d\n", iph->protocol);
    }
}

//This function will start the packet capture loop
void start_packet_capture()
{
    int sock_raw;
    struct sockaddr_in saddr;
    int saddr_len;

    unsigned char *buffer = (unsigned char *)malloc(BUFSIZE); //Allocate memory for buffer to store packets

    sock_raw = socket(AF_INET, SOCK_RAW, IPPROTO_TCP); //Create socket for capturing packets

    if (sock_raw < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    //Set socket options to capture packets from specified interface
    struct sockaddr_in interface_addr;
    memset(&interface_addr, 0, sizeof(interface_addr));
    interface_addr.sin_family = AF_INET;
    interface_addr.sin_addr.s_addr = inet_addr(interface);
    if (setsockopt(sock_raw, IPPROTO_IP, IP_HDRINCL, &(int){1}, sizeof(int)) < 0) {
        printf("Error setting socket options\n");
        exit(1);
    }
    if (bind(sock_raw, (struct sockaddr *)&interface_addr, sizeof(interface_addr)) < 0) {
        printf("Error binding socket\n");
        exit(1);
    }

    printf("Starting packet capture on interface %s...\n", interface);

    while (1) {
        saddr_len = sizeof(saddr);
        int recv_size = recvfrom(sock_raw, buffer, BUFSIZE, 0, (struct sockaddr *)&saddr, &saddr_len);
        if (recv_size < 0) {
            printf("Error receiving data\n");
        }

        process_packet(buffer, recv_size);
    }
}


int main(int argc, char** argv)
{
    if (argc != 2) {
        printf("Usage: ./qos_monitor <interface>\n");
        exit(1);
    }

    interface = argv[1];

    gettimeofday(&last_time, NULL);

    start_packet_capture();

    return 0;
}