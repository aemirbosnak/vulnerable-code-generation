//Falcon-180B DATASET v1.0 Category: Educational ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000

struct word {
    char *word;
    int frequency;
};

int compare_frequency(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    FILE *input_file;
    char line[1000];
    char *word;
    int word_count = 0;
    int i = 0;
    struct word *words = (struct word *)malloc(MAX_WORDS * sizeof(struct word));

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: couldn't open input file.\n");
        exit(1);
    }

    while (fgets(line, 1000, input_file)!= NULL) {
        word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            if (word_count >= MAX_WORDS) {
                printf("Error: maximum number of words reached.\n");
                exit(1);
            }
            words[i].word = strdup(word);
            words[i].frequency = 1;
            i++;
            word_count++;
            word = strtok(NULL, ",.?!;:");
        }
    }

    qsort(words, i, sizeof(struct word), compare_frequency);

    for (int j = 0; j < i; j++) {
        printf("%s: %d\n", words[j].word, words[j].frequency);
    }

    free(words);
    fclose(input_file);

    return 0;
}