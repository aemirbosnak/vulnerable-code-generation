//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100

typedef struct {
    char *pattern;
    int action;
} Rule;

int main(int argc, char *argv[]) {
    int num_rules = 0;
    Rule rules[MAX_RULES];

    printf("Welcome to the Intrusion Detection System!\n");

    // read in rules from file
    FILE *file = fopen("rules.txt", "r");
    if (file == NULL) {
        printf("Error: could not open rules file.\n");
        exit(1);
    }

    char line[MAX_RULE_LENGTH];
    while (fgets(line, MAX_RULE_LENGTH, file)!= NULL) {
        if (num_rules >= MAX_RULES) {
            printf("Error: maximum number of rules exceeded.\n");
            exit(1);
        }

        char *pattern = strtok(line, " ");
        int action = atoi(strtok(NULL, " "));

        rules[num_rules].pattern = strdup(pattern);
        rules[num_rules].action = action;
        num_rules++;
    }

    fclose(file);

    // start monitoring network traffic
    while (1) {
        char packet[MAX_RULE_LENGTH];
        fgets(packet, MAX_RULE_LENGTH, stdin);

        for (int i = 0; i < num_rules; i++) {
            if (strstr(packet, rules[i].pattern)!= NULL) {
                printf("Intrusion detected! Taking action %d.\n", rules[i].action);
                break;
            }
        }
    }

    return 0;
}