//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <string.h>

#define MAX_RULES 10

typedef struct {
    char *ip_range;
} FirewallRule;

FirewallRule firewall_rules[MAX_RULES];
int rule_count = 0;

void add_firewall_rule(const char *ip_range) {
    if (rule_count < MAX_RULES) {
        firewall_rules[rule_count].ip_range = strdup(ip_range);
        rule_count++;
    } else {
        printf("Maximum number of firewall rules reached!\n");
    }
}

int is_ip_allowed(const char *ip_str) {
    struct in_addr ip_addr;
    inet_pton(AF_INET, ip_str, &ip_addr);
    
    for (int i = 0; i < rule_count; i++) {
        struct in_addr rule_addr;
        // Check if IP is the same as the rule
        inet_pton(AF_INET, firewall_rules[i].ip_range, &rule_addr);
        if (ip_addr.s_addr == rule_addr.s_addr) {
            return 1; // IP is allowed
        }
    }
    return 0; // IP is blocked
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ip *ip_header = (struct ip *)(packet + 14); // Assuming Ethernet II
    char src_ip[INET_ADDRSTRLEN];
    char dest_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(ip_header->ip_src), src_ip, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &(ip_header->ip_dst), dest_ip, INET_ADDRSTRLEN);

    if (is_ip_allowed(src_ip)) {
        printf("Allowed packet from %s to %s\n", src_ip, dest_ip);
    } else {
        printf("Blocked packet from %s to %s\n", src_ip, dest_ip);
    }
}

int main() {
    // Adding firewall rules (allowed IPs)
    add_firewall_rule("192.168.1.5");
    add_firewall_rule("192.168.1.10");

    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_if_t *alldevs, *device;

    // Find all devices
    if(pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        return 1;
    }

    // Choose the first device for simplicity
    device = alldevs;
    if (device == NULL) {
        fprintf(stderr, "No devices found!\n");
        return 1;
    }

    pcap_t *handle = pcap_open_live(device->name, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device->name, errbuf);
        return 1;
    }

    printf("Starting packet capture on device %s\n", device->name);
    // Start capturing packets
    pcap_loop(handle, 0, packet_handler, NULL);

    // Cleanup
    pcap_freealldevs(alldevs);
    pcap_close(handle);
    return 0;
}