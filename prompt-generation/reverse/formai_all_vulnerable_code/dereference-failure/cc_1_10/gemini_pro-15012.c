//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <arpa/inet.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100

struct rule {
    char *ip_address;
    int port;
    bool allow;
};

struct firewall {
    struct rule rules[MAX_RULES];
    int num_rules;
};

struct firewall *firewall_create() {
    struct firewall *firewall = malloc(sizeof(struct firewall));
    if (firewall == NULL) {
        return NULL;
    }

    firewall->num_rules = 0;

    return firewall;
}

void firewall_destroy(struct firewall *firewall) {
    for (int i = 0; i < firewall->num_rules; i++) {
        free(firewall->rules[i].ip_address);
    }

    free(firewall);
}

bool firewall_add_rule(struct firewall *firewall, char *ip_address, int port, bool allow) {
    if (firewall->num_rules >= MAX_RULES) {
        return false;
    }

    struct rule rule;
    rule.ip_address = strdup(ip_address);
    if (rule.ip_address == NULL) {
        return false;
    }

    rule.port = port;
    rule.allow = allow;

    firewall->rules[firewall->num_rules++] = rule;

    return true;
}

bool firewall_check_rule(struct firewall *firewall, char *ip_address, int port) {
    for (int i = 0; i < firewall->num_rules; i++) {
        struct rule rule = firewall->rules[i];

        if (strcmp(rule.ip_address, ip_address) == 0 && rule.port == port) {
            return rule.allow;
        }
    }

    return false;
}

int main() {
    struct firewall *firewall = firewall_create();

    firewall_add_rule(firewall, "192.168.1.1", 80, true);
    firewall_add_rule(firewall, "192.168.1.2", 443, false);

    bool allowed = firewall_check_rule(firewall, "192.168.1.1", 80);
    printf("192.168.1.1:80 is %s\n", allowed ? "allowed" : "blocked");

    allowed = firewall_check_rule(firewall, "192.168.1.2", 443);
    printf("192.168.1.2:443 is %s\n", allowed ? "allowed" : "blocked");

    firewall_destroy(firewall);

    return 0;
}