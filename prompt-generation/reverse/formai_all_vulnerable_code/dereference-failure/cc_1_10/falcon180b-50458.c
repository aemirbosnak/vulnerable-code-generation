//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char* word;
    char* translation;
} Translation;

void load_translations(Translation* translations, FILE* file) {
    char line[1024];
    while(fgets(line, sizeof(line), file)) {
        char* word = strtok(line, " ");
        char* translation = strtok(NULL, " ");
        translations->word = strdup(word);
        translations->translation = strdup(translation);
        translations++;
    }
}

Translation* find_translation(Translation* translations, char* word) {
    for(Translation* t = translations; t->word!= NULL; t++) {
        if(strcmp(t->word, word) == 0) {
            return t;
        }
    }
    return NULL;
}

void translate_sentence(char* sentence, Translation* translations) {
    char* word = strtok(sentence, " ");
    while(word!= NULL) {
        Translation* t = find_translation(translations, word);
        if(t!= NULL) {
            printf("%s ", t->translation);
        } else {
            printf("%s ", word);
        }
        word = strtok(NULL, " ");
    }
    printf("\n");
}

int main() {
    FILE* translations_file = fopen("translations.txt", "r");
    if(translations_file == NULL) {
        printf("Error: could not open translations file.\n");
        return 1;
    }
    Translation translations[1000];
    load_translations(translations, translations_file);
    fclose(translations_file);

    char sentence[1024];
    printf("Enter a sentence to translate:\n");
    fgets(sentence, sizeof(sentence), stdin);

    translate_sentence(sentence, translations);

    return 0;
}