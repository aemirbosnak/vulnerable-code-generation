//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_NUM_RULES 100
#define MAX_RULE_LENGTH 80
#define MAX_NUM_KEYWORDS 100
#define MAX_KEYWORD_LENGTH 20

struct rule {
    char *keyword;
    int action;
};

struct keyword {
    char *name;
    int count;
};

struct log_entry {
    char *line;
    int is_alert;
};

int num_rules = 0;
int num_keywords = 0;
struct rule *rules = NULL;
struct keyword *keywords = NULL;

int add_rule(char *keyword, int action) {
    struct rule *rule = (struct rule *) malloc(sizeof(struct rule));
    rule->keyword = strdup(keyword);
    rule->action = action;
    rules = (struct rule *) realloc(rules, sizeof(struct rule) * ++num_rules);
    rules[num_rules - 1] = *rule;
    return 0;
}

int add_keyword(char *name) {
    struct keyword *keyword = (struct keyword *) malloc(sizeof(struct keyword));
    keyword->name = strdup(name);
    keyword->count = 0;
    keywords = (struct keyword *) realloc(keywords, sizeof(struct keyword) * ++num_keywords);
    keywords[num_keywords - 1] = *keyword;
    return 0;
}

int process_line(char *line, int is_alert) {
    int i;
    for (i = 0; i < num_keywords; i++) {
        if (strstr(line, keywords[i].name)!= NULL) {
            keywords[i].count++;
        }
    }
    return 0;
}

int main() {
    char line[MAX_LINE_SIZE];
    int is_alert = 0;
    struct log_entry entry;

    add_rule("attack", 1);
    add_rule("vulnerability", 2);
    add_keyword("SQL injection");
    add_keyword("XSS");

    while (fgets(line, MAX_LINE_SIZE, stdin)!= NULL) {
        process_line(line, is_alert);
        if (is_alert) {
            printf("ALERT: %s\n", line);
        }
    }

    return 0;
}