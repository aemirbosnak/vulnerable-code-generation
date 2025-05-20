//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the sentiment lexicon
const char *positive_words[] = {"good", "great", "excellent", "awesome", "superb"};
const char *negative_words[] = {"bad", "terrible", "awful", "horrible", "atrocious"};

// Function to analyze the sentiment of a given string
int analyze_sentiment(const char *string) {
    // Convert the string to lowercase
    char *lower_string = malloc(strlen(string) + 1);
    strcpy(lower_string, string);
    for (int i = 0; i < strlen(lower_string); i++) {
        lower_string[i] = tolower(lower_string[i]);
    }

    // Count the number of positive and negative words in the string
    int positive_count = 0;
    int negative_count = 0;
    for (int i = 0; i < strlen(lower_string); i++) {
        for (int j = 0; j < 5; j++) {
            if (strstr(lower_string, positive_words[j])) {
                positive_count++;
            }
            if (strstr(lower_string, negative_words[j])) {
                negative_count++;
            }
        }
    }

    // Return the sentiment of the string
    if (positive_count > negative_count) {
        return 1;
    } else if (negative_count > positive_count) {
        return -1;
    } else {
        return 0;
    }
}

// Main function
int main() {
    // Get the user input
    char *string = malloc(1024);
    printf("Enter a string: ");
    fgets(string, 1024, stdin);

    // Analyze the sentiment of the string
    int sentiment = analyze_sentiment(string);

    // Print the result
    if (sentiment == 1) {
        printf("The string has a positive sentiment.\n");
    } else if (sentiment == -1) {
        printf("The string has a negative sentiment.\n");
    } else {
        printf("The string has a neutral sentiment.\n");
    }

    // Free the allocated memory
    free(string);

    return 0;
}