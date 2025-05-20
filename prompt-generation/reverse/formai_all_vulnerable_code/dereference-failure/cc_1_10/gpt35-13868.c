//FormAI DATASET v1.0 Category: Firewall ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RULES 50
#define MAX_IP_LEN 20
#define MAX_PORTS 10
#define MAX_PORT_LEN 10

/* Structure to hold Firewall Rule information */
typedef struct {
    char source_ip[MAX_IP_LEN];
    char dest_ip[MAX_IP_LEN];
    char ports[MAX_PORTS][MAX_PORT_LEN];
    int num_ports;
    bool allow;
} FirewallRule;

/* Global array to hold the firewall rules */
FirewallRule rules[MAX_RULES];
int num_rules = 0;

/* Function to validate if IP address is valid */
bool is_valid_ip(char *ip) {
    int n1, n2, n3, n4;
    if (sscanf(ip, "%d.%d.%d.%d", &n1, &n2, &n3, &n4) != 4) {
        return false;
    }
    if (n1 < 0 || n1 > 255 || n2 < 0 || n2 > 255 || n3 < 0 || n3 > 255 || n4 < 0 || n4 > 255) {
        return false;
    }
    return true;
}

/* Function to validate if port is valid */
bool is_valid_port(char *port_str) {
    int port = atoi(port_str);
    if (port < 0 || port > 65535) {
        return false;
    }
    return true;
}

/* Function to parse the firewall rule string and populate the rule in the rules array */
void parse_rule(char *rule_str) {
    char *token;
    FirewallRule firewall_rule;
    token = strtok(rule_str, ",");
    strcpy(firewall_rule.source_ip, token);
    token = strtok(NULL, ",");
    strcpy(firewall_rule.dest_ip, token);
    firewall_rule.num_ports = 0;
    while ((token = strtok(NULL, ",")) != NULL) {
        if (is_valid_port(token)) {
            strcpy(firewall_rule.ports[firewall_rule.num_ports], token);
            firewall_rule.num_ports++;
        }
    }
    firewall_rule.allow = true;
    if (strstr(rule_str, "deny")) {
        firewall_rule.allow = false;
    }
    rules[num_rules] = firewall_rule;
    num_rules++;
}

/* Function to read the firewall rule file and populate the rules array */
void load_rules(char *rule_file) {
    FILE *fp;
    fp = fopen(rule_file, "r");
    if (fp == NULL) {
        printf("Error: Could not open rule file: %s\n", rule_file);
        exit(1);
    }
    char rule_str[1000];
    while (fgets(rule_str, sizeof(rule_str), fp) != NULL) {
        parse_rule(rule_str);
    }
    fclose(fp);
}

/* Function to check if source and destination IPs match the rule */
bool check_ip_rule(char *source_ip, char *dest_ip, FirewallRule rule) {
    if (strcmp(source_ip, rule.source_ip) == 0 && strcmp(dest_ip, rule.dest_ip) == 0) {
        return true;
    }
    return false;
}

/* Function to check if ports match the rule */
bool check_port_rule(int port, FirewallRule rule) {
    for (int i = 0; i < rule.num_ports; i++) {
        if (strcmp(rule.ports[i], "*") == 0 || atoi(rule.ports[i]) == port) {
            return true;
        }
    }
    return false;
}

/* Function to check if a packet should be allowed through the firewall */
bool check_packet(char *source_ip, char *dest_ip, int port) {
    for (int i = 0; i < num_rules; i++) {
        if (check_ip_rule(source_ip, dest_ip, rules[i]) && check_port_rule(port, rules[i])) {
            return rules[i].allow;
        }
    }
    return true;
}

/* Main function to read the packet and check if it should be allowed */
int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Error: Usage: ./firewall <rule-file> <packet>\n");
        exit(1);
    }
    load_rules(argv[1]);
    char source_ip[MAX_IP_LEN];
    char dest_ip[MAX_IP_LEN];
    int port;
    if (sscanf(argv[2], "%s %s %d", source_ip, dest_ip, &port) != 3) {
        printf("Error: Incorrect Packet format!\n");
        exit(1);
    }
    if (!is_valid_ip(source_ip) || !is_valid_ip(dest_ip) || !is_valid_port(argv[3])) {
        printf("Error: Incorrect Packet format!\n");
        exit(1);
    }
    if (check_packet(source_ip, dest_ip, port)) {
        printf("Packet allowed!\n");
    } else {
        printf("Packet denied!\n");
    }
    return 0;
}