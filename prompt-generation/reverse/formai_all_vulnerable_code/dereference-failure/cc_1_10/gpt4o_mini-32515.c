//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000
#define MAX_SENTENCES 100
#define MAX_WORDS 100

// Function to calculate the number of sentences in the input text
int count_sentences(const char *text) {
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            count++;
        }
    }
    return count;
}

// Function to split text into sentences
void split_sentences(const char *text, char sentences[MAX_SENTENCES][MAX_LENGTH]) {
    char *token;
    char *text_copy = strdup(text);
    int index = 0;

    token = strtok(text_copy, ".!?");
    while (token != NULL && index < MAX_SENTENCES) {
        strcpy(sentences[index], token);
        index++;
        token = strtok(NULL, ".!?");
    }
    free(text_copy);
}

// Function to count words in a sentence
int count_words(const char *sentence) {
    int count = 0;
    char *token = strtok(strdup(sentence), " ");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

// Function to summarize text by selecting the top few sentences
void summarize(const char *text, char *summary, int num_sentences) {
    char sentences[MAX_SENTENCES][MAX_LENGTH];
    int total_sentences = count_sentences(text);
    split_sentences(text, sentences);
    
    int words_in_summary = 0;
    summary[0] = '\0'; // Start with an empty summary

    for (int i = 0; i < total_sentences && i < num_sentences; i++) {
        int word_count = count_words(sentences[i]);
        if (words_in_summary + word_count <= 50) {  // Limit to 50 words
            strcat(summary, sentences[i]);
            strcat(summary, ". "); // Re-adding period for sentence separation
            words_in_summary += word_count;
        }
    }
}

// Main function: The creator of the summarization
int main(void) {
    char text[MAX_LENGTH];
    char summary[MAX_LENGTH];

    printf("Enter the text to summarize (up to %d characters):\n", MAX_LENGTH);
    fgets(text, MAX_LENGTH, stdin);

    // Generate a summary of the input text
    summarize(text, summary, 5); // Adjust to summarize up to 5 sentences

    printf("\n--- Summary ---\n");
    printf("%s\n", summary);
    return 0;
}