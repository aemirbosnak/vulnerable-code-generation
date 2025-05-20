//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50
#define VOCABULARY_SIZE 1000

typedef struct {
    char *english;
    char *alien;
} Word;

Word vocabulary[VOCABULARY_SIZE];
int vocabularySize = 0;

void loadVocabulary(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open vocabulary file.\n");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        char *english = strtok(line, ",");
        char *alien = strtok(NULL, ",");

        if (english == NULL || alien == NULL) {
            printf("Error: invalid line in vocabulary file.\n");
            exit(1);
        }

        vocabulary[vocabularySize++] = (Word) {.english = strdup(english),.alien = strdup(alien) };
    }

    fclose(file);
}

char *translate(char *word) {
    for (int i = 0; i < vocabularySize; i++) {
        if (strcmp(word, vocabulary[i].english) == 0) {
            return vocabulary[i].alien;
        }
    }

    return strdup(word);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <vocabulary_file> <text_file>\n", argv[0]);
        exit(1);
    }

    char *vocabularyFilename = argv[1];
    char *textFilename = argv[2];

    loadVocabulary(vocabularyFilename);

    FILE *inputFile = fopen(textFilename, "r");
    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, inputFile)!= NULL) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            char *translation = translate(word);
            printf("%s ", translation);
            word = strtok(NULL, " ");
        }
        printf("\n");
    }

    fclose(inputFile);

    return 0;
}