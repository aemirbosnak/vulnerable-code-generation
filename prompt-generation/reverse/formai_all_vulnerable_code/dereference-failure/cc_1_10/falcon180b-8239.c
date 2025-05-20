//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 50

typedef struct {
    char *english;
    char *cat;
} Word;

int numWords = 0;
Word *wordList = NULL;

void addWord(char *english, char *cat) {
    numWords++;
    wordList = realloc(wordList, sizeof(Word) * numWords);
    wordList[numWords-1].english = strdup(english);
    wordList[numWords-1].cat = strdup(cat);
}

int main() {
    FILE *file;
    char line[100];
    char *english, *cat;

    file = fopen("cat_dictionary.txt", "r");

    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        english = strtok(line, "\t");
        cat = strtok(NULL, "\n");

        addWord(english, cat);
    }

    fclose(file);

    printf("Enter a sentence to translate:\n");
    char sentence[1000];
    fgets(sentence, sizeof(sentence), stdin);

    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(token, wordList[i].english) == 0) {
                printf("%s ", wordList[i].cat);
                break;
            }
        }

        if (i == numWords) {
            printf("%s ", token);
        }

        token = strtok(NULL, " ");
    }

    printf("\n");

    return 0;
}