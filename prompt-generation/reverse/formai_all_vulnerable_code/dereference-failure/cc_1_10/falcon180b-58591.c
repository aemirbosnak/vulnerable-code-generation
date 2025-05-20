//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 1000
#define MAX_EVENTS 10000
#define MAX_EVENT_LENGTH 1000

struct rule {
    char *pattern;
    int action;
};

struct event {
    char *data;
    int length;
};

struct rule rules[MAX_RULES];
int num_rules;

struct event events[MAX_EVENTS];
int num_events;

void add_rule(char *pattern, int action) {
    if (num_rules >= MAX_RULES) {
        printf("Error: Maximum number of rules reached.\n");
        return;
    }

    rules[num_rules].pattern = strdup(pattern);
    rules[num_rules].action = action;

    num_rules++;
}

void add_event(char *data, int length) {
    if (num_events >= MAX_EVENTS) {
        printf("Error: Maximum number of events reached.\n");
        return;
    }

    events[num_events].data = malloc(length + 1);
    memcpy(events[num_events].data, data, length);
    events[num_events].length = length;

    num_events++;
}

int match_rule(char *data, int length, int rule_index) {
    char *pattern = rules[rule_index].pattern;
    int pattern_length = strlen(pattern);

    if (length < pattern_length) {
        return 0;
    }

    int i;
    for (i = 0; i < pattern_length; i++) {
        if (pattern[i]!= '*' && data[i]!= pattern[i]) {
            return 0;
        }
    }

    return rules[rule_index].action;
}

void process_event(int event_index) {
    int i;
    for (i = 0; i < num_rules; i++) {
        int action = match_rule(events[event_index].data, events[event_index].length, i);
        if (action!= 0) {
            printf("Rule %d matched event %d: %s\n", i, event_index, rules[i].pattern);
            break;
        }
    }
}

int main() {
    add_rule("*attack*", 1);
    add_rule("*error*", 2);
    add_rule("*warning*", 3);

    add_event("Login failed for user admin", 33);
    add_event("Server error: Out of memory", 37);
    add_event("Warning: High CPU usage", 30);

    int i;
    for (i = 0; i < num_events; i++) {
        process_event(i);
    }

    return 0;
}