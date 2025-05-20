//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 10000

typedef struct word_counter {
    char* word;
    int count;
} word_counter;

int is_word_char(char c) {
    return isalpha(c) || c == '\'' || c == '-';
}

void to_lowercase(char* str) {
    int i;
    for (i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void add_word(word_counter* counter, int* num_words, char* word) {
    int i;
    for (i = 0; i < *num_words; i++) {
        if (strcmp(counter[i].word, word) == 0) {
            counter[i].count++;
            return;
        }
    }
    if (*num_words < MAX_NUM_WORDS) {
        counter[*num_words].word = strdup(word);
        counter[*num_words].count = 1;
        (*num_words)++;
    }
}

word_counter* get_word_counts(char* text, int* num_words) {
    word_counter* counter = calloc(MAX_NUM_WORDS, sizeof(word_counter));
    int in_word = 0;
    int word_start = 0;
    int i;
    for (i = 0; text[i]; i++) {
        if (is_word_char(text[i])) {
            if (!in_word) {
                in_word = 1;
                word_start = i;
            }
        } else {
            if (in_word) {
                in_word = 0;
                int word_end = i;
                char word[MAX_WORD_LENGTH + 1];
                strncpy(word, text + word_start, word_end - word_start);
                word[word_end - word_start] = '\0';
                to_lowercase(word);
                add_word(counter, num_words, word);
            }
        }
    }
    if (in_word) {
        int word_end = i;
        char word[MAX_WORD_LENGTH + 1];
        strncpy(word, text + word_start, word_end - word_start);
        word[word_end - word_start] = '\0';
        to_lowercase(word);
        add_word(counter, num_words, word);
    }
    return counter;
}

int compare_word_counter(const void* a, const void* b) {
    const word_counter* aa = a;
    const word_counter* bb = b;
    int cmp = bb->count - aa->count;
    if (cmp == 0) {
        return strcmp(aa->word, bb->word);
    }
}

int main() {
    char text[10000] = "This is a test text for the c word frequency counter.";
    int num_words = 0;
    word_counter* counter = get_word_counts(text, &num_words);
    qsort(counter, num_words, sizeof(word_counter), compare_word_counter);
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s %d\n", counter[i].word, counter[i].count);
    }
    return 0;
}