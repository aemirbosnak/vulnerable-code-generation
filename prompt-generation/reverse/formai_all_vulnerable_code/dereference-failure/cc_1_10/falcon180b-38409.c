//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 10
#define MAX_SENTENCES 50

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

typedef struct {
    char *sentence;
    int length;
} Sentence;

typedef struct {
    Sentence *sentences;
    int num_sentences;
} Text;

void generate_random_sentence(Sentence *sentence, int max_length) {
    char *words[MAX_WORDS];
    int num_words = 0;

    srand(time(NULL));
    while (num_words < max_length) {
        char *word = (char *)malloc(sizeof(char) * (rand() % 10 + 1));
        strcpy(word, "");
        for (int i = 0; i < strlen(word); i++) {
            word[i] = toupper(rand() % 26 + 'A');
        }
        words[num_words] = word;
        num_words++;
    }

    for (int i = 0; i < max_length; i++) {
        strcat(sentence->sentence, words[i]);
        if (i < max_length - 1) {
            strcat(sentence->sentence, " ");
        }
    }

    sentence->length = strlen(sentence->sentence);
}

void generate_text(Text *text, int num_sentences, int max_sentence_length) {
    text->sentences = (Sentence *)malloc(sizeof(Sentence) * num_sentences);
    text->num_sentences = num_sentences;

    for (int i = 0; i < num_sentences; i++) {
        text->sentences[i].sentence = (char *)malloc(sizeof(char) * (max_sentence_length + 1));
        generate_random_sentence(&text->sentences[i], max_sentence_length);
    }
}

void print_text(Text *text) {
    for (int i = 0; i < text->num_sentences; i++) {
        printf("%s\n", text->sentences[i].sentence);
    }
}

void free_text(Text *text) {
    for (int i = 0; i < text->num_sentences; i++) {
        free(text->sentences[i].sentence);
    }
    free(text->sentences);
}

int main() {
    int num_sentences;
    printf("Enter the number of sentences: ");
    scanf("%d", &num_sentences);

    int max_sentence_length;
    printf("Enter the maximum sentence length: ");
    scanf("%d", &max_sentence_length);

    Text text;
    generate_text(&text, num_sentences, max_sentence_length);
    print_text(&text);

    free_text(&text);

    return 0;
}