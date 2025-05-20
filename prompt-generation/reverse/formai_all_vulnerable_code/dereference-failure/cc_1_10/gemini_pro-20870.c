//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: mathematical
#include <pcap/pcap.h>
#include <stdio.h>
#include <math.h>

typedef struct {
    double mean;
    double stddev;
    double min;
    double max;
} packet_stats;

void print_stats(packet_stats stats) {
    printf("Mean: %.2f bytes\n", stats.mean);
    printf("Standard deviation: %.2f bytes\n", stats.stddev);
    printf("Minimum: %.2f bytes\n", stats.min);
    printf("Maximum: %.2f bytes\n", stats.max);
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live("en0", 65535, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live: %s\n", errbuf);
        return 1;
    }

    packet_stats stats = {0, 0, INFINITY, -INFINITY};
    int count = 0;

    while (1) {
        struct pcap_pkthdr *header;
        const unsigned char *data;
        int res = pcap_next_ex(handle, &header, &data);
        if (res == -1) {
            fprintf(stderr, "pcap_next_ex: %s\n", pcap_geterr(handle));
            break;
        } else if (res == 0) {
            continue;
        }

        double size = header->len;
        stats.mean = stats.mean + (size - stats.mean) / (count + 1);
        stats.stddev = stats.stddev + (size - stats.mean) * (size - stats.stddev) / (count + 1);
        stats.min = fmin(stats.min, size);
        stats.max = fmax(stats.max, size);
        count++;

        if (count % 1000 == 0) {
            print_stats(stats);
        }
    }

    pcap_close(handle);

    return 0;
}