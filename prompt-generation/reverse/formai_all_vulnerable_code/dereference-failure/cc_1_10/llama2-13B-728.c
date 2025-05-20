//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 32

// Function to count the number of words in a given string
int count_words(char *str) {
    int word_count = 0;
    char *token;

    while ((token = strtok(str, " ")) != NULL) {
        word_count++;
    }

    return word_count;
}

// Function to remove duplicate words from a given string
char *remove_duplicates(char *str) {
    char *new_str = NULL;
    char *token;
    int word_count = 0;

    // Create a new string without duplicates
    for (token = strtok(str, " "); token != NULL; token = strtok(NULL, " ")) {
        if (word_count == 0 || strcmp(token, new_str) != 0) {
            if (word_count > 0) {
                new_str[word_count - 1] = '\0';
            }
            new_str = realloc(new_str, strlen(new_str) + strlen(token) + 1);
            strcat(new_str, token);
            word_count++;
        }
    }

    return new_str;
}

int main() {
    char *input = "Hello World! How are you? I am fine, thank you. I love to code!";
    char *output = remove_duplicates(input);
    printf("Output: %s\n", output);

    free(output);

    return 0;
}