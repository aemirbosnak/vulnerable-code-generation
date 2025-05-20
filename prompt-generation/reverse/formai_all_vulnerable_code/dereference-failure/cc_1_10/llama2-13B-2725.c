//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: statistical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define WORD_COUNT_MAX 1000

struct word {
    char *word;
    int count;
};

struct word *word_list[WORD_COUNT_MAX];
int word_count = 0;

void add_word(char *word) {
    struct word *new_word;

    if (word_count == WORD_COUNT_MAX) {
        printf("Error: Maximum word count reached (%d).\n", WORD_COUNT_MAX);
        return;
    }

    new_word = (struct word *)malloc(sizeof(struct word));
    new_word->word = word;
    new_word->count = 1;
    word_list[word_count] = new_word;
    word_count++;
}

void print_word_counts() {
    int i;
    for (i = 0; i < word_count; i++) {
        struct word *word = word_list[i];
        printf("%s: %d\n", word->word, word->count);
    }
}

int main() {
    char line[100];
    int count = 0;

    srand(time(NULL));  // for randomizing the input text

    while (1) {
        printf("Enter a sentence or phrase: ");
        fgets(line, 100, stdin);
        add_word(line);
        count++;

        if (count % 10 == 0) {
            print_word_counts();
        }
    }

    return 0;
}