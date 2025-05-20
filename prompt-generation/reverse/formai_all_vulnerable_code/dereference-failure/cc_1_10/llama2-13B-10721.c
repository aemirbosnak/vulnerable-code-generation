//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORD_COUNT 100000
#define MAX_LINE_LENGTH 1024

struct word_counter {
    int word_count[MAX_WORD_COUNT];
    int line_count;
};

void init_word_counter(struct word_counter *counter) {
    memset(counter->word_count, 0, sizeof(counter->word_count));
    counter->line_count = 0;
}

void add_word(struct word_counter *counter, const char *word) {
    int i = 0;
    while (word[i] != '\0') {
        if (word[i] == ' ') {
            i++;
        }
        counter->word_count[word[i] - 'a']++;
    }
    counter->line_count++;
}

void print_word_count(struct word_counter *counter) {
    int i;
    for (i = 0; i < MAX_WORD_COUNT; i++) {
        if (counter->word_count[i]) {
            printf("%c: %d\n", i + 'a', counter->word_count[i]);
        }
    }
    printf("Total words: %d\n", counter->line_count * MAX_WORD_COUNT);
}

int main() {
    struct word_counter counter;
    init_word_counter(&counter);

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, stdin)) {
        int i = 0;
        while (line[i] != '\0') {
            add_word(&counter, line + i);
            i++;
        }
    }

    print_word_count(&counter);

    return 0;
}