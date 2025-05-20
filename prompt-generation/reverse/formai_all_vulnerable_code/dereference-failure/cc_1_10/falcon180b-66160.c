//Falcon-180B DATASET v1.0 Category: Firewall ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_RULES 100
#define MAX_RULE_LEN 80

struct rule {
    char src_ip[16];
    char dest_ip[16];
    char protocol[10];
    int src_port;
    int dest_port;
    int action;
};

void add_rule(struct rule *rules, int num_rules, char *rule_str) {
    char src_ip[16] = {0};
    char dest_ip[16] = {0};
    char protocol[10] = {0};
    int src_port = 0, dest_port = 0;
    int action = 0;

    sscanf(rule_str, "%15s %15s %9s %d:%d %d", src_ip, dest_ip, protocol, &src_port, &dest_port, &action);

    strcpy(rules[num_rules].src_ip, src_ip);
    strcpy(rules[num_rules].dest_ip, dest_ip);
    strcpy(rules[num_rules].protocol, protocol);
    rules[num_rules].src_port = src_port;
    rules[num_rules].dest_port = dest_port;
    rules[num_rules].action = action;

    num_rules++;
}

int main() {
    FILE *rules_file;
    char rule_str[MAX_RULE_LEN] = {0};
    struct rule rules[MAX_RULES] = {{0}};
    int num_rules = 0;

    rules_file = fopen("firewall_rules.txt", "r");

    if (rules_file == NULL) {
        printf("Error opening rules file: %s\n", strerror(errno));
        exit(1);
    }

    while (fgets(rule_str, MAX_RULE_LEN, rules_file)!= NULL) {
        add_rule(rules, num_rules, rule_str);
    }

    fclose(rules_file);

    printf("Number of rules: %d\n", num_rules);

    for (int i = 0; i < num_rules; i++) {
        printf("Rule %d: %s -> %s (%s:%d -> %s:%d) %s\n", i+1, rules[i].src_ip, rules[i].dest_ip, rules[i].protocol, rules[i].src_port, rules[i].dest_port, (rules[i].action == 1)? "Allow" : "Deny");
    }

    return 0;
}