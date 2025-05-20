//MISTRAL-7B DATASET v1.0 Category: Benchmarking ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LARGE_FILE "largefile.txt"
#define WORD_SIZE 32

typedef struct Word {
    char data[WORD_SIZE];
    struct Word *next;
} Word;

Word *read_file(const char *filename) {
    FILE *fp = fopen(filename, "r");
    Word *head = NULL, *current = NULL;

    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        current = (Word *)malloc(sizeof(Word));
        strcpy(current->data, line);
        current->next = head;
        head = current;
    }

    fclose(fp);
    return head;
}

size_t count_words(Word *head) {
    size_t count = 0;
    Word *current = head;

    while (current != NULL) {
        if (strlen(current->data) > 0 && current->next == NULL) {
            count++;
        }
        current = current->next;
    }

    return count;
}

int main() {
    clock_t start = clock();
    Word *head = read_file(LARGE_FILE);
    size_t num_words = count_words(head);
    clock_t end = clock();

    printf("Number of words in %s: %ld\n", LARGE_FILE, num_words);
    printf("Time elapsed: %.3f ms\n", (end - start) * 1000.0 / CLOCKS_PER_SEC);

    while (head != NULL) {
        Word *temp = head;
        head = head->next;
        free(temp);
    }

    return EXIT_SUCCESS;
}