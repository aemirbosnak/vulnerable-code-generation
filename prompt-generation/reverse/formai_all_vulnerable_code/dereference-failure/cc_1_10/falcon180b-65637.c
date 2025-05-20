//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100

typedef struct {
    char *pattern;
    char *action;
} rule_t;

rule_t rules[MAX_RULES];
int num_rules;

void load_rules(char *filename) {
    FILE *fp;
    char line[MAX_RULE_LENGTH];
    char *token;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open rules file.\n");
        exit(1);
    }

    num_rules = 0;
    while (fgets(line, MAX_RULE_LENGTH, fp)!= NULL) {
        token = strtok(line, " ");
        if (token == NULL) {
            continue;
        }
        rules[num_rules].pattern = strdup(token);

        token = strtok(NULL, " ");
        if (token == NULL) {
            printf("Error: invalid rule format.\n");
            exit(1);
        }
        rules[num_rules].action = strdup(token);

        num_rules++;
    }

    fclose(fp);
}

void match_rule(char *input) {
    int i;
    for (i = 0; i < num_rules; i++) {
        if (strcmp(input, rules[i].pattern) == 0) {
            printf("Matched rule: %s\n", rules[i].action);
        }
    }
}

int main() {
    load_rules("rules.txt");

    char input[MAX_RULE_LENGTH];
    while (1) {
        printf("Enter input: ");
        fgets(input, MAX_RULE_LENGTH, stdin);
        match_rule(input);
    }

    return 0;
}