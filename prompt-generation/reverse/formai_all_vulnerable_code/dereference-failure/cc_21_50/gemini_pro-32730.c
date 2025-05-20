//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct sentence {
    char *text;
    int len;
};

struct summary {
    char *text;
    int len;
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Read the input file
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }
    fseek(fp, 0, SEEK_END);
    long input_len = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *input = malloc(input_len + 1);
    if (input == NULL) {
        perror("malloc");
        fclose(fp);
        return EXIT_FAILURE;
    }
    fread(input, input_len, 1, fp);
    fclose(fp);
    input[input_len] = '\0';

    // Tokenize the input into sentences
    struct sentence *sentences = NULL;
    int nsentences = 0;
    char *sentence_start = input;
    while (*sentence_start != '\0') {
        char *sentence_end = sentence_start;
        while (*sentence_end != '\0' && *sentence_end != '.' && *sentence_end != '!' && *sentence_end != '?') {
            sentence_end++;
        }
        if (*sentence_end != '\0') {
            struct sentence sentence;
            sentence.text = malloc(sentence_end - sentence_start + 1);
            if (sentence.text == NULL) {
                perror("malloc");
                free(input);
                free(sentences);
                return EXIT_FAILURE;
            }
            strncpy(sentence.text, sentence_start, sentence_end - sentence_start);
            sentence.text[sentence_end - sentence_start] = '\0';
            sentence.len = sentence_end - sentence_start;
            sentences = realloc(sentences, (nsentences + 1) * sizeof(struct sentence));
            if (sentences == NULL) {
                perror("realloc");
                free(input);
                free(sentences);
                return EXIT_FAILURE;
            }
            sentences[nsentences++] = sentence;
            sentence_start = sentence_end + 1;
        } else {
            break;
        }
    }
    free(input);

    // Calculate the sentence scores
    int *scores = malloc(nsentences * sizeof(int));
    if (scores == NULL) {
        perror("malloc");
        free(sentences);
        return EXIT_FAILURE;
    }
    for (int i = 0; i < nsentences; i++) {
        int score = 0;
        char *word = sentences[i].text;
        while (*word != '\0') {
            while (*word != '\0' && !isalpha(*word)) {
                word++;
            }
            if (*word != '\0') {
                score++;
                while (*word != '\0' && isalpha(*word)) {
                    word++;
                }
            }
        }
        scores[i] = score;
    }

    // Find the top-scoring sentences
    struct summary summary;
    summary.text = NULL;
    summary.len = 0;
    int nsentences_to_summarize = nsentences / 10;
    if (nsentences_to_summarize < 1) {
        nsentences_to_summarize = 1;
    }
    for (int i = 0; i < nsentences_to_summarize; i++) {
        int max_score = -1;
        int max_score_index = -1;
        for (int j = 0; j < nsentences; j++) {
            if (scores[j] > max_score) {
                max_score = scores[j];
                max_score_index = j;
            }
        }
        if (max_score_index != -1) {
            summary.text = realloc(summary.text, summary.len + sentences[max_score_index].len + 1);
            if (summary.text == NULL) {
                perror("realloc");
                free(sentences);
                free(scores);
                return EXIT_FAILURE;
            }
            strcpy(summary.text + summary.len, sentences[max_score_index].text);
            summary.len += sentences[max_score_index].len;
            scores[max_score_index] = -1;
        }
    }

    // Print the summary
    printf("%s", summary.text);
    free(summary.text);
    free(sentences);
    free(scores);
    return EXIT_SUCCESS;
}