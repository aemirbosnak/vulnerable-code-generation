//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

WordCount words[MAX_WORDS];

void readWords(char *filename) {
    FILE *file = fopen(filename, "r");
    char line[MAX_WORD_LEN];
    char *word;
    int i = 0;

    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_WORD_LEN, file)!= NULL) {
        word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            strcpy(words[i].word, word);
            words[i].count = 0;
            i++;
            if (i >= MAX_WORDS) {
                printf("Error: too many words in file\n");
                exit(1);
            }
            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(file);
}

void generateTheory(int numWords, int maxLen) {
    char theory[MAX_WORD_LEN * numWords + 1];
    int i, j, k;
    int wordCount = 0;

    for (i = 0; i < numWords; i++) {
        j = rand() % MAX_WORDS;
        while (words[j].count >= 2) {
            j = (j + rand() % MAX_WORDS) % MAX_WORDS;
        }
        strcat(theory, words[j].word);
        words[j].count++;
        wordCount++;
        if (wordCount >= maxLen) {
            break;
        }
    }

    theory[strlen(theory) - 1] = '\0';
    printf("Theory: %s\n", theory);
}

int main(int argc, char *argv[]) {
    srand(time(NULL));
    if (argc!= 3) {
        printf("Usage: %s <filename> <max_length>\n", argv[0]);
        exit(1);
    }

    int maxLen = atoi(argv[2]);

    readWords(argv[1]);
    generateTheory(10, maxLen);

    return 0;
}