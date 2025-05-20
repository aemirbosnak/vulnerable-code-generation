//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 50

// Define a structure to store words
typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} Word;

// Function to compare two strings (case insensitive)
int strcasecmp(const char *str1, const char *str2) {
    int result = 0;
    
    while (*str1!= '\0' && *str2!= '\0') {
        if (tolower(*str1)!= tolower(*str2)) {
            result = tolower(*str1) - tolower(*str2);
            break;
        }
        str1++;
        str2++;
    }
    
    return result;
}

// Function to load words from a file into an array
void load_words(Word *words, const char *filename) {
    FILE *file = fopen(filename, "r");
    char word[MAX_WORD_LENGTH];
    int count = 0;
    
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }
    
    while (fscanf(file, "%s", word) == 1) {
        strcpy(words[count].word, word);
        words[count].is_correct = true;
        count++;
        
        if (count >= MAX_WORDS) {
            printf("Error: too many words in file '%s'\n", filename);
            exit(1);
        }
    }
    
    fclose(file);
}

// Function to check if a word is spelled correctly
bool is_correct_spelling(const char *word) {
    Word *words = malloc(MAX_WORDS * sizeof(Word));
    int count = 0;
    bool is_correct = false;
    
    // Load words from file
    load_words(words, "words.txt");
    
    // Check if word exists in array
    for (int i = 0; i < count; i++) {
        if (strcasecmp(word, words[i].word) == 0) {
            is_correct = words[i].is_correct;
            break;
        }
    }
    
    // Free memory
    free(words);
    
    return is_correct;
}

int main() {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
    
    // Prompt user for input
    printf("Enter a word to check its spelling: ");
    scanf("%s", word);
    
    // Check if word is spelled correctly
    is_correct = is_correct_spelling(word);
    
    // Print result
    if (is_correct) {
        printf("%s is spelled correctly.\n", word);
    } else {
        printf("%s is spelled incorrectly.\n", word);
    }
    
    return 0;
}