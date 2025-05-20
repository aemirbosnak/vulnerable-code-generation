//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOLS 100
#define MAX_RULES 100
#define MAX_STRING_LEN 100

typedef struct {
    char *symbol;
    int count;
} Symbol;

typedef struct {
    Symbol *from;
    Symbol *to;
    int count;
} Rule;

typedef struct {
    Rule *rules;
    int num_rules;
} Grammar;

void generate_symbols(Grammar *grammar, int num_symbols) {
    int i;
    for (i = 0; i < num_symbols; i++) {
        char symbol[MAX_STRING_LEN];
        sprintf(symbol, "S%d", i);
        grammar->rules[i].from = (Symbol*)malloc(sizeof(Symbol));
        grammar->rules[i].from->symbol = strdup(symbol);
        grammar->rules[i].from->count = 0;
        grammar->rules[i].to = (Symbol*)malloc(sizeof(Symbol));
        grammar->rules[i].to->symbol = strdup(" ");
        grammar->rules[i].to->count = 0;
        grammar->num_rules++;
    }
}

void generate_rules(Grammar *grammar, int num_rules) {
    int i;
    for (i = 0; i < num_rules; i++) {
        char rule_str[MAX_STRING_LEN];
        sprintf(rule_str, "S%d -> %s", i, "S0");
        grammar->rules[i].from->symbol = strdup(rule_str);
        grammar->rules[i].from->count++;
    }
}

void print_grammar(Grammar *grammar) {
    int i;
    for (i = 0; i < grammar->num_rules; i++) {
        printf("%s -> %s\n", grammar->rules[i].from->symbol, grammar->rules[i].to->symbol);
    }
}

int main() {
    Grammar grammar;
    generate_symbols(&grammar, 2);
    generate_rules(&grammar, 4);
    print_grammar(&grammar);
    return 0;
}