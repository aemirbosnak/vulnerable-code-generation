//GPT-4o-mini DATASET v1.0 Category: Wireless Network Scanner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 2048
#define ETH_P_ALL 0x0003

struct wifi_packet {
    unsigned char dest[6];
    unsigned char src[6];
    unsigned char type[2];
    unsigned char data[BUFFER_SIZE - 14]; // Rest for data
};

// Function to process received packets
void process_packet(unsigned char *buffer, int size) {
    struct wifi_packet *packet = (struct wifi_packet *)buffer;
    unsigned char *ssid;
    
    if (packet->data[0] == 0x80) { // Beacon frame
        ssid = &packet->data[36]; // SSID in the packet structure (offset depends on standard)
        int ssid_length = packet->data[37];
        
        printf("SSID: ");
        for (int i = 0; i < ssid_length; i++) {
            printf("%c", ssid[i]);
        }
        printf("  | MAC: ");
        for(int i = 0; i < 6; i++) {
            printf("%02X%s", packet->src[i], (i < 5) ? ":" : "");
        }
        printf("\n");
    }
}

// Function to capture packets
void capture_packets() {
    int sockfd;
    unsigned char *buffer = (unsigned char *)malloc(BUFFER_SIZE);
    struct sockaddr saddr;
    
    sockfd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (sockfd < 0) {
        perror("Socket Error");
        exit(EXIT_FAILURE);
    }

    while (1) {
        socklen_t saddr_len = sizeof(saddr);
        int data_size = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, &saddr, &saddr_len);
        
        if (data_size < 0) {
            perror("Receive Error");
            close(sockfd);
            exit(EXIT_FAILURE);
        }

        process_packet(buffer, data_size);
    }

    close(sockfd);
    free(buffer);
}

int main() {
    printf("Starting Wireless Network Scanner...\n");
    printf("Press Ctrl+C to stop scanning.\n");
    
    capture_packets();
    
    return 0;
}