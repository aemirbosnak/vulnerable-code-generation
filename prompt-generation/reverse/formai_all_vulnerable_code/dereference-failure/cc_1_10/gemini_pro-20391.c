//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: complete
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define MAX_PACKETS 1000
#define MAX_PACKET_LENGTH 65536

// Global variables
pcap_t *handle;
int quit = 0;

// Function to handle SIGINT signal (Ctrl+C)
void signal_handler(int sig) {
    quit = 1;
}

// Function to print packet information
void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    // Get the timestamp of the packet
    time_t timestamp;
    timestamp = header->ts.tv_sec;
    struct tm *tm;
    tm = localtime(&timestamp);

    // Get the source and destination IP addresses
    struct in_addr src_addr, dst_addr;
    src_addr.s_addr = *(uint32_t *)(packet + 12);
    dst_addr.s_addr = *(uint32_t *)(packet + 16);

    // Get the source and destination ports
    uint16_t src_port, dst_port;
    if (ntohs(*(uint16_t *)(packet + 20)) == 6) {
        // TCP packet
        src_port = ntohs(*(uint16_t *)(packet + 34));
        dst_port = ntohs(*(uint16_t *)(packet + 36));
    } else if (ntohs(*(uint16_t *)(packet + 20)) == 17) {
        // UDP packet
        src_port = ntohs(*(uint16_t *)(packet + 34));
        dst_port = ntohs(*(uint16_t *)(packet + 36));
    } else {
        // Unknown protocol
        src_port = 0;
        dst_port = 0;
    }

    // Print the packet information
    printf("[%02d:%02d:%02d] %s:%d -> %s:%d\n", tm->tm_hour, tm->tm_min, tm->tm_sec, inet_ntoa(src_addr), src_port, inet_ntoa(dst_addr), dst_port);
}

int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return -1;
    }

    // Set up the signal handler
    if (signal(SIGINT, signal_handler) == SIG_ERR) {
        perror("signal");
        return -1;
    }

    // Open the network interface
    handle = pcap_open_live(argv[1], BUFSIZ, 1, 1000, NULL);
    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live: %s\n", pcap_geterr(handle));
        return -1;
    }

    // Start the packet capture loop
    while (!quit) {
        // Retrieve packets from the network
        struct pcap_pkthdr *header;
        const u_char *packet;
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == -1) {
            // Error occurred
            fprintf(stderr, "pcap_next_ex: %s\n", pcap_geterr(handle));
            break;
        } else if (res == 0) {
            // Timeout
            continue;
        } else if (res == 1) {
            // Process the packet
            process_packet(NULL, header, packet);
        }
    }

    // Close the network interface
    pcap_close(handle);

    return 0;
}