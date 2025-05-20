//FormAI DATASET v1.0 Category: Text Summarizer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_WORDS 1000

char* summarizer(char* text);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./summarizer <file>\n");
        return 1;
    }
    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Unable to open file %s\n", argv[1]);
        return 1;
    }
    char* text = (char*) malloc(sizeof(char) * MAX_WORDS);
    if (text == NULL) {
        printf("Unable to allocate memory\n");
        return 1;
    }
    fgets(text, MAX_WORDS, fp);
    char* summary = summarizer(text);
    if (summary == NULL) {
        printf("Unable to summarize text\n");
        return 1;
    }
    printf("Summary: %s\n", summary);
    free(text);
    free(summary);
    fclose(fp);
    return 0;
}

char* summarizer(char* text) {
    char* summary = (char*) malloc(sizeof(char) * MAX_WORDS);
    if (summary == NULL) {
        return NULL;
    }
    char* sentences[MAX_SENTENCES];
    int num_sentences = 0;
    int sentence_length[MAX_SENTENCES];
    char* ptr_sentence;
    char* ptr_word;
    ptr_sentence = strtok(text, ".\n");
    while (ptr_sentence != NULL && num_sentences < MAX_SENTENCES) {
        sentences[num_sentences] = ptr_sentence;
        sentence_length[num_sentences] = strlen(sentences[num_sentences]);
        ptr_sentence = strtok(NULL, ".\n");
        num_sentences++;
    }
    int total_words = 0;
    for (int i = 0; i < num_sentences; i++) {
        ptr_word = strtok(sentences[i], " \t");
        while (ptr_word != NULL) {
            total_words++;
            ptr_word = strtok(NULL, " \t");
        }
    }
    ptr_sentence = strtok(text, ".\n");
    int num_words = 0;
    int summary_length = 0;
    while (ptr_sentence != NULL && num_words < total_words / 2) {
        int sentence_rank = 0;
        ptr_word = strtok(ptr_sentence, " \t");
        while (ptr_word != NULL) {
            sentence_rank++;
            ptr_word = strtok(NULL, " \t");
        }
        int sentence_score = sentence_rank * sentence_rank / sentence_length[num_sentences];
        if (sentence_score > 3) {
            strcat(summary, ptr_sentence);
            strcat(summary, ". ");
            summary_length += sentence_length[num_sentences];
        }
        ptr_sentence = strtok(NULL, ".\n");
        num_words += sentence_rank;
    }
    if (summary_length == 0) {
        free(summary);
        return NULL;
    }
    return summary;
}