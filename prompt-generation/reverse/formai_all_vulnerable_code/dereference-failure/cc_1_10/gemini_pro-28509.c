//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <time.h>

#define SNAP_LEN 1518

int main() {
    char *device;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct pcap_pkthdr *header;
    const u_char *packet;

    device = pcap_lookupdev(errbuf);
    if (device == NULL) {
        fprintf(stderr, "pcap_lookupdev() error: %s\n", errbuf);
        return 1;
    }

    handle = pcap_open_live(device, SNAP_LEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live() error: %s\n", errbuf);
        return 1;
    }

    while (1) {
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == -1) {
            fprintf(stderr, "pcap_next_ex() error: %s\n", pcap_geterr(handle));
            break;
        } else if (res == 0) {
            continue;
        }

        struct tm *tm;
        char buf[32];
        time_t t = header->ts.tv_sec;
        tm = localtime(&t);
        strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", tm);

        printf("%s.%06d ", buf, header->ts.tv_usec);
        printf("len=%d ", header->len);
        printf("cap=%d ", header->caplen);
        printf("%s\n", packet);
    }

    pcap_close(handle);
    return 0;
}