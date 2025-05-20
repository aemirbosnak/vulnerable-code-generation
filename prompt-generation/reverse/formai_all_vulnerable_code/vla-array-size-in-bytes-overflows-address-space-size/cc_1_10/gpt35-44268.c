//FormAI DATASET v1.0 Category: Firewall ; Style: Linus Torvalds
/**
* This is a Firewall program written in the Linus Torvalds style.
* This program takes in packets as input and checks if they should be allowed through the firewall.
* If a packet is allowed, it is forwarded to its destination. If not, it is dropped.
**/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define the struct for packets
typedef struct Packet {
    char sourceIP[20];
    char destIP[20];
    int sourcePort;
    int destPort;
    char protocol[10];
} Packet;

// Define the struct for Firewall rules
typedef struct Rule {
    char sourceIP[20];
    char destIP[20];
    int sourcePort;
    int destPort;
    char protocol[10];
    bool allow;
} Rule;

// Define the function to parse packets from input
Packet parse_packet(char* input) {
    Packet packet;
    sscanf(input, "%s %d %s %d %s", packet.sourceIP, &packet.sourcePort, packet.destIP, &packet.destPort, packet.protocol);
    return packet;
}

// Define the function to parse firewall rules from input
Rule parse_rule(char* input) {
    Rule rule;
    char allowStr[10];
    sscanf(input, "%s %s %d %d %s", rule.sourceIP, rule.destIP, &rule.sourcePort, &rule.destPort, rule.protocol);
    sscanf(input, "%*s %*s %*d %*d %*s %s", allowStr);
    if (strcmp(allowStr, "allow") == 0) {
        rule.allow = true;
    } else {
        rule.allow = false;
    }
    return rule;
}

// Define the function to check if a packet matches a firewall rule
bool packet_matches_rule(Packet packet, Rule rule) {
    bool sourceMatch = strcmp(packet.sourceIP, rule.sourceIP) == 0;
    bool destMatch = strcmp(packet.destIP, rule.destIP) == 0;
    bool sourcePortMatch = packet.sourcePort == rule.sourcePort;
    bool destPortMatch = packet.destPort == rule.destPort;
    bool protocolMatch = strcmp(packet.protocol, rule.protocol) == 0;
    if (sourceMatch && destMatch && sourcePortMatch && destPortMatch && protocolMatch) {
        return true;
    } else {
        return false;
    }
}

// Define the main function
int main() {
    // Read in firewall rules
    int numRules;
    scanf("%d", &numRules);
    Rule rules[numRules];
    for (int i = 0; i < numRules; i++) {
        char input[100];
        scanf("%s", input);
        rules[i] = parse_rule(input);
    }

    // Read in packets and check if they should be allowed
    int numPackets;
    scanf("%d", &numPackets);
    for (int i = 0; i < numPackets; i++) {
        char input[100];
        scanf("%s", input);
        Packet packet = parse_packet(input);
        bool allowed = false;
        for (int j = 0; j < numRules; j++) {
            if (packet_matches_rule(packet, rules[j])) {
                allowed = rules[j].allow;
                break;
            }
        }
        if (allowed) {
            printf("Packet %d: ALLOWED\n", i+1);
        } else {
            printf("Packet %d: DROPPED\n", i+1);
        }
    }

    return 0;
}