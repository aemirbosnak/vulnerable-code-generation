//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

typedef struct {
    char *word;
    int count;
} word_count_t;

word_count_t *create_word_count_table(char *text) {
    word_count_t *table = malloc(sizeof(word_count_t) * 256);
    memset(table, 0, sizeof(word_count_t) * 256);

    char *word = strtok(text, " ");
    while (word!= NULL) {
        int index = tolower(word[0]) - 'a';
        table[index].word = word;
        table[index].count++;
        word = strtok(NULL, " ");
    }

    return table;
}

void print_word_count_table(word_count_t *table) {
    for (int i = 0; i < 256; i++) {
        if (table[i].word!= NULL) {
            printf("%c: %s (%d)\n", i + 'a', table[i].word, table[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <text_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    char *text = malloc(1024 * 1024);
    fread(text, sizeof(char), fread(text, sizeof(char), 1024 * 1024, file), file);
    text[strcspn(text, "\n")] = '\0';

    word_count_t *table = create_word_count_table(text);
    print_word_count_table(table);

    free(text);
    free(table);

    return 0;
}