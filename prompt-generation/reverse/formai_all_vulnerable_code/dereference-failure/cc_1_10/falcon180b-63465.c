//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: complex
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 5000
#define MAX_WORD_LENGTH 20
#define MAX_DICTIONARY_WORDS 10000

// Function to load dictionary into memory
void loadDictionary(char *filename, char *dictionary[]) {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    int i = 0;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        strcpy(dictionary[i], line);
        i++;
    }
    fclose(file);
}

// Function to check if a word is in the dictionary
int isWord(char *word, char *dictionary[]) {
    int i, j;
    for (i = 0; i < MAX_DICTIONARY_WORDS; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to spell check a sentence
void spellCheck(char *sentence) {
    char *word;
    char *dictionary[MAX_DICTIONARY_WORDS];
    loadDictionary("dictionary.txt", dictionary);
    word = strtok(sentence, " ");
    while (word!= NULL) {
        if (!isWord(word, dictionary)) {
            printf("Possible spelling mistake: %s\n", word);
        }
        word = strtok(NULL, " ");
    }
}

// Main function
int main() {
    char sentence[MAX_WORDS];
    printf("Enter a sentence to spell check:\n");
    fgets(sentence, MAX_WORDS, stdin);
    spellCheck(sentence);
    return 0;
}