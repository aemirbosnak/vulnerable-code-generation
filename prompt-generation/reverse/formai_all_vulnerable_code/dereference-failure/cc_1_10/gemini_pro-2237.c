//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: lively
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Split the text into sentences
char **split_sentences(char *text) {
    char **sentences = malloc(sizeof(char *) * 100); // Assuming a maximum of 100 sentences
    int num_sentences = 0;

    char *sentence = strtok(text, ".");
    while (sentence != NULL) {
        sentences[num_sentences++] = strdup(sentence);
        sentence = strtok(NULL, ".");
    }

    return sentences;
}

// Calculate the score of a sentence
int sentence_score(char *sentence) {
    int score = 0;

    // Add points for keywords
    char *keywords[] = {"important", "significant", "key", "crucial", "main"};
    for (int i = 0; i < 5; i++) {
        if (strstr(sentence, keywords[i]) != NULL) {
            score += 5;
        }
    }

    // Add points for length
    score += strlen(sentence) / 10;

    // Add points for complexity
    int num_words = 0;
    char *word = strtok(sentence, " ");
    while (word != NULL) {
        num_words++;
        word = strtok(NULL, " ");
    }
    score += num_words / 5;

    return score;
}

// Summarize the text
char *summarize_text(char *text) {
    // Split the text into sentences
    char **sentences = split_sentences(text);

    // Calculate the score of each sentence
    int *scores = malloc(sizeof(int) * 100);
    for (int i = 0; i < 100; i++) {
        scores[i] = sentence_score(sentences[i]);
    }

    // Find the highest-scoring sentences
    int highest_score = 0;
    int num_highest_sentences = 0;
    for (int i = 0; i < 100; i++) {
        if (scores[i] > highest_score) {
            highest_score = scores[i];
            num_highest_sentences = 1;
        } else if (scores[i] == highest_score) {
            num_highest_sentences++;
        }
    }

    // Create the summary
    char *summary = malloc(sizeof(char) * 1000); // Assuming a maximum summary length of 1000 characters
    int summary_length = 0;

    for (int i = 0; i < 100; i++) {
        if (scores[i] == highest_score) {
            summary_length += strlen(sentences[i]) + 1; // Add 1 for the period at the end of the sentence
            if (summary_length > 1000) {
                break;
            }
            strcat(summary, sentences[i]);
            strcat(summary, ". ");
        }
    }

    // Return the summary
    return summary;
}

int main() {
    // Get the text from the user
    char text[1000];
    printf("Enter the text you want to summarize: ");
    gets(text);

    // Summarize the text
    char *summary = summarize_text(text);

    // Print the summary
    printf("Summary: %s\n", summary);

    return 0;
}