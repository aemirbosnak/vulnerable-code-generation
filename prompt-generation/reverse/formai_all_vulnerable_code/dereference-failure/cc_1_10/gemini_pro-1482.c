//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LEN 100

struct Sentence {
    char *text;
    int length;
};

struct SentenceList {
    struct Sentence *sentences;
    int num_sentences;
};

struct SentenceList* new_sentence_list(int num_sentences) {
    struct SentenceList *list = malloc(sizeof(struct SentenceList));
    list->sentences = malloc(num_sentences * sizeof(struct Sentence));
    list->num_sentences = num_sentences;
    return list;
}

void free_sentence_list(struct SentenceList *list) {
    for (int i = 0; i < list->num_sentences; i++) {
        free(list->sentences[i].text);
    }
    free(list->sentences);
    free(list);
}

struct Sentence* new_sentence(char *text) {
    struct Sentence *sentence = malloc(sizeof(struct Sentence));
    sentence->text = strdup(text);
    sentence->length = strlen(text);
    return sentence;
}

void free_sentence(struct Sentence *sentence) {
    free(sentence->text);
    free(sentence);
}

void add_sentence_to_list(struct SentenceList *list, struct Sentence *sentence) {
    list->sentences[list->num_sentences++] = *sentence;
}

char* summarize_text(char *text) {
    // Split the text into sentences.
    struct SentenceList *sentences = new_sentence_list(0);
    char *sentence_start = text;
    while (*sentence_start != '\0') {
        char *sentence_end = strchr(sentence_start, '.');
        if (sentence_end == NULL) {
            sentence_end = strchr(sentence_start, '!');
        }
        if (sentence_end == NULL) {
            sentence_end = strchr(sentence_start, '?');
        }
        if (sentence_end == NULL) {
            // No more sentences.
            break;
        }
        *sentence_end = '\0';
        struct Sentence *sentence = new_sentence(sentence_start);
        add_sentence_to_list(sentences, sentence);
        sentence_start = sentence_end + 1;
    }

    // Rank the sentences by importance.
    for (int i = 0; i < sentences->num_sentences; i++) {
        for (int j = i + 1; j < sentences->num_sentences; j++) {
            if (sentences->sentences[i].length < sentences->sentences[j].length) {
                struct Sentence temp = sentences->sentences[i];
                sentences->sentences[i] = sentences->sentences[j];
                sentences->sentences[j] = temp;
            }
        }
    }

    // Create the summary.
    char *summary = malloc(MAX_SENTENCE_LEN * sentences->num_sentences);
    int summary_length = 0;
    for (int i = 0; i < sentences->num_sentences; i++) {
        if (summary_length + sentences->sentences[i].length > MAX_SENTENCE_LEN) {
            break;
        }
        strcat(summary, sentences->sentences[i].text);
        summary_length += sentences->sentences[i].length + 1;
    }

    // Free the memory used by the sentence list.
    free_sentence_list(sentences);

    // Return the summary.
    return summary;
}

int main() {
    char *text = "This is a very long text that I want to summarize. It has many sentences, some of which are more important than others. I want to be able to quickly and easily get a sense of what the text is about without having to read the whole thing.";

    char *summary = summarize_text(text);

    printf("Summary: %s\n", summary);

    free(summary);

    return 0;
}