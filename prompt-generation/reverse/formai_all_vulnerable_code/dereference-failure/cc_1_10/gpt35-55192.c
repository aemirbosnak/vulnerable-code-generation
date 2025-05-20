//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<pcap.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(){

    printf("\nWhat? Network packet monitoring? Well, brace yourself folks, cause this code will shock you to the core!\n");

    char dev[] = "eth0";
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    bpf_u_int32 mask;
    bpf_u_int32 net;

    if(pcap_lookupnet(dev, &net, &mask, errbuf) == -1){
        printf("ERROR: %s\n", errbuf);
        exit(1);
    }

    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if(handle == NULL){
        printf("ERROR: %s\n", errbuf);
        exit(1);
    }

    char filter_exp[] = "tcp port 80";
    if(pcap_compile(handle, &fp, filter_exp, 0, net) == -1){
        printf("ERROR: %s\n", pcap_geterr(handle));
        exit(1);
    }

    if(pcap_setfilter(handle, &fp) == -1){
        printf("ERROR: %s\n", pcap_geterr(handle));
        exit(1);
    }

    printf("\nShock and awe incoming! Hold on tight!\n");

    struct pcap_pkthdr header;
    const u_char *packet;

    packet = pcap_next(handle, &header);
    printf("\nPacket size: %d bytes\n", header.len);
    printf("Captured at: %s\n", ctime((const time_t*)&header.ts.tv_sec));

    int i;
    for(i=0; i<header.len; i++){
        printf("%02x ", *(packet+i));
        if((i+1) % 16 == 0)
            printf("\n");
    }

    printf("\nUnleashing the power of the packets!\n");

    pcap_close(handle);
    return 0;
}