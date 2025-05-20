//FormAI DATASET v1.0 Category: Firewall ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_IP_SIZE 16

typedef struct FirewallRule {
    char *ip;
    int port;
} FirewallRule;

/**
 * Check if the given IP matches the given rule
 * @param ip the IP to check
 * @param rule the rule to match against
 * @return 1 if the IP matches, 0 otherwise
 */
int matches_rule(char *ip, FirewallRule *rule) {
    // Check if the IPs match
    if (strcmp(ip, rule->ip) != 0) {
        return 0;
    }

    // Check if the ports match
    if (rule->port == 0) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * Parse a line from the rules file and return a FirewallRule struct
 * @param line the line to parse
 * @return a pointer to a FirewallRule struct, or NULL if the line is invalid
 */
FirewallRule *parse_rule(char *line) {
    FirewallRule *rule = malloc(sizeof(FirewallRule));
    char *ip_str = strtok(line, ":");
    char *port_str = strtok(NULL, ":");
    int port;

    // Check if the IP and port were successfully parsed
    if (ip_str == NULL || port_str == NULL) {
        return NULL;
    }

    // Copy the IP string and parse the port
    rule->ip = strdup(ip_str);
    port = atoi(port_str);

    // Make sure the port is valid
    if (port < 0 || port > 65535) {
        return NULL;
    }

    rule->port = port;

    return rule;
}

int main(int argc, char **argv) {
    FILE *rules_file;
    char line[MAX_LINE_SIZE];
    char ip[MAX_IP_SIZE];
    FirewallRule *rules;
    int num_rules = 0;
    int i;

    if (argc < 2) {
        printf("Usage: firewall <rules_file>\n");
        exit(1);
    }

    rules_file = fopen(argv[1], "r");

    if (rules_file == NULL) {
        printf("Error opening rules file: %s\n", argv[1]);
        exit(1);
    }

    // Read the rules file and store the rules in an array
    while (fgets(line, MAX_LINE_SIZE, rules_file) != NULL) {
        FirewallRule *rule = parse_rule(line);

        if (rule != NULL) {
            num_rules++;
            rules = realloc(rules, num_rules * sizeof(FirewallRule));
            rules[num_rules-1] = *rule;
            free(rule);
        }
    }

    fclose(rules_file);

    // Prompt for an IP address to check
    printf("Enter an IP address to check: ");
    fgets(ip, MAX_IP_SIZE, stdin);
    ip[strlen(ip)-1] = '\0';

    // Check if the IP matches any of the rules
    for (i = 0; i < num_rules; i++) {
        if (matches_rule(ip, &rules[i])) {
            printf("IP %s matches rule %s:%d\n", ip, rules[i].ip, rules[i].port);
            exit(0);
        }
    }

    printf("IP %s does not match any rules\n", ip);

    return 0;
}