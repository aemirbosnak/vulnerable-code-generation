//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to compute the sentiment score of a given sentence */
int compute_sentiment(const char* sentence) {

    /* Define the sentiment score variable */
    int sentiment_score = 0;

    /* Define the set of positive and negative words */
    const char* positive_words[] = {"good", "great", "excellent", "fantastic", "amazing"};
    const char* negative_words[] = {"bad", "poor", "terrible", "horrible", "awful"};

    /* Count the number of positive and negative words present in the sentence */
    int num_positive_words = 0;
    int num_negative_words = 0;

    /* Tokenize the sentence to extract individual words */
    char* word = strtok(sentence, " ");

    while (word != NULL) {

        /* Check if the word is present in the positive or negative words set */
        for (int i = 0; i < 5; i++) {
            if (strcmp(word, positive_words[i]) == 0) {
                num_positive_words++;
            }
            if (strcmp(word, negative_words[i]) == 0) {
                num_negative_words++;
            }
        }

        /* Move on to the next word */
        word = strtok(NULL, " ");
    }

    /* Compute the sentiment score by taking the difference between the number of positive and negative words */
    sentiment_score = num_positive_words - num_negative_words;

    return sentiment_score;
}

int main() {

    /* Define the test sentences */
    const char* test_sentence1 = "I had a great weekend";
    const char* test_sentence2 = "The movie was terrible";

    /* Compute the sentiment score of the test sentences */
    int sentiment_score1 = compute_sentiment(test_sentence1);
    int sentiment_score2 = compute_sentiment(test_sentence2);

    /* Print the sentiment score of the test sentences */
    printf("Sentiment score of \"%s\": %d\n", test_sentence1, sentiment_score1);
    printf("Sentiment score of \"%s\": %d\n", test_sentence2, sentiment_score2);

    return 0;
}