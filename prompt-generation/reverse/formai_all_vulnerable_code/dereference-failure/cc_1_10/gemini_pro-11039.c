//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a sentence
#define MAX_SENTENCE_LENGTH 1024

// Define the number of words in the dictionary
#define NUM_WORDS 1000

// Define the dictionary of words and their sentiments
char *dictionary[NUM_WORDS];
int sentiments[NUM_WORDS];

// Load the dictionary from a file
void load_dictionary(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening dictionary file");
        exit(1);
    }

    int i = 0;
    while (!feof(file)) {
        char line[MAX_SENTENCE_LENGTH];
        if (fgets(line, MAX_SENTENCE_LENGTH, file) != NULL) {
            char *word = strtok(line, ",");
            char *sentiment = strtok(NULL, ",");
            dictionary[i] = strdup(word);
            sentiments[i] = atoi(sentiment);
            i++;
        }
    }

    fclose(file);
}

// Analyze the sentiment of a sentence
int analyze_sentiment(char *sentence) {
    // Tokenize the sentence into words
    char *words[MAX_SENTENCE_LENGTH];
    int num_words = 0;
    char *word = strtok(sentence, " ");
    while (word != NULL) {
        words[num_words] = word;
        num_words++;
        word = strtok(NULL, " ");
    }

    // Calculate the total sentiment of the sentence
    int total_sentiment = 0;
    for (int i = 0; i < num_words; i++) {
        // Find the word in the dictionary
        int index = -1;
        for (int j = 0; j < NUM_WORDS; j++) {
            if (strcmp(words[i], dictionary[j]) == 0) {
                index = j;
                break;
            }
        }

        // If the word is found in the dictionary, add its sentiment to the total
        if (index != -1) {
            total_sentiment += sentiments[index];
        }
    }

    return total_sentiment;
}

// Print the sentiment of a sentence
void print_sentiment(int sentiment) {
    if (sentiment > 0) {
        printf("Positive\n");
    } else if (sentiment < 0) {
        printf("Negative\n");
    } else {
        printf("Neutral\n");
    }
}

// Main function
int main() {
    // Load the dictionary
    load_dictionary("dictionary.txt");

    // Get the sentence from the user
    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence: ");
    gets(sentence);

    // Analyze the sentiment of the sentence
    int sentiment = analyze_sentiment(sentence);

    // Print the sentiment of the sentence
    print_sentiment(sentiment);

    return 0;
}