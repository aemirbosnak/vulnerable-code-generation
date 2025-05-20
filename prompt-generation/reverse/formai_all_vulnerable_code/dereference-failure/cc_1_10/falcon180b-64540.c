//Falcon-180B DATASET v1.0 Category: Memory management ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20

typedef struct {
    char *word;
    int length;
} Word;

void *my_malloc(size_t size) {
    printf("Allocating %zu bytes\n", size);
    return malloc(size);
}

void *my_realloc(void *ptr, size_t size) {
    printf("Reallocating %p to %zu bytes\n", ptr, size);
    return realloc(ptr, size);
}

void my_free(void *ptr) {
    printf("Freeing %p\n", ptr);
    free(ptr);
}

int main() {
    char *sentence = "The quick brown fox jumps over the lazy dog";
    char *token = strtok(sentence, " ");
    int num_words = 0;

    while (token!= NULL) {
        if (num_words >= MAX_WORDS) {
            printf("Error: Too many words in sentence\n");
            exit(1);
        }

        Word *word_ptr = (Word *)my_malloc(sizeof(Word));
        word_ptr->word = strdup(token);
        word_ptr->length = strlen(token);

        printf("Allocated %p for word '%s'\n", word_ptr, token);

        token = strtok(NULL, " ");
        num_words++;
    }

    printf("Number of words: %d\n", num_words);

    for (int i = 0; i < num_words; i++) {
        Word *word_ptr = (Word *)my_malloc(sizeof(Word));
        word_ptr->word = strdup(sentence);
        word_ptr->length = strlen(sentence);

        printf("Allocated %p for word '%s'\n", word_ptr, sentence);
    }

    return 0;
}