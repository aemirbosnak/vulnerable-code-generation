//FormAI DATASET v1.0 Category: Text Summarizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCES 50
#define MAX_WORDS_SENTENCE 10
#define MAX_WORD_LENGTH 25

typedef struct {
    char words[MAX_WORDS_SENTENCE][MAX_WORD_LENGTH];
    int count;
} Sentence;

void tokenize(char* text, Sentence* sentences, int* num_sentences) {
    int i, j, k, len;
    *num_sentences = 0;
    len = strlen(text);

    for (i = 0; i < len; i++) {
        if (*num_sentences >= MAX_SENTENCES) {
            break;
        }
        k = 0;
        for (j = i; j < len; j++) {
            if (text[j] == '.') {
                sentences[*num_sentences].words[k][0] = '\0';
                (*num_sentences)++;
                i = j;
                break;
            }
            if (!isspace(text[j]) && k < MAX_WORD_LENGTH - 1) {
                sentences[*num_sentences].words[k][0] = text[j];
                sentences[*num_sentences].words[k][1] = '\0';
                k++;
            }
        }
    }
}

int find_character(char c, char* str) {
    int i, len = strlen(str);
    for (i = 0; i < len; i++) {
        if (str[i] == c) {
            return 1;
        }
    }
    return 0;
}

void remove_chars(char* text, char* chars) {
    int i, j, len, offset = 0;
    len = strlen(text);
    for (i = 0; i < len; i++) {
        if (find_character(text[i], chars) != 1) {
            text[i - offset] = text[i];
        } else {
            offset++;
        }
    }
    text[len - offset] = '\0';
}

void remove_punctuation(Sentence* sentences, int num_sentences) {
    int i, j, k, len;
    char punctuations[] = {'.', ',', '!', '?'};
    for (i = 0; i < num_sentences; i++) {
        len = strlen(sentences[i].words[k]);
        for (j = 0; j < len; j++) {
            if (find_character(sentences[i].words[k][j], punctuations) == 1) {
                for (k = j; k < len - 1; k++) {
                    sentences[i].words[k][0] = sentences[i].words[k+1][0];
                }
                sentences[i].words[len-1][0] = '\0';
                len--;
            }
        }
    }
}

void to_lower_case(Sentence* sentences, int num_sentences) {
    int i, j, k, len;
    for (i = 0; i < num_sentences; i++) {
        len = strlen(sentences[i].words[k]);
        for (j = 0; j < len; j++) {
            sentences[i].words[k][j] = tolower(sentences[i].words[k][j]);
        }
    }
}

void print_sentences(Sentence* sentences, int num_sentences) {
    int i, j;
    for (i = 0; i < num_sentences; i++) {
        printf("Sentence %d: ", i+1);
        for (j = 0; j < sentences[i].count; j++) {
            printf("%s ", sentences[i].words[j]);
        }
        printf("\n");
    }
}

int main() {
    char text[500];
    printf("Enter text:\n");
    fgets(text, 500, stdin);

    Sentence sentences[MAX_SENTENCES];
    int num_sentences = 0;

    tokenize(text, sentences, &num_sentences);
    print_sentences(sentences, num_sentences);
    remove_punctuation(sentences, num_sentences);
    to_lower_case(sentences, num_sentences);
    print_sentences(sentences, num_sentences);

    return 0;
}