//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_verb;
} Word;

Word* create_word(char* str) {
    Word* w = (Word*)malloc(sizeof(Word));
    strncpy(w->word, str, MAX_WORD_LENGTH);
    w->is_verb = false;
    return w;
}

typedef struct {
    Word* words;
    int num_words;
} Sentence;

Sentence* create_sentence() {
    Sentence* s = (Sentence*)malloc(sizeof(Sentence));
    s->words = NULL;
    s->num_words = 0;
    return s;
}

void add_word_to_sentence(Sentence* s, Word* w) {
    s->words = (Word*)realloc(s->words, sizeof(Word) * (s->num_words + 1));
    s->words[s->num_words] = *w;
    s->num_words++;
}

void print_sentence(Sentence* s) {
    for (int i = 0; i < s->num_words; i++) {
        printf("%s ", s->words[i].word);
    }
    printf("\n");
}

void free_sentence(Sentence* s) {
    for (int i = 0; i < s->num_words; i++) {
        free(s->words[i].word);
    }
    free(s->words);
    free(s);
}

int main() {
    char input[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence: ");
    fgets(input, MAX_SENTENCE_LENGTH, stdin);

    Sentence* sentence = create_sentence();
    char* word = strtok(input, " ");
    while (word!= NULL) {
        Word* w = create_word(word);
        if (strcasecmp(word, "meow") == 0) {
            w->is_verb = true;
        }
        add_word_to_sentence(sentence, w);
        word = strtok(NULL, " ");
    }

    print_sentence(sentence);

    free_sentence(sentence);

    return 0;
}