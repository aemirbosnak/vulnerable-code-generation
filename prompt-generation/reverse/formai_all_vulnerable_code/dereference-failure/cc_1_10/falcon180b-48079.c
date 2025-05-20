//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100
#define MAX_WORDS 100

struct word {
    char *word;
    int length;
    int count;
};

struct word *words[MAX_WORDS];
int num_words = 0;

int compare(const void *a, const void *b) {
    struct word *w1 = (struct word *)a;
    struct word *w2 = (struct word *)b;
    return strcmp(w1->word, w2->word);
}

int main() {
    char input[MAX_LENGTH];
    char *word;
    int i, j, k, length;
    int count = 0;
    int freq[26] = {0};

    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);
    length = strlen(input);

    for (i = 0; i < length; i++) {
        if (isalpha(input[i])) {
            word = malloc(length - i + 1);
            strncpy(word, input + i, length - i);
            word[length - i] = '\0';

            if (num_words == MAX_WORDS) {
                printf("Maximum number of words reached.\n");
                exit(1);
            }

            for (j = 0; j < num_words; j++) {
                if (strcmp(words[j]->word, word) == 0) {
                    words[j]->count++;
                    free(word);
                    break;
                }
            }

            if (j == num_words) {
                words[num_words] = malloc(sizeof(struct word));
                words[num_words]->word = word;
                words[num_words]->length = strlen(word);
                words[num_words]->count = 1;
                num_words++;
            }
        }
    }

    qsort(words, num_words, sizeof(struct word *), compare);

    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i]->word, words[i]->count);
    }

    return 0;
}