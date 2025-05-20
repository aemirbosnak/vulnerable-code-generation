//Falcon-180B DATASET v1.0 Category: Firewall ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100

struct rule {
    char *protocol;
    char *src_ip;
    char *src_port;
    char *dst_ip;
    char *dst_port;
    char *action;
};

void add_rule(struct rule *rules, int rule_count, char *protocol, char *src_ip, char *src_port, char *dst_ip, char *dst_port, char *action) {
    if (rule_count >= MAX_RULES) {
        printf("Error: Maximum number of rules reached.\n");
        return;
    }

    rules[rule_count].protocol = strdup(protocol);
    rules[rule_count].src_ip = strdup(src_ip);
    rules[rule_count].src_port = strdup(src_port);
    rules[rule_count].dst_ip = strdup(dst_ip);
    rules[rule_count].dst_port = strdup(dst_port);
    rules[rule_count].action = strdup(action);

    rule_count++;
}

void print_rules(struct rule *rules, int rule_count) {
    printf("Firewall Rules:\n");
    for (int i = 0; i < rule_count; i++) {
        printf("Rule %d: %s %s:%s -> %s:%s %s\n", i + 1, rules[i].protocol, rules[i].src_ip, rules[i].src_port, rules[i].dst_ip, rules[i].dst_port, rules[i].action);
    }
}

int main() {
    struct rule rules[MAX_RULES];
    int rule_count = 0;

    add_rule(rules, rule_count, "TCP", "192.168.1.1", "80", "192.168.1.2", "80", "allow");
    add_rule(rules, rule_count, "TCP", "192.168.1.2", "80", "192.168.1.1", "80", "allow");
    add_rule(rules, rule_count, "TCP", "192.168.1.1", "22", "192.168.1.2", "22", "allow");
    add_rule(rules, rule_count, "TCP", "192.168.1.2", "22", "192.168.1.1", "22", "allow");

    print_rules(rules, rule_count);

    return 0;
}