//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word {
    char english[MAX_WORD_LENGTH];
    char cat[MAX_WORD_LENGTH];
};

int main() {
    struct word dictionary[MAX_WORDS];
    int num_words = 0;
    FILE *input_file;
    char line[1000];
    char *word;
    char *saveptr;

    // Open the input file
    input_file = fopen("dictionary.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Read the dictionary file
    while (fgets(line, sizeof(line), input_file)!= NULL) {
        // Split the line into words
        word = strtok_r(line, " ", &saveptr);
        while (word!= NULL) {
            // Add the word to the dictionary
            strcpy(dictionary[num_words].english, word);
            strcpy(dictionary[num_words].cat, "");
            num_words++;

            // Move to the next word
            word = strtok_r(NULL, " ", &saveptr);
        }
    }

    // Close the input file
    fclose(input_file);

    // Translate a sentence
    printf("Enter a sentence to translate:\n");
    fgets(line, sizeof(line), stdin);
    char *sentence = strtok(line, "\n");

    // Split the sentence into words
    word = strtok(sentence, " ");
    while (word!= NULL) {
        // Search the dictionary for the English word
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(word, dictionary[i].english) == 0) {
                // Found the word, print the translation
                printf("%s -> %s\n", word, dictionary[i].cat);
                break;
            }
        }

        // If the word is not found, print an error message
        if (i == num_words) {
            printf("Unknown word: %s\n", word);
        }

        // Move to the next word
        word = strtok(NULL, " ");
    }

    return 0;
}