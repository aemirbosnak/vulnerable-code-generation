//Falcon-180B DATASET v1.0 Category: Firewall ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 1000
#define MAX_RULE_LENGTH 100

typedef struct {
    char *ip;
    char *mask;
    int action;
} rule_t;

int main() {
    int num_rules = 0;
    rule_t rules[MAX_RULES];

    FILE *file = fopen("firewall.conf", "r");
    if (!file) {
        printf("Could not open firewall.conf\n");
        return 1;
    }

    char line[MAX_RULE_LENGTH];
    while (fgets(line, MAX_RULE_LENGTH, file)) {
        if (num_rules >= MAX_RULES) {
            printf("Maximum number of rules exceeded\n");
            fclose(file);
            return 1;
        }

        char *token = strtok(line, " ");
        if (!token) {
            printf("Invalid rule format\n");
            fclose(file);
            return 1;
        }

        rules[num_rules].ip = strdup(token);

        token = strtok(NULL, " ");
        if (!token) {
            printf("Invalid rule format\n");
            fclose(file);
            return 1;
        }

        rules[num_rules].mask = strdup(token);

        token = strtok(NULL, " ");
        if (!token) {
            printf("Invalid rule format\n");
            fclose(file);
            return 1;
        }

        rules[num_rules].action = atoi(token);

        num_rules++;
    }

    fclose(file);

    printf("Firewall rules:\n");
    for (int i = 0; i < num_rules; i++) {
        printf("%s/%s -> %d\n", rules[i].ip, rules[i].mask, rules[i].action);
    }

    return 0;
}