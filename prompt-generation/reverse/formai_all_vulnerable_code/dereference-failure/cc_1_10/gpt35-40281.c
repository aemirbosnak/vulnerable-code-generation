//FormAI DATASET v1.0 Category: Firewall ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define some constants
#define MAX_RULES 1000
#define MAX_IP_LEN 16

// Define the rule structure
typedef struct firewall_rule {
    char ip[MAX_IP_LEN];
    char action[10];
} firewall_rule;

// Define the firewall structure
typedef struct firewall {
    int num_rules;
    firewall_rule rules[MAX_RULES];
} firewall;

// Add a rule to the firewall structure
void add_rule(firewall* fw, char* ip, char* action) {
    if (fw->num_rules < MAX_RULES) {
        strcpy(fw->rules[fw->num_rules].ip, ip);
        strcpy(fw->rules[fw->num_rules].action, action);
        fw->num_rules++;
    } else {
        printf("Error: Maximum number of rules exceeded.\n");
    }
}

// Check if an IP matches a rule in the firewall structure
int check_rule(firewall* fw, char* ip) {
    int i;
    for (i = 0; i < fw->num_rules; i++) {
        if (strcmp(ip, fw->rules[i].ip) == 0) {
            if (strcmp(fw->rules[i].action, "allow") == 0) {
                return 1;
            } else if (strcmp(fw->rules[i].action, "deny") == 0) {
                return 0;
            }
        }
    }
    return 1;
}

// Example usage of the firewall
int main() {
    // Create the firewall
    firewall* fw = (firewall*) malloc(sizeof(firewall));
    fw->num_rules = 0;

    // Add some rules to the firewall
    add_rule(fw, "192.168.0.1", "allow");
    add_rule(fw, "10.1.2.3", "deny");

    // Check some IP addresses against the firewall
    if (check_rule(fw, "192.168.0.1")) {
        printf("Allowed!\n");
    } else {
        printf("Denied!\n");
    }

    if (check_rule(fw, "10.1.2.3")) {
        printf("Allowed!\n");
    } else {
        printf("Denied!\n");
    }

    if (check_rule(fw, "8.8.8.8")) {
        printf("Allowed!\n");
    } else {
        printf("Denied!\n");
    }

    // Free memory and exit
    free(fw);
    return 0;
}