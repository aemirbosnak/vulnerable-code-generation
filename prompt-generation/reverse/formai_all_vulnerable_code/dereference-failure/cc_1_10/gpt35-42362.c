//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: accurate
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>
#include <arpa/inet.h>

/* Define the header structures */
typedef struct ethernetHeader {
    unsigned char destination[6];
    unsigned char source[6];
    unsigned short type;
} ethernetHeader;

typedef struct ipHeader {
    unsigned char versionAndHeaderLength;
    unsigned char serviceType;
    unsigned short length;
    unsigned short identification;
    unsigned short flagsAndFragmentOffset;
    unsigned char timeToLive;
    unsigned char protocol;
    unsigned short checksum;
    struct in_addr sourceIpAddress;
    struct in_addr destinationIpAddress;
} ipHeader;

typedef struct udpHeader {
    unsigned short sourcePort;
    unsigned short destinationPort;
    unsigned short length;
    unsigned short checksum;
} udpHeader;

/* Define a function to print the packet contents in a readable format */
void printPacket(const unsigned char* packet, int length) {
    /* Parse the ethernet header */
    const ethernetHeader *ethernet = (ethernetHeader *) packet;

    /* Get the source MAC address */
    printf("Source MAC address: %02X:%02X:%02X:%02X:%02X:%02X\n", 
        ethernet->source[0], ethernet->source[1], ethernet->source[2], 
        ethernet->source[3], ethernet->source[4], ethernet->source[5]);

    /* Get the destination MAC address */
    printf("Destination MAC address: %02X:%02X:%02X:%02X:%02X:%02X\n", 
        ethernet->destination[0], ethernet->destination[1], ethernet->destination[2], 
        ethernet->destination[3], ethernet->destination[4], ethernet->destination[5]);

    /* Parse the IP header */
    const ipHeader *ip = (ipHeader *) (packet + sizeof(ethernetHeader));

    /* Get the source IP address */
    char sourceIp[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(ip->sourceIpAddress), sourceIp, INET_ADDRSTRLEN);
    printf("Source IP address: %s\n", sourceIp);

    /* Get the destination IP address */
    char destIp[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(ip->destinationIpAddress), destIp, INET_ADDRSTRLEN);
    printf("Destination IP address: %s\n", destIp);

    /* If protocol is not UDP, exit */
    if (ip->protocol != IPPROTO_UDP) {
        printf("Protocol is not UDP.\n");
        return;
    }

    /* Parse the UDP header */
    const udpHeader *udp = (udpHeader *) (packet + sizeof(ethernetHeader) + sizeof(ipHeader));

    /* Get the source port */
    printf("Source port: %d\n", ntohs(udp->sourcePort));

    /* Get the destination port */
    printf("Destination port: %d\n", ntohs(udp->destinationPort));

    /* Get the length */
    printf("Packet length: %d\n", length);
}

int main(int argc, char **argv) {
    pcap_t *pcap;
    char errorBuffer[PCAP_ERRBUF_SIZE];
    pcap_if_t *devices;

    /* Get available devices */
    if (pcap_findalldevs(&devices, errorBuffer) == -1) {
        printf("Error finding devices: %s\n", errorBuffer);
        exit(1);
    }

    /* Print available devices */
    pcap_if_t *d;
    int deviceCount = 0;
    for(d=devices; d; d=d->next) {
        printf("%d. %s ", ++deviceCount, d->name);
        if (d->description)
            printf("(%s)\n", d->description);
        else
            printf("(No description available)\n");
    }

    /* If no device available, exit */
    if (deviceCount == 0) {
        printf("No devices found.\n");
        exit(1);
    }

    int deviceNumber = 0;
    char deviceName[256];
    printf("Enter the number of the device you want to monitor: ");
    scanf("%d", &deviceNumber);
    if (deviceNumber < 1 || deviceNumber > deviceCount) {
        printf("Invalid device number.\n");
        exit(1);
    }

    /* Select the selected device */
    pcap_if_t *selectedDevice = devices;
    for (int i = 0; i < deviceNumber - 1; i++) {
        selectedDevice = selectedDevice->next;
    }
    sprintf(deviceName, "%s", selectedDevice->name);

    /* Open the selected device */
    pcap = pcap_open_live(deviceName, BUFSIZ, 1, 0, errorBuffer);
    if (pcap == NULL) {
        printf("Error opening device: %s\n", errorBuffer);
        exit(1);
    }

    /* Loop through captured packets */
    struct pcap_pkthdr header;
    const unsigned char *packet;

    while (1) {
        packet = pcap_next(pcap, &header);
        if (packet == NULL) continue;

        /* Output packet details */
        printPacket(packet, header.len);
    }

    /* Close the handle */
    pcap_close(pcap);
    return 0;
}