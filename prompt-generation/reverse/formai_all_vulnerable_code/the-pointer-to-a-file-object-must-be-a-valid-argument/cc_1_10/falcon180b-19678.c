//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define NUM_FEATURES 10
#define SPAM_THRESHOLD 0.8

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

typedef struct {
    WordCount words[NUM_FEATURES];
} FeatureVector;

void readTrainingData(const char* filename, FeatureVector* featureVector) {
    FILE* file = fopen(filename, "r");
    char line[1000];
    char word[MAX_WORD_LENGTH];
    int wordCount = 0;
    while (fgets(line, sizeof(line), file)!= NULL) {
        char* token = strtok(line, " ");
        while (token!= NULL) {
            word[wordCount] = tolower(token[0]);
            wordCount++;
            if (wordCount >= MAX_WORD_LENGTH) {
                break;
            }
            token = strtok(NULL, " ");
        }
        word[wordCount] = '\0';
        for (int i = 0; i < NUM_FEATURES; i++) {
            if (strcmp(word, featureVector->words[i].word) == 0) {
                featureVector->words[i].count++;
                break;
            }
        }
    }
    fclose(file);
}

int isSpam(const char* email, FeatureVector* featureVector) {
    int spamCount = 0;
    char* token = strtok(email, " ");
    while (token!= NULL) {
        WordCount* word = NULL;
        for (int i = 0; i < NUM_FEATURES; i++) {
            if (strcmp(token, featureVector->words[i].word) == 0) {
                word = &featureVector->words[i];
                break;
            }
        }
        if (word!= NULL) {
            spamCount += word->count;
        }
        token = strtok(NULL, " ");
    }
    return (spamCount / NUM_FEATURES) >= SPAM_THRESHOLD;
}

int main() {
    FeatureVector featureVector;
    readTrainingData("training_data.txt", &featureVector);

    char* email = "This is a spam email. Please buy my product.";
    if (isSpam(email, &featureVector)) {
        printf("Spam detected!\n");
    } else {
        printf("Not spam.\n");
    }

    return 0;
}