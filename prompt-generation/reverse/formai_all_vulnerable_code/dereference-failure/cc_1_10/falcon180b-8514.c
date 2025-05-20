//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 100000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int main() {
    FILE *inputFile;
    char line[1000];
    char word[MAX_WORD_LENGTH];
    int frequency = 0;
    WordFrequency *wordFrequencies = (WordFrequency*)malloc(MAX_NUM_WORDS * sizeof(WordFrequency));

    inputFile = fopen("input.txt", "r");

    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), inputFile)!= NULL) {
        char *token = strtok(line, " ");

        while (token!= NULL) {
            if (strlen(token) > 0) {
                strcpy(word, token);
                frequency = 0;

                for (int i = 0; i < MAX_NUM_WORDS; i++) {
                    if (strcmp(wordFrequencies[i].word, word) == 0) {
                        frequency = wordFrequencies[i].frequency;
                        break;
                    }
                }

                if (frequency == 0) {
                    frequency = 1;
                    strcpy(wordFrequencies[frequency].word, word);
                } else {
                    frequency++;
                }
            }

            token = strtok(NULL, " ");
        }
    }

    fclose(inputFile);

    printf("Word Frequency:\n");

    for (int i = 0; i < MAX_NUM_WORDS; i++) {
        if (wordFrequencies[i].frequency > 0) {
            printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
        }
    }

    free(wordFrequencies);

    return 0;
}