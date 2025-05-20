//MISTRAL-7B DATASET v1.0 Category: Intrusion detection system ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

#define LOG_FILE "/var/log/syslog"
#define ALERT_FILE "/var/log/intrusion.log"
#define BUF_SIZE 4096
#define RULES_FILE "rules.txt"

typedef struct rule {
    char *event;
    char *source;
    char *destination;
} rule_t;

rule_t *rules = NULL;
size_t num_rules = 0;

void read_rules() {
    FILE *fp = fopen(RULES_FILE, "r");
    char line[1024];
    rule_t rule;

    if (fp == NULL) {
        perror("Error opening rules file");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%s %s %s", rule.event, rule.source, rule.destination);
        rules = realloc(rules, sizeof(rule_t) * (num_rules + 1));
        strcpy(rules[num_rules].event, rule.event);
        strcpy(rules[num_rules].source, rule.source);
        strcpy(rules[num_rules].destination, rule.destination);
        num_rules++;
    }

    fclose(fp);
}

int match_rule(const char *line) {
    for (size_t i = 0; i < num_rules; i++) {
        if (strstr(line, rules[i].event) &&
            (strstr(line, rules[i].source) || strstr(line, rules[i].destination))) {
            return i;
        }
    }

    return -1;
}

void alert(const char *line) {
    FILE *fp = fopen(ALERT_FILE, "a");
    if (fp == NULL) {
        perror("Error opening alert file");
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "%s\n", line);
    fprintf(stderr, "Intrusion detected: %s\n", line);

    fclose(fp);
}

int main() {
    int fd = open(LOG_FILE, O_RDONLY);
    char buf[BUF_SIZE];
    size_t bytes_read;

    if (fd < 0) {
        perror("Error opening log file");
        exit(EXIT_FAILURE);
    }

    read_rules();

    while ((bytes_read = read(fd, buf, BUF_SIZE)) > 0) {
        char *line = strtok(buf, "\n");

        while (line != NULL) {
            int rule_idx = match_rule(line);
            if (rule_idx >= 0) {
                alert(line);
                break;
            }
            line = strtok(NULL, "\n");
        }
    }

    close(fd);

    free(rules);

    return EXIT_SUCCESS;
}