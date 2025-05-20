//Falcon-180B DATASET v1.0 Category: Firewall ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_RULES 100
#define MAX_LENGTH 100

typedef struct {
    char *pattern;
    char *replacement;
    int length;
} Rule;

void add_rule(Rule *rules, int num_rules, char *pattern, char *replacement) {
    if (num_rules >= MAX_RULES) {
        printf("Error: Maximum number of rules reached.\n");
        exit(1);
    }

    Rule rule;
    rule.pattern = strdup(pattern);
    rule.replacement = strdup(replacement);
    rule.length = strlen(rule.pattern);

    rules[num_rules++] = rule;
}

void apply_rules(char *input, Rule *rules, int num_rules) {
    char *output = malloc(strlen(input) + 1);
    char *pos = output;

    for (int i = 0; i < num_rules; i++) {
        Rule rule = rules[i];

        char *match = strstr(input, rule.pattern);

        while (match!= NULL) {
            memcpy(pos, input, match - input);
            pos += match - input;

            memcpy(pos, rule.replacement, rule.length);
            pos += rule.length;

            match += rule.length;
        }

        memcpy(pos, match, strlen(match));
        pos += strlen(match);
    }

    memcpy(pos, input + strlen(input), 1);
    *pos = '\0';

    printf("%s\n", output);
    free(output);
}

int main() {
    Rule rules[MAX_RULES];
    int num_rules = 0;

    // Example rules
    add_rule(rules, num_rules, "firewall", "censorship device");
    add_rule(rules, num_rules, "Microsoft", "Micro$oft");
    add_rule(rules, num_rules, "Windows", "Winblows");

    char input[MAX_LENGTH];
    printf("Enter text to filter:\n");
    fgets(input, MAX_LENGTH, stdin);

    apply_rules(input, rules, num_rules);

    return 0;
}