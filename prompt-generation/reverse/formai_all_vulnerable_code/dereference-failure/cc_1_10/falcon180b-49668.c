//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100

typedef struct {
    char *english;
    char *alien;
} translation_t;

translation_t translations[] = {
    {"hello", "qweqweqwe"},
    {"world", "asdasdasd"},
    {"how", "zxczxczxc"},
    {"are", "qweqwe"},
    {"you", "asdasd"},
    {"?", "zxczxc"},
    {"!", "qweqweqweasdasdasdasd"},
    {"I", "qwe"},
    {"am", "asd"},
    {"programmer", "qweqweqweasdasdasdasdasd"},
    {NULL, NULL}
};

char *translate_word(char *word) {
    int i = 0;
    while (translations[i].english!= NULL) {
        if (strcmp(word, translations[i].english) == 0) {
            return translations[i].alien;
        }
        i++;
    }
    return word;
}

char *translate_sentence(char *sentence) {
    char *token = strtok(sentence, " ");
    char *translated_sentence = malloc(MAX_WORD_LENGTH * sizeof(char));
    strcpy(translated_sentence, "");

    while (token!= NULL) {
        char *translated_token = translate_word(token);
        strcat(translated_sentence, translated_token);
        strcat(translated_sentence, " ");
        token = strtok(NULL, " ");
    }

    return translated_sentence;
}

int main() {
    char input[MAX_WORD_LENGTH];
    printf("Enter a sentence in English: ");
    fgets(input, MAX_WORD_LENGTH, stdin);
    char *translated_sentence = translate_sentence(input);
    printf("Translated sentence: %s\n", translated_sentence);

    free(translated_sentence);
    return 0;
}