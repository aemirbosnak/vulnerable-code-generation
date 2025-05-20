//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: brave
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Define a function to remove all punctuation from a string
char *remove_punctuation(char *str) {
    size_t len = strlen(str);
    char *new_str = malloc(len + 1);
    int i, j;

    for (i = 0, j = 0; i < len; i++) {
        if (str[i] < 33 || str[i] > 126) {
            continue;
        }
        new_str[j++] = str[i];
    }
    new_str[j] = '\0';

    return new_str;
}

// Define a function to count the number of words in a string
int count_words(char *str) {
    int count = 0;
    int in_word = 0;

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ') {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            count++;
        }
    }

    return count;
}

// Define a function to reverse a string
char *reverse_string(char *str) {
    int len = strlen(str);
    char *new_str = malloc(len + 1);

    for (int i = 0, j = len - 1; i < len; i++, j--) {
        new_str[i] = str[j];
    }
    new_str[len] = '\0';

    return new_str;
}

// Define a function to print a string in a box
void print_in_box(char *str) {
    int len = strlen(str);
    int width = len + 4;
    int height = 3;

    // Print the top of the box
    for (int i = 0; i < width; i++) {
        printf("-");
    }
    printf("\n");

    // Print the sides of the box
    for (int i = 0; i < height - 1; i++) {
        printf("| ");
        printf("%s", str);
        printf(" |");
        printf("\n");
    }

    // Print the bottom of the box
    for (int i = 0; i < width; i++) {
        printf("-");
    }
    printf("\n");
}

int main() {
    char *str = "The quick brown fox jumps over the lazy dog.";

    // Remove punctuation from the string
    char *new_str = remove_punctuation(str);

    // Count the number of words in the string
    int word_count = count_words(new_str);

    // Reverse the string
    char *reversed_str = reverse_string(new_str);

    // Print the string in a box
    print_in_box(reversed_str);

    // Free the allocated memory
    free(new_str);
    free(reversed_str);

    return 0;
}