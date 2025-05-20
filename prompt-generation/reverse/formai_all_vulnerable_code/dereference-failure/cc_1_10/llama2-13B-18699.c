//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORDS 50

// Function to split a line into words
char *split_line(char *line) {
    char *words[MAX_WORDS];
    char *token = strtok(line, " ");
    int i = 0;

    while (token != NULL && i < MAX_WORDS) {
        words[i++] = token;
        token = strtok(NULL, " ");
    }

    return words;
}

// Function to reverse a line
char *reverse_line(char *line) {
    char *rev = malloc(strlen(line) * sizeof(char));
    int i = strlen(line) - 1;

    while (i >= 0) {
        rev[i] = line[i];
        i--;
    }

    return rev;
}

int main() {
    // Read a poem from the user
    char poem[MAX_LINE_LENGTH];
    printf("Enter a poem: ");
    fgets(poem, MAX_LINE_LENGTH, stdin);

    // Split the poem into words
    char *words = split_line(poem);

    // Reverse each line of the poem
    char *reversed_poem = malloc(strlen(poem) * sizeof(char));
    int i = 0;

    for (int j = strlen(words) - 1; j >= 0; j--) {
        reversed_poem[i++] = words[j];
    }

    // Print the reversed poem
    printf("The reversed poem is: %s\n", reversed_poem);

    // Free memory
    free(words);
    free(reversed_poem);

    return 0;
}