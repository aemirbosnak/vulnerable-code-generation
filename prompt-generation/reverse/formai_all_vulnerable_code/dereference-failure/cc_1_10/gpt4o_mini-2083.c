//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_RULES 100
#define MAX_IP_LEN 16

typedef enum {ALLOW, BLOCK} Action;

typedef struct {
    char ip[MAX_IP_LEN];
    Action action;
} Rule;

Rule rules[MAX_RULES];
int rule_count = 0;

void add_rule(const char *ip, Action action) {
    if (rule_count < MAX_RULES) {
        strncpy(rules[rule_count].ip, ip, MAX_IP_LEN);
        rules[rule_count].action = action;
        rule_count++;
    } else {
        printf("Rule limit reached. Cannot add more rules.\n");
    }
}

int check_rule(const char *ip) {
    for (int i = 0; i < rule_count; i++) {
        if (strcmp(rules[i].ip, ip) == 0) {
            return rules[i].action;
        }
    }
    return ALLOW; // Default action is to allow
}

void print_rules() {
    printf("Current Firewall Rules:\n");
    for (int i = 0; i < rule_count; i++) {
        printf("%s - %s\n", rules[i].ip, (rules[i].action == ALLOW) ? "ALLOW" : "BLOCK");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <ip_address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *input_ip = argv[1];

    // Sample rules (you could modify to take user input)
    add_rule("192.168.1.100", BLOCK);
    add_rule("10.0.0.1", ALLOW);
    add_rule("172.16.0.5", BLOCK);
    
    print_rules();

    // Check input IP against rules
    if (check_rule(input_ip) == ALLOW) {
        printf("Access granted for IP: %s\n", input_ip);
    } else {
        printf("Access denied for IP: %s\n", input_ip);
    }

    return 0;
}