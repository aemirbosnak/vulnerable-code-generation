//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 1024

// Function to generate a random word
char *generate_random_word(void) {
    char *word = malloc(sizeof(char) * MAX_LENGTH);
    srand(time(NULL));
    for (int i = 0; i < MAX_LENGTH; i++) {
        word[i] = 'a' + (rand() % 26);
    }
    return word;
}

// Function to replace all occurrences of a word in a string
char *replace_word(char *str, char *old_word, char *new_word) {
    char *new_str = malloc(sizeof(char) * strlen(str) + 1);
    int i = 0;
    for (; str[i] != '\0'; i++) {
        if (strcmp(str + i, old_word) == 0) {
            new_str[i] = new_word[0];
        } else {
            new_str[i] = str[i];
        }
    }
    return new_str;
}

int main() {
    char *str = "The quick brown fox jumps over the lazy dog";
    char *old_word = "brown";
    char *new_word = "golden";

    // Generate a random word to replace old_word with
    char *random_word = generate_random_word();

    // Replace all occurrences of old_word with new_word
    char *replaced_str = replace_word(str, old_word, new_word);

    // Print the replaced string
    printf("%s\n", replaced_str);

    // Free memory
    free(replaced_str);
    free(random_word);

    return 0;
}