//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 10
#define MAX_RULE_LENGTH 100

// Rule structure
typedef struct {
    char *pattern;
    int action;
} Rule;

// Function to load rules from a file
int load_rules(Rule rules[], int max_rules, char *filename) {
    FILE *fp;
    int count = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening rules file: %s\n", filename);
        return -1;
    }

    while (count < max_rules && fgets(rules[count].pattern, MAX_RULE_LENGTH, fp)!= NULL) {
        rules[count].action = 0;
        count++;
    }

    fclose(fp);
    return count;
}

// Function to match a string against a rule pattern
int match_rule(char *string, Rule rule) {
    if (strstr(string, rule.pattern)!= NULL) {
        return rule.action;
    }
    return 0;
}

// Function to process a packet
void process_packet(char *packet, Rule rules[], int num_rules) {
    int i, matched_rule = 0;

    for (i = 0; i < num_rules; i++) {
        if (match_rule(packet, rules[i]) == 1) {
            matched_rule = 1;
            break;
        }
    }

    if (matched_rule) {
        printf("Intrusion detected in packet: %s\n", packet);
    }
}

// Main function
int main(int argc, char *argv[]) {
    Rule rules[MAX_RULES];
    int num_rules;

    // Load rules from file
    num_rules = load_rules(rules, MAX_RULES, "rules.txt");

    // Process packets
    char packet[100];
    while (fgets(packet, sizeof(packet), stdin)!= NULL) {
        process_packet(packet, rules, num_rules);
    }

    return 0;
}