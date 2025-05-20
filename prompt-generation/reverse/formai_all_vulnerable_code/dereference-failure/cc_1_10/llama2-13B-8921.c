//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: careful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define WORD_SEPARATOR " "

struct word {
    char *text;
    size_t length;
};

typedef struct word word_t;

int main() {
    clock_t start_time = clock();

    // Load the text to count
    char *text = "Hello, world! This is a sample text for the word count tool.";
    size_t text_length = strlen(text);

    // Create an array to store the words
    word_t *words = malloc(text_length * sizeof(word_t));

    // Iterate through the text and count the words
    char *ptr = text;
    size_t i = 0;
    while (ptr != NULL && i < text_length) {
        // Check if the current character is a word separator
        if (strchr(WORD_SEPARATOR, *ptr) != NULL) {
            // If it is, then we have found the end of a word
            words[i].text = ptr;
            words[i].length = ptr - words[i].text;
            i++;
        }
        ptr++;
    }

    // Print the word count
    printf("Word Count:\n");
    for (size_t j = 0; j < i; j++) {
        printf("%d. %s\n", j + 1, words[j].text);
    }

    free(words);

    clock_t end_time = clock();
    double elapsed_time = (end_time - start_time) / CLOCKS_PER_SEC;
    printf("Elapsed time: %f seconds\n", elapsed_time);

    return 0;
}