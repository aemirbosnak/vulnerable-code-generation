//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a word in the text
typedef struct {
    char* word;
    int count;
} Word;

// Define a function to compare two words
int compareWords(const void* a, const void* b) {
    Word* word1 = (Word*)a;
    Word* word2 = (Word*)b;
    return strcmp(word1->word, word2->word);
}

// Define a function to count the number of occurrences of each word in the text
int countWords(char* text, Word* words, int* numWords) {
    char* token;
    char* tempText = malloc(strlen(text) + 1);
    strcpy(tempText, text);

    // Tokenize the text into words
    token = strtok(tempText, " ,.-:;?!");
    while (token != NULL) {
        // Check if the word is already in the list of words
        int found = 0;
        for (int i = 0; i < *numWords; i++) {
            if (strcmp(token, words[i].word) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }

        // If the word is not in the list, add it to the list
        if (!found) {
            words[*numWords].word = malloc(strlen(token) + 1);
            strcpy(words[*numWords].word, token);
            words[*numWords].count = 1;
            (*numWords)++;
        }

        // Get the next token
        token = strtok(NULL, " ,.-:;?!");
    }

    free(tempText);

    return *numWords;
}

// Define a function to print the words and their counts
void printWords(Word* words, int numWords) {
    // Sort the words by their counts
    qsort(words, numWords, sizeof(Word), compareWords);

    // Print the words and their counts
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    // Get the text from the user
    char* text = malloc(1000);
    printf("Enter the text: ");
    gets(text);

    // Create an array of words to store the words in the text
    Word* words = malloc(1000 * sizeof(Word));

    // Initialize the number of words to 0
    int numWords = 0;

    // Count the number of occurrences of each word in the text
    numWords = countWords(text, words, &numWords);

    // Print the words and their counts
    printWords(words, numWords);

    // Free the memory allocated to the words
    for (int i = 0; i < numWords; i++) {
        free(words[i].word);
    }
    free(words);
    free(text);

    return 0;
}