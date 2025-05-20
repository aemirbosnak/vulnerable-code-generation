//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// Structure to represent a rule
typedef struct Rule {
    int protocol; // Protocol (TCP/UDP/ICMP)
    int port;     // Port number
    char *source_ip; // Source IP address
    char *destination_ip; // Destination IP address
    char *action;    // Action (ALLOW/DENY)
} Rule;

// Structure to represent the firewall
typedef struct Firewall {
    int num_rules; // Number of rules
    Rule *rules;     // Array of rules
} Firewall;

// Function to create a new firewall
Firewall *create_firewall() {
    Firewall *firewall = malloc(sizeof(Firewall));
    firewall->num_rules = 0;
    firewall->rules = NULL;
    return firewall;
}

// Function to destroy a firewall
void destroy_firewall(Firewall *firewall) {
    for (int i = 0; i < firewall->num_rules; i++) {
        free(firewall->rules[i].source_ip);
        free(firewall->rules[i].destination_ip);
        free(firewall->rules[i].action);
    }
    free(firewall->rules);
    free(firewall);
}

// Function to add a rule to the firewall
void add_rule(Firewall *firewall, Rule rule) {
    firewall->num_rules++;
    firewall->rules = realloc(firewall->rules, firewall->num_rules * sizeof(Rule));
    firewall->rules[firewall->num_rules - 1] = rule;
}

// Function to check if a packet is allowed by the firewall
int check_packet(Firewall *firewall, int protocol, int port, char *source_ip, char *destination_ip) {
    for (int i = 0; i < firewall->num_rules; i++) {
        Rule rule = firewall->rules[i];
        if (rule.protocol == protocol && rule.port == port && strcmp(rule.source_ip, source_ip) == 0 && strcmp(rule.destination_ip, destination_ip) == 0) {
            return strcmp(rule.action, "ALLOW") == 0;
        }
    }
    return 0;
}

// Function to test the firewall
int main() {
    // Create a new firewall
    Firewall *firewall = create_firewall();

    // Add some rules to the firewall
    Rule rule1 = { IPPROTO_TCP, 80, "192.168.1.1", "192.168.1.2", "ALLOW" };
    Rule rule2 = { IPPROTO_UDP, 53, "192.168.1.2", "8.8.8.8", "ALLOW" };
    Rule rule3 = { IPPROTO_ICMP, 0, "192.168.1.3", "192.168.1.4", "DENY" };
    add_rule(firewall, rule1);
    add_rule(firewall, rule2);
    add_rule(firewall, rule3);

    // Check if some packets are allowed by the firewall
    int allowed1 = check_packet(firewall, IPPROTO_TCP, 80, "192.168.1.1", "192.168.1.2");
    int allowed2 = check_packet(firewall, IPPROTO_UDP, 53, "192.168.1.2", "8.8.8.8");
    int allowed3 = check_packet(firewall, IPPROTO_ICMP, 0, "192.168.1.3", "192.168.1.4");

    // Print the results
    printf("Packet 1 allowed: %s\n", allowed1 ? "Yes" : "No");
    printf("Packet 2 allowed: %s\n", allowed2 ? "Yes" : "No");
    printf("Packet 3 allowed: %s\n", allowed3 ? "Yes" : "No");

    // Destroy the firewall
    destroy_firewall(firewall);

    return 0;
}