//FormAI DATASET v1.0 Category: Firewall ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define structs for firewall rules and packets
typedef struct {
    char protocol[10];
    char src_ip[16];
    char dst_ip[16];
    int src_port;
    int dst_port;
} Rule;

typedef struct {
    char protocol[10];
    char src_ip[16];
    char dst_ip[16];
    int src_port;
    int dst_port;
} Packet;

// Define function to read firewall rules from a file
void read_rules(char *filename, Rule *rules, int *num_rules) {
    FILE *file;
    char line[100];
    char *token;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }

    while (fgets(line, 100, file) != NULL) {
        // Parse each line of the file and store values in a rule struct
        token = strtok(line, ",");
        strcpy(rules[*num_rules].protocol, token);
        token = strtok(NULL, ",");
        strcpy(rules[*num_rules].src_ip, token);
        token = strtok(NULL, ",");
        strcpy(rules[*num_rules].dst_ip, token);
        token = strtok(NULL, ",");
        rules[*num_rules].src_port = atoi(token);
        token = strtok(NULL, ",");
        rules[*num_rules].dst_port = atoi(token);
        (*num_rules)++;
    }

    fclose(file);
}

// Define function to check if a packet matches a firewall rule
int match_rule(Rule rule, Packet packet) {
    if (strcmp(rule.protocol, packet.protocol) != 0) return 0;
    if (strcmp(rule.src_ip, packet.src_ip) != 0) return 0;
    if (strcmp(rule.dst_ip, packet.dst_ip) != 0) return 0;
    if (rule.src_port != packet.src_port) return 0;
    if (rule.dst_port != packet.dst_port) return 0;
    return 1;
}

// Define main function
int main() {
    Rule rules[100];
    Packet packet;
    int num_rules = 0;
    int i;

    // Read rules from file
    read_rules("firewall_rules.csv", rules, &num_rules);

    // Get user input for packet values
    printf("Enter protocol: ");
    scanf("%s", packet.protocol);
    printf("Enter source IP: ");
    scanf("%s", packet.src_ip);
    printf("Enter destination IP: ");
    scanf("%s", packet.dst_ip);
    printf("Enter source port: ");
    scanf("%d", &packet.src_port);
    printf("Enter destination port: ");
    scanf("%d", &packet.dst_port);

    // Check if packet matches any rules, and allow or deny access accordingly
    for (i = 0; i < num_rules; i++) {
        if (match_rule(rules[i], packet)) {
            printf("Access allowed\n");
            exit(0);
        }
    }

    printf("Access denied\n");
    return 0;
}