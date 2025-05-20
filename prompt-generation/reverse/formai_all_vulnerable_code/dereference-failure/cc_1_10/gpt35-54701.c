//FormAI DATASET v1.0 Category: Firewall ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This program is a Firewall that will block or allow incoming requests based on rules that are specified by the user */

void allow(char *ip) {
    printf("Incoming request from %s allowed\n", ip);
    return;
}

void block(char *ip) {
    printf("Incoming request from %s blocked\n", ip);
    return;
}

int main() {
    int num_rules, i, len;
    char **rules, *line, *ip, *action;
    printf("Welcome to the Firewall program.\n");
    printf("How many rules would you like to set?\n");
    scanf("%d", &num_rules);
    rules = (char**)malloc(sizeof(char*) * num_rules);
    printf("Please input the rules in the following format:\n");
    printf(" <ACTION> <IP ADDRESS>\n");
    printf("Allow incoming requests from specific IP addresses by typing 'allow' and the IP address.\n");
    printf("Block incoming requests from specific IP addresses by typing 'block' and the IP address.\n");
    printf("Example: allow 192.168.1.1\n");
    printf("Please input the rules:\n");
    getchar();
    for(i=0; i<num_rules; i++) {
        line = NULL;
        len = 0;
        getline(&line, &len, stdin);
        line[strcspn(line, "\n")] = 0;
        rules[i] = (char*)malloc(sizeof(char) * len);
        strcpy(rules[i], line);
        free(line);
    }
    printf("Rules set. Now waiting for incoming requests to be checked by the Firewall.\n");
    printf("Please enter 'exit' to quit the program.\n");
    while(1) {
        printf("Input the IP address of incoming request:\n");
        ip = NULL;
        len = 0;
        getline(&ip, &len, stdin);
        ip[strcspn(ip, "\n")] = 0;
        if(strcmp(ip, "exit") == 0) {
            break;
        }
        for(i=0; i<num_rules; i++) {
            action = strtok(rules[i], " ");
            if(strcmp(action, "allow") == 0) {
                if(strcmp(strtok(NULL, " "), ip) == 0) {
                    allow(ip);
                    break;
                }
            }
            else if(strcmp(action, "block") == 0) {
                if(strcmp(strtok(NULL, " "), ip) == 0) {
                    block(ip);
                    break;
                }
            }
        }
        if(i == num_rules) {
            printf("Incoming request from %s blocked by default\n", ip);
        }
        free(ip);
    }
    printf("Exiting the Firewall program. Thank you for using!\n");
    for(i=0; i<num_rules; i++) {
        free(rules[i]);
    }
    free(rules);
    return 0;
}