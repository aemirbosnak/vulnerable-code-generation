//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: modular
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 100
#define INITIAL_CAPACITY 1000

typedef struct wordfreq {
    char *word;
    int count;
} wordfreq_t;

typedef struct frequencycounter {
    wordfreq_t *list;
    int capacity;
    int size;
} frequencycounter_t;

void parse_words(FILE *fp, frequencycounter_t *fc);
void count_word(frequencycounter_t *fc, char *word);
void add_word_to_list(frequencycounter_t *fc, char *word);
int find_word_index(frequencycounter_t *fc, char *word);
void resize_list(frequencycounter_t *fc);

int main(int argc, char *argv[])
{
    frequencycounter_t fc;
    fc.list = malloc(sizeof(wordfreq_t) * INITIAL_CAPACITY);
    fc.capacity = INITIAL_CAPACITY;
    fc.size = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", argv[1]);
        return 2;
    }

    parse_words(fp, &fc);
    fclose(fp);

    printf("Word frequencies:\n");
    for (int i = 0; i < fc.size; i++) {
        printf("%s: %d\n", fc.list[i].word, fc.list[i].count);
        free(fc.list[i].word);
    }

    free(fc.list);
    return 0;
}

void parse_words(FILE *fp, frequencycounter_t *fc)
{
    char word[MAX_WORD_LEN];
    int c;
    int pos = 0;
    while ((c = fgetc(fp)) != EOF) {
        if (isalpha(c) || c == '-') {
            word[pos++] = tolower(c);
            if (pos == MAX_WORD_LEN - 1) { // word too long, skip rest of it
                while ((c = fgetc(fp)) != EOF && isalpha(c));
                pos = 0;
            }
        } else if (pos > 0) {
            word[pos] = '\0';
            count_word(fc, word);
            pos = 0;
        }
    }
}

void count_word(frequencycounter_t *fc, char *word)
{
    int index = find_word_index(fc, word);
    if (index == -1) {
        add_word_to_list(fc, word);
    } else {
        fc->list[index].count++;
        free(word);
    }
}

void add_word_to_list(frequencycounter_t *fc, char *word)
{
    if (fc->size == fc->capacity) {
        resize_list(fc);
    }
    wordfreq_t wf = {word, 1};
    fc->list[fc->size++] = wf;
}

int find_word_index(frequencycounter_t *fc, char *word)
{
    for (int i = 0; i < fc->size; i++) {
        if (strcmp(fc->list[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

void resize_list(frequencycounter_t *fc)
{
    fc->capacity *= 2;
    fc->list = realloc(fc->list, sizeof(wordfreq_t) * fc->capacity);
}