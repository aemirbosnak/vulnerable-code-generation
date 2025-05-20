//FormAI DATASET v1.0 Category: Spell checking ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICTIONARY_SIZE 1000

void toLowerCase(char* word) {
    int i;
    for (i = 0; word[i]; i++){
        word[i] = tolower(word[i]);
    }
}

int spellCheck(char* word, char** dictionary, int dictionarySize){
    int i;
    for (i = 0; i < dictionarySize; i++){
        if (strcmp(word, dictionary[i]) == 0){
            return 1;
        }
    }
    return 0;
}

int main() {
    // Read dictionary file
    char* filename = "dictionary.txt";
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        exit(1);
    }

    char* dictionary[MAX_DICTIONARY_SIZE];
    int dictionarySize = 0;

    char line[MAX_WORD_LENGTH + 1];
    while (fgets(line, sizeof(line), file)) {
        // Remove newline character
        line[strcspn(line, "\n")] = 0;
        dictionary[dictionarySize] = malloc(sizeof(line));
        strcpy(dictionary[dictionarySize], line);

        dictionarySize++;
    }
    
    fclose(file);

    // Read text file to spell check
    char* textFilename = "text.txt";
    FILE* textFile = fopen(textFilename, "r");
    if (textFile == NULL) {
        printf("Could not open file %s\n", textFilename);
        exit(1);
    }

    char text[MAX_WORD_LENGTH + 1];
    while (fscanf(textFile, "%s", text) != EOF) {
        // Convert word to lowercase
        toLowerCase(text);
        // Check if word is in dictionary
        if (!spellCheck(text, dictionary, dictionarySize)) {
            printf("Misspelled word: %s\n", text);
        }
    }

    fclose(textFile);

    // Free dictionary memory
    int i;
    for (i = 0; i < dictionarySize; i++) {
        free(dictionary[i]);
    }

    return 0;
}