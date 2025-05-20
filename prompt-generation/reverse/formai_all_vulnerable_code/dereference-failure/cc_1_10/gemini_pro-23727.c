//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: intelligent
#include <stdio.h>
#include <string.h>

// Define the sentiment scores for each word
int sentiment_scores[] = {
    // Positive words
    [0] = 1,  // "good"
    [1] = 2,  // "great"
    [2] = 3,  // "excellent"
    [3] = 4,  // "amazing"
    [4] = 5,  // "superb"

    // Negative words
    [5] = -1, // "bad"
    [6] = -2, // "terrible"
    [7] = -3, // "horrible"
    [8] = -4, // "awful"
    [9] = -5, // "dreadful"
};

// Define the number of words in the sentiment dictionary
int num_words = sizeof(sentiment_scores) / sizeof(int);

// Analyze the sentiment of a given text
int analyze_sentiment(char *text) {
    // Convert the text to lowercase
    char *lowercase_text = strdup(text);
    for (int i = 0; i < strlen(lowercase_text); i++) {
        lowercase_text[i] = tolower(lowercase_text[i]);
    }

    // Initialize the sentiment score
    int sentiment_score = 0;

    // Tokenize the text into words
    char *tokens[100];  // Assuming a maximum of 100 words
    int num_tokens = 0;
    char *token = strtok(lowercase_text, " ");
    while (token != NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, " ");
    }

    // Iterate over the words and add their sentiment scores to the total score
    for (int i = 0; i < num_tokens; i++) {
        // Search for the word in the sentiment dictionary
        int index = -1;
        for (int j = 0; j < num_words; j++) {
            if (strcmp(tokens[i], sentiment_scores[j]) == 0) {
                index = j;
                break;
            }
        }

        // If the word is found, add its sentiment score to the total score
        if (index != -1) {
            sentiment_score += sentiment_scores[index];
        }
    }

    // Free the allocated memory
    free(lowercase_text);

    // Return the sentiment score
    return sentiment_score;
}

// Print the sentiment of a given text
void print_sentiment(char *text) {
    int sentiment_score = analyze_sentiment(text);

    // Determine the sentiment
    char *sentiment;
    if (sentiment_score > 0) {
        sentiment = "positive";
    } else if (sentiment_score < 0) {
        sentiment = "negative";
    } else {
        sentiment = "neutral";
    }

    // Print the sentiment
    printf("The sentiment of the text is %s: %d\n", sentiment, sentiment_score);
}

// Main function
int main() {
    // Get the input text from the user
    char text[100];
    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);

    // Analyze the sentiment of the text
    print_sentiment(text);

    return 0;
}