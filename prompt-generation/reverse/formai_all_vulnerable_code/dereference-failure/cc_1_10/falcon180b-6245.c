//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: Alan Turing
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100

// Structure for a rule
typedef struct {
    char *pattern;
    void (*callback)(char *data);
} rule_t;

// Callback function for matching rules
void match_callback(char *data) {
    printf("Match found: %s\n", data);
}

// Function to add a rule
void add_rule(rule_t *rules, int num_rules, char *pattern, void (*callback)(char *)) {
    if (num_rules >= MAX_RULES) {
        printf("Error: Maximum number of rules exceeded.\n");
        exit(1);
    }

    rules[num_rules].pattern = strdup(pattern);
    rules[num_rules].callback = callback;

    num_rules++;
}

// Function to remove a rule
void remove_rule(rule_t *rules, int num_rules, int index) {
    if (index >= num_rules || index < 0) {
        printf("Error: Invalid rule index.\n");
        exit(1);
    }

    free(rules[index].pattern);

    for (int i = index; i < num_rules - 1; i++) {
        rules[i] = rules[i + 1];
    }

    num_rules--;
}

// Function to evaluate data against rules
void evaluate_data(rule_t *rules, int num_rules, char *data) {
    for (int i = 0; i < num_rules; i++) {
        if (strstr(data, rules[i].pattern)!= NULL) {
            rules[i].callback(data);
        }
    }
}

// Main function
int main() {
    // Initialize rules
    rule_t rules[MAX_RULES];
    int num_rules = 0;

    // Add rules
    add_rule(rules, num_rules, "Hello", match_callback);
    add_rule(rules, num_rules, "World", match_callback);

    // Evaluate data
    char *data = "Hello, World!";
    evaluate_data(rules, num_rules, data);

    // Remove rule
    remove_rule(rules, num_rules, 0);

    // Evaluate data again
    evaluate_data(rules, num_rules, data);

    return 0;
}