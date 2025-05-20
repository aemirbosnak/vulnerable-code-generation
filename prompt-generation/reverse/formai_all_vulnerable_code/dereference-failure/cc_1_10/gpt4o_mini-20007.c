//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <pcap.h>

#define SIZE_ETHERNET 14
#define IP_HL(ip) (((ip)->ip_hl) & 0x0f)
#define TCP_HL(th) (((th)->th_off) & 0x0f)

struct firewall_rule {
    char ip[INET_ADDRSTRLEN];
    int port;
    int action; // 0 = allow, 1 = block
};

struct firewall {
    struct firewall_rule *rules;
    int rule_count;
};

struct firewall my_firewall;

void init_firewall() {
    my_firewall.rules = malloc(sizeof(struct firewall_rule) * 100);
    my_firewall.rule_count = 0;
}

void add_rule(const char *ip, int port, int action) {
    if (my_firewall.rule_count < 100) {
        strncpy(my_firewall.rules[my_firewall.rule_count].ip, ip, INET_ADDRSTRLEN);
        my_firewall.rules[my_firewall.rule_count].port = port;
        my_firewall.rules[my_firewall.rule_count].action = action;
        my_firewall.rule_count++;
    } else {
        printf("Rule limit reached.\n");
    }
}

int match_rule(const char *src_ip, int src_port) {
    for (int i = 0; i < my_firewall.rule_count; i++) {
        if (strcmp(my_firewall.rules[i].ip, src_ip) == 0 &&
            my_firewall.rules[i].port == src_port) {
            return my_firewall.rules[i].action;
        }
    }
    return 0; // default allow if no rule matches
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    const struct ip *ip_header = (struct ip *)(packet + SIZE_ETHERNET);
    const struct tcphdr *tcp_header = (struct tcphdr *)(packet + SIZE_ETHERNET + IP_HL(ip_header) * 4);
    
    char src_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(ip_header->ip_src), src_ip, INET_ADDRSTRLEN);
    
    int src_port = ntohs(tcp_header->th_sport);
    
    int action = match_rule(src_ip, src_port);
    if (action == 0) {
        printf("Packet from %s:%d allowed\n", src_ip, src_port);
    } else {
        printf("Packet from %s:%d blocked\n", src_ip, src_port);
    }
}

void start_capture(char *dev) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", dev, errbuf);
        return;
    }

    pcap_loop(handle, 0, packet_handler, NULL);
    pcap_close(handle);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <network_interface>\n", argv[0]);
        return 1;
    }

    init_firewall();
    add_rule("192.168.1.10", 8080, 1); // block example rule
    add_rule("192.168.1.15", 80, 0); // allow example rule

    printf("Starting packet capture on %s...\n", argv[1]);
    start_capture(argv[1]);

    free(my_firewall.rules);
    return 0;
}