//FormAI DATASET v1.0 Category: Firewall ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define LINE_LENGTH 100
#define MAX_RULES 100

struct Rule {
    char protocol[LINE_LENGTH];
    char source_ip[LINE_LENGTH];
    char dest_ip[LINE_LENGTH];
    int source_port;
    int dest_port;
    char action[LINE_LENGTH];
};

int parse_ip(char* ip_string, unsigned char* ip) {
    return  inet_pton(AF_INET, ip_string, ip);
}

bool match_ip(unsigned char* rule_ip, unsigned char* packet_ip) {
    for (int i = 0; i < 4; i++) {
        if (rule_ip[i] != packet_ip[i] && rule_ip[i] != 255) {
            return false;
        }
    }
    return true;
}

bool match_rule(struct Rule rule, unsigned char* packet_ip, int packet_port) {
    unsigned char rule_ip[4];
    parse_ip(rule.source_ip, rule_ip);
    if (!match_ip(rule_ip, packet_ip)) {
        return false;
    }

    parse_ip(rule.dest_ip, rule_ip);
    if (!match_ip(rule_ip, packet_ip)) {
        return false;
    }

    if (strcmp(rule.protocol, "tcp") == 0) {
        if (rule.source_port != packet_port && rule.source_port != -1) {
            return false;
        }

        if (rule.dest_port != -1 && rule.dest_port != packet_port) {
            return false;
        }
    }
    return true;
}

void recursive_firewall(FILE* rule_file, unsigned char* packet_ip, int packet_port) {
    int line_len = LINE_LENGTH;
    char line[line_len];

    struct Rule rules[MAX_RULES];
    int num_rules = 0;

    while (fgets(line, line_len, rule_file)) {
        if (num_rules >= MAX_RULES) {
            printf("Too many rules. Maximum allowed is %d\n", MAX_RULES);
            exit(1);
        }

        char* token = strtok(line, " ");
        strcpy(rules[num_rules].protocol, token);

        token = strtok(NULL, " ");
        strcpy(rules[num_rules].source_ip, token);

        token = strtok(NULL, " ");
        strcpy(rules[num_rules].dest_ip, token);

        token = strtok(NULL, " ");
        rules[num_rules].source_port = atoi(token);

        token = strtok(NULL, " ");
        rules[num_rules].dest_port = atoi(token);

        token = strtok(NULL, " ");
        strcpy(rules[num_rules].action, token);

        num_rules++;
    }

    for (int i = 0; i < num_rules; i++) {
        if (match_rule(rules[i], packet_ip, packet_port)) {
            if (strcmp(rules[i].action, "allow") == 0) {
                printf("Packet allowed by rule number %d\n", i+1);
                return;
            } else {
                printf("Packet blocked by rule number %d\n", i+1);
                return;
            }
        }
    }
}

int main(int argc, char** argv) {
    FILE* rule_file = fopen(argv[1], "r");
    char* packet_str = argv[2];
    int packet_port = atoi(argv[3]);
    unsigned char packet_ip[4];
    parse_ip(packet_str, packet_ip);

    recursive_firewall(rule_file, packet_ip, packet_port);

    fclose(rule_file);
    return 0;
}