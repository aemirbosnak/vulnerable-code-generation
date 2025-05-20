//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

// Structure to store words and their translations
typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordTranslation;

// Function to load words and translations from a file
void loadWords(WordTranslation words[], FILE *file) {
    char line[MAX_WORD_LENGTH];
    int count = 0;

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL && count < MAX_WORDS) {
        char *token = strtok(line, "\t");
        strcpy(words[count].word, token);

        token = strtok(NULL, "\t");
        strcpy(words[count].translation, token);

        count++;
    }
}

// Function to translate a sentence
void translateSentence(WordTranslation words[], char sentence[]) {
    int i, j;
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];

    // Split the sentence into words
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        // Convert the word to lowercase
        for (i = 0; i < strlen(token); i++) {
            token[i] = tolower(token[i]);
        }

        // Search for the word in the list of translations
        for (j = 0; j < MAX_WORDS; j++) {
            if (strcmp(token, words[j].word) == 0) {
                // Word found, use its translation
                strcpy(translation, words[j].translation);
                break;
            }
        }

        // If the word was not found, use the original word
        if (j == MAX_WORDS) {
            strcpy(translation, token);
        }

        // Print the translation followed by a space
        printf("%s ", translation);

        // Get the next word
        token = strtok(NULL, " ");
    }
}

int main() {
    WordTranslation words[MAX_WORDS];
    FILE *file;

    // Load words and translations from a file
    file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    loadWords(words, file);
    fclose(file);

    // Translate a sentence
    char sentence[] = "Hello world, how are you?";
    translateSentence(words, sentence);

    return 0;
}