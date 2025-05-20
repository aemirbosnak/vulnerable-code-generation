//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char *word;
    int count;
} WordFrequency;

int main() {
    char filename[100];
    FILE *file;
    char word[MAX_WORD_LEN];
    WordFrequency *word_freq = (WordFrequency *)malloc(MAX_WORDS * sizeof(WordFrequency));
    int num_words = 0;
    int i;

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(file, "%s", word)!= EOF) {
        for (i = 0; i < num_words; i++) {
            if (strcmp(word, word_freq[i].word) == 0) {
                word_freq[i].count++;
                break;
            }
        }
        if (i == num_words) {
            word_freq[num_words].word = strdup(word);
            word_freq[num_words].count = 1;
            num_words++;
        }
    }

    fclose(file);

    printf("Word frequencies:\n");
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_freq[i].word, word_freq[i].count);
    }

    free(word_freq);
    return 0;
}