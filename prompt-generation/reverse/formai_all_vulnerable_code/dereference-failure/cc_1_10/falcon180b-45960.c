//Falcon-180B DATASET v1.0 Category: Firewall ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULE_LENGTH 100
#define MAX_RULES 100

struct rule {
    char *src_ip;
    char *dst_ip;
    char *src_port;
    char *dst_port;
    char action;
};

void add_rule(struct rule *rules, int num_rules, char *rule_str) {
    char *token;
    int i = num_rules;

    while ((token = strtok(rule_str, " "))!= NULL) {
        if (i >= MAX_RULES) {
            printf("Error: Maximum number of rules exceeded.\n");
            exit(1);
        }

        switch (token[0]) {
            case 'A':
                rules[i].action = 'A';
                break;
            case 'D':
                rules[i].action = 'D';
                break;
            default:
                printf("Error: Invalid action specified.\n");
                exit(1);
        }

        if (strlen(token) > MAX_RULE_LENGTH) {
            printf("Error: Rule string too long.\n");
            exit(1);
        }

        strcpy(rules[i].src_ip, token);
        i++;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <rule1> <rule2>...\n", argv[0]);
        exit(1);
    }

    int num_rules = 0;
    struct rule rules[MAX_RULES];

    while (num_rules < MAX_RULES && argc > 1) {
        add_rule(rules, num_rules, argv[1]);
        argc--;
        num_rules++;
    }

    printf("Firewall rules:\n");
    for (int i = 0; i < num_rules; i++) {
        printf("Rule %d: %s\n", i + 1, rules[i].src_ip);
    }

    return 0;
}