//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50
#define MIN_WORD_LENGTH 3

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void loadWords(char *filename, WordFrequency *words) {
    FILE *file = fopen(filename, "r");
    char word[MAX_WORD_LENGTH];
    char line[MAX_WORD_LENGTH];
    int wordCount = 0;

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        int i = 0;
        while (line[i]!= '\0' && line[i]!= '\n') {
            if (isalpha(line[i])) {
                strncat(word, &line[i], 1);
            }
            i++;
        }
        if (strlen(word) >= MIN_WORD_LENGTH) {
            int j = 0;
            while (j < wordCount && strcmp(words[j].word, word)!= 0) {
                j++;
            }
            if (j == wordCount) {
                strcpy(words[wordCount].word, word);
                words[wordCount].frequency = 1;
                wordCount++;
            } else {
                words[j].frequency++;
            }
        }
    }

    fclose(file);
}

void sortWords(WordFrequency *words, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (words[j].frequency > words[i].frequency) {
                WordFrequency temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

int isSpam(char *filename, WordFrequency *words, int count) {
    FILE *file = fopen(filename, "r");
    char line[MAX_WORD_LENGTH];
    int spamCount = 0;

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        int i = 0;
        while (line[i]!= '\0' && line[i]!= '\n') {
            if (isalpha(line[i])) {
                int j = 0;
                while (j < count && strcmp(words[j].word, line)!= 0) {
                    j++;
                }
                if (j == count) {
                    spamCount++;
                }
            }
            i++;
        }
    }

    fclose(file);

    return spamCount;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <training_data_file> <input_file>\n", argv[0]);
        return 1;
    }

    char *trainingDataFile = argv[1];
    char *inputFile = argv[2];

    WordFrequency words[MAX_WORDS];
    int wordCount = 0;

    loadWords(trainingDataFile, words);
    sortWords(words, wordCount);

    int spamCount = isSpam(inputFile, words, wordCount);

    if (spamCount >= 5) {
        printf("Spam detected!\n");
    } else {
        printf("No spam detected.\n");
    }

    return 0;
}