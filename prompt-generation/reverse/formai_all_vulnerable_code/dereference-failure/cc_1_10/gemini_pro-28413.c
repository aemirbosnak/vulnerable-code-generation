//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORDS 1000
#define MAX_SENTENCES 100

// Define the structure of a word
typedef struct {
    char *word;
    int frequency;
    float sentiment;
} Word;

// Define the structure of a sentence
typedef struct {
    char *sentence;
    int length;
    float sentiment;
} Sentence;

// Define the structure of the sentiment analysis tool
typedef struct {
    Word words[MAX_WORDS];
    int num_words;
    Sentence sentences[MAX_SENTENCES];
    int num_sentences;
} SentimentAnalysisTool;

// Create a new sentiment analysis tool
SentimentAnalysisTool *new_sentiment_analysis_tool() {
    SentimentAnalysisTool *tool = malloc(sizeof(SentimentAnalysisTool));
    tool->num_words = 0;
    tool->num_sentences = 0;
    return tool;
}

// Add a word to the sentiment analysis tool
void add_word(SentimentAnalysisTool *tool, char *word, float sentiment) {
    // Convert the word to lowercase
    for (int i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }

    // Check if the word already exists in the tool
    for (int i = 0; i < tool->num_words; i++) {
        if (strcmp(tool->words[i].word, word) == 0) {
            // If the word already exists, increment its frequency and update its sentiment
            tool->words[i].frequency++;
            tool->words[i].sentiment = (tool->words[i].sentiment + sentiment) / 2;
            return;
        }
    }

    // If the word does not exist, add it to the tool
    tool->words[tool->num_words].word = strdup(word);
    tool->words[tool->num_words].frequency = 1;
    tool->words[tool->num_words].sentiment = sentiment;
    tool->num_words++;
}

// Add a sentence to the sentiment analysis tool
void add_sentence(SentimentAnalysisTool *tool, char *sentence) {
    // Convert the sentence to lowercase
    for (int i = 0; i < strlen(sentence); i++) {
        sentence[i] = tolower(sentence[i]);
    }

    // Tokenize the sentence into words
    char *words[MAX_WORDS];
    int num_words = 0;
    char *token = strtok(sentence, " ");
    while (token != NULL) {
        words[num_words++] = token;
        token = strtok(NULL, " ");
    }

    // Calculate the sentiment of the sentence
    float sentiment = 0;
    for (int i = 0; i < num_words; i++) {
        // Find the word in the tool
        int index = -1;
        for (int j = 0; j < tool->num_words; j++) {
            if (strcmp(tool->words[j].word, words[i]) == 0) {
                index = j;
                break;
            }
        }

        // If the word is not found, set its sentiment to 0
        if (index == -1) {
            sentiment += 0;
        } else {
            // Add the sentiment of the word to the sentiment of the sentence
            sentiment += tool->words[index].sentiment;
        }
    }

    // Add the sentence to the tool
    tool->sentences[tool->num_sentences].sentence = strdup(sentence);
    tool->sentences[tool->num_sentences].length = num_words;
    tool->sentences[tool->num_sentences].sentiment = sentiment;
    tool->num_sentences++;
}

// Analyze the sentiment of a text
float analyze_sentiment(SentimentAnalysisTool *tool, char *text) {
    // Tokenize the text into sentences
    char *sentences[MAX_SENTENCES];
    int num_sentences = 0;
    char *token = strtok(text, ".");
    while (token != NULL) {
        sentences[num_sentences++] = token;
        token = strtok(NULL, ".");
    }

    // Calculate the sentiment of the text
    float sentiment = 0;
    for (int i = 0; i < num_sentences; i++) {
        // Add the sentence to the tool
        add_sentence(tool, sentences[i]);

        // Add the sentiment of the sentence to the sentiment of the text
        sentiment += tool->sentences[i].sentiment;
    }

    // Return the sentiment of the text
    return sentiment;
}

// Free the memory allocated by the sentiment analysis tool
void free_sentiment_analysis_tool(SentimentAnalysisTool *tool) {
    // Free the words
    for (int i = 0; i < tool->num_words; i++) {
        free(tool->words[i].word);
    }

    // Free the sentences
    for (int i = 0; i < tool->num_sentences; i++) {
        free(tool->sentences[i].sentence);
    }

    // Free the tool
    free(tool);
}

// Print the sentiment analysis tool
void print_sentiment_analysis_tool(SentimentAnalysisTool *tool) {
    // Print the words
    printf("Words:\n");
    for (int i = 0; i < tool->num_words; i++) {
        printf("%s: %d, %f\n", tool->words[i].word, tool->words[i].frequency, tool->words[i].sentiment);
    }

    // Print the sentences
    printf("Sentences:\n");
    for (int i = 0; i < tool->num_sentences; i++) {
        printf("%s: %d, %f\n", tool->sentences[i].sentence, tool->sentences[i].length, tool->sentences[i].sentiment);
    }
}

// Test the sentiment analysis tool
int main() {
    // Create a new sentiment analysis tool
    SentimentAnalysisTool *tool = new_sentiment_analysis_tool();

    // Add some words to the tool
    add_word(tool, "good", 1.0);
    add_word(tool, "bad", -1.0);
    add_word(tool, "ok", 0.0);

    // Add some sentences to the tool
    add_sentence(tool, "This is a good movie.");
    add_sentence(tool, "This is a bad movie.");
    add_sentence(tool, "This is an ok movie.");

    // Print the sentiment analysis tool
    print_sentiment_analysis_tool(tool);

    // Analyze the sentiment of a text
    float sentiment = analyze_sentiment(tool, "This is a good movie. This is a bad movie.");
    printf("Sentiment: %f\n", sentiment);

    // Free the memory allocated by the sentiment analysis tool
    free_sentiment_analysis_tool(tool);

    return 0;
}