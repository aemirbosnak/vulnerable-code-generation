//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 500
#define MAX_WORD_LENGTH 20

typedef struct {
    char *word;
    int count;
} WordFrequency;

void loadWords(char **words, int *numWords) {
    FILE *file = fopen("words.txt", "r");
    if(file == NULL) {
        printf("Error: Could not open words file.\n");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    int wordCount = 0;
    while(fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        char *word = strtok(line, " \n\r");
        while(word!= NULL) {
            words[wordCount] = strdup(word);
            wordCount++;
            word = strtok(NULL, " \n\r");
        }
    }
    *numWords = wordCount;

    fclose(file);
}

void generateTheory(char **words, int numWords, int maxTheoryLength) {
    srand(time(NULL));
    int theoryLength = rand() % maxTheoryLength + 1;
    char theory[theoryLength];
    theory[theoryLength - 1] = '\0';

    int i = 0;
    while(i < theoryLength) {
        int wordIndex = rand() % numWords;
        strncat(theory, words[wordIndex], MAX_WORD_LENGTH);
        i += strlen(words[wordIndex]);
        if(i < theoryLength) {
            strncat(theory, " ", 1);
        }
    }

    printf("Theory: %s\n", theory);
}

int main(int argc, char *argv[]) {
    if(argc!= 3) {
        printf("Usage: %s <words_file> <max_theory_length>\n", argv[0]);
        return 1;
    }

    char **words = malloc(MAX_WORDS * sizeof(char *));
    int numWords = 0;
    loadWords(words, &numWords);

    int maxTheoryLength = atoi(argv[2]);

    while(1) {
        generateTheory(words, numWords, maxTheoryLength);
    }

    return 0;
}