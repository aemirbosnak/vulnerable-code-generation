//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 10000
#define MAX_SENTENCES 100
#define MAX_LENGTH 256

// Structure to hold sentences and their importance score
typedef struct {
    char sentence[MAX_LENGTH];
    int score;
} Sentence;

// Function to calculate sentence scores based on word frequency
void calculate_scores(Sentence sentences[], int sentence_count, char *word_list[], int word_count) {
    for (int i = 0; i < sentence_count; i++) {
        sentences[i].score = 0;
        for (int j = 0; j < word_count; j++) {
            if (strstr(sentences[i].sentence, word_list[j]) != NULL) {
                sentences[i].score++;
            }
        }
    }
}

// Function to read contents from a file
char* read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Failed to open the file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char *content = (char *)malloc(MAX_SIZE);
    size_t n = fread(content, 1, MAX_SIZE - 1, file);
    content[n] = '\0';
    fclose(file);
    return content;
}

// Function to split text into sentences
int split_into_sentences(char *text, Sentence sentences[]) {
    char *token = strtok(text, ".!?");
    int count = 0;

    while (token != NULL && count < MAX_SENTENCES) {
        strcpy(sentences[count].sentence, token);
        sentences[count].score = 0; // Initialize score to zero
        count++;
        token = strtok(NULL, ".!?");
    }

    return count;
}

// Function to summarize text
void summarize_text(Sentence sentences[], int sentence_count) {
    // Sort sentences based on their scores
    for (int i = 0; i < sentence_count; i++) {
        for (int j = i + 1; j < sentence_count; j++) {
            if (sentences[j].score > sentences[i].score) {
                Sentence temp = sentences[i];
                sentences[i] = sentences[j];
                sentences[j] = temp;
            }
        }
    }

    // Print the top 5 sentences as a summary
    printf("\n--- Text Summary ---\n");
    for (int i = 0; i < sentence_count && i < 5; i++) {
        if (sentences[i].score > 0) {
            printf("%s.\n", sentences[i].sentence);
        }
    }
}

int main() {
    printf("Welcome to the Creative C Text Summarizer!\n");
    printf("Let's unlock the essence of your text together!\n");

    char *filename = "input.txt"; // The input file containing text
    char *text = read_file(filename);
    
    // Generate a list of keywords/important words for scoring
    char *word_list[] = {"important", "creative", "summary", "text", "C", "program", "knowledge"};
    int word_count = sizeof(word_list) / sizeof(word_list[0]);

    Sentence sentences[MAX_SENTENCES];
    int sentence_count = split_into_sentences(text, sentences);
    
    calculate_scores(sentences, sentence_count, word_list, word_count);
    summarize_text(sentences, sentence_count);
    
    free(text);
    printf("Summarization complete! Dive into the highlights!\n");
    return EXIT_SUCCESS;
}