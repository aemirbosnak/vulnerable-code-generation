//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1024

// Function to generate a random word
char *generate_random_word(void) {
    char word[50];
    srand(time(NULL));
    int i;

    for (i = 0; i < 50; i++) {
        word[i] = 'a' + (rand() % 26);
    }

    return word;
}

// Function to replace all occurrences of a word in a string
char *replace_word(char *string, char *word) {
    char *new_string = malloc(strlen(string) + 1);
    char *ptr = string;
    char *new_ptr = new_string;

    while (*ptr != '\0') {
        if (strcmp(ptr, word) == 0) {
            *new_ptr++ = '*';
            *new_ptr++ = ' ';
            ptr++;
        } else {
            *new_ptr++ = *ptr++;
        }
    }

    *new_ptr = '\0';

    return new_string;
}

int main(void) {
    char *string = "The quick brown fox jumps over the lazy dog.";
    char *word = generate_random_word();
    char *new_string = replace_word(string, word);

    printf("%s\n", new_string);

    free(new_string);
    free(word);

    return 0;
}