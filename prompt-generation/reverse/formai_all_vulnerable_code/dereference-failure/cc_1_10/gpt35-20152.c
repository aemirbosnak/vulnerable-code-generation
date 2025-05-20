//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SENTENCES 10
#define MAX_WORDS 200
#define MAX_LENGTH 2000

char *read_input(FILE *fp) {
    char *input = malloc(sizeof(char) * MAX_LENGTH);
    char c;
    int i = 0;
    while ((c = fgetc(fp)) != EOF) {
        input[i++] = c;
    }
    input[i] = '\0';

    return input;
}

int get_word_count(char *sentence) {
    int count = 0;
    char *token = strtok(sentence, " ");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

char **split_into_sentences(char *input) {
    char **sentences = malloc(sizeof(char*) * MAX_SENTENCES);
    char *token = strtok(input, ".!?");
    int i = 0;
    while (token != NULL) {
        sentences[i++] = token;
        token = strtok(NULL, ".!?");
    }
    sentences[i] = NULL;
    return sentences;
}

char **split_sentence(char *sentence) {
    char **words = malloc(sizeof(char*) * MAX_WORDS);
    char *token = strtok(sentence, " ");
    int i = 0;
    while (token != NULL) {
        words[i++] = token;
        token = strtok(NULL, " ");
    }
    words[i] = NULL;
    return words;
}

int find_sentence_with_max_words(char **sentences) {
    int max_words = 0;
    int sentence_index = 0;
    for (int i = 0; i < MAX_SENTENCES && sentences[i] != NULL; i++) {
        int word_count = get_word_count(sentences[i]);
        if (word_count > max_words) {
            max_words = word_count;
            sentence_index = i;
        }
    }
    return sentence_index;
}

char *get_summary(char **sentences) {
    char *summary = malloc(sizeof(char) * MAX_SENTENCES * MAX_LENGTH);
    int summary_length = 0;
    int remaining_words = MAX_WORDS;
    int i = 0;
    while (remaining_words > 0) {
        char *sentence = sentences[i++];
        int word_count = get_word_count(sentence);
        if (word_count <= remaining_words) {
            remaining_words -= word_count;
            strcat(summary, sentence);
            strcat(summary, ". ");
            summary_length += strlen(sentence) + 2;
        } else {
            char **words = split_sentence(sentence);
            int j = 0;
            while (remaining_words > 0 && words[j] != NULL) {
                strcat(summary, words[j++]);
                strcat(summary, " ");
                remaining_words--;
                summary_length += strlen(words[j-1]) + 1;
            }
            strcat(summary, ". ");
            summary_length += 2;
        }
    }

    return summary;
}

int main() {
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Could not open file.");
        exit(1);
    }
    char *input = read_input(fp);
    fclose(fp);

    char **sentences = split_into_sentences(input);
    int sentence_index = find_sentence_with_max_words(sentences);
    char *summary_sentence = sentences[sentence_index];
    char **summary_sentence_words = split_sentence(summary_sentence);
    int summary_word_count = get_word_count(summary_sentence);
    printf("Summary:\n");
    for (int i = 0; i < summary_word_count; i++) {
        printf("%s ", summary_sentence_words[i]);
    }
    printf("\n");

    char *summary = get_summary(sentences);
    printf("Full Summary:\n%s", summary);

    free(input);
    free(sentences);
    free(summary_sentence_words);
    free(summary);
    return 0;
}