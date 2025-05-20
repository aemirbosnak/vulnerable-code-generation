//MISTRAL-7B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: synchronous
#include <stdio.h>
#include <pcap.h>

#define SNAPLEN 65567
#define BUFSIZE 1024

void handle_packet(const u_char *packet, const struct pcap_pkthdr *header, const u_int8_t *user) {
    printf("Packet captured: size=%d\n", header->len);
}

int main(int argc, char *argv[]) {
    pcap_if_t *interface;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s interface\n", argv[0]);
        return -1;
    }

    if ((interface = pcap_findalldevs(errbuf, sizeof(errbuf))) == NULL) {
        fprintf(stderr, "Error: %s\n", errbuf);
        return -1;
    }

    for (pcap_if_t *i = interface; i; i = i->next) {
        if (strstr(i->name, argv[1]) != NULL) {
            break;
        }
    }

    if (interface == NULL) {
        fprintf(stderr, "Error: No such interface %s\n", argv[1]);
        pcap_freealldevs(interface);
        return -1;
    }

    if ((handle = pcap_open_live(interface->name, SNAPLEN, 1, 1000, errbuf)) == NULL) {
        fprintf(stderr, "Error: %s\n", errbuf);
        pcap_freealldevs(interface);
        return -1;
    }

    printf("Listening on %s...\n", interface->description);

    pcap_loop(handle, -1, handle_packet, NULL);

    pcap_close(handle);
    pcap_freealldevs(interface);

    return 0;
}