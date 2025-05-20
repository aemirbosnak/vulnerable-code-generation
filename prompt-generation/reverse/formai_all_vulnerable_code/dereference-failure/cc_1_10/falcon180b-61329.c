//Falcon-180B DATASET v1.0 Category: Firewall ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100
#define MAX_IP_LENGTH 16

typedef struct {
    char ip[MAX_IP_LENGTH];
    char action;
} rule_t;

int main() {
    int num_rules = 0;
    rule_t rules[MAX_RULES];
    char input[MAX_RULE_LENGTH];
    char *token;
    FILE *fp;

    // Open the rules file
    fp = fopen("rules.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open rules file.\n");
        exit(1);
    }

    // Read in the rules
    while (fgets(input, MAX_RULE_LENGTH, fp)!= NULL) {
        token = strtok(input, " ");
        strcpy(rules[num_rules].ip, token);
        rules[num_rules].action = *token++;
        num_rules++;
    }

    // Close the rules file
    fclose(fp);

    // Simulate incoming packets
    char packet_ip[MAX_IP_LENGTH];
    printf("Enter the IP address of the incoming packet: ");
    scanf("%s", packet_ip);

    // Check the rules
    int i;
    for (i = 0; i < num_rules; i++) {
        if (strcmp(packet_ip, rules[i].ip) == 0) {
            printf("Packet %s %c\n", packet_ip, rules[i].action);
            break;
        }
    }

    // If no rule matches, default to deny
    if (i == num_rules) {
        printf("Packet %s denied\n", packet_ip);
    }

    return 0;
}