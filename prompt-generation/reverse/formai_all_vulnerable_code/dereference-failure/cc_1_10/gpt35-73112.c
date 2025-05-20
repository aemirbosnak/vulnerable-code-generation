//FormAI DATASET v1.0 Category: Firewall ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* IP structure */
typedef struct {
    int octet[4];
}IP;

/* Firewall rule structure */
typedef struct {
    char protocol[10];
    char direction[10];
    IP source_ip;
    int source_port;
    IP destination_ip;
    int destination_port;
}FirewallRule;

/* Function to parse IP address string */
IP parseIP(char* ip_string) {
    char* token = strtok(ip_string, ".");
    IP ip;

    int i = 0;
    while(token != NULL) {
        ip.octet[i++] = atoi(token);
        token = strtok(NULL, ".");
    }
    return ip;
}

/* Function to compare IP addresses */
int compareIP(IP ip1, IP ip2) {
    int i;
    for(i = 0; i < 4; i++) {
        if(ip1.octet[i] != ip2.octet[i])
            return 0;
    }
    return 1;
}

/* Function to check if IP address is in subnet */
int isInSubnet(IP ip, IP network_address, int subnet_mask) {
    int i;
    for(i = 0; i < 4; i++) {
        if((ip.octet[i] & subnet_mask) != (network_address.octet[i] & subnet_mask))
            return 0;
    }
    return 1;
}

/* Function to check if a packet matches a firewall rule */
int matchesRule(char* packet, FirewallRule rule) {
    // Parse packet header
    char* protocol = strtok(packet, ",");
    char* direction = strtok(NULL, ",");
    char* source_ip_string = strtok(NULL, ",");
    char* source_port_string = strtok(NULL, ",");
    char* destination_ip_string = strtok(NULL, ",");
    char* destination_port_string = strtok(NULL, ",");

    // Parse IP addresses and ports
    IP source_ip = parseIP(source_ip_string);
    int source_port = atoi(source_port_string);
    IP destination_ip = parseIP(destination_ip_string);
    int destination_port = atoi(destination_port_string);

    // Compare protocol and check if directions match
    if(strcmp(protocol, rule.protocol) != 0 || strcmp(direction, rule.direction) != 0)
        return 0;

    // Check if source IP and port match
    if(!compareIP(source_ip, rule.source_ip) || source_port != rule.source_port)
        return 0;

    // Check if destination IP and port match
    if(!compareIP(destination_ip, rule.destination_ip) || destination_port != rule.destination_port)
        return 0;

    return 1;
}

int main() {
    FILE* rule_file = fopen("firewall_rules.txt", "r");
    if(rule_file == NULL) {
        printf("Error opening firewall rules file.\n");
        return 1;
    }

    // Load firewall rules from file
    int num_rules = 0;
    FirewallRule rules[100];
    char line[100];
    while(fgets(line, sizeof(line), rule_file)) {
        char* token = strtok(line, " ");
        strcpy(rules[num_rules].protocol, token);

        token = strtok(NULL, " ");
        strcpy(rules[num_rules].direction, token);

        token = strtok(NULL, "/");
        rules[num_rules].source_ip = parseIP(token);

        token = strtok(NULL, " ");
        rules[num_rules].source_port = atoi(token);

        token = strtok(NULL, "/");
        rules[num_rules].destination_ip = parseIP(token);

        token = strtok(NULL, " ");
        rules[num_rules].destination_port = atoi(token);

        num_rules++;
    }

    fclose(rule_file);

    // Listen for incoming packets
    char packet[100];
    while(1) {
        printf("Enter packet header (protocol,direction,source_ip,source_port,destination_ip,destination_port):\n");
        fgets(packet, sizeof(packet), stdin);

        // Check if packet matches any firewall rules
        int i;
        for(i = 0; i < num_rules; i++) {
            if(matchesRule(packet, rules[i])) {
                printf("Packet is allowed.\n");
                break;
            }
        }
        if(i == num_rules)
            printf("Packet is blocked.\n");
    }

    return 0;
}