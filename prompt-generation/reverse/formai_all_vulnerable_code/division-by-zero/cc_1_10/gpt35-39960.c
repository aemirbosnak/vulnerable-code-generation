//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: optimized
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// function to get positive words from file
void loadPositiveWords(char *filename, char **positiveWords, int *numPositiveWords) {
    // open file
    FILE * f = fopen(filename, "r");
    if (f == NULL) {
        printf("Error: could not open %s\n", filename);
        *numPositiveWords = 0;
        return;
    }

    // count number of words in file
    int numWords = 0;
    char c;
    while ((c = fgetc(f)) != EOF) {
        if (c == '\n') {
            numWords++;
        }
    }

    // allocate memory for words
    *positiveWords = (char *) malloc((numWords + 1) * sizeof(char *));

    // read words from file into array
    rewind(f);
    int i = 0;
    while (fgets((*positiveWords) + i, 25, f)) {
        (*positiveWords)[strlen((*positiveWords) + i) - 1] = '\0';
        i += strlen((*positiveWords) + i) + 1;
    }
    (*numPositiveWords) = numWords;

    // close file
    fclose(f);
}

// function to get negative words from file
void loadNegativeWords(char *filename, char **negativeWords, int *numNegativeWords) {
    // open file
    FILE * f = fopen(filename, "r");
    if (f == NULL) {
        printf("Error: could not open %s\n", filename);
        *numNegativeWords = 0;
        return;
    }

    // count number of words in file
    int numWords = 0;
    char c;
    while ((c = fgetc(f)) != EOF) {
        if (c == '\n') {
            numWords++;
        }
    }

    // allocate memory for words
    *negativeWords = (char *) malloc((numWords + 1) * sizeof(char *));

    // read words from file into array
    rewind(f);
    int i = 0;
    while (fgets((*negativeWords) + i, 25, f)) {
        (*negativeWords)[strlen((*negativeWords) + i) - 1] = '\0';
        i += strlen((*negativeWords) + i) + 1;
    }
    (*numNegativeWords) = numWords;

    // close file
    fclose(f);
}

// function to perform sentiment analysis on input text
int analyzeSentiment(char *text, char **positiveWords, int numPositiveWords, char **negativeWords, int numNegativeWords) {
    int numWords = 0;
    char *word;
    int sentimentScore = 0;

    // tokenize input text into individual words
    word = strtok(text, " .,!?\n");
    while (word != NULL) {
        numWords++;

        // check if word is positive or negative
        int found = 0;
        for (int i = 0; i < numPositiveWords; i++) {
            if (strcmp(word, positiveWords[i]) == 0) {
                sentimentScore++;
                found = 1;
                break;
            }
        }
        if (!found) {
            for (int i = 0; i < numNegativeWords; i++) {
                if (strcmp(word, negativeWords[i]) == 0) {
                    sentimentScore--;
                    found = 1;
                    break;
                }
            }
        }

        // get next word
        word = strtok(NULL, " .,!?\n");
    }

    // calculate sentiment score
    int score = sentimentScore * 100 / numWords;
    return score;
}

int main() {
    char *positiveWords;
    char *negativeWords;
    int numPositiveWords;
    int numNegativeWords;

    // load positive and negative words from files
    loadPositiveWords("positive_words.txt", &positiveWords, &numPositiveWords);
    loadNegativeWords("negative_words.txt", &negativeWords, &numNegativeWords);

    // read input text
    char input[1000];
    printf("Enter text to analyze sentiment:\n");
    fgets(input, 1000, stdin);

    // perform sentiment analysis
    int score = analyzeSentiment(input, &positiveWords, numPositiveWords, &negativeWords, numNegativeWords);
    printf("Sentiment score: %d\n", score);

    // free memory
    free(positiveWords);
    free(negativeWords);

    return 0;
}