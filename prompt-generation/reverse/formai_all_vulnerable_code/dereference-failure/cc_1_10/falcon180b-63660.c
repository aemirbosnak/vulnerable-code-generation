//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 20

struct word {
    char word[MAX_WORD_LENGTH];
    int count;
};

struct word *words = NULL;
int num_words = 0;

void init_words() {
    words = (struct word *)malloc(MAX_WORDS * sizeof(struct word));
    num_words = 0;
}

void add_word(char *word) {
    struct word *w = words + num_words;
    strcpy(w->word, word);
    w->count = 1;
    num_words++;
}

void print_words() {
    for (int i = 0; i < num_words; i++) {
        printf("%s %d\n", words[i].word, words[i].count);
    }
}

void count_words(char *text) {
    char *word = strtok(text, ",.?!;:\"'");
    while (word!= NULL) {
        if (strlen(word) > 0) {
            struct word *w = words + num_words;
            int found = 0;
            for (int i = 0; i < num_words; i++) {
                if (strcmp(w->word, word) == 0) {
                    w->count++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(w->word, word);
                w->count = 1;
                num_words++;
            }
        }
        word = strtok(NULL, ",.?!;:\"'");
    }
}

int main() {
    init_words();
    char text[1000000];
    printf("Enter text to spell check:\n");
    fgets(text, sizeof(text), stdin);
    count_words(text);
    print_words();
    return 0;
}