//FormAI DATASET v1.0 Category: Firewall ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100

// Define struct to hold firewall rules
typedef struct {
    char protocol[4];
    char source_ip[16];
    char dest_ip[16];
    int source_port;
    int dest_port;
    int action;
} rule;

// Define function to parse user input into firewall rule
void parse_rule(char* input, rule* r) {
    char* token;
    token = strtok(input, " ");
    strcpy(r->protocol, token);
    token = strtok(NULL, " ");
    strcpy(r->source_ip, token);
    token = strtok(NULL, " ");
    strcpy(r->dest_ip, token);
    token = strtok(NULL, " ");
    r->source_port = atoi(token);
    token = strtok(NULL, " ");
    r->dest_port = atoi(token);
    token = strtok(NULL, " ");
    if (strcmp(token, "allow") == 0) {
        r->action = 1;
    } else {
        r->action = 0;
    }
}

// Define function to check if packet matches firewall rule
int match_rule(char* packet, rule* r) {
    char protocol[4], source_ip[16], dest_ip[16];
    int source_port, dest_port;
    sscanf(packet, "%s %s %s %d %d", protocol, source_ip, dest_ip, &source_port, &dest_port);
    if (strcmp(protocol, r->protocol) == 0 &&
        strcmp(source_ip, r->source_ip) == 0 &&
        strcmp(dest_ip, r->dest_ip) == 0 &&
        source_port == r->source_port &&
        dest_port == r->dest_port) {
        return r->action;
    } else {
        return -1;
    }
}

// Define function to read firewall rules from file
int read_rules(char* filename, rule* rules) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        return 0;
    }
    char line[100];
    int i = 0;
    while (fgets(line, 100, fp) != NULL) {
        parse_rule(line, &rules[i]);
        i++;
    }
    fclose(fp);
    return i;
}

// Define function to print firewall rule
void print_rule(rule* r) {
    printf("%s %s %s %d %d ", r->protocol, r->source_ip, r->dest_ip, r->source_port, r->dest_port);
    if (r->action == 1) {
        printf("allow\n");
    } else {
        printf("deny\n");
    }
}

int main() {
    // Read firewall rules from file
    rule rules[MAX_RULES];
    int num_rules = read_rules("firewall_rules.txt", rules);
    if (num_rules == 0) {
        return 1;
    }

    // Define variables for packet processing loop
    char input[100];
    char packet[100];
    int action;
    printf("Enter packets to process, 'exit' to quit:\n");
    while (fgets(input, 100, stdin) != NULL) {
        if (strcmp(input, "exit\n") == 0) {
            break;
        }
        sscanf(input, "%s", packet);
        action = -1;
        for (int i = 0; i < num_rules; i++) {
            action = match_rule(packet, &rules[i]);
            if (action != -1) {
                break;
            }
        }
        if (action == 1) {
            printf("Packet allowed by firewall.\n");
        } else {
            printf("Packet denied by firewall.\n");
        }
    }

    return 0;
}