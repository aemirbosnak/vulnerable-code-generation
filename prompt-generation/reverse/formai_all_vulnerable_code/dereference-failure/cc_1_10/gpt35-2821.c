//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: protected
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data);

int main(int argc, char **argv)
{
    pcap_if_t *all_devs, *dev;
    char err_buf[PCAP_ERRBUF_SIZE];
    pcap_t *ad_handle;

    printf("Finding available devices...\n");

    // Get available devices for capture
    if(pcap_findalldevs(&all_devs, err_buf) == -1) {
        printf("Error finding devices: %s\n", err_buf);
        return 1;
    }

    // No devices found
    if(all_devs == NULL) {
        printf("No devices found.\n");
        return 1;
    }

    // Print available devices
    int i = 1;
    for(dev = all_devs; dev != NULL; dev = dev->next) {
        printf("%d. %s\n", i++, dev->name);
    }

    // Select device for capture
    int dev_num;
    printf("\nSelect device for capture: ");
    scanf("%d", &dev_num);

    if(dev_num < 1 || dev_num > i-1) {
        printf("\nInvalid device number.\n");
        pcap_freealldevs(all_devs);
        return 1;
    }

    // Find selected device
    dev = all_devs;
    for(i=1; i<dev_num; i++) {
        dev = dev->next;
    }

    // Capture packets on selected device
    int snap_len = 65535; // Max packet length
    int timeout = 1000; // Capture timeout in ms
    if((ad_handle = pcap_open_live(dev->name, snap_len, 1, timeout, err_buf)) == NULL) {
        printf("Error opening device %s: %s\n", dev->name, err_buf);
        pcap_freealldevs(all_devs);
        return 1;
    }

    printf("\nStart capturing on device: %s\n\n", dev->name);

    // Start capturing packets
    pcap_loop(ad_handle, 0, packet_handler, NULL);

    // Release resources
    pcap_close(ad_handle);
    pcap_freealldevs(all_devs);

    return 0;
}

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    // Get wireless header
    const unsigned char *data = pkt_data;
    int type = data[0x0e] * 256 + data[0x0f];

    // Identify network characteristics
    switch(type) {
        case 0x0008:
            printf("Ethernet II\n");
            break;
        case 0x0806:
            printf("Address Resolution Protocol (ARP)\n");
            break;
        case 0x0842:
            printf("Wake-on-LAN\n");
            break;
        case 0x22f0:
            printf("IEEE 802.11 Radiotap\n");
            break;
        default:
            printf("Unknown packet type\n");
            break;
    }
}