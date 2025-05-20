//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000
#define MAX_VOCABULARY_SIZE 10000

typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} Vocabulary;

Vocabulary vocabulary[MAX_VOCABULARY_SIZE];
int vocabularySize = 0;

void loadVocabulary(char* filename) {
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: could not open vocabulary file.\n");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        char* english = strtok(line, " ");
        char* alien = strtok(NULL, " ");

        strcpy(vocabulary[vocabularySize].english, english);
        strcpy(vocabulary[vocabularySize].alien, alien);

        vocabularySize++;
    }

    fclose(file);
}

bool isEnglish(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool isAlien(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void translateSentence(char* sentence) {
    int i = 0;

    while (i < strlen(sentence)) {
        if (isEnglish(sentence[i])) {
            i++;

            int wordLength = 0;
            while (i < strlen(sentence) && isEnglish(sentence[i])) {
                wordLength++;
                i++;
            }

            char word[MAX_WORD_LENGTH];
            strncpy(word, sentence + i - wordLength, wordLength);
            word[wordLength] = '\0';

            for (int j = 0; j < vocabularySize; j++) {
                if (strcmp(word, vocabulary[j].english) == 0) {
                    strcat(sentence, vocabulary[j].alien);
                    i += strlen(vocabulary[j].alien) - 1;
                    break;
                }
            }
        } else {
            i++;
        }
    }
}

int main() {
    loadVocabulary("vocabulary.txt");

    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence to translate:\n");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    translateSentence(sentence);

    printf("Translated sentence: %s\n", sentence);

    return 0;
}