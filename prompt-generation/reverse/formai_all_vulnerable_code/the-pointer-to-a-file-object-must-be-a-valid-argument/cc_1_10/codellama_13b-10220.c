//Code Llama-13B DATASET v1.0 Category: Word Count Tool ; Style: active
// C Word Count Tool Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold a word and its count
struct word_count {
    char word[100];
    int count;
};

// Define an array to hold the words and their counts
struct word_count words[100];

// Define a function to count the words in a file
void count_words(char* filename) {
    // Open the file and read its contents
    FILE* fp = fopen(filename, "r");
    char line[100];
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Split the line into words
        char* word = strtok(line, " ");
        while (word != NULL) {
            // Increment the count for each word
            int i = 0;
            while (words[i].word[0] != '\0') {
                if (strcmp(words[i].word, word) == 0) {
                    words[i].count++;
                    break;
                }
                i++;
            }
            // Add the word to the array if it doesn't already exist
            if (words[i].word[0] == '\0') {
                strcpy(words[i].word, word);
                words[i].count = 1;
            }
            word = strtok(NULL, " ");
        }
    }
    fclose(fp);
}

// Define a function to print the words and their counts
void print_words() {
    // Print the words and their counts
    int i = 0;
    while (words[i].word[0] != '\0') {
        printf("%s: %d\n", words[i].word, words[i].count);
        i++;
    }
}

int main() {
    // Count the words in the file
    count_words("example.txt");

    // Print the words and their counts
    print_words();

    return 0;
}