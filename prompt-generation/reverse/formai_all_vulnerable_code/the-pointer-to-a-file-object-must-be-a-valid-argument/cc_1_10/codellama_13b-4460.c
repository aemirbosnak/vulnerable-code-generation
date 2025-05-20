//Code Llama-13B DATASET v1.0 Category: Spell checking ; Style: happy
// C Spell Checking Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the words and their counts
struct WordCount {
    char word[20];
    int count;
};

// Function to read the text file and store the words in an array
void read_file(char* filename, struct WordCount* word_counts, int* word_count) {
    FILE* fp = fopen(filename, "r");
    char line[200];
    int i = 0;

    while (fgets(line, sizeof(line), fp) != NULL) {
        char* word = strtok(line, " ");
        while (word != NULL) {
            strcpy(word_counts[i].word, word);
            word_counts[i].count = 1;
            i++;
            word = strtok(NULL, " ");
        }
    }

    *word_count = i;
}

// Function to check the spelling of a word
int check_spelling(char* word, struct WordCount* word_counts, int word_count) {
    for (int i = 0; i < word_count; i++) {
        if (strcmp(word_counts[i].word, word) == 0) {
            return word_counts[i].count;
        }
    }

    return -1;
}

// Function to print the words with their counts
void print_words(struct WordCount* word_counts, int word_count) {
    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Initialize the word_counts array
    struct WordCount word_counts[1000];
    int word_count = 0;

    // Read the text file and store the words in the word_counts array
    read_file(argv[1], word_counts, &word_count);

    // Check the spelling of the words
    for (int i = 0; i < word_count; i++) {
        int count = check_spelling(word_counts[i].word, word_counts, word_count);
        if (count > 1) {
            printf("%s: %d\n", word_counts[i].word, count);
        }
    }

    // Print the words with their counts
    print_words(word_counts, word_count);

    return 0;
}