//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000

struct word {
    char *word;
    int count;
};

struct word_list {
    struct word words[MAX_WORDS];
    int size;
};

void add_word(struct word_list *list, char *word) {
    int i;
    for (i = 0; i < list->size; i++) {
        if (strcmp(list->words[i].word, word) == 0) {
            list->words[i].count++;
            return;
        }
    }

    if (list->size == MAX_WORDS) {
        fprintf(stderr, "Error: Maximum number of words reached.\n");
        return;
    }

    list->words[list->size].word = strdup(word);
    list->words[list->size].count = 1;
    list->size++;
}

int compare_words(const void *a, const void *b) {
    return strcmp(((struct word *) a)->word, ((struct word *) b)->word);
}

void print_word_list(struct word_list *list) {
    int i;

    qsort(list->words, list->size, sizeof(struct word), compare_words);

    for (i = 0; i < list->size; i++) {
        printf("%s: %d\n", list->words[i].word, list->words[i].count);
    }
}

int main(int argc, char *argv[]) {
    int i;
    struct word_list word_list;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    word_list.size = 0;

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp)) {
        char *word = strtok(buffer, " ");
        while (word != NULL) {
            add_word(&word_list, word);
            word = strtok(NULL, " ");
        }
    }

    fclose(fp);

    print_word_list(&word_list);

    for (i = 0; i < word_list.size; i++) {
        free(word_list.words[i].word);
    }

    return EXIT_SUCCESS;
}