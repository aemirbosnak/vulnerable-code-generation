//FormAI DATASET v1.0 Category: Firewall ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_IP 20
#define MAX_RULES 100

/* Structure to hold each rule in the firewall */
typedef struct rule {
    char ip_addr[MAX_IP];
    int port;
} Rule;

/* Function to check if an IP address matches the given rule */
bool matches_rule(char* ip, Rule* rule) {
    /* Split the IP address into individual octets */
    int octet1, octet2, octet3, octet4;
    sscanf(ip, "%d.%d.%d.%d", &octet1, &octet2, &octet3, &octet4);
    
    /* Split the rule IP address into individual octets */
    char* rule_ip = rule->ip_addr;
    int rule_octet1, rule_octet2, rule_octet3, rule_octet4;
    sscanf(rule_ip, "%d.%d.%d.%d", &rule_octet1, &rule_octet2, &rule_octet3, &rule_octet4);
    
    /* Compare each octet, or wildcards if rule uses '*' */
    if (strcmp(rule_ip, "*.*.*.*") == 0) {
        /* Wildcard match all IPs */
        return true;
    } else if (strcmp(rule_ip, "*.*.*") == 0) {
        /* Wildcard match first 3 octets */
        return octet1 == rule_octet1 && octet2 == rule_octet2 && octet3 == rule_octet3;
    } else if (strcmp(rule_ip, "*.*") == 0) {
        /* Wildcard match first 2 octets */
        return octet1 == rule_octet1 && octet2 == rule_octet2;
    } else if (strcmp(rule_ip, "*") == 0) {
        /* Wildcard match first octet */
        return octet1 == rule_octet1;
    } else {
        /* Exact match all octets */
        return octet1 == rule_octet1 && octet2 == rule_octet2 && octet3 == rule_octet3 && octet4 == rule_octet4;
    }
}

int main() {
    /* Create an empty array to hold the rules */
    Rule rules[MAX_RULES];
    int num_rules = 0;
    
    /* Read in the rules from a file */
    FILE* file = fopen("rules.txt", "r");
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        /* Parse the rule into an IP address and port number */
        char* token = strtok(line, ",");
        strncpy(rules[num_rules].ip_addr, token, MAX_IP);
        token = strtok(NULL, ",");
        rules[num_rules].port = atoi(token);
        
        num_rules++;
    }
    fclose(file);
    
    /* Prompt the user for an IP address */
    printf("Enter an IP address: ");
    char ip[MAX_IP];
    fgets(ip, sizeof(ip), stdin);
    strtok(ip, "\n");  // remove newline character
    
    /* Check each rule to see if it matches the IP address */
    bool allowed = false;
    for (int i = 0; i < num_rules; i++) {
        if (matches_rule(ip, &rules[i])) {
            printf("IP address %s matches rule %s,%d\n", ip, rules[i].ip_addr, rules[i].port);
            allowed = true;
            break;
        }
    }
    
    if (allowed) {
        printf("Access granted\n");
    } else {
        printf("Access denied\n");
    }
    
    return 0;
}