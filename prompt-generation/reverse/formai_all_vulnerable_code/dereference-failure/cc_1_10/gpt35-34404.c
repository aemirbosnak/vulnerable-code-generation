//FormAI DATASET v1.0 Category: Firewall ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define RULES_FILE "rules.txt" // file that contains the firewall rules

struct rule {
    char protocol[10]; // protocol (TCP or UDP)
    char source_ip[20]; // source IP address
    int source_port; // source port
    char destination_ip[20]; // destination IP address
    int destination_port; // destination port
};

struct packet_header {
    struct iphdr ip; // IP header
    struct tcphdr tcp; // TCP header
};

int is_rule_matched(struct rule r, struct packet_header p_header) {
    if (strcmp(r.protocol, "TCP") == 0 && p_header.ip.protocol == IPPROTO_TCP) { // check protocol
        if (strcmp(r.source_ip, "any") == 0 || strcmp(r.source_ip, inet_ntoa(*(struct in_addr*)&(p_header.ip.saddr))) == 0) { // check source IP
            if (r.source_port == -1 || r.source_port == ntohs(p_header.tcp.source)) { // check source port
                if (strcmp(r.destination_ip, "any") == 0 || strcmp(r.destination_ip, inet_ntoa(*(struct in_addr*)&(p_header.ip.daddr))) == 0) { // check destination IP
                    if (r.destination_port == -1 || r.destination_port == ntohs(p_header.tcp.dest)) { // check destination port
                        return 1; // rule matched
                    }
                }
            }
        }
    }
    return 0; // rule not matched
}

void apply_firewall_rules(struct rule* rules, int num_rules, struct packet_header p_header) {
    for (int i = 0; i < num_rules; i++) {
        if (is_rule_matched(rules[i], p_header)) {
            printf("Packet dropped: \n");
            printf("Protocol: %s\n", rules[i].protocol);
            printf("Source IP: %s\n", rules[i].source_ip);
            printf("Source port: %d\n", rules[i].source_port);
            printf("Destination IP: %s\n", rules[i].destination_ip);
            printf("Destination port: %d\n\n", rules[i].destination_port);
            exit(0); // drop packet and terminate program
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        return 1;
    }

    int sock_fd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sock_fd == -1) {
        perror("socket");
        return 1;
    }

    char buffer[4096];
    struct sockaddr_in src_addr;
    socklen_t src_addr_len = sizeof(src_addr);

    struct rule rules[100];
    int num_rules = 0;

    FILE* fp = fopen(RULES_FILE, "r");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    char line[100];
    while (fgets(line, sizeof(line), fp) != NULL) {
        char* token = strtok(line, ",");
        strcpy(rules[num_rules].protocol, token);
        token = strtok(NULL, ",");
        strcpy(rules[num_rules].source_ip, token);
        token = strtok(NULL, ",");
        rules[num_rules].source_port = atoi(token);
        token = strtok(NULL, ",");
        strcpy(rules[num_rules].destination_ip, token);
        token = strtok(NULL, "\n");
        rules[num_rules].destination_port = atoi(token);
        num_rules++;
    }

    fclose(fp);

    while (1) {
        int len = recvfrom(sock_fd, buffer, sizeof(buffer), 0, (struct sockaddr*)&src_addr, &src_addr_len);
        if (len == -1) {
            perror("recvfrom");
            return 1;
        }
        struct packet_header p_header;
        memcpy(&p_header, buffer, sizeof(p_header));
        apply_firewall_rules(rules, num_rules, p_header);
    }

    close(sock_fd);
    return 0;
}