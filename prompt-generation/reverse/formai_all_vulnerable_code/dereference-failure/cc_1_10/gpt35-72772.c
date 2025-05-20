//FormAI DATASET v1.0 Category: Text Summarizer ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SENTENCES 1000
#define MAX_WORDS 1000
#define MAX_CHARACTERS 10000

char* get_input_text(char *filename) {
    FILE *fp;
    char *text;
    long int size_of_file;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File cannot be opened\n");
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    size_of_file = ftell(fp);
    rewind(fp);

    text = malloc(sizeof(char) * (size_of_file + 1));
    fread(text, sizeof(char), size_of_file, fp);
    text[size_of_file] = '\0';

    fclose(fp);

    return text;
}

void tokenize_sentences(char *text, char *sentences[][MAX_WORDS]) {
    char *token;
    char *sentence_token;
    int sentence_count = 0;
    int word_count;

    token = strtok(text, "\n");
    while (token != NULL) {
        sentence_token = strtok(token, " ");
        word_count = 0;
        while (sentence_token != NULL) {
            if (strlen(sentence_token) > 2) {
                sentences[sentence_count][word_count] =
                    (char*)malloc(sizeof(char) * (strlen(sentence_token) + 1));
                strcpy(sentences[sentence_count][word_count], sentence_token);
                word_count++;
            }
            sentence_token = strtok(NULL, " ");
        }
        sentence_count++;
        token = strtok(NULL, "\n");
    }
}

void count_word_frequencies(char *sentences[][MAX_WORDS],
                            int *sentence_word_count, float *word_frequency) {
    int sentence_count = 0;
    int word_count = 0;
    int i, j;

    while (sentences[sentence_count][0] != NULL) {
        word_count = 0;
        while (sentences[sentence_count][word_count] != NULL) {
            word_frequency[sentence_count] +=
                (1.0 / sentence_word_count[sentence_count]) * (1.0 / sentence_word_count[sentence_count]);
            for (i = 0; i < sentence_count; i++) {
                for (j = 0; j < sentence_word_count[i]; j++) {
                    if (strcmp(sentences[sentence_count][word_count], sentences[i][j]) == 0) {
                        word_frequency[sentence_count] +=
                            (1.0 / sentence_word_count[i]) * (1.0 / sentence_word_count[sentence_count]);
                    }
                }
            }
            word_count++;
        }
        sentence_count++;
    }
}

void create_sentence_score(char *sentences[][MAX_WORDS],
                           int *sentence_word_count, float *word_frequency,
                           float *sentence_score) {
    int sentence_count = 0;
    int word_count = 0;

    while (sentences[sentence_count][0] != NULL) {
        word_count = 0;
        while (sentences[sentence_count][word_count] != NULL) {
            sentence_score[sentence_count] +=
                word_frequency[sentence_count];

            word_count++;
        }
        sentence_score[sentence_count] /= sentence_word_count[sentence_count];
        sentence_count++;
    }
}

void print_summary(char *sentences[][MAX_WORDS], float *sentence_score) {
    int i = 0;

    while (sentences[i][0] != NULL) {
        if (sentence_score[i] > 0.05) {
            printf("%s ", sentences[i][0]);
        }
        i++;
    }
    printf("\n");
}

int main() {
    char *filename = "input.txt";
    char *text;
    char *sentences[MAX_SENTENCES][MAX_WORDS];
    int sentence_word_count[MAX_SENTENCES] = { 0 };
    float word_frequency[MAX_SENTENCES] = { 0 };
    float sentence_score[MAX_SENTENCES] = { 0 };

    text = get_input_text(filename);

    tokenize_sentences(text, sentences);

    int sentence_count = 0;
    int word_count = 0;
    while (sentences[sentence_count][0] != NULL) {
        word_count = 0;
        while (sentences[sentence_count][word_count] != NULL) {
            sentence_word_count[sentence_count]++;
            word_count++;
        }
        sentence_count++;
    }

    count_word_frequencies(sentences, sentence_word_count, word_frequency);

    create_sentence_score(sentences, sentence_word_count, word_frequency, sentence_score);

    print_summary(sentences, sentence_score);

    return 0;
}