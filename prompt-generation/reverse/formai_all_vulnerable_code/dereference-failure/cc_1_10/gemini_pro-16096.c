//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

int main() {
    // Get the input text from the user.
    char *text = malloc(MAX_LINE_LENGTH * sizeof(char));
    printf("Enter some text: ");
    fgets(text, MAX_LINE_LENGTH, stdin);

    // Remove all the punctuation from the text.
    char *new_text = malloc(strlen(text) * sizeof(char));
    int new_text_index = 0;
    for (int i = 0; i < strlen(text); i++) {
        char c = text[i];
        if (!ispunct(c)) {
            new_text[new_text_index] = c;
            new_text_index++;
        }
    }
    new_text[new_text_index] = '\0';

    // Convert all the letters in the text to lowercase.
    for (int i = 0; i < strlen(new_text); i++) {
        new_text[i] = tolower(new_text[i]);
    }

    // Remove all the duplicate words from the text.
    char **words = malloc(MAX_LINE_LENGTH * sizeof(char *));
    int num_words = 0;
    char *word = strtok(new_text, " ");
    while (word != NULL) {
        int found = 0;
        for (int i = 0; i < num_words; i++) {
            if (strcmp(word, words[i]) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            words[num_words] = malloc(strlen(word) * sizeof(char));
            strcpy(words[num_words], word);
            num_words++;
        }
        word = strtok(NULL, " ");
    }

    // Print the unique words in the text.
    for (int i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");

    // Free the allocated memory.
    free(text);
    free(new_text);
    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }
    free(words);

    return 0;
}