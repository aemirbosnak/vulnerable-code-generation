//FormAI DATASET v1.0 Category: Spell checking ; Style: Ada Lovelace
/* A Spell checking program in Ada Lovelace style */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is alphabetical
int is_alpha(char c) {
    return isalpha(c);
}

// Function to remove punctuation from a string
void remove_punctuation(char *string) {
    int len = strlen(string);
    for(int i = 0; i < len; i++) {
        if(is_alpha(string[i]) || isspace(string[i])) {
            continue;
        }
        else {
            for(int j = i; j < len; j++) {
                string[j] = string[j+1];
            }
            len--;
        }
    }
}

// Function to convert a string to lowercase
void to_lowercase(char *word) {
    int len = strlen(word);
    for(int i = 0; i < len; i++) {
        word[i] = tolower(word[i]);
    }
}

// Function to check if a word is spelled correctly
int is_spelled_correctly(char *word, char **dictionary, int dict_size) {
    to_lowercase(word);
    remove_punctuation(word);
    for(int i = 0; i < dict_size; i++) {
        if(strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Main function
int main() {
    char **dictionary = {"hello", "world", "how", "are", "you"};
    int dict_size = 5;
    char input[100];
    printf("Enter a sentence: ");
    fgets(input, 100, stdin);
    char *word = strtok(input, " ");
    while(word != NULL) {
        if(!is_spelled_correctly(word, dictionary, dict_size)) {
            printf("%s is misspelled!\n", word);
        }
        word = strtok(NULL, " ");
    }
    return 0;
}