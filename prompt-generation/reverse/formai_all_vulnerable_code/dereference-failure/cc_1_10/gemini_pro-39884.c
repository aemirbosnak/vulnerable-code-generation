//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

// Define the maximum number of rules
#define MAX_RULES 100

// Define the structure of a firewall rule
typedef struct firewall_rule {
    char *address;
    int port;
    char *protocol;
    int action;
} firewall_rule;

// Define the structure of the firewall
typedef struct firewall {
    firewall_rule rules[MAX_RULES];
    int num_rules;
} firewall;

// Initialize the firewall
firewall *init_firewall() {
    firewall *fw = malloc(sizeof(firewall));
    fw->num_rules = 0;
    return fw;
}

// Add a rule to the firewall
void add_rule(firewall *fw, char *address, int port, char *protocol, int action) {
    if (fw->num_rules >= MAX_RULES) {
        printf("Error: Maximum number of rules reached\n");
        return;
    }

    fw->rules[fw->num_rules].address = strdup(address);
    fw->rules[fw->num_rules].port = port;
    fw->rules[fw->num_rules].protocol = strdup(protocol);
    fw->rules[fw->num_rules].action = action;
    fw->num_rules++;
}

// Check if a packet matches a firewall rule
int check_rule(firewall *fw, char *address, int port, char *protocol) {
    for (int i = 0; i < fw->num_rules; i++) {
        if (strcmp(fw->rules[i].address, address) == 0 &&
            fw->rules[i].port == port &&
            strcmp(fw->rules[i].protocol, protocol) == 0) {
            return fw->rules[i].action;
        }
    }

    return -1;
}

// Process a packet
int process_packet(firewall *fw, char *address, int port, char *protocol) {
    int action = check_rule(fw, address, port, protocol);

    if (action == -1) {
        printf("Error: No matching rule found\n");
        return -1;
    } else if (action == 0) {
        printf("Packet allowed\n");
        return 0;
    } else if (action == 1) {
        printf("Packet blocked\n");
        return 1;
    } else {
        printf("Error: Invalid action\n");
        return -1;
    }
}

// Free the memory allocated by the firewall
void free_firewall(firewall *fw) {
    for (int i = 0; i < fw->num_rules; i++) {
        free(fw->rules[i].address);
        free(fw->rules[i].protocol);
    }

    free(fw);
}

// Main function
int main() {
    // Initialize the firewall
    firewall *fw = init_firewall();

    // Add some rules to the firewall
    add_rule(fw, "192.168.1.1", 80, "tcp", 0);
    add_rule(fw, "192.168.1.2", 22, "tcp", 0);
    add_rule(fw, "192.168.1.3", 443, "tcp", 1);

    // Process a few packets
    process_packet(fw, "192.168.1.1", 80, "tcp");
    process_packet(fw, "192.168.1.2", 22, "tcp");
    process_packet(fw, "192.168.1.3", 443, "tcp");
    process_packet(fw, "192.168.1.4", 8080, "udp");

    // Free the memory allocated by the firewall
    free_firewall(fw);

    return 0;
}