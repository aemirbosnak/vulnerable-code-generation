//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#define MAX_LINE_SIZE 1000
#define MAX_WORD_SIZE 100

typedef struct {
    char word[MAX_WORD_SIZE];
    int count;
} Word;

typedef struct {
    Word *words;
    int num_words;
    int total_words;
} WordList;

void init_word_list(WordList *list);
void add_word(WordList *list, char *word);
void print_word_list(WordList *list);

int main() {
    FILE *file;
    char line[MAX_LINE_SIZE];
    time_t start_time, end_time;
    WordList word_list;

    init_word_list(&word_list);

    file = fopen("logfile.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }

    time(&start_time);
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        add_word(&word_list, line);
    }
    time(&end_time);

    print_word_list(&word_list);

    printf("Total words: %d\n", word_list.total_words);
    printf("Time taken: %ld seconds\n", end_time - start_time);

    fclose(file);
    return 0;
}

void init_word_list(WordList *list) {
    list->words = NULL;
    list->num_words = 0;
    list->total_words = 0;
}

void add_word(WordList *list, char *word) {
    Word *new_word = NULL;
    int i;

    for (i = 0; i < list->num_words; i++) {
        if (strcmp(list->words[i].word, word) == 0) {
            list->words[i].count++;
            return;
        }
    }

    new_word = (Word*) malloc(sizeof(Word));
    strcpy(new_word->word, word);
    new_word->count = 1;

    list->words = (Word*) realloc(list->words, sizeof(Word) * (list->num_words + 1));
    list->words[list->num_words] = *new_word;
    list->num_words++;

    list->total_words++;
}

void print_word_list(WordList *list) {
    int i;

    for (i = 0; i < list->num_words; i++) {
        printf("%s: %d\n", list->words[i].word, list->words[i].count);
    }
}