//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 50

typedef struct {
    char *word;
    int index;
} WordIndex;

WordIndex word_indexes[MAX_WORDS];
int num_indexes = 0;

void add_word_index(char *word) {
    int i;
    for (i = 0; i < num_indexes; i++) {
        if (strcmp(word, word_indexes[i].word) == 0) {
            return;
        }
    }
    if (num_indexes >= MAX_WORDS) {
        printf("Error: too many words\n");
        exit(1);
    }
    word_indexes[num_indexes].word = strdup(word);
    word_indexes[num_indexes].index = num_indexes;
    num_indexes++;
}

void print_indexes() {
    int i;
    for (i = 0; i < num_indexes; i++) {
        printf("%s: %d\n", word_indexes[i].word, word_indexes[i].index);
    }
}

int main() {
    char word[MAX_WORD_LEN];
    while (fgets(word, MAX_WORD_LEN, stdin)!= NULL) {
        int len = strlen(word);
        if (len > 0 && word[len - 1] == '\n') {
            word[len - 1] = '\0';
            len--;
        }
        if (len > 0) {
            add_word_index(word);
        }
    }
    print_indexes();
    return 0;
}