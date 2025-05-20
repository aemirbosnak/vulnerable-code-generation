//FormAI DATASET v1.0 Category: Text Summarizer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/* Utility functions */
char *str_tolower(char *str);
int num_lines_in_file(FILE *fp);
bool is_sentence_ending(char c);
void print_summary(char **sentences, int num_sentences, int max_words);

/* Function to summarize text */
void summarize_text(char *filename, int max_sentences, int max_words) {
    /* Open file */
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    /* Count the number of lines in the file */
    int num_lines = num_lines_in_file(fp);

    /* Allocate memory for sentences */
    char **sentences = malloc(num_lines * sizeof(char *));
    for (int i = 0; i < num_lines; i++) {
        sentences[i] = malloc(1000 * sizeof(char));
    }

    /* Read file and extract sentences */
    char line[1000];
    char *token;
    int sentence_count = 0;
    while (fgets(line, 1000, fp) != NULL) {
        /* Tokenize line into sentences */
        token = strtok(line, ".!?");
        while (token) {
            /* Store sentence in array */
            strcpy(sentences[sentence_count], token);
            sentence_count++;
            token = strtok(NULL, ".!?");
        }
    }

    /* Convert all sentences to lower case */
    for (int i = 0; i < sentence_count; i++) {
        str_tolower(sentences[i]);
    }

    /* Order sentences by length */
    char *temp;
    for (int i = 0; i < sentence_count - 1; i++) {
        for (int j = i + 1; j < sentence_count; j++) {
            if (strlen(sentences[i]) > strlen(sentences[j])) {
                temp = sentences[i];
                sentences[i] = sentences[j];
                sentences[j] = temp;
            }
        }
    }

    /* Choose top sentences */
    int num_sentences = sentence_count < max_sentences ? sentence_count : max_sentences;
    char **top_sentences = malloc(num_sentences * sizeof(char *));
    for (int i = 0; i < num_sentences; i++) {
        top_sentences[i] = sentences[i];
    }

    /* Order top sentences by position in original text */
    char *orig_sentence;
    for (int i = 0; i < num_sentences - 1; i++) {
        for (int j = i + 1; j < num_sentences; j++) {
            if (strstr(top_sentences[i], top_sentences[j]) != NULL) {
                orig_sentence = top_sentences[i];
                top_sentences[i] = top_sentences[j];
                top_sentences[j] = orig_sentence;
            }
        }
    }

    /* Print summary */
    print_summary(top_sentences, num_sentences, max_words);

    /* Free memory */
    for (int i = 0; i < num_lines; i++) {
        free(sentences[i]);
    }
    free(sentences);
    free(top_sentences);

    /* Close file */
    fclose(fp);
}

/* Helper function to convert string to lowercase */
char *str_tolower(char *str) {
    char *p = str;
    while (*p) {
        *p = tolower((unsigned char) *p);
        p++;
    }
    return str;
}

/* Helper function to count the number of lines in a file */
int num_lines_in_file(FILE *fp) {
    char ch;
    int lines = 0;

    while (!feof(fp)) {
        ch = fgetc(fp);
        if (ch == '\n') {
            lines++;
        }
    }

    rewind(fp);
    return lines;
}

/* Helper function to check if character is sentence ending */
bool is_sentence_ending(char c) {
    return c == '.' || c == '?' || c == '!';
}

/* Helper function to print summary */
void print_summary(char **sentences, int num_sentences, int max_words) {
    int word_count = 0;
    printf("Summary:\n");

    for (int i = 0; i < num_sentences; i++) {
        char *sentence = sentences[i];
        printf("%s", sentence);
        word_count += strlen(sentence);

        if (word_count >= max_words) {
            break;
        }
    }
}

/* Main Function */
int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <filename> <max sentences> <max words>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    int max_sentences = atoi(argv[2]);
    int max_words = atoi(argv[3]);

    summarize_text(filename, max_sentences, max_words);

    return 0;
}