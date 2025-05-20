//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

char words[MAX_WORDS][MAX_WORD_LENGTH];
int numWords;

void readWords(char* filename) {
    FILE* file;
    char word[MAX_WORD_LENGTH];
    int i = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    while (fscanf(file, "%s", word)!= EOF) {
        strcpy(words[i], word);
        i++;
    }

    fclose(file);
    numWords = i;
}

void printWords() {
    int i;

    for (i = 0; i < numWords; i++) {
        printf("%s ", words[i]);
    }
}

int compareWords(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

void sortWords() {
    qsort(words, numWords, sizeof(words[0]), compareWords);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    strcpy(argv[1], argv[2]);
    readWords(argv[1]);
    sortWords();
    printWords();

    return 0;
}