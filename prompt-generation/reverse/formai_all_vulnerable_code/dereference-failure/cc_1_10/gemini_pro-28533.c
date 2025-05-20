//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *interface;
    pcap_t *handle;
    struct pcap_pkthdr *header;
    const u_char *data;
    char errbuf[PCAP_ERRBUF_SIZE];

    if (argc != 2) {
        printf("usage: %s interface\n", argv[0]);
        return EXIT_FAILURE;
    }

    interface = argv[1];

    handle = pcap_open_live(interface, 65535, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("error opening interface: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    while (1) {
        int r = pcap_next_ex(handle, &header, &data);
        if (r == -1) {
            printf("error reading packet: %s\n", pcap_geterr(handle));
            break;
        } else if (r == 0) {
            continue;
        }

        struct tm *tm = localtime((time_t *)&header->ts.tv_sec);
        printf("%02d:%02d:%02d.%06d ", tm->tm_hour, tm->tm_min, tm->tm_sec, header->ts.tv_usec);

        for (int i = 0; i < header->len; i++) {
            printf("%02x", data[i]);
            if (i % 16 == 15) {
                printf("\n");
            }
        }

        printf("\n\n");
    }

    pcap_close(handle);
    return EXIT_SUCCESS;
}