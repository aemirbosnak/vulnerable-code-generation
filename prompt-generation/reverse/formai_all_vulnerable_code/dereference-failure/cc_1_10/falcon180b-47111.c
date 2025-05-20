//Falcon-180B DATASET v1.0 Category: Text processing ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_WORDS 10000

struct word {
    char *text;
    int count;
};

int compare_words(const void *a, const void *b) {
    struct word *word1 = (struct word *)a;
    struct word *word2 = (struct word *)b;
    return strcmp(word1->text, word2->text);
}

void count_words(char *text) {
    char *word;
    char *saveptr;
    struct word *words[MAX_WORDS];
    int num_words = 0;

    word = strtok_r(text, " ", &saveptr);
    while (word!= NULL && num_words < MAX_WORDS) {
        struct word *new_word = malloc(sizeof(struct word));
        new_word->text = strdup(word);
        new_word->count = 1;
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(words[i]->text, word) == 0) {
                words[i]->count++;
                free(new_word->text);
                free(new_word);
                break;
            }
        }
        if (i == num_words) {
            words[num_words++] = new_word;
        }
        word = strtok_r(NULL, " ", &saveptr);
    }
    qsort(words, num_words, sizeof(struct word), compare_words);
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i]->text, words[i]->count);
    }
}

int main() {
    char text[1000000];
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    count_words(text);
    return 0;
}