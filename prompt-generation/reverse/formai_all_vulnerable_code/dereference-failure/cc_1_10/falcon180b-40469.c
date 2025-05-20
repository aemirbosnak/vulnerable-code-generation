//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Forward declaration of functions
void tokenize(char *sentence, char **tokens);
int countWords(char **tokens);
double calculateSentiment(char **tokens);

int main() {
    char sentence[1000];
    char **tokens;
    int numTokens;
    double sentiment;

    printf("Enter a sentence to analyze: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Tokenize the sentence
    tokenize(sentence, &tokens);
    numTokens = countWords(tokens);

    // Calculate the sentiment score
    sentiment = calculateSentiment(tokens);

    printf("Sentiment score: %.2f\n", sentiment);

    for (int i = 0; i < numTokens; i++) {
        free(tokens[i]);
    }
    free(tokens);

    return 0;
}

// Tokenizes a sentence into words
void tokenize(char *sentence, char **tokens) {
    char *token = strtok(sentence, ",.?!;:");
    int numTokens = 0;

    while (token!= NULL) {
        tokens[numTokens] = strdup(token);
        numTokens++;
        token = strtok(NULL, ",.?!;:");
    }

    tokens[numTokens] = NULL;
}

// Counts the number of words in a tokenized sentence
int countWords(char **tokens) {
    int numWords = 0;

    while (tokens[numWords]!= NULL) {
        numWords++;
    }

    return numWords;
}

// Calculates the sentiment score of a tokenized sentence
double calculateSentiment(char **tokens) {
    double sentiment = 0.0;
    int numTokens = countWords(tokens);

    for (int i = 0; i < numTokens; i++) {
        char *token = tokens[i];
        if (strlen(token) > 0) {
            int len = strlen(token);
            for (int j = 0; j < len; j++) {
                if (isalpha(token[j])) {
                    if (token[j] == 'a' || token[j] == 'A') {
                        sentiment += 1.0;
                    } else if (token[j] == 'o' || token[j] == 'O') {
                        sentiment -= 1.0;
                    }
                }
            }
        }
    }

    return sentiment / numTokens;
}