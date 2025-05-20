//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1000
#define MAX_SUMMARY_LENGTH 200
#define MAX_SENTENCE_LENGTH 200
#define MAX_NUM_SENTENCES 50

// Structure to hold each sentence and its word count
typedef struct {
    char sentence[MAX_SENTENCE_LENGTH];
    int word_count;
} Sentence;

// Function to tokenize a string into sentences
int tokenize_sentences(char *text, Sentence *sentences) {
    char *token;
    int count = 0;

    // Split text into sentences based on punctuation
    token = strtok(text, ".!?");
    while (token != NULL && count < MAX_NUM_SENTENCES) {
        strncpy(sentences[count].sentence, token, MAX_SENTENCE_LENGTH - 1);
        sentences[count].sentence[MAX_SENTENCE_LENGTH - 1] = '\0'; // Null-terminate
        // Count words in the sentence
        sentences[count].word_count = 0;
        char *word_token = strtok(token, " ");
        while (word_token != NULL) {
            sentences[count].word_count++;
            word_token = strtok(NULL, " ");
        }
        count++;
        token = strtok(NULL, ".!?");
    }
    return count;
}

// Function to create a summary from the sentences
void create_summary(Sentence *sentences, int num_sentences, char *summary) {
    int total_words = 0;
    int selected_word_count = 0;
    int select_index = 0;
    char *summary_ptr = summary;

    // Count total words in all sentences
    for (int i = 0; i < num_sentences; i++) {
        total_words += sentences[i].word_count;
    }
    
    // Select sentences based on word count
    for (int i = 0; i < num_sentences && selected_word_count < MAX_SUMMARY_LENGTH; i++) {
        int add_words = sentences[i].word_count;
        if (selected_word_count + add_words <= MAX_SUMMARY_LENGTH) {
            select_index = i;
            selected_word_count += add_words;
            summary_ptr += sprintf(summary_ptr, "%s. ", sentences[i].sentence);
        }
    }

    // Null-terminate the summary string
    summary[strlen(summary) - 1] = '\0'; // Remove the last space
}

// Main function to handle input and output
int main() {
    char text[MAX_TEXT_LENGTH];
    Sentence sentences[MAX_NUM_SENTENCES];
    char summary[MAX_SUMMARY_LENGTH + 1] = "";

    // Input the original text
    printf("Enter text (max length %d characters):\n", MAX_TEXT_LENGTH);
    fgets(text, sizeof(text), stdin);

    // Tokenize the text into sentences
    int num_sentences = tokenize_sentences(text, sentences);
    printf("\nTotal Sentences: %d\n", num_sentences);
    
    // Create a summary
    create_summary(sentences, num_sentences, summary);
    
    // Output the summary
    printf("\nSummary:\n%s\n", summary);
    
    return 0;
}