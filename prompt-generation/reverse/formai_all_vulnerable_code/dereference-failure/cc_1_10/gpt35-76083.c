//FormAI DATASET v1.0 Category: Firewall ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <errno.h>

typedef struct {
    struct in_addr src_ip;
    u_short src_port;
    struct in_addr dst_ip;
    u_short dst_port;
    uint32_t seq_num;
    uint32_t ack_num;
} flow_t;

typedef struct {
    struct in_addr ip;
    // List of accepted flows
    int num_flows_accepted;
    flow_t *flows_accepted;
} rule_t;

typedef struct {
    // List of rules
    int num_rules;
    rule_t *rules;
} firewall_t;

int firewall_rule_accepts(flow_t *flow, rule_t *rule) {
    if (rule->ip.s_addr == INADDR_ANY || flow->dst_ip.s_addr == rule->ip.s_addr) {
        for (int i = 0; i < rule->num_flows_accepted; i++) {
            if (rule->flows_accepted[i].src_port == INADDR_ANY || rule->flows_accepted[i].src_port == flow->src_port) {
                if (rule->flows_accepted[i].src_ip.s_addr == INADDR_ANY || rule->flows_accepted[i].src_ip.s_addr == flow->src_ip.s_addr) {
                    if (rule->flows_accepted[i].dst_port == INADDR_ANY || rule->flows_accepted[i].dst_port == flow->dst_port) {
                        if (rule->flows_accepted[i].seq_num == 0 || rule->flows_accepted[i].seq_num == flow->seq_num) {
                            if (rule->flows_accepted[i].ack_num == 0 || rule->flows_accepted[i].ack_num == flow->ack_num) {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int firewall_accept_packet(firewall_t *firewall, struct iphdr *ip_header, struct tcphdr *tcp_header) {
    flow_t flow = {
            .src_ip = {ip_header->saddr},
            .dst_ip = {ip_header->daddr},
            .src_port = ntohs(tcp_header->source),
            .dst_port = ntohs(tcp_header->dest),
            .seq_num = ntohl(tcp_header->seq),
            .ack_num = ntohl(tcp_header->ack_seq),
    };
    for (int i = 0; i < firewall->num_rules; i++) {
        if (firewall_rule_accepts(&flow, &firewall->rules[i])) {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {

    firewall_t firewall = {
            .num_rules = 1,
            .rules = malloc(sizeof(rule_t)),
    };

    rule_t rule = {
            .ip = {inet_addr("192.168.0.1")},
            .num_flows_accepted = 1,
            .flows_accepted = malloc(sizeof(flow_t)),
    };

    flow_t flow = {
            .src_ip = {0},
            .src_port = 80,
            .dst_ip = {0},
            .dst_port = INADDR_ANY,
            .seq_num = 0,
            .ack_num = 0,
    };

    memcpy(&rule.flows_accepted[0], &flow, sizeof(flow_t));
    memcpy(&firewall.rules[0], &rule, sizeof(rule_t));

    int sock_raw = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sock_raw == -1) {
        printf("Error: %s", strerror(errno));
        return EXIT_FAILURE;
    }

    char packet[65536];
    while (1) {
        int len = recv(sock_raw, packet, sizeof(packet), 0);
        if (len == -1) {
            printf("Error: %s", strerror(errno));
            return EXIT_FAILURE;
        }

        struct iphdr *ip_header = (struct iphdr *) packet;
        struct tcphdr *tcp_header = (struct tcphdr *) (packet + sizeof(struct iphdr));
        if (firewall_accept_packet(&firewall, ip_header, tcp_header)) {
            printf("Packet accepted!");
        } else {
            printf("Packet rejected!");
        }
    }

    close(sock_raw);
    return EXIT_SUCCESS;
}