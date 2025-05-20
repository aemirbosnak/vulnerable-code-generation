//Falcon-180B DATASET v1.0 Category: Firewall ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100
#define MAX_IP_LENGTH 16
#define ALLOW 1
#define DENY 0

typedef struct {
    int action;
    char ip[MAX_IP_LENGTH];
} rule_t;

int num_rules = 0;
rule_t rules[MAX_RULES];

void add_rule(char* ip, int action) {
    if (num_rules >= MAX_RULES) {
        printf("Error: Maximum number of rules reached.\n");
        exit(1);
    }
    strcpy(rules[num_rules].ip, ip);
    rules[num_rules].action = action;
    num_rules++;
}

int match_rule(char* ip) {
    for (int i = 0; i < num_rules; i++) {
        if (strcmp(ip, rules[i].ip) == 0) {
            return rules[i].action;
        }
    }
    return DENY;
}

int main() {
    printf("Sherlock Holmes' Firewall\n");
    printf("-------------------------\n");
    char input[MAX_RULE_LENGTH];
    while (1) {
        printf("Enter rule (ip action): ");
        scanf("%s", input);
        char* ip = strtok(input, " ");
        int action = atoi(strtok(NULL, " "));
        add_rule(ip, action);
    }
    return 0;
}