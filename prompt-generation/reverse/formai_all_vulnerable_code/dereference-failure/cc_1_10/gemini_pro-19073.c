//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <netinet/in.h>
#include <netinet/ether.h>
#include <unistd.h>
#include <signal.h>

// Global variables
pcap_t *handle;
int g_running = 1;

// Function to handle signals
void signal_handler(int sig)
{
    g_running = 0;
}

// Function to print the MAC address
void print_mac(unsigned char *mac)
{
    int i;
    for (i = 0; i < 6; i++)
    {
        printf("%02x", mac[i]);
        if (i < 5)
        {
            printf(":");
        }
    }
}

// Function to scan for wireless networks
void scan_wireless()
{
    // Open the network interface
    char *interface = "wlan0";
    handle = pcap_open_live(interface, 65535, 1, 1000, NULL);
    if (handle == NULL)
    {
        printf("Error opening interface!\n");
        exit(1);
    }

    // Start sniffing
    while (g_running)
    {
        struct pcap_pkthdr *header;
        const unsigned char *data;
        int res = pcap_next_ex(handle, &header, &data);
        if (res == 1)
        {
            // Parse the packet
            const struct ether_header *eth_header = (const struct ether_header *)data;
            if (ntohs(eth_header->ether_type) == ETHERTYPE_IP)
            {
                printf("IP packet received\n");
                printf("Source MAC: ");
                print_mac(eth_header->ether_shost);
                printf("\n");
                printf("Destination MAC: ");
                print_mac(eth_header->ether_dhost);
                printf("\n");
            }
            else if (ntohs(eth_header->ether_type) == ETHERTYPE_ARP)
            {
                printf("ARP packet received\n");
                printf("Sender MAC: ");
                print_mac(eth_header->ether_shost);
                printf("\n");
                printf("Target MAC: ");
                print_mac(eth_header->ether_dhost);
                printf("\n");
            }
            else
            {
                printf("Unknown packet type\n");
            }
        }
        else if (res == -1)
        {
            printf("Error sniffing packets!\n");
            exit(1);
        }
    }

    // Close the network interface
    pcap_close(handle);
}

int main()
{
    // Initialize signal handling
    signal(SIGINT, signal_handler);

    // Scan for wireless networks
    scan_wireless();

    return 0;
}