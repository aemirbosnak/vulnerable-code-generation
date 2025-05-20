//Falcon-180B DATASET v1.0 Category: Firewall ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 1000
#define MAX_RULE_SIZE 100
#define MAX_PACKET_SIZE 1000

typedef struct {
    char *rule;
    int action;
} rule_t;

typedef struct {
    int num_rules;
    rule_t rules[MAX_RULES];
} firewall_t;

firewall_t *create_firewall() {
    firewall_t *fw = malloc(sizeof(firewall_t));
    if (fw == NULL) {
        printf("Error: could not allocate memory for firewall.\n");
        exit(1);
    }
    fw->num_rules = 0;
    return fw;
}

void destroy_firewall(firewall_t *fw) {
    free(fw);
}

int add_rule(firewall_t *fw, char *rule, int action) {
    if (fw->num_rules >= MAX_RULES) {
        printf("Error: maximum number of rules reached.\n");
        return -1;
    }
    fw->rules[fw->num_rules].rule = strdup(rule);
    fw->rules[fw->num_rules].action = action;
    fw->num_rules++;
    return 0;
}

int remove_rule(firewall_t *fw, int index) {
    if (index < 0 || index >= fw->num_rules) {
        printf("Error: invalid rule index.\n");
        return -1;
    }
    free(fw->rules[index].rule);
    fw->num_rules--;
    for (int i = index; i < fw->num_rules; i++) {
        fw->rules[i] = fw->rules[i+1];
    }
    return 0;
}

int get_rule_action(firewall_t *fw, char *packet, int packet_size) {
    for (int i = 0; i < fw->num_rules; i++) {
        int rule_size = strlen(fw->rules[i].rule);
        if (rule_size > packet_size) {
            continue;
        }
        if (strncmp(packet, fw->rules[i].rule, rule_size) == 0) {
            return fw->rules[i].action;
        }
    }
    return -1;
}

int main() {
    firewall_t *fw = create_firewall();
    add_rule(fw, "GET", 1);
    add_rule(fw, "POST", 2);
    int action = get_rule_action(fw, "GET", 3);
    printf("Action: %d\n", action);
    destroy_firewall(fw);
    return 0;
}