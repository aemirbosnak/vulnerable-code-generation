//MISTRAL-7B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: synchronous
#include <stdio.h>
#include <pcap.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SNAP_LEN 1514
#define BUF_LEN 1024

typedef struct packet_data {
    u_char data[SNAP_LEN];
    u_int size;
    u_int len;
    u_int timestamp;
} packet_data;

void process_packet(const u_char *packet, const struct pcap_pkthdr *header, void *user);

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    char *dev;
    pcap_if_t *devices;
    pcap_t *handle;

    if (pcap_findalldevs(&devices, errbuf) == -1) {
        fprintf(stderr, "Error: %s\n", errbuf);
        return -1;
    }

    for (dev = devices->name; *dev != '\0'; dev++) {
        printf("%s\n", dev);
    }

    if (argc < 2) {
        printf("Usage: %s interface\n", argv[0]);
        return -1;
    }

    strcpy(dev, argv[1]);

    handle = pcap_open_live(dev, SNAP_LEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error: %s\n", errbuf);
        return -1;
    }

    pcap_loop(handle, -1, process_packet, NULL);

    pcap_close(handle);
    pcap_freealldevs(devices);

    return 0;
}

void process_packet(const u_char *packet, const struct pcap_pkthdr *header, void *user) {
    packet_data *data = (packet_data *) malloc(sizeof(packet_data));

    data->size = header->caplen;
    data->len = header->len;
    data->timestamp = header->ts.tv_sec * 1000 + header->ts.tv_usec / 1000;

    memcpy(data->data, packet, data->size);

    printf("Packet Size: %d bytes\n", data->size);
    printf("Packet Length: %d bytes\n", data->len);
    printf("Timestamp: %lu microseconds\n", data->timestamp);
    printf("Data:\n");
    for (int i = 0; i < data->size; i++) {
        printf("%02x ", data->data[i]);
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    printf("\n");

    free(data);
}