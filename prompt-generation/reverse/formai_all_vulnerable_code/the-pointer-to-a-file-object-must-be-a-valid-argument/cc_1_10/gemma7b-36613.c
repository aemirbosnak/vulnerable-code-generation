//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Lexical_Entry {
    char *lexeme;
    int line_number;
    struct Lexical_Entry *next;
} Lexical_Entry;

typedef struct Grammar_Rule {
    char *rule_name;
    char **terminals;
    int num_terminals;
    struct Grammar_Rule *next;
} Grammar_Rule;

void parse_grammar(FILE *fp) {
    Grammar_Rule *rules = NULL;
    char buffer[MAX_BUFFER_SIZE];
    int line_number = 1;

    // Read the grammar rules from the file
    while (fgets(buffer, MAX_BUFFER_SIZE, fp) != NULL) {
        // Create a new grammar rule
        Grammar_Rule *new_rule = malloc(sizeof(Grammar_Rule));
        new_rule->rule_name = strdup(buffer);
        new_rule->terminals = malloc(sizeof(char *) * 10);
        new_rule->num_terminals = 0;
        new_rule->next = rules;
        rules = new_rule;

        // Increment the line number
        line_number++;
    }

    // Print the grammar rules
    for (rules = rules; rules; rules = rules->next) {
        printf("Rule: %s\n", rules->rule_name);
        printf("Terminals:\n");
        for (int i = 0; i < rules->num_terminals; i++) {
            printf("  %s\n", rules->terminals[i]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp = fopen("grammar.txt", "r");
    parse_grammar(fp);
    fclose(fp);

    return 0;
}