//FormAI DATASET v1.0 Category: Firewall ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_IP_LEN 15
#define MAX_RULE_LEN 50
#define MAX_LINE_LEN 100

typedef struct rule {
    char protocol[10];
    char source_ip[MAX_IP_LEN + 1];
    char dest_ip[MAX_IP_LEN + 1];
    int source_port;
    int dest_port;
} Rule;

// Function to parse a line and insert a rule
// Returns true if rule was inserted successfully
bool insertRule(char* line, Rule* rules, int* numRules) {
    Rule r;
    char* token;
    token = strtok(line, " ");
    int i = 0;
    while(token != NULL && i < 5) {
        switch(i) {
            case 0:
                strcpy(r.protocol, token);
                break;
            case 1:
                strcpy(r.source_ip, token);
                break;
            case 2:
                strcpy(r.dest_ip, token);
                break;
            case 3:
                r.source_port = atoi(token);
                break;
            case 4:
                r.dest_port = atoi(token);
                break;
        }
        token = strtok(NULL, " ");
        i++;
    }
    if(i < 5) {
        printf("Invalid rule: %s\n", line);
        return false;
    }
    rules[*numRules] = r;
    *numRules = *numRules + 1;
    return true;
}

// Function to check if a rule allows a packet
bool checkPacket(Rule r, char* protocol, char* source_ip, char* dest_ip, int source_port, int dest_port) {
    if(strcmp(r.protocol, protocol) != 0 && strcmp(r.protocol, "any") != 0) {
        return false;
    }
    if(strcmp(r.source_ip, source_ip) != 0 && strcmp(r.source_ip, "any") != 0) {
        return false;
    }
    if(strcmp(r.dest_ip, dest_ip) != 0 && strcmp(r.dest_ip, "any") != 0) {
        return false;
    }
    if(r.source_port != source_port && r.source_port != -1) {
        return false;
    }
    if(r.dest_port != dest_port && r.dest_port != -1) {
        return false;
    }
    return true;
}

// Function to read a line of input from stdin
char* readLine() {
    char* line = malloc(MAX_LINE_LEN);
    fgets(line, MAX_LINE_LEN, stdin);
    line[strcspn(line, "\r\n")] = 0;
    return line;
}

int main() {
    // Initialize rule array
    Rule rules[MAX_RULE_LEN];
    int numRules = 0;

    // Read in rules
    printf("Enter rules (one per line, format: protocol source_ip dest_ip source_port dest_port)\n");
    while(numRules < MAX_RULE_LEN) {
        char* line = readLine();
        if(strcmp(line, "exit") == 0) {
            break;
        }
        else if(insertRule(line, rules, &numRules)) {
            printf("Rule added.\n");
        }
        free(line);
    }

    // Check packets until 'exit' is entered
    printf("Enter packets (format: protocol source_ip dest_ip source_port dest_port)\n");
    while(true) {
        char* line = readLine();
        if(strcmp(line, "exit") == 0) {
            break;
        }
        char protocol[10];
        char source_ip[MAX_IP_LEN + 1];
        char dest_ip[MAX_IP_LEN + 1];
        int source_port, dest_port;
        sscanf(line, "%s %s %s %d %d", protocol, source_ip, dest_ip, &source_port, &dest_port);
        bool allowed = false;
        for(int i = 0; i < numRules; i++) {
            if(checkPacket(rules[i], protocol, source_ip, dest_ip, source_port, dest_port)) {
                allowed = true;
                break;
            }
        }
        if(allowed) {
            printf("Packet allowed.\n");
        }
        else {
            printf("Packet denied.\n");
        }
        free(line);
    }

    return 0;
}