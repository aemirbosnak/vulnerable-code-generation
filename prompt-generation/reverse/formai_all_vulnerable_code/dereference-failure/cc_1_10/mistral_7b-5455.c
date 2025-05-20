//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: complex
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1000

void reverse(char *str, int start, int end) {
    char temp;
    for (; start < end; start++, end--) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
    }
}

void print_string_reverse(char *str) {
    int len = strlen(str);
    reverse(str, 0, len - 1);
    printf("%s\n", str);
}

void split_string(char *str, char delimiter, char **tokens, int *count) {
    int current = 0, next = 0;
    *count = 0;
    while (*(str + next) != '\0') {
        if (*(str + next) == delimiter) {
            *(str + next) = '\0';
            tokens[*count] = str + current;
            current = next + 1;
            (*count)++;
        }
        next++;
    }
    tokens[*count] = str + current;
}

void join_strings(char **strings, int count, char *dest, char delimiter) {
    int i;
    for (i = 0; i < count - 1; i++) {
        strcat(dest, strings[i]);
        strcat(dest, &delimiter);
    }
    strcat(dest, strings[count - 1]);
}

int main() {
    char input_str[MAX_LEN];
    char delimiter[] = {','};
    char *tokens[100];
    int token_count;
    char output_str[MAX_LEN];

    printf("Enter a string with comma-separated tokens: ");
    fgets(input_str, MAX_LEN, stdin);

    split_string(input_str, *delimiter, tokens, &token_count);

    printf("Tokens: ");
    int i;
    for (i = 0; i < token_count; i++) {
        printf("%s ", tokens[i]);
    }
    printf("\n");

    join_strings(tokens, token_count, output_str, *delimiter);

    print_string_reverse(output_str);

    for (i = 0; i < token_count; i++) {
        free(tokens[i]);
    }
    free(tokens);

    return 0;
}