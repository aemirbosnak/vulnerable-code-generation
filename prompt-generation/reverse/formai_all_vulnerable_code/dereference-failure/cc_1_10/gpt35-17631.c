//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

//function to handle packet capture
void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
    static int count = 1;
    printf("Packet %d:\n", count);
    printf("Packet size: %d bytes\n", pkthdr->len);
    printf("Captured time: %s\n", ctime((const time_t *)&pkthdr->ts.tv_sec));

    //printing captured bytes in medieval style
    printf("Captured bytes: ");
    for (int i = 0; i < pkthdr->len; i++) {
        printf("%02X ", packet[i]);
        if (i % 16 == 15) {
            printf("\n                        ");
        }
    }
    printf("\n\n");
    count++;
}

int main()
{
    char* device = NULL;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* handle;
    int timeout = 1000;
    int packetCount = 10; //capturing 10 packets

    //getting available devices
    pcap_if_t* alldevs;
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error in pcap_findalldevs: %s\n", errbuf);
        exit(1);
    }

    //selecting first available device
    device = alldevs->name;
    printf("Using device: %s\n", device);

    //opening device for packet capturing
    handle = pcap_open_live(device, BUFSIZ, 1, timeout, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device %s: %s\n", device, errbuf);
        exit(1);
    }

    //capturing packets
    pcap_loop(handle, packetCount, packetHandler, NULL);

    //closing device handle and deallocating memory
    pcap_close(handle);
    pcap_freealldevs(alldevs);

    return 0;
}