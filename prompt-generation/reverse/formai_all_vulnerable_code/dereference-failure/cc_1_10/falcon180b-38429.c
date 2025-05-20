//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100
#define MAX_RULE_LEN 100

typedef struct {
    char *pattern;
    int action;
} rule_t;

int main() {
    int num_rules = 0;
    rule_t rules[MAX_RULES];
    char input_buffer[1024];
    int i;

    printf("Enter intrusion detection rules (pattern action):\n");
    while (fgets(input_buffer, sizeof(input_buffer), stdin)!= NULL) {
        if (num_rules >= MAX_RULES) {
            printf("Error: Maximum number of rules exceeded.\n");
            exit(1);
        }
        char *pattern = strtok(input_buffer, " ");
        int action = atoi(strtok(NULL, " "));
        rules[num_rules].pattern = strdup(pattern);
        rules[num_rules].action = action;
        num_rules++;
    }

    printf("Enter data to scan:\n");
    fgets(input_buffer, sizeof(input_buffer), stdin);

    for (i = 0; i < num_rules; i++) {
        if (strstr(input_buffer, rules[i].pattern)!= NULL) {
            switch (rules[i].action) {
                case 1:
                    printf("Intrusion detected! Blocking connection...\n");
                    break;
                case 2:
                    printf("Intrusion detected! Alerting administrator...\n");
                    break;
                default:
                    printf("Intrusion detected! Taking no action...\n");
            }
            break;
        }
    }

    if (i == num_rules) {
        printf("No intrusion detected.\n");
    }

    return 0;
}