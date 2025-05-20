//Falcon2-11B DATASET v1.0 Category: Spell checking ; Style: genius
#include <stdio.h>
#include <string.h>

// Function to check if a word is spelled correctly
int isSpelledCorrectly(const char* word) {
    // Check if the word is empty or null
    if (word == NULL || strlen(word) == 0) {
        return 0;
    }
    
    // Convert the word to lowercase
    int length = strlen(word);
    char* lowercaseWord = (char*)malloc(length * sizeof(char));
    for (int i = 0; i < length; i++) {
        lowercaseWord[i] = tolower(word[i]);
    }
    
    // Check if the word is in the dictionary
    char* dictionary[100];
    int dictionarySize = 0;
    FILE* dictionaryFile = fopen("dictionary.txt", "r");
    if (dictionaryFile == NULL) {
        printf("Error opening dictionary file\n");
        return 0;
    }
    char line[100];
    while (fgets(line, sizeof(line), dictionaryFile)!= NULL) {
        dictionary[dictionarySize] = strdup(line);
        dictionarySize++;
    }
    fclose(dictionaryFile);
    
    // Check if the word is in the dictionary
    for (int i = 0; i < dictionarySize; i++) {
        if (strcmp(dictionary[i], lowercaseWord) == 0) {
            return 1;
        }
    }
    
    return 0;
}

int main() {
    char word[100];
    printf("Enter a word: ");
    fgets(word, sizeof(word), stdin);
    word[strcspn(word, "\n")] = '\0'; // Remove newline character
    
    if (isSpelledCorrectly(word)) {
        printf("The word is spelled correctly.\n");
    } else {
        printf("The word is not spelled correctly.\n");
    }
    
    return 0;
}