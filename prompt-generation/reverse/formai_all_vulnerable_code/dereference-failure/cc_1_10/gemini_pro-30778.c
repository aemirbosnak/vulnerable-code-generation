//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <net/ethernet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <time.h>

#define ETH_HDRLEN 14
#define IP_HDRLEN 20
#define TCP_HDRLEN 20
#define UDP_HDRLEN 8

struct timeval start_time;
struct timeval end_time;
double elapsed_time;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *interface = argv[1];

    // Open the network interface
    pcap_t *handle = pcap_open_live(interface, BUFSIZ, 1, 1000, NULL);
    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live() failed: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    // Start the timer
    gettimeofday(&start_time, NULL);

    // Initialize the QoS metrics
    unsigned long long int num_packets = 0;
    unsigned long long int num_bytes = 0;
    unsigned long long int num_tcp_packets = 0;
    unsigned long long int num_tcp_bytes = 0;
    unsigned long long int num_udp_packets = 0;
    unsigned long long int num_udp_bytes = 0;

    // Capture and process the packets
    while (1) {
        // Get the next packet
        struct pcap_pkthdr *header;
        const unsigned char *data;
        int res = pcap_next_ex(handle, &header, &data);
        if (res == -1) {
            fprintf(stderr, "pcap_next_ex() failed: %s\n", pcap_geterr(handle));
            break;
        } else if (res == 0) {
            continue;
        }

        // Increment the packet count
        num_packets++;

        // Increment the byte count
        num_bytes += header->len;

        // Get the Ethernet header
        struct ethhdr *eth_hdr = (struct ethhdr *) data;

        // Get the IP header
        struct iphdr *ip_hdr = (struct iphdr *) (data + ETH_HDRLEN);

        // Get the TCP header
        struct tcphdr *tcp_hdr = (struct tcphdr *) (data + ETH_HDRLEN + IP_HDRLEN);

        // Get the UDP header
        struct udphdr *udp_hdr = (struct udphdr *) (data + ETH_HDRLEN + IP_HDRLEN);

        // Increment the TCP packet count and byte count
        if (ip_hdr->protocol == IPPROTO_TCP) {
            num_tcp_packets++;
            num_tcp_bytes += header->len - ETH_HDRLEN - IP_HDRLEN - TCP_HDRLEN;
        }

        // Increment the UDP packet count and byte count
        else if (ip_hdr->protocol == IPPROTO_UDP) {
            num_udp_packets++;
            num_udp_bytes += header->len - ETH_HDRLEN - IP_HDRLEN - UDP_HDRLEN;
        }
    }

    // Stop the timer
    gettimeofday(&end_time, NULL);

    // Calculate the elapsed time
    elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000.0 + (end_time.tv_usec - start_time.tv_usec) / 1000.0;

    // Print the QoS metrics
    printf("Total packets: %llu\n", num_packets);
    printf("Total bytes: %llu\n", num_bytes);
    printf("TCP packets: %llu\n", num_tcp_packets);
    printf("TCP bytes: %llu\n", num_tcp_bytes);
    printf("UDP packets: %llu\n", num_udp_packets);
    printf("UDP bytes: %llu\n", num_udp_bytes);
    printf("Elapsed time: %.3f ms\n", elapsed_time);

    // Close the network interface
    pcap_close(handle);

    return EXIT_SUCCESS;
}