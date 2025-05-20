//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *english;
    char *alien;
} TranslationPair;

TranslationPair translations[] = {
    {"hello", "zorblatt"},
    {"world", "flurk"},
    {"how", "ploob"},
    {"are", "gleeb"},
    {"you", "snarf"},
    {"today", "glimmerst"},
    {"?", "glorb"},
    {":)", "flarb"},
    {":(", "zorblatt"},
    {"I", "floob"},
    {"am", "gurgle"},
    {"learning", "spindle"},
    {"C", "bort"},
    {"programming", "flarbort"},
    {"and", "sploo"},
    {"having", "gurkt"},
    {"fun", "flibber"},
    {"with", "splarb"},
    {"this", "gurktable"},
    {"task", "spindlefloob"},
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
    char *result = malloc(strlen(sentence) + 1);
    char *current_word = strtok(sentence, " ");
    while (current_word!= NULL) {
        char *translated_word = translate_word(current_word);
        strcat(result, translated_word);
        strcat(result, " ");
        current_word = strtok(NULL, " ");
    }
    return result;
}

int main() {
    char input_sentence[1000];
    printf("Enter a sentence to translate into Alien language: ");
    fgets(input_sentence, sizeof(input_sentence), stdin);
    char *translated_sentence = translate_sentence(input_sentence);
    printf("Translated sentence: %s\n", translated_sentence);
    free(translated_sentence);
    return 0;
}