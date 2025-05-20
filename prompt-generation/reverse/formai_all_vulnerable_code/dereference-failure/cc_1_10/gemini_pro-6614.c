//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_RULES 100

typedef struct rule {
    char *src_ip;
    char *dst_ip;
    int src_port;
    int dst_port;
    char *protocol;
    char *action;
} rule_t;

rule_t rules[MAX_RULES];
int num_rules = 0;

void load_rules(char *filename) {
    FILE *fp;
    char line[1024];

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        char *src_ip, *dst_ip, *protocol, *action;
        int src_port, dst_port;

        if (sscanf(line, "%s %s %d %d %s %s", src_ip, dst_ip, &src_port, &dst_port, protocol, action) != 6) {
            fprintf(stderr, "Invalid rule: %s", line);
            continue;
        }

        rules[num_rules].src_ip = strdup(src_ip);
        rules[num_rules].dst_ip = strdup(dst_ip);
        rules[num_rules].src_port = src_port;
        rules[num_rules].dst_port = dst_port;
        rules[num_rules].protocol = strdup(protocol);
        rules[num_rules].action = strdup(action);

        num_rules++;
    }

    fclose(fp);
}

int check_rule(rule_t *rule, char *src_ip, int src_port, char *dst_ip, int dst_port, char *protocol) {
    if (strcmp(rule->src_ip, src_ip) != 0) {
        return 0;
    }

    if (strcmp(rule->dst_ip, dst_ip) != 0) {
        return 0;
    }

    if (rule->src_port != src_port) {
        return 0;
    }

    if (rule->dst_port != dst_port) {
        return 0;
    }

    if (strcmp(rule->protocol, protocol) != 0) {
        return 0;
    }

    return 1;
}

int main(int argc, char **argv) {
    char *filename;
    char *src_ip;
    int src_port;
    char *dst_ip;
    int dst_port;
    char *protocol;
    int i;

    if (argc != 8) {
        fprintf(stderr, "Usage: %s <filename> <src_ip> <src_port> <dst_ip> <dst_port> <protocol> <action>\n", argv[0]);
        exit(1);
    }

    filename = argv[1];
    src_ip = argv[2];
    src_port = atoi(argv[3]);
    dst_ip = argv[4];
    dst_port = atoi(argv[5]);
    protocol = argv[6];

    load_rules(filename);

    for (i = 0; i < num_rules; i++) {
        if (check_rule(&rules[i], src_ip, src_port, dst_ip, dst_port, protocol)) {
            printf("Action: %s\n", rules[i].action);
            return 0;
        }
    }

    printf("Action: deny\n");
    return 0;
}