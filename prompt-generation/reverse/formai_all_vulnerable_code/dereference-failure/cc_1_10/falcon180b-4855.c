//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_SENTENCES 1000
#define MIN_SENTENCE_LENGTH 5

typedef struct {
    char *text;
    int length;
} Sentence;

Sentence sentences[MAX_SENTENCES];
int num_sentences = 0;

void add_sentence(char *text) {
    if (num_sentences >= MAX_SENTENCES) {
        printf("Error: Too many sentences.\n");
        exit(1);
    }

    sentences[num_sentences].text = malloc(strlen(text) + 1);
    strcpy(sentences[num_sentences].text, text);
    sentences[num_sentences].length = strlen(text);

    num_sentences++;
}

void print_sentences() {
    for (int i = 0; i < num_sentences; i++) {
        printf("%s\n", sentences[i].text);
    }
}

void remove_punctuation(char *text) {
    int length = strlen(text);

    for (int i = 0; i < length; i++) {
        if (!isalnum(text[i])) {
            memmove(&text[i], &text[i + 1], length - i - 1);
            length--;
        }
    }

    text[length] = '\0';
}

void tokenize(char *text) {
    int length = strlen(text);
    char *token = malloc(length + 1);

    strcpy(token, text);
    remove_punctuation(token);

    int num_tokens = 0;
    char **tokens = malloc(length / 2 * sizeof(char *));

    char *current_token = strtok(token, " ");
    while (current_token!= NULL) {
        if (strlen(current_token) >= MIN_SENTENCE_LENGTH) {
            tokens[num_tokens] = malloc(strlen(current_token) + 1);
            strcpy(tokens[num_tokens], current_token);
            num_tokens++;
        }

        current_token = strtok(NULL, " ");
    }

    free(token);

    for (int i = 0; i < num_tokens; i++) {
        add_sentence(tokens[i]);
        free(tokens[i]);
    }

    free(tokens);
}

int main() {
    char input_text[MAX_SENTENCE_LENGTH];

    printf("Enter text to summarize:\n");
    fgets(input_text, MAX_SENTENCE_LENGTH, stdin);

    tokenize(input_text);

    print_sentences();

    return 0;
}