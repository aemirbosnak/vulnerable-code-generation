//FormAI DATASET v1.0 Category: Firewall ; Style: realistic
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <netinet/ether.h>

#define MAX_FILTER_LEN 1024
#define MAX_DEVICE_LEN 64
#define SNAP_LEN 65535
#define TIMEOUT_MS 1000

struct CFirewallRule {
    char device[MAX_DEVICE_LEN];
    char filter[MAX_FILTER_LEN];
    struct CFirewallRule* next;
};

void process_packet(u_char* args, const struct pcap_pkthdr* header, const u_char* packet) {
    struct CFirewallRule* rule = (struct CFirewallRule*)args;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct ether_header* eth_header;

    // Parse Ethernet header
    eth_header = (struct ether_header*)packet;

    // Check if this packet matches the firewall rule
    pcap_t* handle = pcap_open_live(rule->device, SNAP_LEN, 1, TIMEOUT_MS, errbuf);
    struct bpf_program fp;
    bpf_u_int32 net, mask;
    pcap_lookupnet(rule->device, &net, &mask, errbuf);
    pcap_compile(handle, &fp, rule->filter, 0, mask);
    int res = pcap_offline_filter(&fp, header, packet);
    pcap_close(handle);

    if(res != 0) {
        fprintf(stdout, "Packet blocked by CFirewall filter: %s\n", rule->filter);
        return;
    }

    // Print source and destination MAC addresses
    fprintf(stdout, "Source MAC address: %s\n", ether_ntoa((struct ether_addr*) eth_header->ether_shost));
    fprintf(stdout, "Destination MAC address: %s\n", ether_ntoa((struct ether_addr*) eth_header->ether_dhost));
}

int main(int argc, char* argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    struct CFirewallRule* rule_head = NULL;
    struct CFirewallRule* rule = NULL;

    // Parse command line arguments
    if(argc < 3 || argc % 2 != 1) {
        fprintf(stderr, "Usage: %s device filter [device filter ...]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Set up firewall rules
    for(int i = 1; i < argc; i += 2) {
        rule = (struct CFirewallRule*)malloc(sizeof(struct CFirewallRule));
        if(!rule) {
            fprintf(stderr, "Error: could not allocate memory for firewall rule\n");
            exit(EXIT_FAILURE);
        }
        strncpy(rule->device, argv[i], MAX_DEVICE_LEN);
        strncpy(rule->filter, argv[i+1], MAX_FILTER_LEN);
        rule->next = rule_head;
        rule_head = rule;
    }

    // Open packet capture source and apply firewall rules
    pcap_t* handle;
    struct bpf_program fp;
    bpf_u_int32 net, mask;

    for(rule = rule_head; rule != NULL; rule = rule->next) {
        handle = pcap_open_live(rule->device, SNAP_LEN, 1, TIMEOUT_MS, errbuf);
        if(handle == NULL) {
            fprintf(stderr, "Error: could not open device %s: %s\n", rule->device, errbuf);
            exit(EXIT_FAILURE);
        }

        if(pcap_lookupnet(rule->device, &net, &mask, errbuf) == -1) {
            fprintf(stderr, "Error: could not get netmask for device %s: %s\n", rule->device, errbuf);
            exit(EXIT_FAILURE);
        }

        if(pcap_compile(handle, &fp, rule->filter, 0, mask) == -1) {
            fprintf(stderr, "Error: could not compile filter %s: %s\n", rule->filter, pcap_geterr(handle));
            exit(EXIT_FAILURE);
        }

        if(pcap_setfilter(handle, &fp) == -1) {
            fprintf(stderr, "Error: could not set filter %s: %s\n", rule->filter, pcap_geterr(handle));
            exit(EXIT_FAILURE);
        }

        pcap_loop(handle, -1, process_packet, (u_char*)rule);
        pcap_close(handle);
    }

    return 0;
}