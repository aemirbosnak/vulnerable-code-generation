//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>

#define MAX_RULES 100
#define BUFFER_SIZE 4096

typedef struct FirewallRule {
    char ip_address[INET_ADDRSTRLEN];
    int action; // 0 = block, 1 = allow
} FirewallRule;

FirewallRule rules[MAX_RULES];
int rule_count = 0;

void print_usage() {
    printf("Usage:\n");
    printf("\t-f <file>       Load firewall rules from a file\n");
    printf("\t-a <ip> <action> Add a rule: action (0=block, 1=allow)\n");
    printf("\t-l              List current rules\n");
    printf("\t-d <ip>         Delete a rule by IP address\n");
    printf("\t-h              Show this help\n");
}

void load_rules(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open rule file");
        return;
    }
    
    while (fscanf(file, "%s %d", rules[rule_count].ip_address, &rules[rule_count].action) != EOF && rule_count < MAX_RULES) {
        rule_count++;
    }
    fclose(file);
}

void add_rule(const char *ip_address, int action) {
    if (rule_count >= MAX_RULES) {
        printf("Maximum rule limit reached\n");
        return;
    }
    strncpy(rules[rule_count].ip_address, ip_address, INET_ADDRSTRLEN);
    rules[rule_count].action = action;
    rule_count++;
    printf("Rule added: %s %s\n", ip_address, action == 0 ? "block" : "allow");
}

void delete_rule(const char *ip_address) {
    for (int i = 0; i < rule_count; i++) {
        if (strcmp(rules[i].ip_address, ip_address) == 0) {
            rules[i] = rules[rule_count - 1]; // Replace with the last rule
            rule_count--;
            printf("Rule deleted: %s\n", ip_address);
            return;
        }
    }
    printf("Rule not found: %s\n", ip_address);
}

void list_rules() {
    printf("Current rules:\n");
    for (int i = 0; i < rule_count; i++) {
        printf("\t%s %s\n", rules[i].ip_address, rules[i].action == 0 ? "block" : "allow");
    }
}

int check_packet(const char *ip_address) {
    for (int i = 0; i < rule_count; i++) {
        if (strcmp(rules[i].ip_address, ip_address) == 0) {
            return rules[i].action;
        }
    }
    return 1; // Default to allow if no rules match
}

void packet_simulation(const char *ip_address) {
    int action = check_packet(ip_address);
    printf("Packet from %s is %s\n", ip_address, action == 0 ? "blocked" : "allowed");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage();
        return EXIT_FAILURE;
    }
    
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-f") == 0 && i + 1 < argc) {
            load_rules(argv[++i]);
        } else if (strcmp(argv[i], "-a") == 0 && i + 2 < argc) {
            int action = atoi(argv[++i]);
            add_rule(argv[++i], action);
        } else if (strcmp(argv[i], "-l") == 0) {
            list_rules();
        } else if (strcmp(argv[i], "-d") == 0 && i + 1 < argc) {
            delete_rule(argv[++i]);
        } else if (strcmp(argv[i], "-h") == 0) {
            print_usage();
        } else {
            printf("Invalid argument: %s\n", argv[i]);
            print_usage();
            return EXIT_FAILURE;
        }
    }

    // Simulate packet checking
    packet_simulation("192.168.1.1");
    packet_simulation("10.0.0.1");

    return EXIT_SUCCESS;
}