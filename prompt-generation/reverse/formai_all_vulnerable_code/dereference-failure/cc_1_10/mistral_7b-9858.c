//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DICTIONARY_FILE "dictionary.txt"
#define LINE_SIZE 100

typedef struct {
    char word[LINE_SIZE];
} DictionaryEntry;

int main(void) {
    FILE *dictionaryFile;
    DictionaryEntry *dictionary;
    int numEntries = 0;
    char userWord[LINE_SIZE];
    int i;

    dictionaryFile = fopen(DICTIONARY_FILE, "r");
    if (dictionaryFile == NULL) {
        fprintf(stderr, "Could not open dictionary file.\n");
        return 1;
    }

    dictionary = malloc(sizeof(DictionaryEntry));
    if (dictionary == NULL) {
        fprintf(stderr, "Could not allocate memory for dictionary.\n");
        fclose(dictionaryFile);
        return 1;
    }

    while (fgets(dictionary[numEntries].word, LINE_SIZE, dictionaryFile) != NULL) {
        numEntries++;
        if (numEntries >= 1000) {
            DictionaryEntry *newDictionary;
            newDictionary = realloc(dictionary, (numEntries + 1) * sizeof(DictionaryEntry));
            if (newDictionary == NULL) {
                fprintf(stderr, "Could not reallocate memory for dictionary.\n");
                free(dictionary);
                fclose(dictionaryFile);
                return 1;
            }
            dictionary = newDictionary;
        }
    }

    fclose(dictionaryFile);

    printf("Enter a word to check the spelling of, Dr. Watson: ");
    scanf("%s", userWord);

    if (ConsultingTheDictionary(userWord, dictionary, numEntries)) {
        printf("The word '%s' is in the dictionary, Dr. Watson.\n", userWord);
    } else {
        printf("The word '%s' is not in the dictionary, Dr. Watson. Perhaps it is a new and exotic word, or a typo?\n", userWord);
    }

    free(dictionary);

    return 0;
}

int ConsultingTheDictionary(char *word, DictionaryEntry *dictionary, int numEntries) {
    int i;

    for (i = 0; i < numEntries; i++) {
        if (strcasecmp(dictionary[i].word, word) == 0) {
            return 1;
        }
    }

    return 0;
}