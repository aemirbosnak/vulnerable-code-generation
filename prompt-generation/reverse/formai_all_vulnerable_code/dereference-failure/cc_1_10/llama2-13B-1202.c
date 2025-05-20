//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 1024
#define MAX_WORDS 10

// Function to count the number of words in a given string
int word_count(const char *str) {
    int i, count = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\t') {
            count++;
        }
    }
    return count;
}

// Function to extract the first word from a given string
char *get_first_word(const char *str) {
    int i, len = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\t') {
            len = i + 1;
            break;
        }
    }
    return strndup(str, len);
}

// Function to extract the last word from a given string
char *get_last_word(const char *str) {
    int i, len = 0;
    for (i = strlen(str) - 1; i >= 0; i--) {
        if (str[i] == ' ' || str[i] == '\t') {
            len = i + 1;
            break;
        }
    }
    return strndup(str + len, strlen(str) - len);
}

int main() {
    char *str = "Hello, this is a sample text for demonstrating the word count and extraction functions.";
    int word_count_actual = word_count(str);
    char *first_word = get_first_word(str);
    char *last_word = get_last_word(str);

    printf("Word count: %d\n", word_count_actual);
    printf("First word: %s\n", first_word);
    printf("Last word: %s\n", last_word);

    free(first_word);
    free(last_word);

    return 0;
}