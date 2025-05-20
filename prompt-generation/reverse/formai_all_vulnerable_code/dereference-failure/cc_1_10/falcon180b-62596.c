//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000
#define MAX_LINE_LENGTH 10000

char *translate_word(char *word) {
    char *translation = malloc(MAX_WORD_LENGTH * sizeof(char));
    strcpy(translation, word);

    for (int i = 0; i < strlen(translation); i++) {
        if (isalpha(translation[i])) {
            translation[i] = toupper(translation[i]);
        }
    }

    strcat(translation, " ");
    return translation;
}

char *translate_sentence(char *sentence) {
    char *translation = malloc(MAX_SENTENCE_LENGTH * sizeof(char));
    strcpy(translation, sentence);

    for (int i = 0; i < strlen(translation); i++) {
        if (isalpha(translation[i])) {
            translation[i] = toupper(translation[i]);
        }
    }

    strcat(translation, " ");
    return translation;
}

void translate_file(char *filename) {
    FILE *file = fopen(filename, "r");
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *word = strtok(line, " ");
        char *translation = translate_word(word);

        while (word!= NULL) {
            printf("%s ", translation);
            word = strtok(NULL, " ");
            translation = translate_word(word);
        }

        printf("\n");
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    translate_file(filename);

    return 0;
}