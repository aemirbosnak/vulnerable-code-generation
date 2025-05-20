//Falcon-180B DATASET v1.0 Category: Firewall ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_RULES 100
#define MAX_RULE_LEN 100
#define MAX_IP_LEN 16
#define MAX_PORT_LEN 6

typedef struct {
    char ip[MAX_IP_LEN];
    char port[MAX_PORT_LEN];
    int allow;
} rule_t;

int load_rules(rule_t rules[MAX_RULES]) {
    FILE *fp;
    char line[MAX_RULE_LEN];
    int count = 0;

    fp = fopen("rules.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open rules file.\n");
        return -1;
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (count >= MAX_RULES) {
            printf("Error: too many rules.\n");
            fclose(fp);
            return -1;
        }

        char *ip = strtok(line, " ");
        char *port = strtok(NULL, " ");
        int allow = atoi(strtok(NULL, " "));

        strncpy(rules[count].ip, ip, MAX_IP_LEN);
        strncpy(rules[count].port, port, MAX_PORT_LEN);
        rules[count].allow = allow;

        count++;
    }

    fclose(fp);
    return count;
}

int main() {
    rule_t rules[MAX_RULES];
    int num_rules = load_rules(rules);

    if (num_rules <= 0) {
        return -1;
    }

    printf("Firewall initialized with %d rules.\n", num_rules);

    while (1) {
        char ip[MAX_IP_LEN];
        char port[MAX_PORT_LEN];

        printf("Enter IP address and port (e.g. 192.168.0.1:80): ");
        scanf("%s %s", ip, port);

        int i;
        for (i = 0; i < num_rules; i++) {
            if (strcmp(rules[i].ip, ip) == 0 && strcmp(rules[i].port, port) == 0) {
                if (rules[i].allow) {
                    printf("Connection allowed.\n");
                } else {
                    printf("Connection denied.\n");
                }
                break;
            }
        }

        if (i == num_rules) {
            printf("No rule found for this connection.\n");
        }
    }

    return 0;
}