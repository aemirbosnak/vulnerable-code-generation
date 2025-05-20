//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct wordFrequency {
    char* word;
    int frequency;
} WordFrequency;

WordFrequency* createWordFrequency(char* word, int frequency) {
    WordFrequency* wf = (WordFrequency*) malloc(sizeof(WordFrequency));
    wf->word = word;
    wf->frequency = frequency;
    return wf;
}

void insertWordFrequency(WordFrequency** wfArr, char* word, int* len) {
    int i;
    for (i = 0; i < *len; i++) {
        if (strcmp(wfArr[i]->word, word) == 0) {
            wfArr[i]->frequency++;
            return;
        }
    }

    wfArr[*len] = createWordFrequency(word, 1);
    (*len)++;
}

int compareWordFrequency(const void* a, const void* b) {
    const WordFrequency* wfA = *(const WordFrequency**)a;
    const WordFrequency* wfB = *(const WordFrequency**)b;
    return wfB->frequency - wfA->frequency;
}

int main() {
    printf("Please enter the text to analyze:\n");

    char current;
    char* buffer = (char*) malloc(100 * sizeof(char));
    int bufferIndex = 0;

    /* read input into buffer */
    while ((current = getchar()) != EOF) {
        if (isalpha(current)) {
            buffer[bufferIndex++] = tolower(current);
        }
        else if (bufferIndex > 0) {
            buffer[bufferIndex] = '\0';
            bufferIndex = 0;
            printf("%s\n", buffer); // DEBUG
        }
    }

    /* count word frequencies */
    WordFrequency* wfArr[1000];
    int len = 0;
    char* word = strtok(buffer, " ");
    while (word != NULL) {
        insertWordFrequency(wfArr, word, &len);
        word = strtok(NULL, " ");
    }

    /* print word frequencies */
    printf("\nWord frequencies:\n");
    qsort(wfArr, len, sizeof(WordFrequency*), compareWordFrequency);
    int i;
    for (i = 0; i < len; i++) {
        printf("%s: %d\n", wfArr[i]->word, wfArr[i]->frequency);
        free(wfArr[i]);
    }

    return 0;
}