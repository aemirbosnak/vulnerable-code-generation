//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pcap.h>
#include <sys/types.h>
#include <signal.h>

#define MAX_PACKET_SIZE 65535
#define PROMISCUOUS 1

//Sherlock's Mind
int main() {
    printf("Elementary, my dear Watson.\n");

    //Establishing the connection
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Configuring promiscuous mode
    int on = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &on, sizeof(on)) == -1) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    //Capturing packets
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live("eth0", MAX_PACKET_SIZE, PROMISCUOUS, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    // Detecting the intruders
    struct sockaddr_in src_addr, dest_addr;
    socklen_t addr_len = sizeof(struct sockaddr_in);
    char *src_ip, *dest_ip;
    while (1) {
        char packet[MAX_PACKET_SIZE];
        int packet_len = recvfrom(sockfd, packet, sizeof(packet), 0, (struct sockaddr *) &src_addr, &addr_len);
        if (packet_len < 0) {
            perror("recvfrom");
            exit(EXIT_FAILURE);
        }
        
        // Identifying the suspects
        src_ip = inet_ntoa(src_addr.sin_addr);
        dest_ip = inet_ntoa(dest_addr.sin_addr);
          
        // Analyzing the packets
        if (strcmp(dest_ip, "192.168.1.100") == 0) {
            printf("Detected an intruder: %s\n", src_ip);
            // Take action, block or alert
            // ...
        }
    }

    pcap_close(handle);
    close(sockfd);
    return 0;
}