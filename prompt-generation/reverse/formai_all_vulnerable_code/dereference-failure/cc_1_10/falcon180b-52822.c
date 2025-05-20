//Falcon-180B DATASET v1.0 Category: Text processing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LEN 100

typedef struct {
    char *text;
    int length;
    int num_tokens;
    char **tokens;
} Text;

void tokenize(Text *text) {
    char *token = strtok(text->text, " \t\n\r\f\v");
    int i = 0;
    while (token!= NULL && i < MAX_TOKENS) {
        text->tokens[i] = strdup(token);
        i++;
        token = strtok(NULL, " \t\n\r\f\v");
    }
    text->num_tokens = i;
}

void process_text(Text *text) {
    for (int i = 0; i < text->num_tokens; i++) {
        char *token = text->tokens[i];
        int length = strlen(token);
        for (int j = 0; j < length; j++) {
            if (isalpha(token[j])) {
                token[j] = toupper(token[j]);
            }
        }
        printf("%s\n", token);
    }
}

void cleanup(Text *text) {
    for (int i = 0; i < text->num_tokens; i++) {
        free(text->tokens[i]);
    }
    free(text->tokens);
    free(text->text);
}

int main() {
    Text text;
    text.text = malloc(MAX_TOKEN_LEN * sizeof(char));
    text.length = 0;
    text.num_tokens = 0;
    text.tokens = malloc(MAX_TOKENS * sizeof(char*));

    printf("Enter text: ");
    fgets(text.text, MAX_TOKEN_LEN, stdin);
    text.length = strlen(text.text);

    tokenize(&text);
    process_text(&text);

    cleanup(&text);

    return 0;
}