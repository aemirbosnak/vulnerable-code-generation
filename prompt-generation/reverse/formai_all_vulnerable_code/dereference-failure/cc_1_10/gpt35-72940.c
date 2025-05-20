//FormAI DATASET v1.0 Category: Spell checking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is a letter or not
int isLetter(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    return 0; 
}

// Function to convert a word to lowercase
void toLowercase(char* str) {
    int i;
    for (i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to check if a word is spelled correctly
int checkSpelling(char* word, char** dictionary, int dictSize) {
    int i;
    char* lowercase = (char*) malloc(strlen(word) + 1);   // Create a new string to store the lowercase word
    strcpy(lowercase, word);
    toLowercase(lowercase); // Convert the word to lowercase
    for (i = 0; i < dictSize; i++) {
        if (strcmp(dictionary[i], lowercase) == 0) {     // If the lowercase word is found in the dictionary
            free(lowercase);    // Free the memory allocated for the lowercase word
            return 1;
        }
    }
    free(lowercase);    // Free the memory allocated for the lowercase word
    return 0;
}

int main() {
    char** dictionary = (char**) malloc(2000 * sizeof(char*)); // Create an array of strings to hold the dictionary
    int dictSize = 0;   // Keep track of the number of words in the dictionary
    FILE* dictFile = fopen("dictionary.txt", "r"); // Open the dictionary file
    if (dictFile == NULL) {
        printf("Error: Could not open dictionary file.\n");
        return 1;   // Exit with error code 1
    }
    char buffer[100];
    while (fgets(buffer, 100, dictFile)) {   // Read the dictionary file line by line
        buffer[strlen(buffer) - 1] = '\0';  // Remove the newline character from the end of each line
        dictionary[dictSize] = (char*) malloc(strlen(buffer) + 1);  // Allocate memory for each word in the dictionary
        strcpy(dictionary[dictSize], buffer);
        dictSize++;
    }
    fclose(dictFile);   // Close the dictionary file
    printf("Dictionary loaded with %d words.\n", dictSize);
    char input[1000];
    printf("Enter a sentence to check the spelling: ");
    fgets(input, 1000, stdin);  // Read the user input
    input[strlen(input) - 1] = '\0';    // Remove the newline character from the end of the input
    int i, j;
    int wordStart = -1;
    int wordEnd = -1;
    for (i = 0; input[i]; i++) {
        if (isLetter(input[i])) {  // If the character is a letter
            if (wordStart == -1)    // If we are starting a new word
                wordStart = i;
            wordEnd = i;
        } else {    // If the character is not a letter
            if (wordStart != -1) {  // If we just ended a word
                char* word = (char*) malloc((wordEnd - wordStart + 2) * sizeof(char));    // Allocate memory for the word
                for (j = wordStart; j <= wordEnd; j++)    // Copy the word from the input string to the word variable
                    word[j - wordStart] = input[j];
                word[j - wordStart] = '\0'; // Add the null character to the end of the word
                if (!checkSpelling(word, dictionary, dictSize))
                    printf("Spelling error: %s\n", word); // Print out any spelling errors
                free(word);    // Free the memory allocated for the word
                wordStart = -1;
                wordEnd = -1;
            }
        }
    }
    if (wordStart != -1) {  // If there is still a word left in the input string
        char* word = (char*) malloc((wordEnd - wordStart + 2) * sizeof(char));    // Allocate memory for the word
        for (j = wordStart; j <= wordEnd; j++)    // Copy the word from the input string to the word variable
            word[j - wordStart] = input[j];
        word[j - wordStart] = '\0'; // Add the null character to the end of the word
        if (!checkSpelling(word, dictionary, dictSize))
            printf("Spelling error: %s\n", word); // Print out any spelling errors
        free(word);    // Free the memory allocated for the word
    }
    for (i = 0; i < dictSize; i++) {
        free(dictionary[i]);    // Free the memory allocated for each word in the dictionary
    }
    free(dictionary);   // Free the memory allocated for the dictionary
    return 0;   // Exit with success code 0
}