//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    char translation[MAX_WORD_LEN];
} Word;

int main() {
    FILE *dict_file;
    Word dict[MAX_WORDS];
    int num_words = 0;
    char line[MAX_WORD_LEN];
    char *word;
    char *translation;

    // Open dictionary file
    dict_file = fopen("dictionary.txt", "r");
    if (dict_file == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    // Read words from dictionary file
    while (fgets(line, MAX_WORD_LEN, dict_file)!= NULL) {
        // Split line into word and translation
        word = strtok(line, " ");
        translation = strtok(NULL, " ");

        // Add word and translation to dictionary array
        strcpy(dict[num_words].word, word);
        strcpy(dict[num_words].translation, translation);

        // Increment number of words
        num_words++;
    }

    // Close dictionary file
    fclose(dict_file);

    // Get input from user
    char input[MAX_WORD_LEN];
    printf("Enter a sentence: ");
    fgets(input, MAX_WORD_LEN, stdin);

    // Tokenize input sentence
    char *token = strtok(input, " ");
    while (token!= NULL) {
        // Look up word in dictionary
        for (int i = 0; i < num_words; i++) {
            if (strcmp(dict[i].word, token) == 0) {
                // Replace word with translation
                strcpy(token, dict[i].translation);
                break;
            }
        }

        // Get next token
        token = strtok(NULL, " ");
    }

    // Print translated sentence
    printf("Translated sentence: %s\n", input);

    return 0;
}