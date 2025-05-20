//FormAI DATASET v1.0 Category: Firewall ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition of the Firewall Rule structure
typedef struct {
    char *protocol;
    char *source_address;
    char *destination_address;
    int source_port;
    int destination_port;
    int action;
} FirewallRule;

// Definition of the Firewall configuration structure
typedef struct {
    FirewallRule *rules;
    int num_rules;
} FirewallConfig;

// Function to add a new rule to the configuration
void add_rule(FirewallConfig *config, FirewallRule *new_rule) {
    config->num_rules++;
    config->rules = realloc(config->rules, config->num_rules * sizeof(FirewallRule));
    config->rules[config->num_rules - 1] = *new_rule;
}

// Function to check if a given packet matches an existing rule in the configuration
int packet_matches_rule(FirewallRule *rule, char *protocol, char *source_address, char *destination_address, int source_port, int destination_port) {
    if (strcmp(rule->protocol, protocol) != 0) {
        return 0;
    }
    if (strcmp(rule->source_address, source_address) != 0) {
        return 0;
    }
    if (strcmp(rule->destination_address, destination_address) != 0) {
        return 0;
    }
    if (rule->source_port != source_port) {
        return 0;
    }
    if (rule->destination_port != destination_port) {
        return 0;
    }
    return 1;
}

// Function to check whether a given packet is allowed or not
int is_packet_allowed(FirewallConfig *config, char *protocol, char *source_address, char *destination_address, int source_port, int destination_port) {
    int num_rules = config->num_rules;
    int i;
    for (i = 0; i < num_rules; i++) {
        FirewallRule *rule = &(config->rules[i]);
        if (packet_matches_rule(rule, protocol, source_address, destination_address, source_port, destination_port)) {
            return rule->action;
        }
    }
    return -1;
}

int main() {
    // Create a new empty configuration
    FirewallConfig *config = malloc(sizeof(FirewallConfig));
    config->num_rules = 0;
    config->rules = NULL;

    // Define some sample rules
    FirewallRule *rule1 = malloc(sizeof(FirewallRule));
    rule1->protocol = "TCP";
    rule1->source_address = "192.168.1.1";
    rule1->destination_address = "10.0.0.1";
    rule1->source_port = 80;
    rule1->destination_port = 8080;
    rule1->action = 1;

    FirewallRule *rule2 = malloc(sizeof(FirewallRule));
    rule2->protocol = "UDP";
    rule2->source_address = "192.168.1.2";
    rule2->destination_address = "10.0.0.2";
    rule2->source_port = 53;
    rule2->destination_port = 53;
    rule2->action = 0;

    // Add the rules to the configuration
    add_rule(config, rule1);
    add_rule(config, rule2);

    // Simulate a packet
    char *protocol = "TCP";
    char *source_address = "192.168.1.1";
    char *destination_address = "10.0.0.1";
    int source_port = 80;
    int destination_port = 8080;

    // Check if the packet is allowed
    int action = is_packet_allowed(config, protocol, source_address, destination_address, source_port, destination_port);

    // Output the result
    if (action == 1) {
        printf("Packet allowed!\n");
    } else if (action == 0) {
        printf("Packet denied!\n");
    } else {
        printf("No rule found for packet.\n");
    }

    return 0;
}