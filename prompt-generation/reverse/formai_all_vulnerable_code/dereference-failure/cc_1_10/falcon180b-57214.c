//Falcon-180B DATASET v1.0 Category: Firewall ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100

typedef struct {
    char *protocol;
    char *source_ip;
    char *destination_ip;
    char *action;
} Rule;

int load_rules(Rule *rules) {
    FILE *file = fopen("rules.txt", "r");
    if (file == NULL) {
        printf("Error: could not open rules file.\n");
        return 1;
    }

    int rule_count = 0;
    while (fscanf(file, "%s %s %s %s\n", rules[rule_count].protocol, rules[rule_count].source_ip, rules[rule_count].destination_ip, rules[rule_count].action) == 4) {
        rule_count++;
        if (rule_count >= MAX_RULES) {
            printf("Error: too many rules.\n");
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

int evaluate_rule(Rule *rule, char *protocol, char *source_ip, char *destination_ip) {
    if (strcmp(rule->protocol, protocol)!= 0) {
        return 0;
    }

    if (strcmp(rule->source_ip, "*") == 0 || strcmp(rule->source_ip, source_ip) == 0) {
        if (strcmp(rule->destination_ip, "*") == 0 || strcmp(rule->destination_ip, destination_ip) == 0) {
            return 1;
        }
    }

    return 0;
}

int main() {
    Rule rules[MAX_RULES];
    load_rules(rules);

    char protocol[MAX_RULE_LENGTH];
    char source_ip[MAX_RULE_LENGTH];
    char destination_ip[MAX_RULE_LENGTH];

    while (1) {
        printf("Enter protocol, source IP, and destination IP: ");
        scanf("%s %s %s", protocol, source_ip, destination_ip);

        int rule_found = 0;
        for (int i = 0; i < MAX_RULES; i++) {
            if (evaluate_rule(&rules[i], protocol, source_ip, destination_ip)) {
                printf("Access %s.\n", rules[i].action);
                rule_found = 1;
                break;
            }
        }

        if (!rule_found) {
            printf("Access denied.\n");
        }
    }

    return 0;
}