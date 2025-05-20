//Falcon-180B DATASET v1.0 Category: Firewall ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 80

typedef struct {
    char action;
    char protocol;
    char source_ip[16];
    char dest_ip[16];
    char source_port[6];
    char dest_port[6];
} rule_t;

void add_rule(rule_t* rules, int count, char* line) {
    if (count >= MAX_RULES) {
        printf("Error: Maximum number of rules exceeded.\n");
        return;
    }

    char* token = strtok(line, " ");
    strcpy(rules[count].action, token);

    token = strtok(NULL, " ");
    strcpy(rules[count].protocol, token);

    token = strtok(NULL, " ");
    strcpy(rules[count].source_ip, token);

    token = strtok(NULL, " ");
    strcpy(rules[count].dest_ip, token);

    token = strtok(NULL, " ");
    strcpy(rules[count].source_port, token);

    token = strtok(NULL, " ");
    strcpy(rules[count].dest_port, token);

    count++;
}

int main() {
    FILE* rules_file = fopen("rules.txt", "r");
    if (rules_file == NULL) {
        printf("Error: Unable to open rules file.\n");
        return 1;
    }

    rule_t rules[MAX_RULES];
    int count = 0;

    char line[MAX_RULE_LENGTH];
    while (fgets(line, MAX_RULE_LENGTH, rules_file)!= NULL) {
        add_rule(rules, count, line);
    }

    fclose(rules_file);

    printf("Firewall rules:\n");
    for (int i = 0; i < count; i++) {
        printf("Rule %d: %s %s %s:%s -> %s:%s\n", i+1, rules[i].action, rules[i].protocol, rules[i].source_ip, rules[i].source_port, rules[i].dest_ip, rules[i].dest_port);
    }

    return 0;
}