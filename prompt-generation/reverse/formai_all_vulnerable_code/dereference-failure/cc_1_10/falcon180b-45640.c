//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORDS 5000
#define MAX_WORD_LENGTH 50
#define MIN_WORD_LENGTH 3
#define POSITIVE_SCORE 1
#define NEGATIVE_SCORE -1
#define NEUTRAL_SCORE 0

typedef struct {
    char *word;
    int score;
} WordScore;

int compare(const void *a, const void *b) {
    WordScore *wordScoreA = (WordScore *)a;
    WordScore *wordScoreB = (WordScore *)b;
    return strcmp(wordScoreA->word, wordScoreB->word);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char buffer[MAX_WORD_LENGTH];
    int wordCount = 0;
    WordScore *wordScores = malloc(MAX_WORDS * sizeof(WordScore));
    memset(wordScores, 0, MAX_WORDS * sizeof(WordScore));

    while (fscanf(file, "%s", buffer)!= EOF) {
        int length = strlen(buffer);
        if (length >= MIN_WORD_LENGTH) {
            char *word = malloc((length + 1) * sizeof(char));
            strcpy(word, buffer);
            wordScores[wordCount] = (WordScore) {
               .word = word,
               .score = NEUTRAL_SCORE
            };
            wordCount++;
        }
    }

    qsort(wordScores, wordCount, sizeof(WordScore), compare);

    int totalScore = 0;
    for (int i = 0; i < wordCount; i++) {
        totalScore += wordScores[i].score;
    }

    double sentimentScore = (double)totalScore / wordCount;
    printf("Sentiment score: %.2f\n", sentimentScore);

    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordScores[i].word, wordScores[i].score);
    }

    free(wordScores);
    fclose(file);

    return 0;
}