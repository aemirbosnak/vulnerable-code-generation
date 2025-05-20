//Falcon-180B DATASET v1.0 Category: Firewall ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100
#define ALLOW 1
#define DENY 0

typedef struct {
    char *protocol;
    char *ip_address;
    char *port;
    int action;
} Rule;

int read_rules(Rule *rules, int *num_rules) {
    FILE *file = fopen("firewall_rules.txt", "r");
    if (file == NULL) {
        printf("Error: could not open firewall_rules.txt\n");
        exit(1);
    }

    char line[MAX_RULE_LENGTH];
    while (fgets(line, MAX_RULE_LENGTH, file)!= NULL) {
        if (*num_rules >= MAX_RULES) {
            printf("Error: too many rules\n");
            exit(1);
        }

        char *protocol = strtok(line, " ");
        char *ip_address = strtok(NULL, " ");
        char *port = strtok(NULL, " ");
        int action = strcmp(protocol, "ALLOW") == 0? ALLOW : DENY;

        rules[*num_rules].protocol = strdup(protocol);
        rules[*num_rules].ip_address = strdup(ip_address);
        rules[*num_rules].port = strdup(port);
        rules[*num_rules].action = action;

        (*num_rules)++;
    }

    fclose(file);
    return 0;
}

int evaluate_rule(Rule *rule, char *protocol, char *ip_address, char *port) {
    if (strcmp(rule->protocol, protocol)!= 0) {
        return rule->action;
    }

    if (strcmp(rule->ip_address, "*") == 0 || strcmp(rule->ip_address, ip_address) == 0) {
        if (strcmp(rule->port, "*") == 0 || strcmp(rule->port, port) == 0) {
            return rule->action;
        }
    }

    return rule->action;
}

int main() {
    Rule rules[MAX_RULES];
    int num_rules = 0;

    if (read_rules(rules, &num_rules)!= 0) {
        exit(1);
    }

    char *protocol = "TCP";
    char *ip_address = "192.168.1.2";
    char *port = "80";

    int result = evaluate_rule(&rules[0], protocol, ip_address, port);

    if (result == ALLOW) {
        printf("Access allowed\n");
    } else {
        printf("Access denied\n");
    }

    return 0;
}