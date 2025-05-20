//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_RULES 100

typedef struct {
    char *pattern;
    int action;
} Rule;

int main() {
    // Initialize rules
    Rule rules[MAX_NUM_RULES];
    int num_rules = 0;

    // Load rules from file
    FILE *f = fopen("rules.txt", "r");
    if (f == NULL) {
        printf("Error: could not open rules file.\n");
        exit(1);
    }
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, f)!= NULL) {
        char *pattern = strtok(line, " ");
        int action = atoi(strtok(NULL, " "));
        rules[num_rules] = (Rule) {.pattern = pattern,.action = action};
        num_rules++;
    }
    fclose(f);

    // Start monitoring network traffic
    char input_buffer[MAX_LINE_LENGTH];
    while (fgets(input_buffer, MAX_LINE_LENGTH, stdin)!= NULL) {
        for (int i = 0; i < num_rules; i++) {
            if (strstr(input_buffer, rules[i].pattern)!= NULL) {
                switch (rules[i].action) {
                    case 1:
                        printf("Intrusion detected: %s\n", rules[i].pattern);
                        break;
                    case 2:
                        printf("Possible intrusion detected: %s\n", rules[i].pattern);
                        break;
                    case 3:
                        printf("Suspicious activity detected: %s\n", rules[i].pattern);
                        break;
                    default:
                        printf("Unknown action: %d\n", rules[i].action);
                }
            }
        }
    }
    return 0;
}