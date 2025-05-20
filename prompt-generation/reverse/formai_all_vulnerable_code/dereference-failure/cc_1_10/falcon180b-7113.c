//Falcon-180B DATASET v1.0 Category: Network Packet Monitoring ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <arpa/inet.h>

#define MAX_PACKET_SIZE 65535
#define SNAPLEN 65535
#define TRUE 1
#define FALSE 0

typedef struct {
    u_char* data;
    int size;
} Packet;

void process_packet(u_char* args, const struct pcap_pkthdr* header, const u_char* packet) {
    Packet* pkt = (Packet*)args;
    pkt->data = (u_char*)malloc(header->caplen);
    pkt->size = header->caplen;
    memcpy(pkt->data, packet, header->caplen);
}

void print_packet(Packet* pkt) {
    printf("Packet size: %d\n", pkt->size);
    printf("Packet data:\n");
    for(int i=0; i<pkt->size; i++) {
        printf("%02X ", pkt->data[i]);
        if((i+1)%16 == 0)
            printf("\n");
    }
    printf("\n");
}

int main() {
    char* dev = "eth0";
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* handle;
    Packet* pkt;

    handle = pcap_open_live(dev, SNAPLEN, 1, 1000, errbuf);
    if(handle == NULL) {
        printf("Error opening device: %s\n", errbuf);
        exit(1);
    }

    pkt = (Packet*)malloc(sizeof(Packet));
    pkt->data = NULL;
    pkt->size = 0;

    pcap_loop(handle, -1, process_packet, (u_char*)pkt);

    pcap_close(handle);
    free(pkt->data);
    free(pkt);
    return 0;
}