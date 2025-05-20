//FormAI DATASET v1.0 Category: Spell checking ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Define a constant for the maximum length of a word in the dictionary
#define MAX_WORD_LENGTH 50

// Define a constant for the maximum number of words in the dictionary
#define MAX_NUM_WORDS 10000

// Define a struct to represent a word in the dictionary
typedef struct {
    char word[MAX_WORD_LENGTH];
} DictWord;

// Define a global array to store the dictionary
DictWord dict[MAX_NUM_WORDS];

// Define a global variable to keep track of the number of words in the dictionary
int dictSize = 0;

// Function to read a dictionary file and store its contents in the global dictionary array
void readDictionary(char* filename) {
    // Open the dictionary file for reading
    FILE* dictFile = fopen(filename, "r");
    if (dictFile == NULL) {
        printf("Error: could not open dictionary file %s\n", filename);
        return;
    }

    // Read each line of the file and add its contents to the dictionary array
    char line[MAX_WORD_LENGTH + 1];
    while (fgets(line, sizeof(line), dictFile)) {
        // Remove the trailing newline character from the line
        line[strcspn(line, "\n")] = 0;

        // Store the line as a new word in the dictionary array
        strcpy(dict[dictSize].word, line);
        dictSize++;
    }

    // Close the dictionary file
    fclose(dictFile);
}

// Function to check if a given word is in the dictionary
int checkWord(char* word) {
    // Convert the word to lowercase
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }

    // Check if the word is in the dictionary
    for (int i = 0; i < dictSize; i++) {
        if (strcmp(dict[i].word, word) == 0) {
            return 1;
        }
    }

    // If the word is not found in the dictionary, return 0
    return 0;
}

// Function to tokenize a given string into words and print each word along with its spelling status
void spellCheck(char* str) {
    // Tokenize the input string into words
    char* word = strtok(str, " ");
    while (word != NULL) {
        // Remove any punctuation from the beginning and end of the word
        while (ispunct(word[0])) {
            memmove(word, word+1, strlen(word));
        }
        while (ispunct(word[strlen(word)-1])) {
            word[strlen(word)-1] = '\0';
        }

        // Check if the word is in the dictionary
        int isSpelledCorrectly = checkWord(word);

        // Print the word and its spelling status
        printf("%s: ", word);
        if (isSpelledCorrectly) {
            printf("correctly spelled\n");
        } else {
            printf("misspelled\n");
        }

        // Get the next word in the input string
        word = strtok(NULL, " ");
    }
}

int main() {
    // Read the dictionary file and store its contents in the global dictionary array
    readDictionary("dictionary.txt");

    // Prompt the user to enter a string to be spell-checked
    printf("Enter a string to be spell-checked:\n");
    char input[1000];
    fgets(input, sizeof(input), stdin);

    // Call the spellCheck function to tokenize and spell-check the input string
    spellCheck(input);

    return 0;
}