//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 50

struct word {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

int compare_words(const void *a, const void *b) {
    const struct word *word1 = a;
    const struct word *word2 = b;

    return strcmp(word1->word, word2->word);
}

int main() {
    FILE *input_file;
    char line[MAX_WORD_LENGTH];
    char *word;
    struct word *word_list = malloc(MAX_WORDS * sizeof(struct word));
    int num_words = 0;

    input_file = fopen("input.txt", "r");

    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, input_file)!= NULL) {
        word = strtok(line, ",.?!;:");

        while (word!= NULL) {
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(word_list[i].word, word) == 0) {
                    word_list[i].frequency++;
                    break;
                }
            }

            if (i == num_words) {
                if (num_words >= MAX_WORDS) {
                    printf("Error: Maximum number of words exceeded.\n");
                    exit(1);
                }

                strcpy(word_list[num_words].word, word);
                word_list[num_words].frequency = 1;
                num_words++;
            }

            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(input_file);

    qsort(word_list, num_words, sizeof(struct word), compare_words);

    printf("Word\tFrequency\n");

    for (int i = 0; i < num_words; i++) {
        printf("%s\t%d\n", word_list[i].word, word_list[i].frequency);
    }

    free(word_list);

    return 0;
}