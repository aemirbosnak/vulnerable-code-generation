//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCES 1000
#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 100
#define MIN_SENTENCE_LENGTH 5

typedef struct {
    char *text;
    int length;
} Sentence;

typedef struct {
    Sentence *sentences;
    int num_sentences;
} Text;

void initialize_text(Text *text) {
    text->sentences = (Sentence *) malloc(MAX_SENTENCES * sizeof(Sentence));
    text->num_sentences = 0;
}

void add_sentence(Text *text, char *sentence) {
    if (text->num_sentences >= MAX_SENTENCES) {
        printf("Error: Maximum number of sentences reached.\n");
        return;
    }

    int length = strlen(sentence);
    if (length < MIN_SENTENCE_LENGTH || length > MAX_SENTENCE_LENGTH) {
        printf("Error: Sentence length must be between %d and %d characters.\n", MIN_SENTENCE_LENGTH, MAX_SENTENCE_LENGTH);
        return;
    }

    text->sentences[text->num_sentences].text = strdup(sentence);
    text->sentences[text->num_sentences].length = length;
    text->num_sentences++;
}

void print_text(Text *text) {
    for (int i = 0; i < text->num_sentences; i++) {
        printf("%s\n", text->sentences[i].text);
    }
}

void free_text(Text *text) {
    for (int i = 0; i < text->num_sentences; i++) {
        free(text->sentences[i].text);
    }
    free(text->sentences);
}

int main() {
    Text text;
    initialize_text(&text);

    char sentence[MAX_SENTENCE_LENGTH];
    while (fgets(sentence, sizeof(sentence), stdin)!= NULL) {
        add_sentence(&text, sentence);
    }

    print_text(&text);

    free_text(&text);

    return 0;
}