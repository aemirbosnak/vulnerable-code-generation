//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: Cryptic
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include <pcap.h>
#include <netinet/if_ether.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>

#define DEFAULT_IFACE "eth0"

struct topology_node {
    char* ip_address;
    struct topology_node* next;
};

struct topology_map {
    struct topology_node* head;
};

struct topology_map* create_topology_map()
{
    struct topology_map* map = (struct topology_map*) malloc(sizeof(struct topology_map));
    map->head = NULL;
    return map;
}

void destroy_topology_map(struct topology_map* map)
{
    while (map->head != NULL) {
        struct topology_node* next_node = map->head->next;
        free(map->head);
        map->head = next_node;
    }
    free(map);
}

bool add_topology_node(struct topology_map* map, char* ip_address)
{
    if (map == NULL) return false;
    if (ip_address == NULL) return false;

    struct topology_node* new_node = (struct topology_node*) malloc(sizeof(struct topology_node));
    new_node->ip_address = strdup(ip_address);
    new_node->next = NULL;

    if (map->head == NULL) {
        map->head = new_node;
    } else {
        struct topology_node* current = map->head;
        while (current->next != NULL) current = current->next;
        current->next = new_node;
    }

    return true;
}

int main(int argc, char** argv)
{
    char* interface = DEFAULT_IFACE;
    if (argc > 1) interface = argv[1];

    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* handle = pcap_open_live(interface, BUFSIZ, 1, 1000, errbuf);

    if (handle == NULL) {
        fprintf(stderr, "Error opening device %s: %s\n", interface, errbuf);
        return EXIT_FAILURE;
    }

    while (true) {
        struct pcap_pkthdr* header;
        const uint8_t* packet;
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == 0) continue;
        if (res == -1 || res == -2) break;

        struct ether_header* etherh = (struct ether_header*) packet;
        struct iphdr* iph = (struct iphdr*) (packet + sizeof(struct ether_header));

        if (htons(etherh->ether_type) != ETHERTYPE_IP) continue;
        if (iph->protocol == IPPROTO_TCP) {
            struct tcphdr* tcph = (struct tcphdr*) (packet + sizeof(struct ether_header) + sizeof(struct iphdr));
            printf("TCP packet received from %s:%d to %s:%d\n", inet_ntoa(*(struct in_addr*)&iph->saddr), ntohs(tcph->source), inet_ntoa(*(struct in_addr*)&iph->daddr), ntohs(tcph->dest));
            add_topology_node(create_topology_map(), inet_ntoa(*(struct in_addr*)&iph->saddr));
            add_topology_node(create_topology_map(), inet_ntoa(*(struct in_addr*)&iph->daddr));
        } else if (iph->protocol == IPPROTO_UDP) {
            struct udphdr* udph = (struct udphdr*) (packet + sizeof(struct ether_header) + sizeof(struct iphdr));
            printf("UDP packet received from %s:%d to %s:%d\n", inet_ntoa(*(struct in_addr*)&iph->saddr), ntohs(udph->source), inet_ntoa(*(struct in_addr*)&iph->daddr), ntohs(udph->dest));
            add_topology_node(create_topology_map(), inet_ntoa(*(struct in_addr*)&iph->saddr));
            add_topology_node(create_topology_map(), inet_ntoa(*(struct in_addr*)&iph->daddr));
        } else if (iph->protocol == IPPROTO_ICMP) {
            printf("ICMP packet received from %s to %s\n", inet_ntoa(*(struct in_addr*)&iph->saddr), inet_ntoa(*(struct in_addr*)&iph->daddr));
            add_topology_node(create_topology_map(), inet_ntoa(*(struct in_addr*)&iph->saddr));
            add_topology_node(create_topology_map(), inet_ntoa(*(struct in_addr*)&iph->daddr));
        }  
    }

    pcap_close(handle);
    destroy_topology_map(create_topology_map());

    return EXIT_SUCCESS;
}