//FormAI DATASET v1.0 Category: Syntax parsing ; Style: retro
#include<stdio.h>
#include<stdlib.h>

char* operators[] = { "+", "-", "*", "/", "%", "<<", ">>", "&", "|", "^","=" };
char* keywords[] = { "if", "else", "while", "do", "for", "switch", "case","break" };
int brackets = 0, sq_brackets = 0, cr_brackets = 0;

void parseSyntax(char *line){
    char *word;
    int i = 0;
    while (sscanf(line, "%s", word) > 0) {
        if (isalpha(*word)) {
            for (i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
                if (strcmp(keywords[i], word) == 0) {
                    printf("%s -> Keyword\n", word);
                    break;
                }
            }
            if (i == sizeof(keywords) / sizeof(keywords[0])) {
                printf("%s -> Identifier\n", word);
            }
        }
        else if (isdigit(*word)) {
            printf("%s -> Number\n", word);
        }
        else if (*word == '(') {
            printf("%s -> Open Parenthesis\n", word);
            brackets++;
        }
        else if (*word == '[') {
            printf("%s -> Open Square Bracket\n", word);
            sq_brackets++;
        }
        else if (*word == '{') {
            printf("%s -> Open Curly Bracket\n", word);
            cr_brackets++;
        }
        else if (*word == ')') {
            printf("%s -> Close Parenthesis\n", word);
            brackets--;
        }
        else if (*word == ']') {
            printf("%s -> Close Square Bracket\n", word);
            sq_brackets--;
        }
        else if (*word == '}') {
            printf("%s -> Close Curly Bracket\n", word);
            cr_brackets--;
        }
        else {
            for (i = 0; i < sizeof(operators) / sizeof(operators[0]); i++) {
                if (strcmp(operators[i], word) == 0) {
                    printf("%s -> Operator\n", word);
                    break;
                }
            }
            if (i == sizeof(operators) / sizeof(operators[0])) {
                printf("%s -> Invalid Input\n", word);
            }
        }
        line += strlen(word) + 1;
    }
}

int main() {
    char line[100];
    printf("Enter a line of code to parse syntax:\n");
    fgets(line, sizeof(line), stdin);
    printf("\nTOKEN        Type\n");
    printf("-----        ----\n");
    parseSyntax(line);
    if (brackets != 0) {
        printf("\nERROR: Mismatched Parentheses.\n");
    }
    if (sq_brackets != 0){
        printf("\nERROR: Mismatched Square Brackets.\n");
    }
    if (cr_brackets != 0){
        printf("\nERROR: Mismatched Curly Brackets.\n");
    }
    return 0;
}