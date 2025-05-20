//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

/* Packet statistics structure */
typedef struct packet_stats {
    uint64_t total_packets;
    uint64_t total_bytes;
    uint64_t total_dropped;
    uint64_t max_packet_size;
    uint64_t min_packet_size;
    uint64_t avg_packet_size;
    uint64_t median_packet_size;
    uint64_t q1_packet_size;
    uint64_t q3_packet_size;
    uint64_t iqr_packet_size;
} packet_stats;

/* Initialize packet statistics structure */
void init_packet_stats(packet_stats *stats) {
    stats->total_packets = 0;
    stats->total_bytes = 0;
    stats->total_dropped = 0;
    stats->max_packet_size = 0;
    stats->min_packet_size = 0;
    stats->avg_packet_size = 0;
    stats->median_packet_size = 0;
    stats->q1_packet_size = 0;
    stats->q3_packet_size = 0;
    stats->iqr_packet_size = 0;
}

/* Update packet statistics structure */
void update_packet_stats(packet_stats *stats, const uint8_t *packet, int len) {
    stats->total_packets++;
    stats->total_bytes += len;
    if (len > stats->max_packet_size) {
        stats->max_packet_size = len;
    }
    if (len < stats->min_packet_size || stats->min_packet_size == 0) {
        stats->min_packet_size = len;
    }
}

/* Calculate packet statistics */
void calculate_packet_stats(packet_stats *stats) {
    stats->avg_packet_size = stats->total_bytes / stats->total_packets;
}

/* Print packet statistics */
void print_packet_stats(const packet_stats *stats) {
    printf("Total packets: %lu\n", stats->total_packets);
    printf("Total bytes: %lu\n", stats->total_bytes);
    printf("Total dropped: %lu\n", stats->total_dropped);
    printf("Max packet size: %lu\n", stats->max_packet_size);
    printf("Min packet size: %lu\n", stats->min_packet_size);
    printf("Avg packet size: %lu\n", stats->avg_packet_size);
    printf("Median packet size: %lu\n", stats->median_packet_size);
    printf("Q1 packet size: %lu\n", stats->q1_packet_size);
    printf("Q3 packet size: %lu\n", stats->q3_packet_size);
    printf("IQR packet size: %lu\n", stats->iqr_packet_size);
}

/* Packet handler function */
void packet_handler(u_char *user, const struct pcap_pkthdr *header, const u_char *packet) {
    packet_stats *stats = (packet_stats *)user;

    update_packet_stats(stats, packet, header->len);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *interface = argv[1];
    char errbuf[PCAP_ERRBUF_SIZE];

    // Open the network interface for packet capture
    pcap_t *handle = pcap_open_live(interface, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening interface: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Initialize packet statistics
    packet_stats stats;
    init_packet_stats(&stats);

    // Set the packet handler
    pcap_loop(handle, -1, packet_handler, (u_char *)&stats);

    // Calculate and print packet statistics
    calculate_packet_stats(&stats);
    print_packet_stats(&stats);

    // Close the network interface
    pcap_close(handle);

    return EXIT_SUCCESS;
}