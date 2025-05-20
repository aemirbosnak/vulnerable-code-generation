//FormAI DATASET v1.0 Category: Text Summarizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 20
#define MAX_SENTENCE_LENGTH 200

// Function prototypes
void summarize(char *input_text);
int count_sentences(char *text);
int count_words(char *sentence);
char **get_sentences(char *text);
void free_sentences(char **sentences, int num_sentences);
char *get_best_sentence(char **sentences, int num_sentences, int *used_sentences, char *summary, int summary_size);
void append_sentence(char *summary, int summary_size, char *sentence);
int is_already_used(int *used_sentences, int sentence_index);

int main() {
    char input_text[MAX_SENTENCES * MAX_SENTENCE_LENGTH];
    printf("Enter text to summarize:\n");
    fgets(input_text, sizeof(input_text), stdin);

    summarize(input_text);

    return 0;
}

void summarize(char *input_text) {
    // Count the number of sentences in the input text
    int num_sentences = count_sentences(input_text);

    // If there are too many sentences, reduce to the maximum number
    if (num_sentences > MAX_SENTENCES) {
        num_sentences = MAX_SENTENCES;
    }

    // Get an array of the individual sentences
    char **sentences = get_sentences(input_text);

    // Keep track of which sentences have been used in the summary
    int used_sentences[MAX_SENTENCES] = { 0 };

    // Create a buffer for the summary that is twice the length of the
    // maximum sentence length, in case every sentence is used
    int summary_size = MAX_SENTENCE_LENGTH * 2;
    char summary[summary_size];
    summary[0] = '\0';

    // Loop until we have added the maximum number of sentences to the summary
    while (strlen(summary) / MAX_SENTENCE_LENGTH < MAX_SENTENCES) {
        // Get the best sentence that we haven't used yet
        char *best_sentence = get_best_sentence(sentences, num_sentences, used_sentences, summary, summary_size);

        // If there are no more sentences left, we're done
        if (best_sentence == NULL) {
            break;
        }

        // Add the best sentence to the summary
        append_sentence(summary, summary_size, best_sentence);

        // Mark the sentence as used
        int sentence_index = best_sentence - input_text;
        used_sentences[sentence_index] = 1;
    }

    // Print the summary
    printf("Summary:\n%s\n", summary);

    // Free the memory used for the sentences
    free_sentences(sentences, num_sentences);
}

int count_sentences(char *text) {
    int num_sentences = 0;

    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            num_sentences++;
        }
    }

    return num_sentences;
}

int count_words(char *sentence) {
    int num_words = 1;

    for (int i = 0; i < strlen(sentence); i++) {
        if (sentence[i] == ' ') {
            num_words++;
        }
    }

    return num_words;
}

char **get_sentences(char *text) {
    char **sentences = malloc(MAX_SENTENCES * sizeof(char *));
    int sentence_index = 0;
    int sentence_start = 0;

    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            int sentence_length = i - sentence_start + 1;
            char *sentence = malloc(sentence_length + 1);
            strncpy(sentence, text + sentence_start, sentence_length);
            sentence[sentence_length] = '\0';
            sentences[sentence_index] = sentence;
            sentence_index++;
            sentence_start = i + 1;
        }
    }

    return sentences;
}

void free_sentences(char **sentences, int num_sentences) {
    for (int i = 0; i < num_sentences; i++) {
        free(sentences[i]);
    }

    free(sentences);
}

char *get_best_sentence(char **sentences, int num_sentences, int *used_sentences, char *summary, int summary_size) {
    char *best_sentence = NULL;
    int best_sentence_score = 0;

    for (int i = 0; i < num_sentences; i++) {
        if (!is_already_used(used_sentences, i)) {
            // Calculate the score for the current sentence
            char *sentence = sentences[i];
            int sentence_score = count_words(sentence);

            // Check if the sentence fits in the summary
            int summary_length = strlen(summary) + strlen(sentence);
            if (summary_length >= summary_size) {
                continue;
            }

            // If the new sentence is better than the current best, update the best
            if (sentence_score > best_sentence_score) {
                best_sentence = sentence;
                best_sentence_score = sentence_score;
            }
        }
    }

    return best_sentence;
}

void append_sentence(char *summary, int summary_size, char *sentence) {
    strcat(summary, sentence);
    strcat(summary, " ");
}

int is_already_used(int *used_sentences, int sentence_index) {
    return used_sentences[sentence_index];
}