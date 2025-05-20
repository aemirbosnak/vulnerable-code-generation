//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* translate(char* input);

int main() {
    printf("Welcome to the Cat Language Translator!\n");
    while (1) {
        char input[100];
        printf("Type in a phrase in Cat Language or type 'exit' to quit: ");
        fgets(input, 100, stdin);

        if (strcmp(input, "exit\n") == 0) {
            printf("Goodbye!\n");
            break;
        }

        char* translation = translate(input);
        printf("Translation: %s\n", translation);

        free(translation);
    }

    return 0;
}

char* translate(char* input) {
    int length = strlen(input);
    char* output = (char*) malloc(length * 3 + 1);
    int index = 0;

    for (int i = 0; i < length - 1; i++) {
        char c = input[i];
        if (c == ' ') {
            output[index++] = ' ';
            output[index++] = ' ';
            output[index++] = ' ';
        } else {
            output[index++] = 'm';
            output[index++] = 'e';
            output[index++] = 'o';
            output[index++] = 'w';
        }
    }

    output[index] = '\0';

    return output;
}