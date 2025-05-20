//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_SUMMARY_LENGTH 200
#define MAX_SENTENCES 100

typedef struct {
    char text[MAX_SENTENCE_LENGTH];
    int length;
} Sentence;

typedef struct {
    Sentence sentences[MAX_SENTENCES];
    int num_sentences;
    char summary[MAX_SUMMARY_LENGTH];
    int summary_length;
} Summary;

void initialize_summary(Summary* summary) {
    summary->num_sentences = 0;
    summary->summary_length = 0;
    memset(summary->summary, '\0', MAX_SUMMARY_LENGTH);
}

int add_sentence(Summary* summary, const char* sentence) {
    if (summary->num_sentences >= MAX_SENTENCES) {
        return -1;
    }

    Sentence new_sentence = {
       .text = (char*) malloc(strlen(sentence) + 1),
       .length = strlen(sentence)
    };

    strcpy(new_sentence.text, sentence);
    summary->sentences[summary->num_sentences++] = new_sentence;

    return 0;
}

int generate_summary(Summary* summary) {
    int i, j, k;
    bool found_sentence = false;
    char* summary_text = summary->summary;

    for (i = 0; i < summary->num_sentences; i++) {
        Sentence* sentence = &summary->sentences[i];
        int sentence_length = sentence->length;

        for (j = 0; j < sentence_length; j++) {
            if (!isspace(sentence->text[j])) {
                if (!found_sentence) {
                    strncpy(summary_text, sentence->text + j, MAX_SUMMARY_LENGTH - summary->summary_length);
                    summary->summary_length += strlen(summary_text);
                    found_sentence = true;
                } else {
                    char* word = sentence->text + j;
                    int word_length = strlen(word);

                    if (summary->summary_length + word_length <= MAX_SUMMARY_LENGTH) {
                        strcat(summary_text, " ");
                        strcat(summary_text, word);
                        summary->summary_length += word_length + 1;
                    }
                }
            }
        }
    }

    if (!found_sentence) {
        strcpy(summary_text, "No sentences found in the text.");
        summary->summary_length = strlen(summary_text);
    }

    return 0;
}

int main() {
    FILE* input_file = fopen("input.txt", "r");
    char input_text[MAX_SENTENCE_LENGTH];
    int input_length = 0;

    Summary summary;
    initialize_summary(&summary);

    while (fgets(input_text, MAX_SENTENCE_LENGTH, input_file)!= NULL) {
        int sentence_length = strlen(input_text);

        if (input_length + sentence_length + 1 <= MAX_SENTENCE_LENGTH) {
            strcat(input_text, " ");
            input_length += sentence_length + 1;
        } else {
            add_sentence(&summary, input_text);
            input_length = sentence_length;
        }
    }

    if (input_length > 0) {
        add_sentence(&summary, input_text);
    }

    fclose(input_file);

    generate_summary(&summary);

    printf("Summary:\n%s\n", summary.summary);

    return 0;
}