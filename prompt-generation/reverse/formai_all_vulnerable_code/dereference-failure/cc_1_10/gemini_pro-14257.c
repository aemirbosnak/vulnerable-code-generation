//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *english;
    char *alien;
} word;

int main() {
    // Initialize the dictionary
    word dictionary[] = {
        {"hello", "xizq"},
        {"world", "meex"},
        {"goodbye", "qazz"},
        {"thank you", "siq"},
        {"you're welcome", "bix"},
        {"yes", "daq"},
        {"no", "naq"},
        {"please", "ciq"},
        {"excuse me", "zaq"},
        {"I'm sorry", "hiq"}
    };

    // Get the user's input
    char *input = malloc(100);
    printf("Enter a sentence in English: ");
    gets(input);

    // Tokenize the input sentence
    char *tokens[100];
    int num_tokens = 0;
    char *token = strtok(input, " ");
    while (token != NULL) {
        tokens[num_tokens] = token;
        num_tokens++;
        token = strtok(NULL, " ");
    }

    // Translate each token
    char *output[100];
    for (int i = 0; i < num_tokens; i++) {
        int found = 0;
        for (int j = 0; j < (sizeof(dictionary) / sizeof(word)); j++) {
            if (strcmp(tokens[i], dictionary[j].english) == 0) {
                output[i] = dictionary[j].alien;
                found = 1;
                break;
            }
        }
        if (!found) {
            output[i] = tokens[i];
        }
    }

    // Print the translated sentence
    printf("Translation: ");
    for (int i = 0; i < num_tokens; i++) {
        printf("%s ", output[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(input);
    for (int i = 0; i < num_tokens; i++) {
        free(output[i]);
    }

    return 0;
}