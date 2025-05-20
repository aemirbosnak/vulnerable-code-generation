//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_COUNT 100

// Function to count the number of words in a string
int count_words(char *str) {
    int word_count = 0;
    char *p = str;
    while (*p != '\0') {
        if (*p == ' ' || *p == '\t') {
            word_count++;
        }
        p++;
    }
    return word_count;
}

// Function to generate a random word from a list of words
char *get_random_word(char *words[], int word_count) {
    int i = rand() % word_count;
    return words[i];
}

// Function to print a poem with a random word order
void print_poem(char *words[], int word_count) {
    int i, j;
    for (i = 0; i < word_count; i++) {
        char *word = get_random_word(words, word_count);
        for (j = 0; j < i; j++) {
            if (strcmp(words[j], word) < 0) {
                break;
            }
        }
        if (j == i) {
            printf("%s ", word);
        } else {
            printf("%s %s ", word, words[j]);
        }
    }
    printf("\n");
}

int main() {
    char words[MAX_WORD_COUNT][MAX_LINE_LENGTH];
    int word_count = 0;

    // Load the words from a file
    FILE *file = fopen("words.txt", "r");
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        word_count++;
        strcpy(words[word_count - 1], line);
    }
    fclose(file);

    // Generate a random word order
    srand(time(NULL));
    int i = rand() % word_count;
    char *word = get_random_word(words, word_count);

    // Print the poem
    print_poem(words, word_count);

    return 0;
}