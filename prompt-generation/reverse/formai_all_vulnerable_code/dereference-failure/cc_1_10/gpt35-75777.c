//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50

typedef struct word_count {
    char *word;
    int count;
} word_count;

int cmpfunc(const void *a, const void *b) {
    word_count *word1 = (word_count *)a;
    word_count *word2 = (word_count *)b;
    return -1 * (word1->count - word2->count);
}

int main() {
    // Initialize word count array
    int num_words = 0;
    word_count *word_array = malloc(sizeof(word_count));
    
    // File input
    printf("Enter file name: ");
    char file_name[50];
    scanf("%s", file_name);
    
    FILE *file_input = fopen(file_name, "r");
    
    // Check if file exists
    if (!file_input) {
        printf("File not found");
        return 0;
    }
    
    // File parsing
    char curr_char;
    char curr_word[MAX_WORD_LENGTH];
    int word_length = 0;
    
    while ((curr_char = fgetc(file_input)) != EOF) {
        // If character is not a letter, end current word
        if ((!isalpha(curr_char)) && word_length > 0) {
            // Add the word to the array
            curr_word[word_length] = '\0';
            
            // Check if word already exists in array
            int found_word = 0;
            for (int i = 0; i < num_words; i++) {
                if (strcmp(word_array[i].word, curr_word) == 0) {
                    word_array[i].count++;
                    found_word = 1;
                    break;
                }
            }
            
            // If word does not exist, add it to the array
            if (!found_word) {
                num_words++;
                word_array = realloc(word_array, num_words * sizeof(word_count));
                word_array[num_words - 1].word = malloc(word_length + 1);
                strncpy(word_array[num_words - 1].word, curr_word, word_length + 1);
                word_array[num_words - 1].count = 1;
            }
            
            // Reset word length
            word_length = 0;
        }
        
        // If character is a letter, add it to current word
        else if (isalpha(curr_char)) {
            curr_word[word_length++] = tolower(curr_char);
            // If word length is too long, reset length to 0
            if (word_length > MAX_WORD_LENGTH) {
                word_length = 0;
            }
        }
    }
    
    // Close file
    fclose(file_input);
    
    // Print sorted word count array
    qsort(word_array, num_words, sizeof(word_count), cmpfunc);
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_array[i].word, word_array[i].count);
    }
    
    // Free memory
    for (int i = 0; i < num_words; i++) {
        free(word_array[i].word);
    }
    free(word_array);
    
    return 0;
}