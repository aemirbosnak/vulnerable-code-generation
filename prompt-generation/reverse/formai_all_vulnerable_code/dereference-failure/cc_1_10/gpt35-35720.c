//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BYTE_TO_CAPTURE 65536

void printPacketInfo(const struct pcap_pkthdr* packetHeader, const u_char* packetBody) {
    printf("Packet length: %d\n", packetHeader->len);
    printf("Packet timestamp: %s", ctime((const time_t*)&packetHeader->ts.tv_sec));
    printf("Packet source IP address: %s\n", inet_ntoa(((struct sockaddr_in*)packetBody)->sin_addr));
    printf("Packet source port: %d\n", ntohs(((struct sockaddr_in*)packetBody)->sin_port));
    printf("Packet destination IP address: %s\n", inet_ntoa(((struct sockaddr_in*)(packetBody + sizeof(struct sockaddr_in)))->sin_addr));
    printf("Packet destination port: %d\n", ntohs(((struct sockaddr_in*)(packetBody + sizeof(struct sockaddr_in)))->sin_port));
}

void sniffPackets(pcap_t* pcapHandle, int packetCount) {
    int i;
    for(i = 0; i < packetCount; ++i) {
        struct pcap_pkthdr* packetHeader;
        const u_char* packetBody;
        int returnValue = pcap_next_ex(pcapHandle, &packetHeader, &packetBody);
        if(returnValue == 0) {
            continue;
        }
        else if(returnValue == -1) {
            printf("Error occured while reading the packet.\n");
            return;
        }

        printf("Packet #%d:\n", i+1);
        printPacketInfo(packetHeader, packetBody);
    }
}

int main(int argc, char* argv[]) {
    char errorBuffer[PCAP_ERRBUF_SIZE];

    if(argc != 4) {
        printf("Usage: %s <Interface name> <Packet max count> <timeout>\n", argv[0]);
        return 1;
    }

    char* interfaceName = argv[1];
    int packetMaxCount = atoi(argv[2]);
    int timeout = atoi(argv[3]);

    pcap_t* pcapHandle = pcap_open_live(interfaceName, MAX_BYTE_TO_CAPTURE, 1, timeout, errorBuffer);
    
    if(pcapHandle == NULL) {
        printf("Unable to open device %s\n", interfaceName);
        return 1;
    }

    printf("Starting packet sniffing on device %s...\n", interfaceName);
    sniffPackets(pcapHandle, packetMaxCount);

    pcap_close(pcapHandle);

    return 0;
}