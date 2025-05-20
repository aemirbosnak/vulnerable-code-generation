//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100

// A structure to represent a lexicon entry
struct LexiconEntry {
    char word[MAX_STR_LEN];
    int sentimentScore;
};

// Function to read the lexicon from a file
void readLexicon(char* filename, struct LexiconEntry* lexicon) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open lexicon file\n");
        exit(1);
    }
    char line[MAX_STR_LEN];
    int i = 0;
    while (fgets(line, MAX_STR_LEN, file)) {
        char* token = strtok(line, ",");
        strcpy(lexicon[i].word, token);
        token = strtok(NULL, ",");
        lexicon[i].sentimentScore = atoi(token);
        i++;
    }
    fclose(file);
}

// A function to calculate the sentiment score of a sentence
int calculateSentimentScore(char* sentence, struct LexiconEntry* lexicon, int lexiconSize) {
    int score = 0;
    char* token = strtok(sentence, " ");
    while (token != NULL) {
        for (int i = 0; i < lexiconSize; i++) {
            if (strcmp(token, lexicon[i].word) == 0) {
                score += lexicon[i].sentimentScore;
                break;
            }
        }
        token = strtok(NULL, " ");
    }
    return score;
}

int main() {
    // Read the lexicon
    struct LexiconEntry lexicon[10];
    readLexicon("lexicon.txt", lexicon);
    int lexiconSize = sizeof(lexicon) / sizeof(lexicon[0]);

    // Get the input sentence from the user
    char sentence[MAX_STR_LEN];
    printf("Enter a sentence: ");
    fgets(sentence, MAX_STR_LEN, stdin);
    sentence[strcspn(sentence, "\n")] = '\0'; // remove newline character if present

    // Calculate the sentiment score of the sentence
    int score = calculateSentimentScore(sentence, lexicon, lexiconSize);
    printf("Sentiment score: %d\n", score);

    return 0;
}