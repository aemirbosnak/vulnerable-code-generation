//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_SENTENCES 1000

typedef struct {
    char sentence[MAX_SENTENCE_LENGTH];
    int length;
} Sentence;

typedef struct {
    Sentence sentences[MAX_SENTENCES];
    int num_sentences;
} Text;

int load_text(Text* text, FILE* file) {
    Sentence sentence;
    int num_sentences = 0;
    while (fgets(sentence.sentence, MAX_SENTENCE_LENGTH, file)!= NULL) {
        sentence.length = strlen(sentence.sentence);
        if (num_sentences >= MAX_SENTENCES) {
            printf("Error: reached maximum number of sentences.\n");
            return -1;
        }
        text->sentences[num_sentences] = sentence;
        num_sentences++;
    }
    text->num_sentences = num_sentences;
    return 0;
}

int summarize_text(Text* text, int max_length, char* summary) {
    int total_length = 0;
    int num_sentences = 0;
    Sentence* selected_sentences = malloc(sizeof(Sentence) * max_length);
    memset(selected_sentences, 0, sizeof(Sentence) * max_length);

    for (int i = 0; i < text->num_sentences; i++) {
        Sentence sentence = text->sentences[i];
        int sentence_length = sentence.length;
        if (total_length + sentence_length <= max_length) {
            memcpy(selected_sentences + num_sentences, &sentence, sizeof(Sentence));
            total_length += sentence_length;
            num_sentences++;
        }
    }

    for (int i = 0; i < num_sentences; i++) {
        Sentence sentence = selected_sentences[i];
        strcat(summary, sentence.sentence);
        strcat(summary, " ");
    }

    free(selected_sentences);
    return 0;
}

int main() {
    Text text;
    FILE* input_file = fopen("input.txt", "r");
    if (load_text(&text, input_file)!= 0) {
        return -1;
    }
    fclose(input_file);

    char summary[MAX_SENTENCE_LENGTH * 2];
    summarize_text(&text, MAX_SENTENCE_LENGTH * 2, summary);
    printf("Summary: %s\n", summary);

    return 0;
}