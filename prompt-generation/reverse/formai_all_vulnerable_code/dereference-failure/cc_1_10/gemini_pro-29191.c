//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <pcap/pcap.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PROMISCUOUS 1
#define NONPROMISCUOUS 0

// Prints the list of all network interfaces and their IP addresses
void print_network_interfaces() {
    struct ifreq ifr;
    struct ifconf ifc;
    int sockfd, i;
    char *ip_addr;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return;
    }

    ifc.ifc_len = sizeof(ifc);
    ifc.ifc_req = &ifr;
    if (ioctl(sockfd, SIOCGIFCONF, &ifc) < 0) {
        perror("ioctl");
        return;
    }

    for (i = 0; i < ifc.ifc_len / sizeof(ifr); i++) {
        ifr = ifc.ifc_req[i];
        if (ifr.ifr_addr.sa_family == AF_INET) {
            ip_addr = inet_ntoa(((struct sockaddr_in *) &ifr.ifr_addr)->sin_addr);
            printf("Interface: %s\tIP Address: %s\n", ifr.ifr_name, ip_addr);
        }
    }

    close(sockfd);
}

// Scans for wireless networks using libpcap
void scan_wireless_networks() {
    pcap_t *handle;
    struct pcap_pkthdr *header;
    const u_char *packet;
    char *device, errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program fp;
    char filter_exp[] = "type mgt subtype probe-req"; // Filter expression to capture probe request packets

    device = pcap_lookupdev(errbuf);
    if (device == NULL) {
        fprintf(stderr, "Error finding a suitable device: %s\n", errbuf);
        return;
    }

    handle = pcap_open_live(device, BUFSIZ, PROMISCUOUS, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening the device: %s\n", errbuf);
        return;
    }

    if (pcap_compile(handle, &fp, filter_exp, 0, 0) < 0) {
        fprintf(stderr, "Error compiling the filter: %s\n", pcap_geterr(handle));
        return;
    }

    if (pcap_setfilter(handle, &fp) < 0) {
        fprintf(stderr, "Error setting the filter: %s\n", pcap_geterr(handle));
        return;
    }

    while (1) {
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == 0) continue;
        if (res == -1) {
            fprintf(stderr, "Error reading the packet: %s\n", pcap_geterr(handle));
            break;
        }

        // Parse the packet and extract the SSID (network name)
        const u_char *ssid = packet + 36; // SSID field is located at offset 36 in probe request packets
        int ssid_len = packet[35]; // SSID length is located at offset 35
        printf("SSID: %.*s\n", ssid_len, ssid);
    }

    pcap_close(handle);
}

int main() {
    print_network_interfaces();
    scan_wireless_networks();
    return 0;
}