//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_WORD_LENGTH 50
#define MAX_WORD_COUNT 1000

// Function to split a sentence into words
void split_sentence(char* sentence, char* words[]) {
    int i = 0;
    char* word = strtok(sentence, " ");
    while (word!= NULL) {
        strcpy(words[i], word);
        i++;
        word = strtok(NULL, " ");
    }
}

// Function to clean a word (remove punctuation and convert to lowercase)
void clean_word(char* word) {
    int i = 0;
    while (word[i]!= '\0') {
        if (!isalnum(word[i])) {
            word[i] = '\0';
        } else if (isupper(word[i])) {
            word[i] = tolower(word[i]);
        }
        i++;
    }
}

// Function to calculate the sentiment score of a sentence
int calculate_sentiment_score(char* sentence) {
    int score = 0;
    char* words[MAX_WORD_COUNT];
    int word_count = 0;
    split_sentence(sentence, words);
    for (int i = 0; i < word_count; i++) {
        clean_word(words[i]);
        if (strcmp(words[i], "happy") == 0) {
            score += 1;
        } else if (strcmp(words[i], "sad") == 0) {
            score -= 1;
        }
    }
    return score;
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);
    int sentiment_score = calculate_sentiment_score(sentence);
    if (sentiment_score > 0) {
        printf("Sentiment: Positive\n");
    } else if (sentiment_score < 0) {
        printf("Sentiment: Negative\n");
    } else {
        printf("Sentiment: Neutral\n");
    }
    return 0;
}