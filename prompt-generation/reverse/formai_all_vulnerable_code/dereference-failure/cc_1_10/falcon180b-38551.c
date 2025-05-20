//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_SIZE 100
#define MAX_INDEXES 100

typedef struct {
    char word[WORD_SIZE];
    int count;
} Word;

typedef struct {
    char index[MAX_INDEXES][WORD_SIZE];
    int count;
} Index;

void load_words(char *filename, Word *words) {
    FILE *fp;
    char line[WORD_SIZE];
    int i = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    while (fgets(line, WORD_SIZE, fp)!= NULL) {
        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }
        strcpy(words[i].word, line);
        words[i].count = 0;
        i++;
    }

    fclose(fp);
}

void build_index(Word *words, Index *index) {
    int i, j;

    for (i = 0; i < MAX_INDEXES; i++) {
        strcpy(index[i].index, "");
    }

    for (i = 0; i < MAX_WORDS; i++) {
        if (strlen(words[i].word) == 0) {
            continue;
        }

        for (j = 0; j < MAX_INDEXES; j++) {
            if (strcmp(index[j].index, words[i].word) == 0) {
                index[j].count++;
                break;
            }
        }

        if (j == MAX_INDEXES) {
            strcpy(index[0].index, words[i].word);
            index[0].count++;
        }
    }
}

void search_index(Index *index, char *word) {
    int i;

    for (i = 0; i < MAX_INDEXES; i++) {
        if (strcmp(index[i].index, word) == 0) {
            printf("Found %s: %d\n", word, index[i].count);
            return;
        }
    }

    printf("Not found\n");
}

int main(int argc, char *argv[]) {
    Word words[MAX_WORDS];
    Index index;
    char filename[100];

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    strcpy(filename, argv[1]);

    load_words(filename, words);
    build_index(words, &index);

    while (1) {
        printf("Enter a word to search: ");
        scanf("%s", filename);
        search_index(&index, filename);
    }

    return 0;
}