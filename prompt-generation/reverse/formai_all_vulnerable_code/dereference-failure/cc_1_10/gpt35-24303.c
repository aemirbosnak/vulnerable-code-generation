//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100
#define MAX_OUTPUT_LENGTH 1000
#define CAT_LANGUAGE_PREFIX "meow"

void translate_c_cat_language(char* input, char* output) {
    // convert input to lowercase
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            input[i] = input[i] - 'A' + 'a';
        }
    }

    // initialize output
    output[0] = 0;

    // translate input to cat language
    char* token = strtok(input, " ");
    while (token != NULL) {
        if (strncmp(token, CAT_LANGUAGE_PREFIX, strlen(CAT_LANGUAGE_PREFIX)) == 0) {
            // ignore cat language keywords
        } else {
            strcat(output, CAT_LANGUAGE_PREFIX);
            strcat(output, token);
        }
        strcat(output, " ");
        token = strtok(NULL, " ");
    }

    // remove trailing whitespace
    if (output[strlen(output) - 1] == ' ') {
        output[strlen(output) - 1] = 0;
    }
}

int main() {
    printf("=== C Cat Language Translator ===\n\n");

    char input[MAX_INPUT_LENGTH];
    char output[MAX_OUTPUT_LENGTH];

    printf("Enter a sentence in English: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // remove newline character from input
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = 0;
    }

    printf("\nTranslating to C Cat Language...\n");
    translate_c_cat_language(input, output);

    printf("\nTranslation:\n%s\n", output);

    return 0;
}