//FormAI DATASET v1.0 Category: Spell checking ; Style: safe
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to remove leading and trailing whitespaces
void trim(char * str) {
    int i = 0, j = strlen(str) - 1;
    
    // Remove leading whitespaces
    while(isspace(str[i])) {
        i++;
    }
    
    // Remove trailing whitespaces
    while(isspace(str[j])) {
        j--;
    }
    
    // Shift characters to left to remove the space
    int k = 0;
    for(int p = i; p <= j; p++) {
        str[k++] = str[p];
    }
    str[k] = '\0';
}

// Function to check if a word is spelled correctly
int spellCheck(char * word, char * dictionary[]) {
    // Check if word is in the dictionary
    for(int i = 0; i < 10; i++) {
        if(strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to print spelling suggestions for a misspelled word
void printSuggestions(char * word, char * dictionary[]) {
    printf("Did you mean: ");
    
    // Check for one letter difference
    for(int i = 0; i < 10; i++) {
        int diff = 0;
        for(int j = 0; j < strlen(word); j++) {
            if(word[j] != dictionary[i][j]) {
                diff++;
            }
        }
        if(diff == 1) {
            printf("%s, ", dictionary[i]);
        }
    }
    
    // Check for two letter difference
    for(int i = 0; i < 10; i++) {
        int diff = 0;
        for(int j = 0; j < strlen(word); j++) {
            if(word[j] != dictionary[i][j]) {
                diff++;
            }
        }
        if(diff == 2) {
            printf("%s, ", dictionary[i]);
        }
    }
    printf("\n");
}

int main() {
    char * dictionary[] = {"apple", "banana", "orange", "mango", "kiwi", "grape", "peach", "plum", "pear", "lemon"};
    char input[100];
    
    printf("Enter text: ");
    fgets(input, 100, stdin);
    trim(input);
    
    // Loop through each word in the input
    char * word = strtok(input, " ");
    while(word != NULL) {
        // Remove punctuation
        for(int i = 0; i < strlen(word); i++) {
            if(ispunct(word[i])) {
                memmove(&word[i], &word[i + 1], strlen(word) - i);
            }
        }
        
        // Check spelling
        if(!spellCheck(word, dictionary)) {
            printf("'%s' is misspelled.\n", word);
            printSuggestions(word, dictionary);
        }
        
        word = strtok(NULL, " ");
    }
    
    return 0;
}