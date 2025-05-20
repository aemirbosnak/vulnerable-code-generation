//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 100
#define NUM_WORDS 10

void process_text(char *text) {
    int word_count = 0;
    char words[NUM_WORDS][MAX_LENGTH];
    char *token;
    char *text_copy = malloc(strlen(text) * sizeof(char) + 1);
    strcpy(text_copy, text);

    token = strtok(text_copy, " .,!?");
    while (token != NULL && word_count < NUM_WORDS) {
        strcpy(words[word_count], token);
        word_count++;
        token = strtok(NULL, " .,!?");
    }

    printf("*** SHOCKED TEXT PROCESSING RESULTS ***\n");

    for (int i = 0; i < word_count; i++) {
        int length = strlen(words[i]);
        int upper_count = 0;

        for (int j = 0; j < length; j++) {
            if (isupper(words[i][j])) {
                upper_count++;
            }
        }

        if (upper_count > length / 2) {
            printf("%s: %s IS A SHOCKED WORD!\n", words[i], words[i]);
        } else {
            printf("%s: %s IS NOT A SHOCKED WORD.\n", words[i], words[i]);
        }
    }

    free(text_copy);
}

int main() {
    char input_text[MAX_LENGTH];

    printf("Enter a text to process (max length %d): ", MAX_LENGTH);
    fgets(input_text, MAX_LENGTH, stdin);

    process_text(input_text);

    return 0;
}