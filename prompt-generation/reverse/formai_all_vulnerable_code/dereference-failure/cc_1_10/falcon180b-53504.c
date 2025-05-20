//Falcon-180B DATASET v1.0 Category: Firewall ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100

struct rule {
    char *src_ip;
    char *dst_ip;
    int src_port;
    int dst_port;
    int protocol;
    int action;
};

void add_rule(struct rule *rules, int num_rules, char *line) {
    char *token;
    int i = 0;
    struct rule rule;

    token = strtok(line, " ");
    if (token == NULL) {
        printf("Invalid rule: %s\n", line);
        return;
    }

    rule.src_ip = strdup(token);
    i++;

    token = strtok(NULL, " ");
    if (token == NULL) {
        printf("Invalid rule: %s\n", line);
        free(rule.src_ip);
        return;
    }

    rule.dst_ip = strdup(token);
    i++;

    rule.src_port = atoi(strtok(NULL, " "));
    i++;

    rule.dst_port = atoi(strtok(NULL, " "));
    i++;

    rule.protocol = atoi(strtok(NULL, " "));
    i++;

    rule.action = atoi(strtok(NULL, " "));

    if (num_rules >= MAX_RULES) {
        printf("Maximum number of rules reached\n");
        free(rule.src_ip);
        free(rule.dst_ip);
        return;
    }

    rules[num_rules] = rule;
    num_rules++;
}

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_RULE_LENGTH];
    int num_rules = 0;
    struct rule rules[MAX_RULES];

    if (argc!= 2) {
        printf("Usage: %s <firewall_rules_file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", strerror(errno));
        return 1;
    }

    while (fgets(line, MAX_RULE_LENGTH, file)!= NULL) {
        add_rule(rules, num_rules, line);
    }

    fclose(file);

    printf("Firewall rules:\n");
    for (int i = 0; i < num_rules; i++) {
        printf("%d. %s -> %s:%d (%s:%d)\n", i+1, rules[i].src_ip, rules[i].dst_ip, rules[i].dst_port, rules[i].src_ip, rules[i].src_port);
    }

    return 0;
}