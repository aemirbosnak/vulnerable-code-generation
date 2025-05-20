//Falcon-180B DATASET v1.0 Category: Text processing ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 1000
#define MAX_NUM_LINES 1000

typedef struct {
    char *word;
    int count;
} WordCount;

typedef struct {
    WordCount *wordCounts;
    int numWords;
} WordFrequency;

typedef struct {
    WordFrequency *wordFrequencies;
    int numFrequencies;
} TextAnalysis;

char *readLine(FILE *file) {
    char *line = malloc(MAX_LINE_LENGTH * sizeof(char));
    fgets(line, MAX_LINE_LENGTH, file);
    line[strcspn(line, "\n")] = '\0';
    return line;
}

void splitLine(char *line, char **words) {
    char *word = strtok(line, " ");
    int numWords = 0;

    while (word!= NULL) {
        words[numWords] = word;
        numWords++;
        word = strtok(NULL, " ");
    }
}

void countWords(WordFrequency *wordFrequency, char **words, int numWords) {
    for (int i = 0; i < numWords; i++) {
        WordCount *wordCount = wordFrequency->wordCounts + wordFrequency->numWords;
        wordCount->word = strdup(words[i]);
        wordCount->count = 1;
        wordFrequency->numWords++;
    }
}

void printWordFrequencies(WordFrequency *wordFrequency) {
    for (int i = 0; i < wordFrequency->numWords; i++) {
        printf("%s: %d\n", wordFrequency->wordCounts[i].word, wordFrequency->wordCounts[i].count);
    }
}

void analyzeText(TextAnalysis *textAnalysis) {
    FILE *file = fopen("text.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char *line = readLine(file);
    WordFrequency *wordFrequency = textAnalysis->wordFrequencies + textAnalysis->numFrequencies;

    while (line!= NULL) {
        char **words = malloc(MAX_NUM_WORDS * sizeof(char *));
        int numWords = 0;

        splitLine(line, words);
        countWords(wordFrequency, words, numWords);

        free(line);
        line = readLine(file);

        wordFrequency->numWords = 0;
        wordFrequency++;
        textAnalysis->numFrequencies++;
    }

    fclose(file);
}

int main() {
    TextAnalysis textAnalysis = {0};

    analyzeText(&textAnalysis);

    return 0;
}