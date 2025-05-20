//FormAI DATASET v1.0 Category: Text Summarizer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 200
#define MAX_SENTENCE_LENGTH 300

char* summarize(char* input_text) {
    // Split input text into individual sentences
    char* sentences[MAX_SENTENCES];
    int num_sentences = 0;
    char* sentence_start = input_text;
    while (*input_text) {
        if (*input_text == '.' || *input_text == '?' || *input_text == '!') {
            int sentence_length = input_text - sentence_start + 1;
            sentences[num_sentences] = (char*)malloc(sentence_length + 1);
            strncpy(sentences[num_sentences], sentence_start, sentence_length);
            sentences[num_sentences][sentence_length] = '\0';
            num_sentences++;
            if (num_sentences == MAX_SENTENCES) break;
            sentence_start = input_text + 1;
        }
        input_text++;
    }

    // Find the sentence with the most unique words
    int sentence_scores[MAX_SENTENCES] = { 0 };
    for (int i = 0; i < num_sentences; i++) {
        char* sentence_words[MAX_SENTENCE_LENGTH];
        int num_words = 0;
        char* word_start = sentences[i];

        // Split sentence into individual words
        while (*sentences[i]) {
            if (*sentences[i] == ' ' || *sentences[i] == '\t') {
                int word_length = sentences[i] - word_start;
                sentence_words[num_words] = (char*)malloc(word_length + 1);
                strncpy(sentence_words[num_words], word_start, word_length);
                sentence_words[num_words][word_length] = '\0';
                num_words++;
                word_start = sentences[i] + 1;
            }
            sentences[i]++;
        }

        // Count unique words in sentence
        for (int j = 0; j < num_words; j++) {
            int unique = 1;
            for (int k = 0; k < num_sentences; k++) {
                if (k == i) continue;
                if (strstr(sentences[k], sentence_words[j])) {
                    unique = 0;
                    break;
                }
            }
            if (unique) sentence_scores[i]++;
            free(sentence_words[j]);
        }
    }

    // Find index of highest-scoring sentence
    int highest_scoring_sentence = 0;
    for (int i = 1; i < num_sentences; i++) {
        if (sentence_scores[i] > sentence_scores[highest_scoring_sentence]) {
            highest_scoring_sentence = i;
        }
    }

    // Construct summarized output text
    char* output_text = sentences[highest_scoring_sentence];
    for (int i = 0; i < num_sentences; i++) {
        if (i == highest_scoring_sentence) continue;
        free(sentences[i]);
    }

    return output_text;
}

int main() {
    char* input_text = "The quick brown fox jumped over the lazy dog. A stitch in time saves nine. The early bird catches the worm. The pen is mightier than the sword.";
    char* summary = summarize(input_text);
    printf("%s", summary);
    free(summary);
    return 0;
}