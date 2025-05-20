//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<math.h>
#include<pcap.h>
#include<sys/ioctl.h>
#include<string.h>
#include<errno.h>
#include<arpa/inet.h>
#include<netinet/ether.h>
#include<netinet/ip.h>
#include<signal.h>
#include<net/if.h>
#include<sys/types.h>
#include<netpacket/packet.h>
#include<netinet/ether.h>
#include<ctype.h>

typedef struct{
    unsigned char dest[6];
    unsigned char src[6];
    unsigned short type;
    unsigned char payload[0];
}eth_t;

typedef struct {
    uint8_t version;
    uint8_t type;
    uint16_t len;
    uint8_t payload[0];
} llc_t;

typedef struct {
    unsigned char bssid[6];
    unsigned char sa[6];
    unsigned char da[6];
    unsigned short type;
    unsigned char payload[0];
} wlan_t;

void got_packet(u_char *args, const struct pcap_pkthdr *header,const u_char *packet)
{
    eth_t *eth = (eth_t *)packet;
    struct pcap_pkthdr *md;
    llc_t *llc = (llc_t *)eth->payload;
    wlan_t *wlan = (wlan_t *)llc->payload;
    printf("BSSID: %02x:%02x:%02x:%02x:%02x:%02x\n", wlan->bssid[0], wlan->bssid[1], wlan->bssid[2], wlan->bssid[3], wlan->bssid[4], wlan->bssid[5]);
    int rssi = (int) *(wlan->payload - 2);
    printf("Signal Strength: %d dBm\n", rssi);
}

int main(int argc, char **argv)
{
    char *device = argv[1];
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live(device, BUFSIZ, 1, 1000, error_buffer);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device, error_buffer);
        return 2;
    }
    printf("Listening on device: %s\n", device);
    printf("\nBSSID\t SIGNAL STRENGTH(dbm)\n");
    while (1) {
        struct pcap_pkthdr *header;
        const u_char *packet;
        int ret = pcap_next_ex(handle, &header, &packet);
        if (ret == -1 || ret == -2) {
            fprintf(stderr, "Error reading packet: %s\n", pcap_geterr(handle));
        } else {
            if (ret > 0) {
                got_packet(NULL, header, packet);
            }
        }
    }
    return 0;
}