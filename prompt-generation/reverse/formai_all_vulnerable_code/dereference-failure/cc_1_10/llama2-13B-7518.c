//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define WORD_SEP " "

void word_count(const char* str) {
    size_t len = strlen(str);
    size_t words = 0;

    // Optimization 1: Use a single pass to count words
    for (size_t i = 0; i < len; i++) {
        if (str[i] == ' ' && str[i + 1] != '\0') {
            words++;
        }
    }

    // Optimization 2: Use a buffer to store words
    char buffer[BUFFER_SIZE];
    size_t buffer_len = 0;
    for (size_t i = 0; i < len; i++) {
        if (str[i] == ' ' && buffer_len < BUFFER_SIZE - 1) {
            buffer[buffer_len] = str[i];
            buffer_len++;
        } else if (buffer_len > 0) {
            words++;
            buffer_len = 0;
        }
    }

    // Optimization 3: Use a linked list to store words
    struct word_list {
        char* word;
        struct word_list* next;
    };
    struct word_list* head = NULL;
    for (size_t i = 0; i < len; i++) {
        if (str[i] == ' ' && head == NULL) {
            struct word_list* node = (struct word_list*) malloc(sizeof(struct word_list));
            node->word = str + i;
            node->next = head;
            head = node;
        } else if (head != NULL) {
            head = head->next;
        }
    }

    printf("Total words: %zu\n", words);

    // Free memory
    struct word_list* current = head;
    while (current != NULL) {
        struct word_list* next = current->next;
        free(current->word);
        free(current);
        current = next;
    }
}

int main() {
    char str[] = "Hello, world! How are you today?";
    word_count(str);
    return 0;
}