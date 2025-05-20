//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Define the maximum number of rules
#define MAX_RULES 100

// Define the maximum length of a rule
#define MAX_RULE_LENGTH 100

// Define the structure of a firewall rule
typedef struct {
    char source_ip[16];
    char destination_ip[16];
    int source_port;
    int destination_port;
    char protocol[10];
    char action[10];
} firewall_rule;

// Define the structure of the firewall
typedef struct {
    firewall_rule rules[MAX_RULES];
    int num_rules;
} firewall;

// Create a new firewall
firewall *firewall_new() {
    firewall *fw = malloc(sizeof(firewall));
    fw->num_rules = 0;
    return fw;
}

// Add a rule to the firewall
void firewall_add_rule(firewall *fw, firewall_rule rule) {
    if (fw->num_rules < MAX_RULES) {
        fw->rules[fw->num_rules++] = rule;
    }
}

// Print the firewall rules
void firewall_print_rules(firewall *fw) {
    for (int i = 0; i < fw->num_rules; i++) {
        printf("%s %s %d %d %s %s\n", fw->rules[i].source_ip, fw->rules[i].destination_ip, fw->rules[i].source_port, fw->rules[i].destination_port, fw->rules[i].protocol, fw->rules[i].action);
    }
}

// Check if a packet matches a firewall rule
int firewall_check_packet(firewall *fw, char *source_ip, char *destination_ip, int source_port, int destination_port, char *protocol) {
    for (int i = 0; i < fw->num_rules; i++) {
        firewall_rule rule = fw->rules[i];
        if (strcmp(rule.source_ip, source_ip) == 0 && strcmp(rule.destination_ip, destination_ip) == 0 && rule.source_port == source_port && rule.destination_port == destination_port && strcmp(rule.protocol, protocol) == 0) {
            return 1;
        }
    }
    return 0;
}

// Main function
int main() {
    // Create a new firewall
    firewall *fw = firewall_new();

    // Add some rules to the firewall
    firewall_rule rule1 = { "192.168.1.1", "192.168.1.2", 80, 80, "tcp", "allow" };
    firewall_add_rule(fw, rule1);
    firewall_rule rule2 = { "192.168.1.2", "192.168.1.3", 443, 443, "tcp", "allow" };
    firewall_add_rule(fw, rule2);
    firewall_rule rule3 = { "192.168.1.3", "192.168.1.1", 22, 22, "tcp", "allow" };
    firewall_add_rule(fw, rule3);

    // Print the firewall rules
    firewall_print_rules(fw);

    // Check if a packet matches a firewall rule
    int result = firewall_check_packet(fw, "192.168.1.1", "192.168.1.2", 80, 80, "tcp");
    if (result) {
        printf("Packet allowed\n");
    } else {
        printf("Packet denied\n");
    }

    // Free the firewall
    free(fw);

    return 0;
}