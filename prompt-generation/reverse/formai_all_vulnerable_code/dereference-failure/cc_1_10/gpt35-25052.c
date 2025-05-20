//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

/* This function is called every time a packet is captured */
void handle_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    // TODO: Add your packet analysis / processing code here
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    bpf_u_int32 net;
    bpf_u_int32 mask;
    
    /* Get the network interface and its mask */
    char *dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return(EXIT_FAILURE);
    }
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }
    printf("Device: %s\n", dev);
    printf("Netmask: %s\n", inet_ntoa(*(struct in_addr *)&mask));
    
    /* Open the network interface for capture */
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return(EXIT_FAILURE);
    }
    
    /* Compile and apply the BPF filter */
    char filter_exp[] = "ip"; /* Filter expression to capture only IP packets */
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(EXIT_FAILURE);
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(EXIT_FAILURE);
    }
    
    /* Start the packet capture loop */
    pcap_loop(handle, -1, handle_packet, NULL);
    
    /* Cleanup */
    pcap_freecode(&fp);
    pcap_close(handle);
    
    return(EXIT_SUCCESS);
}