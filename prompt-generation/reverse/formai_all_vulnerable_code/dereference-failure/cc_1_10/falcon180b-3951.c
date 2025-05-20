//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define MAX_LINE_LEN 1000
#define MAX_WORD_COUNT 1000

typedef struct {
    char *word;
    int count;
} WordCount;

int main(int argc, char *argv[]) {
    FILE *fp;
    char input_filename[MAX_LINE_LEN];
    char line[MAX_LINE_LEN];
    char *word;
    WordCount *word_counts = NULL;
    int num_words = 0;
    int i;

    if (argc!= 2) {
        printf("Usage: %s input_file\n", argv[0]);
        return 1;
    }

    strcpy(input_filename, argv[1]);
    fp = fopen(input_filename, "r");

    if (fp == NULL) {
        printf("Error: could not open file %s\n", input_filename);
        return 1;
    }

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        num_words = 0;
        word_counts = (WordCount *) realloc(word_counts, sizeof(WordCount) * (num_words + 1));

        word = strtok(line, ",.?!:;\"'()[]{}<>");
        while (word!= NULL) {
            if (strlen(word) > MAX_WORD_LEN) {
                printf("Warning: word '%s' in line '%s' is too long and will be truncated\n", word, line);
                word[MAX_WORD_LEN - 1] = '\0';
            }

            for (i = 0; i < num_words; i++) {
                if (strcmp(word, word_counts[i].word) == 0) {
                    word_counts[i].count++;
                    break;
                }
            }

            if (i == num_words) {
                word_counts = (WordCount *) realloc(word_counts, sizeof(WordCount) * (num_words + 1));
                strcpy(word_counts[num_words].word, word);
                word_counts[num_words].count = 1;
                num_words++;
            }

            word = strtok(NULL, ",.?!:;\"'()[]{}<>");
        }
    }

    fclose(fp);

    printf("Word frequency:\n");
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    return 0;
}