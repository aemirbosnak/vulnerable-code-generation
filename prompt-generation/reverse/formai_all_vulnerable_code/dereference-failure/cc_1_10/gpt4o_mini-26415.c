//GPT-4o-mini DATASET v1.0 Category: Wireless Network Scanner ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <ifaddrs.h>
#include <pcap.h>

#define SNAP_LEN 1518 // max number of bytes we want to capture
#define SIZE_ETHERNET 14 // Ethernet address length
#define ETHER_TYPE 0x0800 // Type for IP protocol
#define BUF_SIZE 2048

// Struct to hold the found WiFi networks
typedef struct WiFiNetwork {
    char ssid[32];
    int signalStrength;
    char bssid[18];
    struct WiFiNetwork *next;
} WiFiNetwork;

WiFiNetwork *head = NULL;

void addNetwork(const char *ssid, int signalStrength, const char *bssid) {
    WiFiNetwork *newNetwork = (WiFiNetwork *)malloc(sizeof(WiFiNetwork));
    strcpy(newNetwork->ssid, ssid);
    newNetwork->signalStrength = signalStrength;
    strcpy(newNetwork->bssid, bssid);
    newNetwork->next = head;
    head = newNetwork;
}

void printNetworks() {
    WiFiNetwork *current = head;
    printf("\n--- Scavenged Networks ---\n");
    while (current) {
        printf("SSID: %s | Signal Strength: %d dBm | BSSID: %s\n", current->ssid, current->signalStrength, current->bssid);
        current = current->next;
    }
}

void freeNetworks() {
    WiFiNetwork *current = head;
    WiFiNetwork *next;
    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
}

void networkSniffer() {
    // Open a live packet capture
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_if_t *alldevs, *device;
    pcap_t *handle;

    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Unable to find devices: %s\n", errbuf);
        return;
    }

    for (device = alldevs; device != NULL; device = device->next) {
        if (device->flags & PCAP_IF_LOOPBACK) {
            continue;  // Skip loopback interfaces
        }
        printf("Scanning on device: %s\n", device->name);
        
        handle = pcap_open_live(device->name, SNAP_LEN, 1, 1000, errbuf);
        if (handle == NULL) {
            fprintf(stderr, "Could not open device %s: %s\n", device->name, errbuf);
            continue;
        }

        struct pcap_pkthdr header;
        const u_char *packet;

        while (1) {
            packet = pcap_next(handle, &header);
            if (packet == NULL) {
                continue; // Timeout, continue capturing
            }

            const char *ssid = "Scavenged_SSID"; // Placeholder SSID
            int signalStrength = rand() % 100 - 100; // Random signal strength for simulation
            char bssid[18] = "00:00:00:00:00:00"; // Placeholder BSSID
            
            addNetwork(ssid, signalStrength, bssid);
        }
        
        pcap_close(handle);
    }

    pcap_freealldevs(alldevs);
}

int main() {
    printf("In the desolate world of the Techno-Wasteland...\n");
    printf("Gathering remnants of Wireless Networks...\n");
    
    srand(time(NULL)); // Seed for random signal strength
    
    networkSniffer();
    printNetworks();
    freeNetworks();
    
    printf("\n--- All networks scoured and recorded. ---\n");
    return 0;
}