//Falcon-180B DATASET v1.0 Category: Firewall ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100
#define MAX_IP_LENGTH 16
#define MAX_PORT_LENGTH 6

typedef struct {
    char ip[MAX_IP_LENGTH];
    char port[MAX_PORT_LENGTH];
    int action;
} rule_t;

rule_t rules[MAX_RULES];
int num_rules;

void add_rule(char* ip_port, int action) {
    char* token = strtok(ip_port, ":");
    strcpy(rules[num_rules].ip, token);
    rules[num_rules].port[0] = '\0';
    if ((token = strtok(NULL, ":"))!= NULL) {
        strncpy(rules[num_rules].port, token, MAX_PORT_LENGTH - 1);
    }
    rules[num_rules].action = action;
    num_rules++;
}

int match_rule(char* ip, char* port) {
    int i;
    for (i = 0; i < num_rules; i++) {
        if (strcmp(rules[i].ip, ip) == 0 && strcmp(rules[i].port, port) == 0) {
            return rules[i].action;
        }
    }
    return 0;
}

int main() {
    add_rule("192.168.0.1:80", 1);
    add_rule("192.168.0.2:443", 1);
    add_rule("10.0.0.1:22", 0);

    char* ip = "192.168.0.1";
    char* port = "80";
    int action = match_rule(ip, port);

    if (action == 1) {
        printf("Allow\n");
    } else {
        printf("Deny\n");
    }

    return 0;
}