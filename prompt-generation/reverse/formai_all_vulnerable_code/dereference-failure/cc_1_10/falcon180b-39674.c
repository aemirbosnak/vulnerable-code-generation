//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1000

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

struct word_count *create_word_count_table();
void destroy_word_count_table(struct word_count *table);
void print_word_count_table(struct word_count *table);
void count_words(char *line, struct word_count *table);

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    struct word_count *table = create_word_count_table();

    if ((file = fopen("input.txt", "r")) == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        count_words(line, table);
    }

    fclose(file);
    print_word_count_table(table);
    destroy_word_count_table(table);

    return 0;
}

struct word_count *create_word_count_table() {
    struct word_count *table = (struct word_count *) malloc(sizeof(struct word_count) * 26);
    int i;

    for (i = 0; i < 26; i++) {
        table[i].count = 0;
    }

    return table;
}

void destroy_word_count_table(struct word_count *table) {
    free(table);
}

void print_word_count_table(struct word_count *table) {
    int i;

    for (i = 0; i < 26; i++) {
        if (table[i].count > 0) {
            printf("%c: %d\n", i + 'a', table[i].count);
        }
    }
}

void count_words(char *line, struct word_count *table) {
    char *word = strtok(line, ",.!?;:");
    while (word!= NULL) {
        int len = strlen(word);
        if (len > MAX_WORD_LENGTH) {
            len = MAX_WORD_LENGTH;
        }
        strcpy(table[(int) word[0] - 97].word, word);
        table[(int) word[0] - 97].count++;
        word = strtok(NULL, ",.!?;:");
    }
}