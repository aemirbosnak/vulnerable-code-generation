//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define WORD_SIZE 32
#define BUFFER_SIZE 1024

struct word {
    char *text;
    size_t length;
};

struct buffer {
    struct word *words;
    size_t capacity;
    size_t size;
};

void add_word(struct buffer *buffer, char *text) {
    if (buffer->size >= buffer->capacity) {
        buffer->capacity *= 2;
        buffer->words = realloc(buffer->words, sizeof(struct word) * buffer->capacity);
    }

    struct word *word = &buffer->words[buffer->size];
    word->text = text;
    word->length = strlen(text);
    buffer->size++;
}

void print_words(struct buffer *buffer) {
    for (size_t i = 0; i < buffer->size; i++) {
        printf("%d: %s\n", i, buffer->words[i].text);
    }
}

int main() {
    srand(time(NULL));

    struct buffer buffer;
    buffer.capacity = BUFFER_SIZE;
    buffer.words = calloc(sizeof(struct word), buffer.capacity);

    for (size_t i = 0; i < 100; i++) {
        char *text = malloc(WORD_SIZE);
        for (size_t j = 0; j < WORD_SIZE; j++) {
            text[j] = 'a' + (rand() % 26);
        }
        add_word(&buffer, text);
    }

    print_words(&buffer);

    return 0;
}