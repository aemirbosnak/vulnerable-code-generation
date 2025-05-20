//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define THRESHOLD 5

struct word {
    char *word;
    int count;
};

int compare_words(const void *a, const void *b) {
    struct word *w1 = (struct word *)a;
    struct word *w2 = (struct word *)b;

    return strcmp(w1->word, w2->word);
}

int is_spam(char *message) {
    int spam_words = 0;
    struct word *words[MAX_WORDS];

    char *token = strtok(message, " ");
    while (token!= NULL) {
        struct word *word = (struct word *)malloc(sizeof(struct word));
        word->word = token;
        word->count = 0;

        int i;
        for (i = 0; i < MAX_WORDS && words[i]!= NULL; i++) {
            if (strcmp(word->word, words[i]->word) == 0) {
                words[i]->count++;
                break;
            }
        }

        if (i == MAX_WORDS) {
            if (words[0] == NULL) {
                words[0] = word;
            } else {
                free(word);
            }
        }

        token = strtok(NULL, " ");
    }

    qsort(words, MAX_WORDS, sizeof(struct word), compare_words);

    int i;
    for (i = 0; i < MAX_WORDS && words[i]!= NULL; i++) {
        if (words[i]->count >= THRESHOLD) {
            spam_words++;
        }
    }

    free(words[0]);
    free(words);

    return spam_words >= 3? 1 : 0;
}

int main() {
    char message[1000];

    printf("Enter message:\n");
    fgets(message, sizeof(message), stdin);

    if (is_spam(message)) {
        printf("Spam\n");
    } else {
        printf("Not spam\n");
    }

    return 0;
}