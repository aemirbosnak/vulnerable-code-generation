//FormAI DATASET v1.0 Category: Firewall ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RULES 1000
#define MAX_CHARS 1000

struct Rule {
    char protocol[MAX_CHARS];
    char source_ip[MAX_CHARS];
    char dest_ip[MAX_CHARS];
    char action[MAX_CHARS];
    int source_port;
    int dest_port;
};

struct Packet {
    char protocol[MAX_CHARS];
    char source_ip[MAX_CHARS];
    char dest_ip[MAX_CHARS];
    int source_port;
    int dest_port;
};

typedef struct Rule Rule;
typedef struct Packet Packet;

int num_rules = 0;
Rule rules[MAX_RULES];

/*
 * Function to read firewall rules from a file
 */
void read_rules(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error reading file.\n");
        return;
    }
    char line[MAX_CHARS];
    while (fgets(line, MAX_CHARS, fp) != NULL) {
        char* token = strtok(line, ",");
        strcpy(rules[num_rules].protocol, token);
        token = strtok(NULL, ",");
        strcpy(rules[num_rules].source_ip, token);
        token = strtok(NULL, ",");
        strcpy(rules[num_rules].dest_ip, token);
        token = strtok(NULL, ",");
        rules[num_rules].source_port = atoi(token);
        token = strtok(NULL, ",");
        rules[num_rules].dest_port = atoi(token);
        token = strtok(NULL, ",");
        strcpy(rules[num_rules].action, token);
        num_rules++;
    }
    fclose(fp);
}

/*
 * Function to determine if a packet matches a rule
 */
bool match(Packet packet, Rule rule) {
    if (strcmp(rule.protocol, packet.protocol) != 0) {
        return false;
    }
    if (strcmp(rule.source_ip, packet.source_ip) != 0 && strcmp(rule.source_ip, "*") != 0) {
        return false;
    }
    if (strcmp(rule.dest_ip, packet.dest_ip) != 0 && strcmp(rule.dest_ip, "*") != 0) {
        return false;
    }
    if (rule.source_port != packet.source_port && rule.source_port != 0) {
        return false;
    }
    if (rule.dest_port != packet.dest_port && rule.dest_port != 0) {
        return false;
    }
    return true;
}

/*
 * Function to process incoming packets
 */
void process_packets(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error reading file.\n");
        return;
    }
    char line[MAX_CHARS];
    while (fgets(line, MAX_CHARS, fp) != NULL) {
        Packet packet;
        char* token = strtok(line, ",");
        strcpy(packet.protocol, token);
        token = strtok(NULL, ",");
        strcpy(packet.source_ip, token);
        token = strtok(NULL, ",");
        strcpy(packet.dest_ip, token);
        token = strtok(NULL, ",");
        packet.source_port = atoi(token);
        token = strtok(NULL, ",");
        packet.dest_port = atoi(token);
        bool matched = false;
        for (int i = 0; i < num_rules; i++) {
            if (match(packet, rules[i])) {
                printf("Packet matched rule: %s,%s,%s,%d,%d,%s\n", packet.protocol, packet.source_ip, packet.dest_ip, packet.source_port, packet.dest_port, rules[i].action);
                matched = true;
                break;
            }
        }
        if (!matched) {
            printf("Packet did not match any rule.\n");
        }
    }
    fclose(fp);
}

/*
 * Main function to read rules and process packets
 */
int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <rules_file> <packets_file>\n", argv[0]);
        exit(1);
    }
    read_rules(argv[1]);
    process_packets(argv[2]);
    return 0;
}