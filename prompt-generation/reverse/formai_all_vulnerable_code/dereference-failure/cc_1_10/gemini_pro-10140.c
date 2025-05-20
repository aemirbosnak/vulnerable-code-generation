//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: high level of detail
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *text;
    int length;
} Text;

typedef struct {
    char *sentence;
    int length;
    int sentence_number;
} Sentence;

typedef struct {
    Sentence *sentences;
    int num_sentences;
} Summary;

// Create a new text structure for a given string.
Text *new_text(const char *str) {
    Text *text = malloc(sizeof(Text));
    text->text = strdup(str);
    text->length = strlen(str);
    return text;
}

// Free the memory allocated for a text structure.
void free_text(Text *text) {
    free(text->text);
    free(text);
}

// Split a text into an array of sentences.
Sentence *split_into_sentences(Text *text) {
    Sentence *sentences = malloc(sizeof(Sentence) * text->length);
    int num_sentences = 0;

    char *start = text->text;
    char *end = text->text;

    while (*end != '\0') {
        if (*end == '.' || *end == '!' || *end == '?') {
            sentences[num_sentences].sentence = start;
            sentences[num_sentences].length = end - start + 1;
            sentences[num_sentences].sentence_number = num_sentences + 1;
            num_sentences++;
            start = end + 1;
        }
        end++;
    }

    sentences[num_sentences].sentence = start;
    sentences[num_sentences].length = end - start + 1;
    sentences[num_sentences].sentence_number = num_sentences + 1;
    num_sentences++;

    return sentences;
}

// Free the memory allocated for an array of sentences.
void free_sentences(Sentence *sentences, int num_sentences) {
    for (int i = 0; i < num_sentences; i++) {
        free(sentences[i].sentence);
    }
    free(sentences);
}

// Create a new summary structure for a given text.
Summary *new_summary(Text *text) {
    Summary *summary = malloc(sizeof(Summary));
    summary->sentences = split_into_sentences(text);
    summary->num_sentences = 0;

    return summary;
}

// Free the memory allocated for a summary structure.
void free_summary(Summary *summary) {
    free_sentences(summary->sentences, summary->num_sentences);
    free(summary);
}

// Add a sentence to a summary.
void add_sentence_to_summary(Summary *summary, Sentence *sentence) {
    summary->sentences[summary->num_sentences] = *sentence;
    summary->num_sentences++;
}

// Sort the sentences in a summary by their length.
void sort_sentences_by_length(Summary *summary) {
    qsort(summary->sentences, summary->num_sentences, sizeof(Sentence),
        (int (*)(const void *, const void *))strcmp);
}

// Get the top N sentences from a summary.
Summary *get_top_n_sentences(Summary *summary, int n) {
    Summary *top_n_sentences = new_summary(summary);

    for (int i = 0; i < n; i++) {
        add_sentence_to_summary(top_n_sentences, &summary->sentences[i]);
    }

    return top_n_sentences;
}

// Print a summary to the console.
void print_summary(Summary *summary) {
    for (int i = 0; i < summary->num_sentences; i++) {
        printf("%d. %s\n", summary->sentences[i].sentence_number,
            summary->sentences[i].sentence);
    }
}

int main() {
    Text *text = new_text("This is a sample text to be summarized. It has multiple sentences and is fairly long. We will use this text to demonstrate the text summarizer.");
    Summary *summary = new_summary(text);
    sort_sentences_by_length(summary);
    Summary *top_n_sentences = get_top_n_sentences(summary, 3);
    print_summary(top_n_sentences);
    free_summary(summary);
    free_text(text);
    return 0;
}