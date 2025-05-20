//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: excited
#include<stdio.h>
#include<pcap.h>
#include<stdlib.h>
#include<errno.h>
#include<netinet/in.h>
#include<netinet/if_ether.h>

int main() {
    char interface[30];
    int packets, size_limit;
    printf("Enter the interface to be sniffed : ");
    scanf("%s", interface);
    printf("\nEnter the number of packets to capture : ");
    scanf("%d", &packets);
    printf("\nEnter the size limit for packets to capture : ");
    scanf("%d", &size_limit);
    char error[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter[] = "ip";
    bpf_u_int32 mask;
    bpf_u_int32 net;

    if (pcap_lookupnet(interface, &net, &mask, error) == -1) {
        printf("\nCould not get netmask for interface %s : %s\n", interface, pcap_geterr(handle));
        net = 0;
        mask = 0;
    }

    handle = pcap_open_live(interface, BUFSIZ, 1, 1000, error);
    if (handle == NULL) {
        printf("\nCould not open %s - %s\n", interface, error);
        exit(1);
    }

    if (pcap_compile(handle, &fp, filter, 0, net) == -1) {
        printf("\nCould not parse filter %s - %s\n", filter, pcap_geterr(handle));
        exit(1);
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        printf("\nCould not install filter %s - %s\n", filter, pcap_geterr(handle));
        exit(1);
    }

    struct pcap_pkthdr packet_header;
    const u_char *packet_data;
    int count = 0;
    while (count < packets) {
        packet_data = pcap_next(handle, &packet_header);
        if (packet_header.len > size_limit) {
            printf("\nPacket %d:\n", count + 1);
            for (int i = 0; i < packet_header.len; i++) {
                printf("%.2x ", packet_data[i]);
                if ((i + 1) % 16 == 0) {
                    printf("\n");
                }
            }
            printf("\n");
            count++;
        }
    }
    pcap_close(handle);
    return 0;
}