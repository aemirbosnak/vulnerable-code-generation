//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACIES 100
#define MAX_WORDS 100

typedef struct {
    char *name;
    char *description;
    int probability;
} ConspiracyTheory;

ConspiracyTheory conspiracies[MAX_CONSPIRACIES];
char words[MAX_WORDS];

void generateConspiracyTheories() {
    FILE *file;
    char line[256];
    int count = 0;

    file = fopen("conspiracies.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        if (count >= MAX_CONSPIRACIES) {
            printf("Error: Too many conspiracies.\n");
            exit(1);
        }

        char *token = strtok(line, ",");
        conspiracies[count].name = token;
        token = strtok(NULL, ",");
        conspiracies[count].description = token;
        token = strtok(NULL, ",");
        conspiracies[count].probability = atoi(token);

        count++;
    }

    fclose(file);
}

void generateRandomWords() {
    srand(time(NULL));

    for (int i = 0; i < MAX_WORDS; i++) {
        int length = rand() % 10 + 5;
        char *word = malloc(length * sizeof(char));

        for (int j = 0; j < length; j++) {
            word[j] = rand() % 26 + 'a';
        }

        strcat(words, word);
        strcat(words, " ");
    }
}

int main() {
    generateConspiracyTheories();
    generateRandomWords();

    int index = rand() % MAX_CONSPIRACIES;
    printf("The %s conspiracy theory states that %s with a probability of %d%%.", conspiracies[index].name, words, conspiracies[index].probability);

    return 0;
}