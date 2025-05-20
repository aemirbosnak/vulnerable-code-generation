//Falcon-180B DATASET v1.0 Category: Firewall ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RULES 100
#define MAX_CHAIN_NAME_LEN 50
#define MAX_RULE_NAME_LEN 50
#define MAX_RULE_VALUE_LEN 100

typedef struct {
    char chain_name[MAX_CHAIN_NAME_LEN];
    struct chain *next;
} chain;

typedef struct {
    char rule_name[MAX_RULE_NAME_LEN];
    char rule_value[MAX_RULE_VALUE_LEN];
    struct rule *next;
} rule;

typedef struct {
    chain *chains;
    rule *rules;
} firewall;

void init_firewall(firewall *fw) {
    fw->chains = NULL;
    fw->rules = NULL;
}

void add_chain(firewall *fw, char *name) {
    chain *new_chain = malloc(sizeof(chain));
    strcpy(new_chain->chain_name, name);
    new_chain->next = fw->chains;
    fw->chains = new_chain;
}

void add_rule(firewall *fw, char *name, char *value) {
    rule *new_rule = malloc(sizeof(rule));
    strcpy(new_rule->rule_name, name);
    strcpy(new_rule->rule_value, value);
    new_rule->next = fw->rules;
    fw->rules = new_rule;
}

void print_chains(firewall *fw) {
    chain *curr_chain = fw->chains;
    while (curr_chain!= NULL) {
        printf("Chain name: %s\n", curr_chain->chain_name);
        curr_chain = curr_chain->next;
    }
}

void print_rules(firewall *fw) {
    rule *curr_rule = fw->rules;
    while (curr_rule!= NULL) {
        printf("Rule name: %s, Rule value: %s\n", curr_rule->rule_name, curr_rule->rule_value);
        curr_rule = curr_rule->next;
    }
}

int main() {
    firewall fw;
    init_firewall(&fw);

    add_chain(&fw, "INPUT");
    add_chain(&fw, "OUTPUT");

    add_rule(&fw, "ALLOW_HTTP", "-p tcp --dport 80 -j ACCEPT");
    add_rule(&fw, "ALLOW_HTTPS", "-p tcp --dport 443 -j ACCEPT");
    add_rule(&fw, "DENY_ALL", "-j DROP");

    print_chains(&fw);
    print_rules(&fw);

    return 0;
}