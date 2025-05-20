//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the sentiment dictionary
char *sentimentDictionary[] = {
    "good", "great", "excellent", "superb", "awesome",
    "bad", "terrible", "horrible", "awful", "dreadful"
};

// Function to determine the sentiment of a given text
int determineSentiment(char *text) {
    int sentiment = 0;
    for (int i = 0; i < strlen(sentimentDictionary); i++) {
        if (strstr(text, sentimentDictionary[i])) {
            sentiment = (i < 5) ? 1 : -1;
            break;
        }
    }
    return sentiment;
}

// Function to analyze the sentiment of a given text file
void analyzeSentiment(char *filename) {
    // Read the text file into a string
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s", filename);
        return;
    }
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *text = malloc(fileSize + 1);
    fread(text, 1, fileSize, file);
    fclose(file);

    // Analyze the sentiment of the text
    int sentiment = determineSentiment(text);

    // Print the sentiment of the text file
    printf("Sentiment of the file \"%s\": %s\n", filename, (sentiment == 1) ? "positive" : "negative");
}

// Main function
int main() {
    // Analyze the sentiment of the given text files
    analyzeSentiment("positive.txt");
    analyzeSentiment("negative.txt");

    return 0;
}