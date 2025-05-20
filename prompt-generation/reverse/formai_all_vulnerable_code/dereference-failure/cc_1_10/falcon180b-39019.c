//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100

// Rule structure
typedef struct {
    char *pattern;
    int action;
} Rule;

// Function for matching a pattern against a string
bool match_pattern(char *pattern, char *string) {
    int i = 0;
    while (pattern[i]!= '\0' && string[i]!= '\0') {
        if (tolower(pattern[i])!= tolower(string[i])) {
            return false;
        }
        i++;
    }
    return true;
}

// Function for loading rules from a file
void load_rules(Rule *rules, int *num_rules, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open rule file '%s'\n", filename);
        exit(1);
    }

    char line[MAX_RULE_LENGTH];
    int rule_num = 0;

    while (fgets(line, MAX_RULE_LENGTH, file)!= NULL) {
        char *pattern = strtok(line, " ");
        int action = atoi(strtok(NULL, " "));

        if (rule_num >= MAX_RULES) {
            printf("Error: too many rules in file '%s'\n", filename);
            exit(1);
        }

        rules[rule_num].pattern = strdup(pattern);
        rules[rule_num].action = action;
        rule_num++;
    }

    fclose(file);
    *num_rules = rule_num;
}

// Function for checking a packet against the rules
int check_packet(char *packet, Rule *rules, int num_rules) {
    int i;

    for (i = 0; i < num_rules; i++) {
        if (match_pattern(rules[i].pattern, packet)) {
            return rules[i].action;
        }
    }

    return 0;
}

// Main function
int main() {
    // Load rules from file
    Rule rules[MAX_RULES];
    int num_rules = 0;
    load_rules(rules, &num_rules, "rules.txt");

    // Check packets
    char packet[100];
    while (fgets(packet, sizeof(packet), stdin)!= NULL) {
        int action = check_packet(packet, rules, num_rules);
        if (action!= 0) {
            printf("Action: %d\n", action);
        }
    }

    return 0;
}