//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100

typedef struct rule {
    char *pattern;
    int action;
} rule_t;

int main() {
    int num_rules = 0;
    rule_t rules[MAX_RULES];

    FILE *fp = fopen("rules.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open rules file.\n");
        return 1;
    }

    char line[MAX_RULE_LENGTH];
    while (fgets(line, MAX_RULE_LENGTH, fp)!= NULL) {
        if (num_rules >= MAX_RULES) {
            printf("Error: too many rules.\n");
            fclose(fp);
            return 1;
        }

        char *pattern = strtok(line, " ");
        int action = atoi(strtok(NULL, " "));

        rules[num_rules].pattern = strdup(pattern);
        rules[num_rules].action = action;

        num_rules++;
    }

    fclose(fp);

    char input[MAX_RULE_LENGTH];
    while (fgets(input, MAX_RULE_LENGTH, stdin)!= NULL) {
        for (int i = 0; i < num_rules; i++) {
            if (strstr(input, rules[i].pattern)!= NULL) {
                if (rules[i].action == 1) {
                    printf("Intrusion detected: %s\n", rules[i].pattern);
                } else if (rules[i].action == 2) {
                    printf("Possible intrusion: %s\n", rules[i].pattern);
                }
            }
        }
    }

    return 0;
}