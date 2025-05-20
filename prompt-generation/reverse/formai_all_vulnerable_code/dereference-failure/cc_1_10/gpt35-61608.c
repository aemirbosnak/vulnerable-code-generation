//FormAI DATASET v1.0 Category: Firewall ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_IP_SIZE 20
#define MAX_RULES 50

typedef struct Rule {
    char source_ip[MAX_IP_SIZE];
    char destination_ip[MAX_IP_SIZE];
    bool allow;
} Rule;

int main() {
    printf("Welcome to Firewall rules management!\n");
    printf("How many rules do you want to add?\n");
    int num_rules;
    scanf("%d", &num_rules);

    Rule rules[MAX_RULES];
    memset(rules, 0, sizeof(rules));

    printf("Please enter each rule in the following format:\n");
    printf("<source IP>,<destination IP>,<allow/deny>\n");

    for (int i = 0; i < num_rules; i++) {
        char input[100];
        scanf("%s", input);

        char* source_ip = strtok(input, ",");
        char* destination_ip = strtok(NULL, ",");
        char* allow_permission = strtok(NULL, ",");

        strcpy(rules[i].source_ip, source_ip);
        strcpy(rules[i].destination_ip, destination_ip);
        if (strcmp(allow_permission, "allow") == 0)
            rules[i].allow = true;
        else
            rules[i].allow = false;
    }

    printf("Rules added successfully.\n");

    while(true) {
        printf("\nFirewall status: ENABLED.\n");
        printf("Enter IP address to check if it's allowed: ");
        char ip[MAX_IP_SIZE];
        scanf("%s", ip);

        bool allowed = false;
        for (int i = 0; i < num_rules; i++) {
            if (strcmp(ip, rules[i].source_ip) == 0 || strcmp(ip, rules[i].destination_ip) == 0) {
                if (rules[i].allow) {
                    allowed = true;
                    break;
                } else {
                    allowed = false;
                    break;
                }
            }
        }

        if (allowed)
            printf("%s is allowed to connect.\n", ip);
        else
            printf("%s is not allowed to connect.\n", ip);
    }

    return 0;
}