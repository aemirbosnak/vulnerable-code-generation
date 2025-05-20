//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <net/ethernet.h>
#include <pcap.h>

#define MAX_RULES 100
#define RULE_LEN 256

typedef struct FirewallRule {
    char action[10]; // "ALLOW" or "DENY"
    char protocol[10]; // "TCP", "UDP", etc.
    unsigned short port;
} FirewallRule;

FirewallRule rules[MAX_RULES];
int rule_count = 0;

void add_rule(const char *action, const char *protocol, unsigned short port) {
    if (rule_count < MAX_RULES) {
        strcpy(rules[rule_count].action, action);
        strcpy(rules[rule_count].protocol, protocol);
        rules[rule_count].port = port;
        rule_count++;
    } else {
        printf("Max rule limit reached.\n");
    }
}

int evaluate_packet(struct iphdr *ip_header, unsigned short port, const char *protocol) {
    for (int i = 0; i < rule_count; i++) {
        if (strcmp(rules[i].protocol, protocol) == 0 && rules[i].port == port) {
            if (strcmp(rules[i].action, "DENY") == 0) {
                return 0; // Deny the packet
            } else if (strcmp(rules[i].action, "ALLOW") == 0) {
                return 1; // Allow the packet
            }
        }
    }
    return 1; // Default action is to allow
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct iphdr *ip_header = (struct iphdr *)(packet + sizeof(struct ether_header));

    if (ip_header->protocol == IPPROTO_TCP) {
        struct tcphdr *tcp_header = (struct tcphdr *)(packet + sizeof(struct ether_header) + sizeof(struct iphdr));
        if (!evaluate_packet(ip_header, ntohs(tcp_header->dest), "TCP")) {
            printf("TCP packet denied: %u\n", ntohs(tcp_header->dest));
        } else {
            printf("TCP packet allowed: %u\n", ntohs(tcp_header->dest));
        }
    } else if (ip_header->protocol == IPPROTO_UDP) {
        struct udphdr *udp_header = (struct udphdr *)(packet + sizeof(struct ether_header) + sizeof(struct iphdr));
        if (!evaluate_packet(ip_header, ntohs(udp_header->dest), "UDP")) {
            printf("UDP packet denied: %u\n", ntohs(udp_header->dest));
        } else {
            printf("UDP packet allowed: %u\n", ntohs(udp_header->dest));
        }
    } else {
        printf("Unsupported protocol: %u\n", ip_header->protocol);
    }
}

void print_rules() {
    for (int i = 0; i < rule_count; i++) {
        printf("Rule %d: %s %s port %d\n", i + 1, rules[i].action, rules[i].protocol, rules[i].port);
    }
}

int main() {
    // Adding some sample rules
    add_rule("ALLOW", "TCP", 80);   // Allow HTTP
    add_rule("DENY", "TCP", 22);    // Deny SSH
    add_rule("ALLOW", "UDP", 53);    // Allow DNS

    printf("Current Firewall Rules:\n");
    print_rules();

    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_if_t *alldevs;
    pcap_findalldevs(&alldevs, errbuf);
    pcap_t *handle = pcap_open_live(alldevs->name, BUFSIZ, 1, 1000, errbuf);

    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", alldevs->name, errbuf);
        return 2;
    }

    printf("Listening for packets...\n");
    pcap_loop(handle, 0, packet_handler, NULL);

    pcap_close(handle);
    return 0;
}