//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants for the file paths
#define LOG_FILE_PATH "system_log.txt"
#define RULES_FILE_PATH "rules.txt"

// Maximum sizes for the log entries and rules
#define MAX_LOG_ENTRY_SIZE 100
#define MAX_RULE_SIZE 50

// Struct for storing a single rule
typedef struct {
    char keyword[MAX_RULE_SIZE];
    int severity;
} Rule;

// Function to parse a single rule from a string
Rule parse_rule(char* rule_str) {
    Rule rule;
    char* token;

    // Split the string at the comma
    token = strtok(rule_str, ",");
    strcpy(rule.keyword, token);

    // Get the severity
    token = strtok(NULL, ",");
    rule.severity = atoi(token);

    return rule;
}

// Function to read rules from a file
void read_rules(Rule rules[], int* num_rules) {
    FILE* fp;
    char rule_str[MAX_RULE_SIZE*2];

    fp = fopen(RULES_FILE_PATH, "r");
    if (fp == NULL) {
        printf("Error: unable to open rules file\n");
        exit(1);
    }

    // Parse each line of the file into a rule
    while(fgets(rule_str, MAX_RULE_SIZE*2, fp) != NULL) {
        rules[*num_rules] = parse_rule(rule_str);
        (*num_rules)++;
    }

    fclose(fp);
}

// Function to log an entry in the system log
void log_entry(char* entry) {
    FILE* fp;

    fp = fopen(LOG_FILE_PATH, "a");
    if (fp == NULL) {
        printf("Error: unable to write to log file\n");
        exit(1);
    }

    fprintf(fp, "%s\n", entry);

    fclose(fp);
}

// Function to check if a log entry contains a given keyword
int contains_keyword(char* entry, char* keyword) {
    return strstr(entry, keyword) != NULL;
}

// Function to check a log entry against all rules and return the maximum severity
int check_rules(Rule rules[], int num_rules, char* entry) {
    int i, severity = 0;

    for (i = 0; i < num_rules; i++) {
        if (contains_keyword(entry, rules[i].keyword)) {
            if (rules[i].severity > severity) {
                severity = rules[i].severity;
            }
        }
    }

    return severity;
}

int main() {
    Rule rules[50];
    int num_rules = 0;

    read_rules(rules, &num_rules);

    char entry[MAX_LOG_ENTRY_SIZE];
    int severity = 0;

    printf("Enter a log entry: ");
    fgets(entry, MAX_LOG_ENTRY_SIZE, stdin);

    severity = check_rules(rules, num_rules, entry);

    if (severity > 0) {
        printf("Intrusion detected with severity %d\n", severity);
        log_entry(entry);
    } else {
        printf("No intrusion detected\n");
    }

    return 0;
}