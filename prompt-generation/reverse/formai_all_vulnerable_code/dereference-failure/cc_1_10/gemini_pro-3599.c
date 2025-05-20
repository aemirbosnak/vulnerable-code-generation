//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

Word dictionary[MAX_WORDS];
int dictionarySize = 0;

void loadDictionary() {
    FILE *dictFile = fopen("dictionary.txt", "r");
    if (dictFile == NULL) {
        printf("Error opening dictionary file.\n");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, dictFile) != NULL) {
        char *word = strtok(line, "\n");
        strcpy(dictionary[dictionarySize].word, word);
        dictionary[dictionarySize].count = 0;
        dictionarySize++;
    }

    fclose(dictFile);
}

int compareWords(const void *a, const void *b) {
    Word *word1 = (Word *)a;
    Word *word2 = (Word *)b;

    return strcmp(word1->word, word2->word);
}

void spellCheck(char *text) {
    char *word = strtok(text, " \n\t");
    while (word != NULL) {
        int found = 0;
        for (int i = 0; i < dictionarySize; i++) {
            if (strcmp(word, dictionary[i].word) == 0) {
                dictionary[i].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("%s is not in the dictionary.\n", word);
        }

        word = strtok(NULL, " \n\t");
    }
}

void printDictionary() {
    qsort(dictionary, dictionarySize, sizeof(Word), compareWords);

    for (int i = 0; i < dictionarySize; i++) {
        printf("%s: %d\n", dictionary[i].word, dictionary[i].count);
    }
}

int main() {
    loadDictionary();

    char text[] = "This is a sample text to be spell checked.";
    spellCheck(text);

    printDictionary();

    return 0;
}