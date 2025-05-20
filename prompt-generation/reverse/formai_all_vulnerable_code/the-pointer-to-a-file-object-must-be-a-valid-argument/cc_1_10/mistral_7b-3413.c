//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN 100
#define MAX_RULES 10

typedef struct {
    char *input;
    char *output;
} Rule;

void read_file(const char *filename, Rule rules[MAX_RULES]);
void apply_rule(const Rule *rule, char *input);
void generate_fortune(char *input);

int main(int argc, char *argv[]) {
    srand(time(NULL));
    Rule rules[MAX_RULES];

    if (argc < 2) {
        printf("Usage: %s <rulefile>\n", argv[0]);
        exit(1);
    }

    read_file(argv[1], rules);
    char input[MAX_TOKEN] = {0};

    printf("Tell me your current situation, and I will tell you your future:\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // remove newline character

    generate_fortune(input);

    return 0;
}

void read_file(const char *filename, Rule rules[MAX_RULES]) {
    FILE *file = fopen(filename, "r");
    char line[MAX_TOKEN] = {0};
    int rule_index = 0;

    while (fgets(line, sizeof(line), file)) {
        char *token[MAX_TOKEN / 2 + 1] = {0};
        char *token_ptr = strtok(line, " \t:");

        if (!token_ptr) continue;
        int i = 0;
        while (token_ptr && i < MAX_TOKEN / 2) {
            token[i++] = strdup(token_ptr);
            token_ptr = strtok(NULL, " \t:");
        }

        rules[rule_index].input = malloc(strlen(token[0]) + 1);
        strcpy(rules[rule_index].input, token[0]);
        rules[rule_index].output = malloc(strlen(token[1]) + 1);
        strcpy(rules[rule_index].output, token[1]);
        rule_index++;
    }

    fclose(file);
}

void apply_rule(const Rule *rule, char *input) {
    size_t input_len = strlen(input);
    size_t rule_input_len = strlen(rule->input);

    for (size_t i = 0; i < input_len - rule_input_len + 1; i++) {
        if (strncmp(input + i, rule->input, rule_input_len) == 0) {
            strncpy(input + i, rule->output, strlen(rule->output) + 1);
            input[i + strlen(rule->output)] = ' ';
            return;
        }
    }
}

void generate_fortune(char *input) {
    Rule rules[MAX_RULES];
    read_file("rules.txt", rules);

    for (int i = 0; i < rand() % 10 + 1; i++) { // apply random number of rules
        apply_rule(&rules[rand() % MAX_RULES], input);
    }

    printf("Your future: %s\n", input);
}