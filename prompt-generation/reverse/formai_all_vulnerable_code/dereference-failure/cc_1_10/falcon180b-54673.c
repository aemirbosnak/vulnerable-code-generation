//Falcon-180B DATASET v1.0 Category: Firewall ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100
#define MAX_IP_LENGTH 16

typedef struct {
    char ip[MAX_IP_LENGTH];
    char action;
} rule_t;

rule_t rules[MAX_RULES];
int num_rules;

void load_rules() {
    FILE *fp;
    char line[MAX_RULE_LENGTH];
    char *token;
    rule_t rule;

    fp = fopen("firewall.rules", "r");
    if (fp == NULL) {
        printf("Error: could not open firewall.rules\n");
        exit(1);
    }

    num_rules = 0;
    while (fgets(line, MAX_RULE_LENGTH, fp)!= NULL) {
        token = strtok(line, " ");
        strcpy(rule.ip, token);

        token = strtok(NULL, " ");
        if (token == NULL) {
            printf("Error: malformed rule in firewall.rules\n");
            exit(1);
        }

        rule.action = tolower(token[0]);
        rules[num_rules++] = rule;
    }

    fclose(fp);
}

int match_rule(char *ip) {
    int i;
    for (i = 0; i < num_rules; i++) {
        if (strcmp(ip, rules[i].ip) == 0) {
            return rules[i].action;
        }
    }
    return 'D'; // default action is deny
}

int main() {
    load_rules();

    while (1) {
        char ip[MAX_IP_LENGTH];
        printf("Enter IP address: ");
        scanf("%s", ip);

        int action = match_rule(ip);
        if (action == 'A') {
            printf("Access granted\n");
        } else if (action == 'D') {
            printf("Access denied\n");
        }
    }

    return 0;
}