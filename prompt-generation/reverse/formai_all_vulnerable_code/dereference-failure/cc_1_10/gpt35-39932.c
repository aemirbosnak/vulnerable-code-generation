//FormAI DATASET v1.0 Category: Firewall ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for each rule in the firewall list
typedef struct firewall_rule {
    char* source_ip;
    char* dest_ip;
    int source_port;
    int dest_port;
    char* protocol;
    int action;
} firewall_rule_t;

// Define a structure for the firewall
typedef struct firewall {
    int num_rules;
    firewall_rule_t **rules;
} firewall_t;

// Function to create a new firewall rule
firewall_rule_t *new_firewall_rule(char* source_ip, char* dest_ip, int source_port, int dest_port, char* protocol, int action) {
    firewall_rule_t *rule = (firewall_rule_t *) malloc(sizeof(firewall_rule_t));
    rule->source_ip = strdup(source_ip);
    rule->dest_ip = strdup(dest_ip);
    rule->source_port = source_port;
    rule->dest_port = dest_port;
    rule->protocol = strdup(protocol);
    rule->action = action;
    return rule;
}

// Function to add a rule to the firewall
void add_firewall_rule(firewall_t* firewall, firewall_rule_t* rule) {
    firewall->rules = (firewall_rule_t **) realloc(firewall->rules, 
        sizeof(firewall_rule_t *) * (firewall->num_rules + 1));
    firewall->rules[firewall->num_rules++] = rule;
}

// Function to check a packet against the firewall rules
int check_firewall_packet(firewall_t* firewall, char* source_ip, char* dest_ip, int source_port, int dest_port, char* protocol) {
    for (int i = 0; i < firewall->num_rules; i++) {
        firewall_rule_t* rule = firewall->rules[i];
        if ((strcmp(source_ip, rule->source_ip) == 0 || strcmp(rule->source_ip, "*") == 0) &&
            (strcmp(dest_ip, rule->dest_ip) == 0 || strcmp(rule->dest_ip, "*") == 0) &&
            (source_port == rule->source_port || rule->source_port == -1) &&
            (dest_port == rule->dest_port || rule->dest_port == -1) &&
            (strcmp(protocol, rule->protocol) == 0 || strcmp(rule->protocol, "*") == 0)) {
            return rule->action;
        }
    }
    return -1;
}

int main() {
    // Create the firewall
    firewall_t *firewall = (firewall_t *) malloc (sizeof(firewall_t));
    firewall->num_rules = 0;
    firewall->rules = NULL;
    // Add some rules to the firewall
    add_firewall_rule(firewall, new_firewall_rule("192.168.0.1", "*", 80, -1, "tcp", 1));
    add_firewall_rule(firewall, new_firewall_rule("192.168.0.2", "*", -1, -1, "icmp", 0));
    add_firewall_rule(firewall, new_firewall_rule("*", "*", -1, -1, "*", 1));
    // Test the firewall with some packets
    printf("Packet 1: Source IP 192.168.0.1, Dest IP 10.0.0.1, Source Port 80, Dest Port 443, Protocol tcp\n");
    int result = check_firewall_packet(firewall, "192.168.0.1", "10.0.0.1", 80, 443, "tcp");
    if (result == 1) {
        printf("Packet allowed by firewall\n");
    } else {
        printf("Packet denied by firewall\n");
    }
    printf("Packet 2: Source IP 192.168.0.2, Dest IP 10.0.0.2, Source Port 123, Dest Port 321, Protocol icmp\n");
    result = check_firewall_packet(firewall, "192.168.0.2", "10.0.0.2", 123, 321, "icmp");
    if (result == 1) {
        printf("Packet allowed by firewall\n");
    } else {
        printf("Packet denied by firewall\n");
    }
    printf("Packet 3: Source IP 10.0.0.3, Dest IP 10.0.0.4, Source Port 456, Dest Port 789, Protocol udp\n");
    result = check_firewall_packet(firewall, "10.0.0.3", "10.0.0.4", 456, 789, "udp");
    if (result == 1) {
        printf("Packet allowed by firewall\n");
    } else {
        printf("Packet denied by firewall\n");
    }
    // Free the memory used by the firewall
    for (int i = 0; i < firewall->num_rules; i++) {
        free(firewall->rules[i]->source_ip);
        free(firewall->rules[i]->dest_ip);
        free(firewall->rules[i]->protocol);
        free(firewall->rules[i]);
    }
    free(firewall->rules);
    free(firewall);
    return 0;
}