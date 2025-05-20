//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 80
#define MAX_LOG_ENTRIES 1000

typedef struct {
    char *pattern;
    int action;
} Rule;

typedef struct {
    Rule *rules;
    int num_rules;
    char *log_file;
    FILE *log;
    int log_entries;
} IDS;

void init_rule(Rule *rule) {
    rule->pattern = NULL;
    rule->action = 0;
}

void init_ids(IDS *ids) {
    ids->rules = NULL;
    ids->num_rules = 0;
    ids->log_file = NULL;
    ids->log = NULL;
    ids->log_entries = 0;
}

void add_rule(IDS *ids, char *pattern, int action) {
    Rule *rule = malloc(sizeof(Rule));
    init_rule(rule);
    rule->pattern = strdup(pattern);
    rule->action = action;
    ids->rules = realloc(ids->rules, sizeof(Rule) * (ids->num_rules + 1));
    ids->rules[ids->num_rules++] = *rule;
}

int match_rule(IDS *ids, char *data) {
    int i;
    for (i = 0; i < ids->num_rules; i++) {
        Rule *rule = &ids->rules[i];
        if (strstr(data, rule->pattern)!= NULL) {
            return rule->action;
        }
    }
    return 0;
}

void log_entry(IDS *ids, char *data) {
    if (ids->log == NULL) {
        ids->log_file = "intrusion.log";
        ids->log = fopen(ids->log_file, "a");
    }
    fprintf(ids->log, "%s\n", data);
    ids->log_entries++;
}

int main() {
    IDS ids;
    init_ids(&ids);

    add_rule(&ids, "password", 1);
    add_rule(&ids, "admin", 1);

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), stdin)!= NULL) {
        char *data = strtok(buffer, "\r\n");
        int action = match_rule(&ids, data);
        if (action!= 0) {
            log_entry(&ids, data);
            printf("Intrusion detected: %s\n", data);
        }
    }

    return 0;
}