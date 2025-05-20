//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define a struct to represent a word and its sentiment score
typedef struct {
    char *word;
    int score;
} Word;

// Create a dictionary of words and their sentiment scores
Word dictionary[] = {
    {"good", 1},
    {"bad", -1},
    {"excellent", 2},
    {"terrible", -2},
    {"amazing", 3},
    {"horrible", -3},
    {"great", 1},
    {"awful", -1},
    {"superb", 2},
    {"dreadful", -2},
    {"fantastic", 3},
    {"atrocious", -3},
    {"wonderful", 2},
    {"terrible", -2},
    {"magnificent", 3},
    {"disgusting", -3},
    {"outstanding", 3},
    {"abysmal", -3},
    {"brilliant", 3},
    {"appalling", -3},
    {"extraordinary", 3},
    {"deplorable", -3},
    {"remarkable", 3},
    {"pathetic", -3},
    {"spectacular", 3},
    {"woeful", -3}
};

// Function to get the sentiment score of a word
int get_sentiment_score(char *word) {
    // Convert the word to lowercase
    char *lower_word = strdup(word);
    for (int i = 0; lower_word[i]; i++) {
        lower_word[i] = tolower(lower_word[i]);
    }

    // Look up the word in the dictionary
    for (int i = 0; i < sizeof(dictionary) / sizeof(Word); i++) {
        if (strcmp(lower_word, dictionary[i].word) == 0) {
            free(lower_word);
            return dictionary[i].score;
        }
    }

    // If the word is not in the dictionary, return 0
    free(lower_word);
    return 0;
}

// Function to analyze the sentiment of a text
int analyze_sentiment(char *text) {
    // Split the text into words
    char *words[100];
    int num_words = 0;
    char *token = strtok(text, " ");
    while (token != NULL) {
        words[num_words++] = token;
        token = strtok(NULL, " ");
    }

    // Calculate the sentiment score for each word
    int scores[num_words];
    for (int i = 0; i < num_words; i++) {
        scores[i] = get_sentiment_score(words[i]);
    }

    // Calculate the overall sentiment score
    int overall_score = 0;
    for (int i = 0; i < num_words; i++) {
        overall_score += scores[i];
    }

    // Return the overall sentiment score
    return overall_score;
}

// Main function
int main() {
    // Get the input text from the user
    char text[1000];
    printf("Enter the text you want to analyze: ");
    fgets(text, sizeof(text), stdin);

    // Analyze the sentiment of the text
    int sentiment_score = analyze_sentiment(text);

    // Print the sentiment score
    if (sentiment_score > 0) {
        printf("Positive sentiment\n");
    } else if (sentiment_score < 0) {
        printf("Negative sentiment\n");
    } else {
        printf("Neutral sentiment\n");
    }

    return 0;
}