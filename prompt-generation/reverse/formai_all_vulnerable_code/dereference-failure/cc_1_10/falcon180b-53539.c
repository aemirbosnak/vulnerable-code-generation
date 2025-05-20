//Falcon-180B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0
#define MAX_PACKET_SIZE 65536
#define SNAPLEN 1514
#define PCAP_ERRBUF_SIZE 256

/* Packet callback function */
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet received:\n");
    printf("Packet Length: %d\n", header->len);
    printf("Packet Data: ");
    for (int i = 0; i < header->len; i++) {
        printf("%02X ", packet[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    char *dev = NULL;
    pcap_t *handle;
    u_char *packet = malloc(MAX_PACKET_SIZE);

    /* Check if the correct number of arguments are provided */
    if (argc!= 2) {
        printf("Usage: %s <device>\n", argv[0]);
        exit(1);
    }

    /* Open the device for capturing */
    dev = argv[1];
    handle = pcap_open_live(dev, SNAPLEN, 1, 1000, errbuf);

    if (handle == NULL) {
        printf("Error opening device: %s\n", errbuf);
        exit(1);
    }

    /* Set the callback function */
    pcap_loop(handle, -1, packet_handler, NULL);

    /* Close the device */
    pcap_close(handle);

    return 0;
}