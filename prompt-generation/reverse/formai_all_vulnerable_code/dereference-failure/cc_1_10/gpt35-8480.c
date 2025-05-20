//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <netinet/in.h>
#include <linux/if_packet.h>
#include <linux/if_ether.h>
#include <linux/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>

#define MAX_PACKET_SIZE 8192
#define ETHER_TYPE 0x88DC

void scan_wireless_networks(){
    int sockfd;
    struct sockaddr_ll socket_address;
    char *packet = (char*) malloc(MAX_PACKET_SIZE);
    int packet_len;

    sockfd = socket(AF_PACKET, SOCK_RAW, htons(ETHER_TYPE));
    if(sockfd == -1){
        perror("socket");
        exit(EXIT_FAILURE);
    }

    int ifindex = 0;
    struct ifreq ifreq;

    printf("Enter network interface name: ");
    scanf("%s", ifreq.ifr_name);

    if(ioctl(sockfd, SIOCGIFINDEX, &ifreq) < 0){
        perror("ioctl");
        close(sockfd);
        return;
    }

    ifindex = ifreq.ifr_ifindex;

    memset(&socket_address, 0, sizeof(socket_address));

    socket_address.sll_family   = PF_PACKET;
    socket_address.sll_protocol = htons(ETHER_TYPE);
    socket_address.sll_ifindex  = ifindex;

    if(bind(sockfd, (struct sockaddr*)&socket_address, sizeof(socket_address)) < 0){
        perror("bind");
        close(sockfd);
        return;
    }

    printf("\nScanning for wireless networks...\n\n");

    packet_len = create_packet(packet);

    while(1){
        clock_t start = clock();

        if(sendto(sockfd, packet, packet_len, 0, (struct sockaddr*)&socket_address, sizeof(socket_address)) < 0){
            perror("sendto");
            close(sockfd);
            return;
        }

        long int micro = clock() - start;

        if(micro > 50000){
            printf("Wireless network found!\n");
        }

        sleep(1);
    }

    close(sockfd);
}

int create_packet(char* packet){
    uint8_t src_mac[6] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55};
    uint8_t dst_mac[6] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};

    uint16_t eth_type = htons(ETHER_TYPE);

    memcpy(packet, dst_mac, 6);
    memcpy(packet+6, src_mac, 6);
    memcpy(packet+12, &eth_type, 2);

    srand(time(NULL));

    uint8_t random_ssid[32];

    for(int i = 0; i < 32; i++){
        random_ssid[i] = rand() % 256;
    }

    memcpy(packet + 14, "SSID", 4);
    memcpy(packet + 18, random_ssid, 32);

    return 18+32;
}

int main(){
    scan_wireless_networks();
    return 0;
}