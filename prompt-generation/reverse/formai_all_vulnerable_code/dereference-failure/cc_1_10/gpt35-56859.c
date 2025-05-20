//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: thoughtful
/*
* This program captures network packets using the pcap library.
* The pcap library provides functions for capturing and analyzing network packets.
* This program captures packets on a network interface in promiscuous mode, which allows 
* it to capture packets that are not intended for the machine running the program.
*/

#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/* Define the callback function for pcap */
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    /* Print the packet length */
    printf("Packet length: %d\n", header->len);
    
    /* Print the packet data in hex */
    int i;
    for(i=0; i<header->len; i++)
        printf("%02x ", packet[i]);
    printf("\n\n");
}

int main(int argc, char *argv[])
{
    char *dev;                      /* The device to capture packets on */
    char errbuf[PCAP_ERRBUF_SIZE];  /* Error buffer for pcap functions */
    pcap_t *handle;                 /* Handle for pcap functions */
    struct bpf_program fp;          /* Compiled filter program */
    bpf_u_int32 mask;               /* Subnet mask */
    bpf_u_int32 net;                /* IP address of the network */
    char filter_exp[] = "port 80";  /* Filter expression */
    struct pcap_pkthdr header;      /* Packet header */
    const u_char *packet;           /* Packet data */
    
    /* Determine the device to capture packets on */
    dev = pcap_lookupdev(errbuf);
    if(dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return(2);
    }
    printf("Device: %s\n", dev);
    
    /* Get the subnet mask and IP address of the network */
    if(pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }
    
    /* Open the device for capture */
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if(handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return(2);
    }
    
    /* Compile the filter expression */
    if(pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }
    
    /* Apply the filter expression */
    if(pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }
    
    /* Capture packets */
    while(1) {
        packet = pcap_next(handle, &header);
        if(packet != NULL)
            packet_handler(NULL, &header, packet);
    }
    
    /* Close the handle */
    pcap_close(handle);
    
    return(0);
}