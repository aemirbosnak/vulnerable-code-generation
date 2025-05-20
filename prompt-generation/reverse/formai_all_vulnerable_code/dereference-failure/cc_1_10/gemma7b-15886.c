//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX_SENTENCE_LENGTH 1024
#define MAX_WORDS 1024

typedef struct Word {
    char *word;
    int frequency;
} Word;

Word *createWord(char *word) {
    Word *newWord = malloc(sizeof(Word));
    newWord->word = strdup(word);
    newWord->frequency = 0;
    return newWord;
}

void addWord(Word *word, int frequency) {
    word->frequency += frequency;
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    // Remove punctuation from the sentence
    char *sentenceWithoutPunctuation = strpbrk(sentence, ",.!?:;()\"\\|\\n");

    // Split the sentence into words
    char *words = strtok(sentenceWithoutPunctuation, " ");

    // Create an array of words
    Word *wordList = NULL;

    // Add each word to the array
    while (words) {
        Word *newWord = createWord(words);
        addWord(newWord, 1);
        wordList = wordList ? wordList : newWord;
        words = strtok(NULL, " ");
    }

    // Calculate the sentiment of each word
    for (Word *word = wordList; word; word++) {
        // Calculate the sentiment score for each word
        int sentimentScore = calculateSentimentScore(word->word);

        // Print the word and its sentiment score
        printf("%s: %d\n", word->word, sentimentScore);
    }

    return 0;
}

int calculateSentimentScore(char *word) {
    // Create a dictionary of sentiment scores
    int sentimentScores[] = {
        5, // Positive words
        -5, // Negative words
        0 // Neutral words
    };

    // Return the sentiment score for the word
    return sentimentScores[hashWord(word)];
}

int hashWord(char *word) {
    // Calculate the hash of the word
    int hash = 0;
    for (int i = 0; i < strlen(word); i++) {
        hash += word[i] * pow(2, i);
    }

    // Return the hash
    return hash;
}