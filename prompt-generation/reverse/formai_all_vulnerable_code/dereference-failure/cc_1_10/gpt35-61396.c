//FormAI DATASET v1.0 Category: Text Summarizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCES 30
#define MAX_LENGTH 1000

typedef struct sentence {
    char *text;
    int score;
} sentence;

void to_lowercase(char *str);
int is_delimiter(char c);
void extract_sentences(char *text, sentence *sentences);
int count_words(char *string);
int get_sentence_score(sentence s);

int main() {
    char input[MAX_LENGTH];
    printf("Enter text to summarize:\n");
    fgets(input, MAX_LENGTH, stdin);

    sentence sentences[MAX_SENTENCES];
    extract_sentences(input, sentences);

    int num_sentences = sizeof(sentences) / sizeof(sentences[0]);

    for (int i = 0; i < num_sentences; i++) {
        if (sentences[i].text != NULL) {
            sentences[i].score = get_sentence_score(sentences[i]);
        }
    }

    // sort sentences by score
    for (int i = 0; i < num_sentences - 1; i++) {
        for (int j = i + 1; j < num_sentences; j++) {
            if (sentences[j].score > sentences[i].score) {
                sentence temp = sentences[i];
                sentences[i] = sentences[j];
                sentences[j] = temp;
            }
        }
    }

    // print top 3 sentences
    printf("\nSummary:\n");
    for (int i = 0; i < 3 && sentences[i].text != NULL; i++) {
        printf("%s\n", sentences[i].text);
    }

    return 0;
}

void to_lowercase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

int is_delimiter(char c) {
    char delimiters[] = {'.', '?', '!'};
    int num_delimiters = sizeof(delimiters) / sizeof(delimiters[0]);

    for (int i = 0; i < num_delimiters; i++) {
        if (c == delimiters[i]) {
            return 1;
        }
    }

    return 0;
}

void extract_sentences(char *text, sentence *sentences) {
    int num_sentences = 0;
    char *sentence_start = text;
    int sentence_length = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if (is_delimiter(text[i])) {
            sentence_length = &text[i] - sentence_start + 1;

            if (sentence_length > 1) {
                sentences[num_sentences].text = malloc(sentence_length);
                strncpy(sentences[num_sentences].text, sentence_start, sentence_length);
                sentences[num_sentences].text[sentence_length - 1] = '\0';
                to_lowercase(sentences[num_sentences].text);

                num_sentences++;

                if (num_sentences >= MAX_SENTENCES) {
                    break;
                }
            }

            sentence_start = &text[i + 1];
        }
    }
}

int count_words(char *string) {
    int count = 0;
    char *prev = string - 1;

    while (*string != '\0') {
        if (is_delimiter(*string) && !is_delimiter(*prev)) {
            count++;
        }

        prev = string;
        string++;
    }

    return count;
}

int get_sentence_score(sentence s) {
    int num_words = count_words(s.text);

    if (num_words == 0) {
        return 0;
    }

    int num_chars = strlen(s.text);
    int score = (100 * num_words + 10 * num_chars) / (num_chars + 1);

    return score;
}