//FormAI DATASET v1.0 Category: Firewall ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct {
    char ip[16];
    char protocol[4];
    int port;
} Rule;

int main() {
    Rule rules[SIZE];
    int numRules = 0;

    // load rules from configuration file
    FILE* fp = fopen("config.txt", "r");
    char line[50];
    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%s %s %d", rules[numRules].ip, rules[numRules].protocol, &rules[numRules].port);
        numRules++;
    }
    fclose(fp);

    // prompt user for input
    char input[50];
    printf("Enter IP address, protocol, and port number to check if it passes firewall:\n");
    fgets(input, sizeof(input), stdin);
    strtok(input, "\n");

    // parse user input
    char* ip = strtok(input, " ");
    char* protocol = strtok(NULL, " ");
    int port = atoi(strtok(NULL, " "));

    // check if input passes firewall
    int passed = 0;
    for (int i = 0; i < numRules; i++) {
        if (strcmp(ip, rules[i].ip) == 0 &&
            strcmp(protocol, rules[i].protocol) == 0 &&
            (rules[i].port == 0 || rules[i].port == port)) {
            passed = 1;
            break;
        }
    }

    if (passed) {
        printf("Input passes firewall!\n");
    } else {
        printf("Input does not pass firewall!\n");
    }

    return 0;
}