//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 100

struct word {
    char *word;
    int count;
};

int compare_func(const void *a, const void *b) {
    const struct word *word1 = a;
    const struct word *word2 = b;
    return strcmp(word1->word, word2->word);
}

int main(int argc, char **argv) {
    FILE *input_file;
    char buffer[MAX_WORD_LEN];
    char *word;
    struct word *word_list = malloc(MAX_WORDS * sizeof(struct word));
    int num_words = 0;

    if (argc < 2) {
        printf("Usage: %s input_file\n", argv[0]);
        exit(1);
    }

    input_file = fopen(argv[1], "r");
    if (!input_file) {
        printf("Error: Could not open file '%s'\n", argv[1]);
        exit(1);
    }

    while (fgets(buffer, MAX_WORD_LEN, input_file)!= NULL) {
        word = strtok(buffer, ",.?!;:");
        while (word!= NULL) {
            if (num_words >= MAX_WORDS) {
                printf("Error: Maximum number of words reached\n");
                exit(1);
            }
            if (strlen(word) >= MAX_WORD_LEN) {
                printf("Error: Word is too long\n");
                exit(1);
            }
            for (int i = 0; i < strlen(word); i++) {
                if (!isalpha(word[i])) {
                    printf("Error: Word contains non-alphabetic characters\n");
                    exit(1);
                }
            }
            word_list[num_words].word = strdup(word);
            word_list[num_words].count = 0;
            num_words++;
            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(input_file);

    qsort(word_list, num_words, sizeof(struct word), compare_func);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_list[i].word, word_list[i].count);
    }

    return 0;
}