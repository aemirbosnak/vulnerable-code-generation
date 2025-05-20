//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100
#define MAX_ALERT_MESSAGE_LENGTH 100

typedef struct {
    char *pattern;
    char *alert_message;
} Rule;

typedef struct {
    Rule *rules;
    int rule_count;
} RuleSet;

void init_ruleset(RuleSet *ruleset) {
    ruleset->rules = calloc(MAX_RULES, sizeof(Rule));
    ruleset->rule_count = 0;
}

void add_rule(RuleSet *ruleset, char *pattern, char *alert_message) {
    if (ruleset->rule_count >= MAX_RULES) {
        printf("Error: Maximum number of rules reached.\n");
        return;
    }

    Rule *rule = &ruleset->rules[ruleset->rule_count];
    rule->pattern = strdup(pattern);
    rule->alert_message = strdup(alert_message);

    ruleset->rule_count++;
}

void free_ruleset(RuleSet *ruleset) {
    for (int i = 0; i < ruleset->rule_count; i++) {
        free(ruleset->rules[i].pattern);
        free(ruleset->rules[i].alert_message);
    }
    free(ruleset->rules);
}

void analyze_packet(char *packet, RuleSet *ruleset) {
    char *pattern;
    char *alert_message;
    for (int i = 0; i < ruleset->rule_count; i++) {
        pattern = ruleset->rules[i].pattern;
        alert_message = ruleset->rules[i].alert_message;

        if (strstr(packet, pattern)!= NULL) {
            printf("Alert: %s\n", alert_message);
        }
    }
}

int main() {
    RuleSet ruleset;
    init_ruleset(&ruleset);

    add_rule(&ruleset, "password", "Possible password detected in packet.");
    add_rule(&ruleset, "admin", "Possible admin access detected in packet.");
    add_rule(&ruleset, "root", "Possible root access detected in packet.");

    char *packet = "GET /admin/password.php HTTP/1.1";

    analyze_packet(packet, &ruleset);

    free_ruleset(&ruleset);

    return 0;
}