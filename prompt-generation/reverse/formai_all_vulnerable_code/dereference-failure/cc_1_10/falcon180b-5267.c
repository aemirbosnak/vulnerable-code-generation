//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int compareStrings(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void readWords(char *filename, WordCount words[]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    char line[MAX_WORD_LEN];
    while (fgets(line, sizeof(line), file)!= NULL) {
        char *word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            word[strcspn(word, "0123456789")] = '\0';
            int i;
            for (i = 0; i < MAX_WORDS && words[i].word[0]!= '\0'; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == MAX_WORDS) {
                printf("Too many unique words in the file.\n");
                exit(1);
            }
            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(file);

    qsort(words, MAX_WORDS, sizeof(WordCount), compareStrings);
}

void printWords(WordCount words[]) {
    int i;
    for (i = 0; i < MAX_WORDS && words[i].word[0]!= '\0'; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char filename[MAX_WORD_LEN];
    strcpy(filename, argv[1]);

    WordCount words[MAX_WORDS];
    readWords(filename, words);

    printf("Word Count:\n");
    printWords(words);

    return 0;
}