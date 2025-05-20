//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_WORDS 100

struct sentence {
    char *words[MAX_WORDS];
    int num_words;
};

struct summary {
    struct sentence sentences[MAX_SENTENCES];
    int num_sentences;
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <text file>\n", argv[0]);
        return 1;
    }

    // Read the text file into a string.
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *text = malloc(size + 1);
    if (text == NULL) {
        perror("Error allocating memory");
        return 1;
    }
    fread(text, 1, size, fp);
    fclose(fp);
    text[size] = '\0';

    // Tokenize the text into sentences.
    struct sentence *sentences = malloc(sizeof(struct sentence) * MAX_SENTENCES);
    if (sentences == NULL) {
        perror("Error allocating memory");
        return 1;
    }
    int num_sentences = 0;
    char *sentence_start = text;
    while (*sentence_start != '\0') {
        // Find the end of the sentence.
        char *sentence_end = sentence_start;
        while (*sentence_end != '.' && *sentence_end != '!' && *sentence_end != '?') {
            sentence_end++;
        }

        // Copy the sentence into the array.
        sentences[num_sentences].words[0] = sentence_start;
        int num_words = 1;
        char *word_start = sentence_start + 1;
        while (word_start <= sentence_end) {
            // Find the end of the word.
            char *word_end = word_start;
            while (*word_end != ' ' && *word_end != '\t' && *word_end != '\n') {
                word_end++;
            }

            // Copy the word into the array.
            sentences[num_sentences].words[num_words] = word_start;
            num_words++;

            // Skip the whitespace.
            word_start = word_end + 1;
        }
        sentences[num_sentences].num_words = num_words;
        num_sentences++;

        // Advance to the next sentence.
        sentence_start = sentence_end + 1;
    }

    // Summarize the text.
    struct summary summary;
    summary.num_sentences = 0;
    for (int i = 0; i < num_sentences; i++) {
        // Find the most important sentence.
        int max_importance = 0;
        int most_important_sentence = -1;
        for (int j = 0; j < num_sentences; j++) {
            int importance = 0;
            for (int k = 0; k < sentences[j].num_words; k++) {
                if (strcmp(sentences[j].words[k], "important") == 0 || strcmp(sentences[j].words[k], "significant") == 0) {
                    importance++;
                }
            }
            if (importance > max_importance) {
                max_importance = importance;
                most_important_sentence = j;
            }
        }

        // Add the most important sentence to the summary.
        summary.sentences[summary.num_sentences] = sentences[most_important_sentence];
        summary.num_sentences++;

        // Remove the most important sentence from the array.
        for (int j = most_important_sentence; j < num_sentences - 1; j++) {
            sentences[j] = sentences[
                j + 1];
        }
        num_sentences--;
    }

    // Print the summary.
    for (int i = 0; i < summary.num_sentences; i++) {
        for (int j = 0; j < summary.sentences[i].num_words; j++) {
            printf("%s ", summary.sentences[i].words[j]);
        }
        printf("\n");
    }

    // Free the memory.
    free(text);
    free(sentences);
    return 0;
}