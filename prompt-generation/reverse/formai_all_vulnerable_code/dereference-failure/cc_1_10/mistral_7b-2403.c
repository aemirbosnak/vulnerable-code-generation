//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Word {
    char *word;
    int count;
} Word;

int main() {
    int i, j, wordLength, numWords;
    char line[1024], *token;
    Word *wordList;

    printf("In ancient scripts we trust,\nTo count thy words, a humble knight\nShall embark on this noble quest,\nThrough scriptures vast, to reveal the best.\n");

    // Allocate memory for wordList
    wordList = (Word *)calloc(256, sizeof(Word));

    // Open the input file
    FILE *file = fopen("ancient_manuscript.txt", "r");
    if (file == NULL) {
        printf("An error hath occurred,\nUnable to open the tome, thou art undone.\n");
        return 1;
    }

    numWords = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        token = strtok(line, " ,.!\n\t");
        while (token != NULL) {
            wordLength = strlen(token);
            for (i = 0; i < numWords; i++) {
                if (strcmp(token, wordList[i].word) == 0) {
                    wordList[i].count++;
                    break;
                }
            }
            if (i == numWords) {
                wordList[numWords].word = malloc(wordLength + 1);
                strcpy(wordList[numWords].word, token);
                wordList[numWords].count = 1;
                numWords++;
            }
            token = strtok(NULL, " ,.!\n\t");
        }
    }

    fclose(file);

    printf("\nA census hath been taken,\nOf words within this ancient tome,\nTo learn the frequency of each,\nThy faithful servant shall reveal thee this.\n");

    // Print the frequency of each word
    for (i = 0; i < numWords; i++) {
        printf("%s : %d\n", wordList[i].word, wordList[i].count);
    }

    // Free allocated memory
    for (i = 0; i < numWords; i++) {
        free(wordList[i].word);
    }
    free(wordList);

    return 0;
}