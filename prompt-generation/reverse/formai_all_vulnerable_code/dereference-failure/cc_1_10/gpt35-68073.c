//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: relaxed
/*
Welcome to the C Word Frequency Counter program!
In this program, we will be reading in a file and counting the frequency of each word.
We will then output the word count to a new file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

// Struct to hold word count and word
typedef struct WordCount {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

// Function to read in the file and count the words
void read_and_count(FILE *file, WordCount *word_count, int *num_words) {
    char ch;
    char word[MAX_WORD_LENGTH];
    int word_count_index = 0;
    int word_index = 0;
    int i;

    // Read through the file character by character
    while ((ch = fgetc(file)) != EOF) {
        // If the character is alphanumeric, add it to the word
        if (isalnum(ch)) {
            word[word_index++] = tolower(ch);
        }
        // Otherwise, we've hit the end of a word
        else {
            // Terminate the word string
            word[word_index] = '\0';
            
            // If the word has non-zero length, add it to the word count
            if (word_index > 0) {
                int word_found = 0;
                // Search through the word count to see if this word has already been counted
                for (i = 0; i < word_count_index; i++) {
                    if (strcmp(word_count[i].word, word) == 0) {
                        word_count[i].count++;
                        word_found = 1;
                        break;
                    }
                }
                // If the word wasn't found, add it to the word count
                if (!word_found) {
                    strcpy(word_count[word_count_index].word, word);
                    word_count[word_count_index].count = 1;
                    word_count_index++;
                }
                (*num_words)++;
            }
            // Reset the word string
            word_index = 0;
        }
    }
}

// Function to sort the word count by frequency
void sort_word_count(WordCount *word_count, int num_words) {
    int i, j;
    WordCount temp;

    for (i = 0; i < num_words - 1; i++) {
        for (j = 0; j < num_words - i - 1; j++) {
            if (word_count[j].count < word_count[j+1].count) {
                temp = word_count[j];
                word_count[j] = word_count[j+1];
                word_count[j+1] = temp;
            }
        }
    }
}

// Function to output the word count to a file
void output_word_count(FILE *out_file, WordCount *word_count, int num_words) {
    int i;

    for (i = 0; i < num_words; i++) {
        fprintf(out_file, "%-20s%d\n", word_count[i].word, word_count[i].count);
    }
}

int main() {
    FILE *in_file, *out_file;
    WordCount word_count[1000];
    int num_words = 0;
    
    // Open the files
    in_file = fopen("input.txt", "r");
    out_file = fopen("output.txt", "w");
    
    // If either file couldn't be opened, exit
    if (in_file == NULL || out_file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    
    // Read in the file and count the words
    read_and_count(in_file, word_count, &num_words);
    
    // Sort the word count by frequency
    sort_word_count(word_count, num_words);
    
    // Output the word count to a file
    output_word_count(out_file, word_count, num_words);
    
    // Close the files
    fclose(in_file);
    fclose(out_file);
    
    // Done!
    printf("Word count successfully generated!\n");
    return 0;
}