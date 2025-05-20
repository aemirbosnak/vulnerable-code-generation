//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_FILE "dictionary.txt"

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int count;
} WordCount;

void readDictionary(char* filename, WordCount* dictionary, int* numWords) {
    FILE* file = fopen(filename, "r");
    char line[MAX_WORD_LENGTH + 1];
    char* word;
    int i = 0;

    while (fgets(line, sizeof(line), file)!= NULL) {
        word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            if (strlen(word) <= MAX_WORD_LENGTH) {
                strcpy(dictionary[i].word, word);
                dictionary[i].count = 0;
                i++;
            }
            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(file);
    *numWords = i;
}

void spellCheck(char* filename, WordCount* dictionary, int numWords) {
    FILE* file = fopen(filename, "r");
    char line[MAX_WORD_LENGTH + 1];
    char* word;
    int i = 0;

    while (fgets(line, sizeof(line), file)!= NULL) {
        word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            if (strlen(word) <= MAX_WORD_LENGTH) {
                int isMisspelled = 1;
                for (int j = 0; j < numWords; j++) {
                    if (strcmp(dictionary[j].word, word) == 0) {
                        isMisspelled = 0;
                        break;
                    }
                }
                if (isMisspelled) {
                    printf("Possible misspelling: %s\n", word);
                }
            }
            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(file);
}

int main() {
    WordCount dictionary[MAX_WORD_LENGTH + 1];
    int numWords = 0;

    readDictionary(DICTIONARY_FILE, dictionary, &numWords);
    spellCheck("input.txt", dictionary, numWords);

    return 0;
}