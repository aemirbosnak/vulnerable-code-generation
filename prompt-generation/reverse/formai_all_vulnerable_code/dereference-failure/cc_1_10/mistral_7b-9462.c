//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Word {
    char* word;
    int length;
} Word;

void createWords(Word** words, int numWords, char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open file.\n");
        exit(EXIT_FAILURE);
    }

    *words = (Word*) malloc(numWords * sizeof(Word));
    for (int i = 0; i < numWords; i++) {
        fscanf(file, "%s", (*words)[i].word);
        (*words)[i].length = strlen((*words)[i].word);
    }

    fclose(file);
}

void printWord(Word word) {
    printf("%s", word.word);
}

int main() {
    srand(time(NULL));
    int numWords = 10;
    int numTrials = 5;
    int numMisses = 0;

    Word* words;
    createWords(&words, numWords, "words.txt");

    printf("\nShocked Typing Speed Test\n");
    printf("---------------------------\n");

    for (int trial = 0; trial < numTrials; trial++) {
        Word randomWord = words[rand() % numWords];
        printf("\nType the following word as fast as you can:\n");
        printWord(randomWord);

        char input[randomWord.length + 1];
        scanf("%s", input);

        if (strcmp(input, randomWord.word) != 0) {
            numMisses++;
            printf("Error! You missed the word: %s\n", randomWord.word);
        }
    }

    printf("\nYou had %d misses in %d trials.\n", numMisses, numTrials);
    printf("Your typing speed is approximately %d words per minute.\n", (numWords * numTrials / numMisses) * 60 / numTrials);

    free(words);
    return 0;
}