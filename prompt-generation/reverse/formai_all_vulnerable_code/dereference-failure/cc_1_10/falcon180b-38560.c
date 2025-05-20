//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000
#define MAX_NUM_WORDS 100

typedef struct word {
    char *text;
    int length;
} Word;

typedef struct sentence {
    Word *words;
    int num_words;
} Sentence;

Sentence *create_sentence() {
    Sentence *sentence = malloc(sizeof(Sentence));
    sentence->num_words = 0;
    sentence->words = NULL;
    return sentence;
}

void destroy_sentence(Sentence *sentence) {
    for (int i = 0; i < sentence->num_words; i++) {
        free(sentence->words[i].text);
    }
    free(sentence->words);
    free(sentence);
}

void add_word(Sentence *sentence, char *text, int length) {
    Word *word = malloc(sizeof(Word));
    word->text = malloc(length + 1);
    strncpy(word->text, text, length);
    word->text[length] = '\0';
    word->length = length;
    sentence->words = realloc(sentence->words, sizeof(Word) * (sentence->num_words + 1));
    sentence->words[sentence->num_words] = *word;
    sentence->num_words++;
}

void print_sentence(Sentence *sentence) {
    for (int i = 0; i < sentence->num_words; i++) {
        printf("%s ", sentence->words[i].text);
    }
    printf("\n");
}

int main() {
    Sentence *sentence = create_sentence();
    char input[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence: ");
    fgets(input, MAX_SENTENCE_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';
    char *token = strtok(input, " ");
    while (token!= NULL) {
        add_word(sentence, token, strlen(token));
        token = strtok(NULL, " ");
    }
    print_sentence(sentence);
    destroy_sentence(sentence);
    return 0;
}