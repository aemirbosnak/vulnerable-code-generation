//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define STOP_WORD "STOP"

#define MAX_WORD_LEN 50
#define MAX_WORDS 1000

int compare(const void *a, const void *b);

int main(int argc, char *argv[]) {
    char word[MAX_WORD_LEN];
    int word_count[MAX_WORDS] = {0};
    char *words[MAX_WORDS];
    int num_words = 0;
    
    printf("Enter words, one at a time, followed by the word 'STOP':\n");
    
    // Read in words until STOP is entered
    while (1) {
        scanf("%s", word);
        
        // Convert word to lowercase
        int len = strlen(word);
        for (int i = 0; i < len; i++) {
            word[i] = tolower(word[i]);
        }
        
        if (strcmp(word, STOP_WORD) == 0) {
            break;
        }
        
        // Check if word is already in words array
        int found_word = 0;
        for (int i = 0; i < num_words; i++) {
            if (strcmp(word, words[i]) == 0) {
                word_count[i]++;
                found_word = 1;
                break;
            }
        }
        
        // Add new word to words array if it hasn't already been found
        if (!found_word) {
            if (num_words >= MAX_WORDS) {
                printf("Maximum number of words reached. Exiting.\n");
                exit(1);
            }
            
            words[num_words] = malloc((len + 1) * sizeof(char));
            strcpy(words[num_words], word);
            word_count[num_words]++;
            num_words++;
        }
    }
    
    qsort(words, num_words, sizeof(char *), compare);
    
    printf("Word\t\tFrequency\n");
    for (int i = 0; i < num_words; i++) {
        printf("%-15s%d\n", words[i], word_count[i]);
        free(words[i]);
    }
    
    return 0;
}

int compare(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}