//FormAI DATASET v1.0 Category: Firewall ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct FirewallRule {
    char* ip_address;
    char* protocol;
    int port;
    bool allow;
};

void addRule(struct FirewallRule** rules, int* num_rules, char* ip_address, char* protocol, int port, bool allow) {
    // Allocate memory for new rule
    struct FirewallRule* new_rule = malloc(sizeof(struct FirewallRule));
    new_rule->ip_address = malloc(strlen(ip_address) + 1);
    new_rule->protocol = malloc(strlen(protocol) + 1);
    
    // Copy data
    strcpy(new_rule->ip_address, ip_address);
    strcpy(new_rule->protocol, protocol);
    new_rule->port = port;
    new_rule->allow = allow;
    
    // Add rule to array
    (*rules)[*num_rules] = *new_rule;
    (*num_rules)++;
    
    // Reallocate memory for array
    *rules = realloc(*rules, sizeof(struct FirewallRule) * (*num_rules + 1));
}

bool checkRule(struct FirewallRule* rule, char* ip_address, char* protocol, int port) {
    if (strcmp(rule->ip_address, ip_address) == 0) {
        if (strcmp(rule->protocol, protocol) == 0) {
            if (rule->port == port) {
                return rule->allow;
            }
        }
    }
    
    return false;
}

bool packetAllowed(struct FirewallRule** rules, int num_rules, char* ip_address, char* protocol, int port) {
    // Check each rule in the array
    for (int i = 0; i < num_rules; i++) {
        if (checkRule(&(*rules)[i], ip_address, protocol, port)) {
            return true;
        }
    }
    
    return false;
}

int main() {
    struct FirewallRule* rules = malloc(sizeof(struct FirewallRule));
    int num_rules = 0;
    
    addRule(&rules, &num_rules, "192.168.1.1", "TCP", 80, true);
    addRule(&rules, &num_rules, "192.168.1.1", "UDP", 53, true);
    addRule(&rules, &num_rules, "192.168.1.2", "TCP", 22, false);
    
    if (packetAllowed(&rules, num_rules, "192.168.1.1", "TCP", 80)) {
        printf("Packet allowed\n");
    } else {
        printf("Packet blocked\n");
    }
    
    return 0;
}