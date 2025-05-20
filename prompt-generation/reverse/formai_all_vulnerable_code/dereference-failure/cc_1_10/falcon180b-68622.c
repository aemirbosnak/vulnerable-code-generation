//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_SENTENCE_LENGTH 500

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordTranslation;

typedef struct {
    WordTranslation *words;
    int numWords;
} SentenceTranslation;

void loadDictionary(char *filename, WordTranslation *dictionary, int *numEntries) {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    char *word, *translation;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    *numEntries = 0;
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        word = strtok(line, " ");
        translation = strtok(NULL, " ");

        if (word == NULL || translation == NULL) {
            printf("Error: malformed entry in dictionary file.\n");
            exit(1);
        }

        strncpy(dictionary[*numEntries].word, word, MAX_WORD_LENGTH);
        strncpy(dictionary[*numEntries].translation, translation, MAX_WORD_LENGTH);

        (*numEntries)++;
    }

    fclose(file);
}

void translateSentence(char *sentence, SentenceTranslation *translation) {
    char *word, *token;
    int i, j;

    token = strtok(sentence, " ");
    while (token!= NULL) {
        for (i = 0; i < translation->numWords; i++) {
            if (strcmp(token, translation->words[i].word) == 0) {
                strcat(sentence, " ");
                strcat(sentence, translation->words[i].translation);
                break;
            }
        }

        if (i == translation->numWords) {
            strcat(sentence, " ");
            strcat(sentence, token);
        }

        token = strtok(NULL, " ");
    }
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <dictionary_file> <sentence_to_translate>\n", argv[0]);
        return 1;
    }

    WordTranslation dictionary[MAX_WORD_LENGTH];
    int numDictionaryEntries;

    loadDictionary(argv[1], dictionary, &numDictionaryEntries);

    SentenceTranslation translation;
    translation.words = malloc(numDictionaryEntries * sizeof(WordTranslation));
    translation.numWords = numDictionaryEntries;

    for (int i = 0; i < numDictionaryEntries; i++) {
        translation.words[i] = dictionary[i];
    }

    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence to translate: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    translateSentence(sentence, &translation);
    printf("Translated sentence: %s\n", sentence);

    free(translation.words);

    return 0;
}