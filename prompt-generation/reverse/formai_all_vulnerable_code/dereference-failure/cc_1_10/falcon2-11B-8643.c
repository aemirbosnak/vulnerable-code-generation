//Falcon2-11B DATASET v1.0 Category: Text Summarizer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_WORDS_PER_SENTENCE 10

struct Sentence {
    char words[MAX_WORDS_PER_SENTENCE][MAX_SENTENCE_LENGTH + 1];
    int word_count;
};

struct Text {
    struct Sentence sentences[MAX_WORDS_PER_SENTENCE];
    int sentence_count;
};

struct Text *create_text(int sentence_count) {
    struct Text *text = malloc(sizeof(struct Text));
    if (text == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    text->sentence_count = sentence_count;
    return text;
}

void add_sentence(struct Text *text, const char *words) {
    struct Sentence *sentence = &text->sentences[text->sentence_count - 1];
    strncpy(sentence->words[sentence->word_count], words, MAX_SENTENCE_LENGTH);
    sentence->word_count++;
}

void remove_sentence(struct Text *text, int index) {
    if (index < 0 || index >= text->sentence_count) {
        fprintf(stderr, "Invalid sentence index\n");
        exit(1);
    }
    for (int i = index; i < text->sentence_count - 1; i++) {
        strcpy(text->sentences[i].words[0], text->sentences[i + 1].words[0]);
        strcpy(text->sentences[i].words[1], text->sentences[i + 1].words[1]);
    }
    text->sentence_count--;
}

void print_text(struct Text *text) {
    printf("Text:\n");
    for (int i = 0; i < text->sentence_count; i++) {
        printf("Sentence %d:\n", i + 1);
        for (int j = 0; j < text->sentences[i].word_count; j++) {
            printf("%s ", text->sentences[i].words[j]);
        }
        printf("\n");
    }
}

void summarize_text(struct Text *text, int word_count) {
    int sentence_count = text->sentence_count;
    int i = 0;
    int j = 0;
    int index = 0;
    struct Sentence *sentence = &text->sentences[index];
    while (i < sentence_count) {
        if (strncmp(sentence->words[j], "a", 1) == 0) {
            index++;
            sentence_count--;
            j = 0;
        } else if (strncmp(sentence->words[j], "b", 1) == 0) {
            index++;
            sentence_count--;
            j = 0;
        } else if (strncmp(sentence->words[j], "c", 1) == 0) {
            index++;
            sentence_count--;
            j = 0;
        } else if (strncmp(sentence->words[j], "d", 1) == 0) {
            index++;
            sentence_count--;
            j = 0;
        } else if (strncmp(sentence->words[j], "e", 1) == 0) {
            index++;
            sentence_count--;
            j = 0;
        } else if (strncmp(sentence->words[j], "f", 1) == 0) {
            index++;
            sentence_count--;
            j = 0;
        } else if (strncmp(sentence->words[j], "g", 1) == 0) {
            index++;
            sentence_count--;
            j = 0;
        } else if (strncmp(sentence->words[j], "h", 1) == 0) {
            index++;
            sentence_count--;
            j = 0;
        } else if (strncmp(sentence->words[j], "i", 1) == 0) {
            index++;
            sentence_count--;
            j = 0;
        } else if (strncmp(sentence->words[j], "j", 1) == 0) {
            index++;
            sentence_count--;
            j = 0;
        } else if (strncmp(sentence->words[j], "k", 1) == 0) {
            index++;
            sentence_count--;
            j = 0;
        } else if (strncmp(sentence->words[j], "l", 1) == 0) {
            index++;
            sentence_count--;
            j = 0;
        } else if (strncmp(sentence->words[j], "m", 1) == 0) {
            index++;
            sentence_count--;
            j = 0;
        } else if (strncmp(sentence->words[j], "n", 1) == 0) {
            index++;
            sentence_count--;
            j = 0;
        } else if (strncmp(sentence->words[j], "o", 1) == 0) {
            index++;
            sentence_count--;
            j = 0;
        } else if (strncmp(sentence->words[j], "p", 1) == 0) {
            index++;
            sentence_count--;
            j = 0;
        } else if (strncmp(sentence->words[j], "q", 1) == 0) {
            index++;
            sentence_count--;
            j = 0;
        } else if (strncmp(sentence->words[j], "r", 1) == 0) {
            index++;
            sentence_count--;
            j = 0;
        } else if (strncmp(sentence->words[j], "s", 1) == 0) {
            index++;
            sentence_count--;
            j = 0;
        } else if (strncmp(sentence->words[j], "t", 1) == 0) {
            index++;
            sentence_count--;
            j = 0;
        } else if (strncmp(sentence->words[j], "u", 1) == 0) {
            index++;
            sentence_count--;
            j = 0;
        } else if (strncmp(sentence->words[j], "v", 1) == 0) {
            index++;
            sentence_count--;
            j = 0;
        } else if (strncmp(sentence->words[j], "w", 1) == 0) {
            index++;
            sentence_count--;
            j = 0;
        } else if (strncmp(sentence->words[j], "x", 1) == 0) {
            index++;
            sentence_count--;
            j = 0;
        } else if (strncmp(sentence->words[j], "y", 1) == 0) {
            index++;
            sentence_count--;
            j = 0;
        } else if (strncmp(sentence->words[j], "z", 1) == 0) {
            index++;
            sentence_count--;
            j = 0;
        } else {
            i++;
        }
    }
    remove_sentence(text, sentence_count);
}

int main() {
    struct Text *text = create_text(4);
    add_sentence(text, "a b c d");
    add_sentence(text, "e f g h");
    add_sentence(text, "i j k l");
    add_sentence(text, "m n o p");
    summarize_text(text, 5);
    print_text(text);
    return 0;
}