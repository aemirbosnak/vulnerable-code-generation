//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: random
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void packet_handler(u_char* args, const struct pcap_pkthdr* header, const u_char* packet) {
    printf("Packet size: %d bytes\n", header->len);
    // Further processing of packet content
}

int main(int argc, char** argv) {
    pcap_t* handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program fp;
    char filter_exp[] = "tcp port 80";
    bpf_u_int32 net, mask;
    struct pcap_pkthdr header;
    const u_char* packet;
    int capture_limit = 10;

    // Obtain network and mask information for the local network interface
    if (pcap_lookupnet("eth0", &net, &mask, errbuf) == -1) {
        printf("Error in pcap_lookupnet: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Open the network interface handle
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Error in pcap_open_live: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Compile and apply a packet filter
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        printf("Error in pcap_compile: %s\n", pcap_geterr(handle));
        pcap_close(handle);
        return EXIT_FAILURE;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Error in pcap_setfilter: %s\n", pcap_geterr(handle));
        pcap_freecode(&fp);
        pcap_close(handle);
        return EXIT_FAILURE;
    }
    pcap_freecode(&fp);

    // Capture network packets and process them
    while (capture_limit--) {
        packet = pcap_next(handle, &header);
        if (packet != NULL) {
            printf("Packet received at %s\n", 
                   inet_ntoa(((struct sockaddr_in*) &header)->sin_addr));
            packet_handler(NULL, &header, packet);
        }
        else { 
            printf("No packet captured.\n");
        }
    }

    // Cleanup and exit
    pcap_close(handle);
    return EXIT_SUCCESS;
}