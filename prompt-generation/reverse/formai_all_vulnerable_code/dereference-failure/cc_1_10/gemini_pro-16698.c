//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_WORDS 1000

typedef struct sentence {
    char *words[MAX_WORDS];
    int num_words;
} sentence;

typedef struct summary {
    sentence sentences[MAX_SENTENCES];
    int num_sentences;
} summary;

summary summarize_text(char *text) {
    // Tokenize the text into sentences
    char *sentences[MAX_SENTENCES];
    int num_sentences = 0;
    char *sentence_start = text;
    while (*sentence_start != '\0') {
        // Find the end of the sentence
        char *sentence_end = strchr(sentence_start, '.');
        if (sentence_end == NULL) {
            sentence_end = strchr(sentence_start, '!');
        }
        if (sentence_end == NULL) {
            sentence_end = strchr(sentence_start, '?');
        }
        if (sentence_end == NULL) {
            break;
        }
        // Copy the sentence into the array
        sentences[num_sentences] = malloc(sentence_end - sentence_start + 1);
        strncpy(sentences[num_sentences], sentence_start, sentence_end - sentence_start);
        sentences[num_sentences][sentence_end - sentence_start] = '\0';
        num_sentences++;
        // Move to the next sentence
        sentence_start = sentence_end + 1;
    }
    // Tokenize the sentences into words
    summary summary;
    summary.num_sentences = num_sentences;
    for (int i = 0; i < num_sentences; i++) {
        char *words[MAX_WORDS];
        int num_words = 0;
        char *word_start = sentences[i];
        while (*word_start != '\0') {
            // Find the end of the word
            char *word_end = strchr(word_start, ' ');
            if (word_end == NULL) {
                word_end = strchr(word_start, ',');
            }
            if (word_end == NULL) {
                word_end = strchr(word_start, ';');
            }
            if (word_end == NULL) {
                break;
            }
            // Copy the word into the array
            words[num_words] = malloc(word_end - word_start + 1);
            strncpy(words[num_words], word_start, word_end - word_start);
            words[num_words][word_end - word_start] = '\0';
            num_words++;
            // Move to the next word
            word_start = word_end + 1;
        }
        // Copy the words into the summary
        summary.sentences[i].num_words = num_words;
        for (int j = 0; j < num_words; j++) {
            summary.sentences[i].words[j] = words[j];
        }
    }
    // Free the sentences
    for (int i = 0; i < num_sentences; i++) {
        free(sentences[i]);
    }
    return summary;
}

void print_summary(summary summary) {
    for (int i = 0; i < summary.num_sentences; i++) {
        for (int j = 0; j < summary.sentences[i].num_words; j++) {
            printf("%s ", summary.sentences[i].words[j]);
        }
        printf(". ");
    }
    printf("\n");
}

int main() {
    // Get the text from the user
    char text[1000];
    printf("Enter the text to be summarized: ");
    fgets(text, 1000, stdin);
    // Summarize the text
    summary summary = summarize_text(text);
    // Print the summary
    printf("Summary: ");
    print_summary(summary);
    // Free the summary
    for (int i = 0; i < summary.num_sentences; i++) {
        for (int j = 0; j < summary.sentences[i].num_words; j++) {
            free(summary.sentences[i].words[j]);
        }
    }
    return 0;
}