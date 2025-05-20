//FormAI DATASET v1.0 Category: Spell checking ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void check_spellings(char *word);

int main()
{
    char *input_word = (char*) malloc(100 * sizeof(char));
    printf("Enter a word to check if it is spelled correctly: ");
    scanf("%s", input_word);
    check_spellings(input_word);
    free(input_word);
    return 0;
}

void check_spellings(char *word)
{
    char *dictionary[] = {
        "apple",
        "banana",
        "cherry",
        "grape",
        "orange",
        "peach",
        "pear",
        "pineapple",
        "plum",
        "strawberry"
    };
    int num_words = 10; // number of words in dictionary
    
    for(int i=0; i<num_words; i++) {
        if(strcmp(word, dictionary[i]) == 0) {
            printf("%s is spelled correctly!\n", word);
            return;
        }
    }

    // if word is not found in dictionary, attempt to suggest corrections
    int word_len = strlen(word);
    printf("Could not find %s in dictionary!\nSuggestions: \n", word);
    
    // Attempt 1: add one character
    for(int i=0; i<word_len; i++) {
        char *new_word = (char*) calloc((word_len+2), sizeof(char));
        strncpy(new_word, word, i);
        new_word[i] = '_'; // underscore represents a newly inserted character
        strncpy(&new_word[i+1], &word[i], word_len-i);
        for(int j=0; j<num_words; j++) {
            if(strncmp(new_word, dictionary[j], word_len+1) == 0) {
                printf("%s\n", dictionary[j]);
            }
        }
        free(new_word);
    }
    
    // Attempt 2: remove one character
    for(int i=0; i<word_len; i++) {
        char *new_word = (char*) calloc(word_len, sizeof(char));
        strncpy(new_word, word, i);
        strncpy(&new_word[i], &word[i+1], word_len-i-1);
        for(int j=0; j<num_words; j++) {
            if(strcmp(new_word, dictionary[j]) == 0) {
                printf("%s\n", dictionary[j]);
            }
        }
        free(new_word);
    }

    // Attempt 3: replace one character
    for(int i=0; i<word_len; i++) {
        for(char c='a'; c<='z'; c++) {
            if(c == word[i]) continue;
            char *new_word = (char*) calloc(word_len, sizeof(char));
            strncpy(new_word, word, i);
            new_word[i] = c;
            strncpy(&new_word[i+1], &word[i+1], word_len-i-1);
            for(int j=0; j<num_words; j++) {
                if(strcmp(new_word, dictionary[j]) == 0) {
                    printf("%s\n", dictionary[j]);
                }
            }
            free(new_word);
        }
    }

    // Attempt 4: transpose two adjacent characters
    for(int i=0; i<word_len-1; i++) {
        char *new_word = (char*) calloc(word_len, sizeof(char));
        strncpy(new_word, word, i);
        new_word[i] = word[i+1];
        new_word[i+1] = word[i];
        strncpy(&new_word[i+2], &word[i+2], word_len-i-2);
        for(int j=0; j<num_words; j++) {
            if(strcmp(new_word, dictionary[j]) == 0) {
                printf("%s\n", dictionary[j]);
            }
        }
        free(new_word);
    }
}