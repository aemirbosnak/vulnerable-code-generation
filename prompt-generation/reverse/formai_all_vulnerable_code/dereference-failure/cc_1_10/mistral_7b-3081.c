//MISTRAL-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_THEORY 100
#define WORDS_NUM 5

typedef struct {
    char word[WORDS_NUM][50];
} ConspiracyWords;

void loadWords(ConspiracyWords *words);
void printTheory(ConspiracyWords words);

int main() {
    ConspiracyWords words;
    loadWords(&words);
    printTheory(words);
    return 0;
}

void loadWords(ConspiracyWords *words) {
    FILE *file;
    char line[100];
    int i, j;

    file = fopen("conspiracy_words.txt", "r");

    if (file == NULL) {
        printf("Error: Unable to open words file.\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < MAX_THEORY; i++) {
        fgets(line, sizeof(line), file);
        strcpy(words->word[i], strtok(line, " \t\n"));
    }

    fclose(file);
}

void printTheory(ConspiracyWords words) {
    int i, j, k;
    int theory_length;

    srand(time(NULL));

    theory_length = rand() % (MAX_THEORY / 2) * 2 + (MAX_THEORY / 2);

    printf("Theory #%d:\n", rand() % 1000 + 1);

    for (i = 0; i < theory_length; i++) {
        j = rand() % MAX_THEORY;
        k = rand() % WORDS_NUM;
        printf("%s ", words.word[j][k]);
    }

    printf("\n");
}