//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100

typedef struct {
    char rule[MAX_RULE_LENGTH];
    char action[MAX_RULE_LENGTH];
} rule_t;

rule_t rules[MAX_RULES];
int num_rules;

void add_rule(char* rule, char* action) {
    if (num_rules >= MAX_RULES) {
        printf("Error: Too many rules\n");
        exit(1);
    }
    strcpy(rules[num_rules].rule, rule);
    strcpy(rules[num_rules].action, action);
    num_rules++;
}

void process_packet(char* packet) {
    int i;
    for (i = 0; i < num_rules; i++) {
        if (strstr(packet, rules[i].rule)) {
            system(rules[i].action);
        }
    }
}

int main() {
    char line[MAX_RULE_LENGTH];
    char rule[MAX_RULE_LENGTH];
    char action[MAX_RULE_LENGTH];
    num_rules = 0;

    printf("Enter rules (rule action):\n");
    while (fgets(line, MAX_RULE_LENGTH, stdin)!= NULL) {
        char* token = strtok(line, " ");
        strcpy(rule, token);
        token = strtok(NULL, " ");
        strcpy(action, token);
        add_rule(rule, action);
    }

    char packet[MAX_RULE_LENGTH];
    while (fgets(packet, MAX_RULE_LENGTH, stdin)!= NULL) {
        process_packet(packet);
    }

    return 0;
}