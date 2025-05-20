//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>

#define MAX_RULES 100
#define MAX_RULE_LEN 100

struct rule {
    char *ip_address;
    int port;
    char *protocol;
    char *action;
};

struct firewall {
    struct rule rules[MAX_RULES];
    int num_rules;
};

struct firewall *new_firewall() {
    struct firewall *fw = malloc(sizeof(struct firewall));
    fw->num_rules = 0;
    return fw;
}

void add_rule(struct firewall *fw, char *ip_address, int port, char *protocol, char *action) {
    struct rule *rule = &fw->rules[fw->num_rules];
    rule->ip_address = malloc(strlen(ip_address) + 1);
    strcpy(rule->ip_address, ip_address);
    rule->port = port;
    rule->protocol = malloc(strlen(protocol) + 1);
    strcpy(rule->protocol, protocol);
    rule->action = malloc(strlen(action) + 1);
    strcpy(rule->action, action);
    fw->num_rules++;
}

int match_rule(struct rule *rule, char *ip_address, int port, char *protocol) {
    return strcmp(rule->ip_address, ip_address) == 0 && rule->port == port && strcmp(rule->protocol, protocol) == 0;
}

int process_packet(struct firewall *fw, char *ip_address, int port, char *protocol) {
    for (int i = 0; i < fw->num_rules; i++) {
        struct rule *rule = &fw->rules[i];
        if (match_rule(rule, ip_address, port, protocol)) {
            if (strcmp(rule->action, "ALLOW") == 0) {
                return 1;
            } else {
                return 0;
            }
        }
    }
    return 1;
}

void free_firewall(struct firewall *fw) {
    for (int i = 0; i < fw->num_rules; i++) {
        struct rule *rule = &fw->rules[i];
        free(rule->ip_address);
        free(rule->protocol);
        free(rule->action);
    }
    free(fw);
}

int main() {
    struct firewall *fw = new_firewall();
    add_rule(fw, "192.168.1.1", 80, "TCP", "ALLOW");
    add_rule(fw, "192.168.1.2", 443, "TCP", "ALLOW");
    add_rule(fw, "192.168.1.3", 22, "TCP", "DENY");
    char *ip_address = "192.168.1.1";
    int port = 80;
    char *protocol = "TCP";
    if (process_packet(fw, ip_address, port, protocol)) {
        printf("Packet allowed.\n");
    } else {
        printf("Packet blocked.\n");
    }
    free_firewall(fw);
    return 0;
}