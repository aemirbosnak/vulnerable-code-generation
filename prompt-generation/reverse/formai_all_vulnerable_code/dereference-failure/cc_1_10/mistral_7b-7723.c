//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DICTIONARY_SIZE 1000

// Function to convert string to lowercase
void toLowerCase(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to check if a word is present in the dictionary
int isWordPresent(char* dictionary[], char* word) {
    int index;
    for (index = 0; index < DICTIONARY_SIZE; index++) {
        if (strcmp(dictionary[index], word) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a character is alphabet
int isAlphabet(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Function to check if a given word is valid
int isValidWord(char* word) {
    int i;
    toLowerCase(word);
    for (i = 0; word[i] != '\0'; i++) {
        if (!isAlphabet(word[i])) {
            return 0;
        }
    }
    return 1;
}

// Main function
int main() {
    char* dictionary[DICTIONARY_SIZE];
    int index = 0;
    int wordLength;
    char word[50];

    // Load dictionary into an array
    FILE* fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Unable to open dictionary file.\n");
        return 1;
    }

    while (fscanf(fp, "%s", word) != EOF) {
        dictionary[index] = (char*) malloc(strlen(word) + 1);
        strcpy(dictionary[index], word);
        index++;
    }

    fclose(fp);

    while (1) {
        printf("Enter a word: ");
        scanf("%s", word);

        wordLength = strlen(word);

        if (isValidWord(word) == 0) {
            printf("Invalid word. Please enter alphabets only.\n");
            continue;
        }

        if (isWordPresent(dictionary, word) == 1) {
            printf("Word '%s' is present in the dictionary.\n", word);
        } else {
            printf("Word '%s' is not present in the dictionary.\n", word);
        }
    }

    // Free memory allocated to dictionary array
    for (int i = 0; i < index; i++) {
        free(dictionary[i]);
    }

    return 0;
}