//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: surrealist
#include<stdio.h>
#include<pcap.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>

int main()
{
    char errbuf[1024];
    pcap_t* handle;
    const char* device;
    struct bpf_program fp;       
    char filter_exp[] = "udp port 53"; 
    bpf_u_int32 mask;       
    bpf_u_int32 net;
    struct pcap_pkthdr header; 
    const u_char* packet;    

    device = pcap_lookupdev(errbuf);
    if (device == NULL) {
        printf("Couldn't find default device: %s\n", errbuf);
        return(2);
    }
    printf("Device: %s\n", device);

    if (pcap_lookupnet(device, &net, &mask, errbuf) == -1) {
        printf("Couldn't get netmask for device %s: %s\n", device, errbuf);
        net = 0;
        mask = 0;
    }

    handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Couldn't open device %s: %s\n", device, errbuf);
        return(2);
    }

    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        printf("Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }

    printf("Sniffing UDP packets on port 53...\n");

    packet = pcap_next(handle, &header);
    
    if (packet == NULL) {
        printf("No packet captured.\n");
    }
    else {
        printf("Packet Length: %d\n", header.len);
        printf("Packet Content:\n");
        for (int i = 0; i < header.len; i++) {
            printf("%x ", packet[i]);
        }
    }
    
    pcap_close(handle);
    return(0);
}