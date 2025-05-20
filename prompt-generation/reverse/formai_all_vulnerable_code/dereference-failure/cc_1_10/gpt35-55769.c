//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<pcap.h>
#include<arpa/inet.h>
#include<ctype.h>

// A function to print the received packet information
void packet_handler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
    static int count = 1;
    printf("\nPacket number %d:\n", count);
    printf("Received packet size: %d\n", pkthdr->len);
    count++;
}

// A function to print the decoded MAC address
void print_mac(const unsigned char* mac_address)
{
    printf("MAC Address: ");
    for (int i = 0; i < 6; i++) {
        printf("%02x", mac_address[i]);
        if (i != 5) {
            printf(":");
        }
    }
    printf("\n");
}

int main(int argc, char** argv)
{
    char *device = NULL; // Name of the device to capture packets from
    char error_buffer[PCAP_ERRBUF_SIZE]; // Buffer for error messages
    pcap_t *handle; // Session handle
    struct bpf_program filter; // The compiled filter expression
    char filter_exp[] = "wlan type mgt"; // To capture only management frames
    bpf_u_int32 mask; // The netmask of our sniffing device
    bpf_u_int32 net; // The IP of our sniffing device
    int num_packets = 10; // Number of packets to capture
    struct pcap_pkthdr header; // Contains info about captured packet

    // Retrieve the device name
    device = pcap_lookupdev(error_buffer);
    if (device == NULL) {
        fprintf(stderr, "Could not find default device: %s\n", error_buffer);
        return EXIT_FAILURE;
    }

    // Open the capture device
    handle = pcap_open_live(device, BUFSIZ, 1, 1000, error_buffer);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device, error_buffer);
        return EXIT_FAILURE;
    }

    // Compile and apply the filter expression
    if (pcap_compile(handle, &filter, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Could not compile filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return EXIT_FAILURE;
    }
    if (pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Could not apply filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Find and print the network information
    if (pcap_lookupnet(device, &net, &mask, error_buffer) == -1) {
        fprintf(stderr, "Could not get network information: %s\n", error_buffer);
        return EXIT_FAILURE;
    }
    printf("Network: %s\n", inet_ntoa(*(struct in_addr *)&net));
    printf("Netmask: %s\n", inet_ntoa(*(struct in_addr *)&mask));

    // Begin capturing packets
    printf("\nCapturing %d packets...\n", num_packets);
    if (pcap_loop(handle, num_packets, packet_handler, NULL) == -1) {
        fprintf(stderr, "Failed to capture packets: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Get and print the device MAC address
    struct pcap_addr* addrs = NULL;
    if (pcap_findalldevs(&addrs, error_buffer) == -1) {
        fprintf(stderr, "Could not get device address: %s\n", error_buffer);
        return EXIT_FAILURE;
    }
    print_mac(addrs->addr->sa_data);

    printf("\n");
    pcap_close(handle);

    return EXIT_SUCCESS;
}