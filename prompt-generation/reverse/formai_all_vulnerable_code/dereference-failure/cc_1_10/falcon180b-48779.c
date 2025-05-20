//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 20
#define MAX_SENTENCE_LENGTH 100

struct word {
    char *text;
    int length;
    int frequency;
};

struct sentence {
    struct word *words;
    int length;
};

struct sentence *create_sentence() {
    struct sentence *sentence = malloc(sizeof(struct sentence));
    sentence->words = NULL;
    sentence->length = 0;
    return sentence;
}

void add_word(struct sentence *sentence, char *word) {
    struct word *new_word = malloc(sizeof(struct word));
    new_word->text = strdup(word);
    new_word->length = strlen(word);
    new_word->frequency = 1;
    sentence->words = realloc(sentence->words, sizeof(struct word) * (sentence->length + 1));
    sentence->words[sentence->length] = *new_word;
    sentence->length++;
}

void print_sentence(struct sentence *sentence) {
    for (int i = 0; i < sentence->length; i++) {
        struct word *word = &sentence->words[i];
        printf("%s ", word->text);
    }
    printf("\n");
}

void free_sentence(struct sentence *sentence) {
    for (int i = 0; i < sentence->length; i++) {
        free(sentence->words[i].text);
    }
    free(sentence->words);
    free(sentence);
}

int main() {
    char buffer[MAX_SENTENCE_LENGTH];
    struct sentence *sentence = create_sentence();

    printf("Enter a sentence: ");
    fgets(buffer, MAX_SENTENCE_LENGTH, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    char *word = strtok(buffer, " ");
    while (word!= NULL) {
        add_word(sentence, word);
        word = strtok(NULL, " ");
    }

    print_sentence(sentence);

    free_sentence(sentence);

    return 0;
}