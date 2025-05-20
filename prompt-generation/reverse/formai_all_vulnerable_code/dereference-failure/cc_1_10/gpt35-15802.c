//FormAI DATASET v1.0 Category: Firewall ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the firewall rules
struct firewall_rule {
    int protocol;
    char *ip_address;
    char *port_number;
};

// Check if a packet matches the given rule
int packet_matches_rule(char *packet, struct firewall_rule rule) {
    char *protocol_str = strtok(packet, " ");
    int protocol = atoi(protocol_str);
    if(protocol != rule.protocol) {
        return 0;
    }

    char *ip_address = strtok(NULL, " ");
    if(strcmp(ip_address, rule.ip_address) != 0) {
        return 0;
    }

    char *port_number = strtok(NULL, " ");
    if(strcmp(port_number, rule.port_number) != 0) {
        return 0;
    }

    return 1;
}

// Main function
int main() {
    struct firewall_rule rules[3] = {
        {1, "192.168.1.1", "8080"},
        {2, "192.168.1.2", "8081"},
        {3, "192.168.1.3", "8082"}
    };

    printf("Enter the packet to check (in the format 'protocol ip_address port_number'): ");
    char packet[100];
    fgets(packet, 100, stdin);

    int packet_matches = 0;
    for(int i = 0; i < 3; i++) {
        if(packet_matches_rule(packet, rules[i])) {
            packet_matches = 1;
            break;
        }
    }

    if(packet_matches) {
        printf("Packet matches one of the firewall rules.\n");
    } else {
        printf("Packet does not match any of the firewall rules.\n");
    }

    return 0;
}