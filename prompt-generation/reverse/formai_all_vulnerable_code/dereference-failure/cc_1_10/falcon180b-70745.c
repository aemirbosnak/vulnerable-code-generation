//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000

typedef struct word {
    char *text;
    int length;
} Word;

typedef struct sentence {
    Word *words;
    int num_words;
} Sentence;

Sentence *new_sentence() {
    Sentence *sentence = malloc(sizeof(Sentence));
    sentence->num_words = 0;
    sentence->words = NULL;
    return sentence;
}

void free_sentence(Sentence *sentence) {
    for (int i = 0; i < sentence->num_words; i++) {
        free(sentence->words[i].text);
    }
    free(sentence->words);
    free(sentence);
}

void add_word(Sentence *sentence, char *word) {
    Word *new_word = malloc(sizeof(Word));
    new_word->text = strdup(word);
    new_word->length = strlen(word);
    sentence->words = realloc(sentence->words, sizeof(Word) * (sentence->num_words + 1));
    sentence->words[sentence->num_words++] = *new_word;
}

void print_sentence(Sentence *sentence) {
    for (int i = 0; i < sentence->num_words; i++) {
        printf("%s ", sentence->words[i].text);
    }
    printf("\n");
}

int main() {
    char text[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence: ");
    fgets(text, MAX_SENTENCE_LENGTH, stdin);
    Sentence *sentence = new_sentence();
    char *word = strtok(text, " ");
    while (word!= NULL) {
        add_word(sentence, word);
        word = strtok(NULL, " ");
    }
    print_sentence(sentence);
    free_sentence(sentence);
    return 0;
}