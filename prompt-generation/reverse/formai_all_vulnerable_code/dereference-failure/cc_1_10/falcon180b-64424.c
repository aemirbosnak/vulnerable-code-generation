//Falcon-180B DATASET v1.0 Category: Firewall ; Style: excited
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 80

// Struct to hold each rule
typedef struct {
    char *pattern;
    char *replacement;
} Rule;

// Function to read in the rules from the rules.txt file
void read_rules(Rule rules[MAX_RULES]) {
    FILE *fp;
    char line[MAX_RULE_LENGTH];
    int count = 0;

    fp = fopen("rules.txt", "r");

    if (fp == NULL) {
        printf("Error: rules.txt not found!\n");
        exit(1);
    }

    while (fgets(line, MAX_RULE_LENGTH, fp)!= NULL) {
        if (count >= MAX_RULES) {
            printf("Error: Too many rules!\n");
            exit(1);
        }
        rules[count].pattern = malloc(strlen(line) + 1);
        strcpy(rules[count].pattern, line);
        count++;
    }

    fclose(fp);
}

// Function to apply the rules to the input string
void apply_rules(char *input, Rule rules[MAX_RULES]) {
    int i;
    char *pattern;
    char *replacement;

    for (i = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) {
            pattern = rules[i % MAX_RULES].pattern;
            replacement = rules[i % MAX_RULES].replacement;

            while (*pattern!= '\0') {
                if (*pattern == toupper(input[i])) {
                    input[i] = toupper(*replacement);
                    replacement++;
                } else if (*pattern == tolower(input[i])) {
                    input[i] = tolower(*replacement);
                    replacement++;
                } else {
                    pattern++;
                }
            }
        }
    }
}

// Main function
int main() {
    char input[1000];
    Rule rules[MAX_RULES];

    read_rules(rules);

    printf("Enter a string to be filtered:\n");
    fgets(input, 1000, stdin);

    apply_rules(input, rules);

    printf("Filtered string: %s\n", input);

    return 0;
}