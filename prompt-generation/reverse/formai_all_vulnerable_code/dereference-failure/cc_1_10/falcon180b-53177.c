//Falcon-180B DATASET v1.0 Category: Network Packet Monitoring ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <pcap.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX_PACKET_SIZE 65535

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    const u_char *packet;
    struct pcap_pkthdr header;
    int ret;
    int count = 0;

    // Open the network interface for capturing packets
    handle = pcap_open_live("eth0", BUFSIZ, 0, 0, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error: %s\n", errbuf);
        exit(1);
    }

    // Loop through the packets and print their contents
    while (1) {
        ret = pcap_next_ex(handle, &header, &packet);
        if (ret == -1) {
            fprintf(stderr, "Error: %s\n", pcap_geterr(handle));
            exit(1);
        } else if (ret == 0) {
            break;
        }

        printf("Packet %d:\n", count++);
        printf("  Length: %d\n", header.len);
        printf("  Data:\n");

        for (int i = 0; i < header.len; i++) {
            if (i % 16 == 0) {
                printf("\n");
            }
            printf(" %02X", *(packet + i));
        }
        printf("\n");
    }

    // Close the network interface
    pcap_close(handle);

    return 0;
}