//Falcon2-11B DATASET v1.0 Category: Sentiment analysis tool ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Function to analyze sentiment of a given text
char *analyze_sentiment(char *text) {
    // Convert the text to lowercase
    char text_lower[1000];
    strcpy(text_lower, text);
    for (int i = 0; text_lower[i]!= '\0'; i++) {
        text_lower[i] = tolower(text_lower[i]);
    }
    
    // Initialize result string
    char result[1000];
    strcpy(result, "Unknown");
    
    // Iterate over each character in the text
    for (int i = 0; i < strlen(text_lower); i++) {
        // Check if the character is a letter or digit
        if (isalpha(text_lower[i]) || isdigit(text_lower[i])) {
            // Check if the character is in the 'positive' list
            if (strstr(text_lower + i, "pos")!= NULL) {
                strcpy(result, "Positive");
            }
            // Check if the character is in the 'negative' list
            else if (strstr(text_lower + i, "neg")!= NULL) {
                strcpy(result, "Negative");
            }
            // If the character is not in either list, leave it as 'Unknown'
            else {
                strcpy(result, "Unknown");
            }
            // Break out of the loop once we've found the sentiment
            break;
        }
    }
    
    // Return the result string
    return result;
}

int main() {
    // Input text to analyze
    char text[1000];
    printf("Enter a text to analyze: ");
    fgets(text, sizeof(text), stdin);
    
    // Analyze sentiment of the input text
    char *result = analyze_sentiment(text);
    
    // Print the result
    printf("Sentiment: %s\n", result);
    
    // Clean up memory
    free(result);
    
    return 0;
}