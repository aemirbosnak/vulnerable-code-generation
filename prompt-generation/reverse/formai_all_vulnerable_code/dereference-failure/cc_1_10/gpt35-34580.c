//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <pcap/pcap.h>

int main(int argc, char* argv[]){
    //declaring variables
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "port 80";
    bpf_u_int32 net, mask;
    struct pcap_pkthdr header;
    const u_char *packet;
    int packet_count = 0;
    
    printf("Welcome to the unique C Packet Capturer with pcap library:)\n");
    
    //getting the default device
    char *dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        printf("Couldn't find the default device: %s\n", errbuf);
        return 2;
    }
    printf("The default device is %s\n\n", dev);
    
    //getting the network and mask information of the device
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        printf("Couldn't get information of the device: %s\n", errbuf);
        net = 0;
        mask = 0;
    }
    printf("The network is 0x%x\n", net);
    printf("The mask is 0x%x\n\n", mask);
    
    //opening the device with a timeout of 10 seconds
    handle = pcap_open_live(dev, BUFSIZ, 1, 10000, errbuf);
    if (handle == NULL) {
        printf("Couldn't open the device: %s\n", errbuf);
        return 2;
    }
    printf("The device is open now capturing packets...\n\n");
    
    //compiling and setting the filter
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        printf("Couldn't compile the filter: %s\n", pcap_geterr(handle));
        return 2;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Couldn't set the filter: %s\n", pcap_geterr(handle));
        return 2;
    }
    
    //capturing and analyzing packets until the packet count reaches 10
    while (packet_count < 10) {
        packet = pcap_next(handle, &header);
        if (packet == NULL) {
            printf("No packet captured within the timeout.\n");
            continue;
        }
        printf("Packet #%d:\n", ++packet_count);
        printf("   Length: %d bytes\n", header.len);
        printf("   Content:\n");
        for (int i=0; i<header.len; i++) {
            printf("      %02x ", packet[i]);
            if ((i+1)%16 == 0) printf("\n");
        }
        printf("\n\n");
    }
    
    //closing the device
    pcap_close(handle);
    printf("The device is closed now.\n");
    
    printf("Thanks for using the C Packet Capturer with pcap library ;)\n");
    return 0;
}