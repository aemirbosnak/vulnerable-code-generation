//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    FILE *file;
    char filename[100];
    char line[1000];
    int num_words = 0;
    WordCount *word_counts = malloc(MAX_WORDS * sizeof(WordCount));

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, 1000, file)!= NULL) {
        char *word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            if (num_words >= MAX_WORDS) {
                printf("Maximum number of words reached.\n");
                exit(1);
            }

            int len = strlen(word);
            if (len > MAX_WORD_LENGTH) {
                printf("Word too long.\n");
                exit(1);
            }

            for (int i = 0; i < len; i++) {
                if (!isalpha(word[i])) {
                    printf("Invalid character in word.\n");
                    exit(1);
                }
            }

            strcpy(word_counts[num_words].word, word);
            word_counts[num_words].count = 1;
            num_words++;

            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(file);

    printf("Enter the word to search for: ");
    char search_word[MAX_WORD_LENGTH];
    scanf("%s", search_word);

    for (int i = 0; i < num_words; i++) {
        if (strcmp(word_counts[i].word, search_word) == 0) {
            printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
        }
    }

    free(word_counts);

    return 0;
}