//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACY_LENGTH 100
#define MAX_WORDS 100

typedef struct {
    char *word;
    int length;
} Word;

Word words[MAX_WORDS];

void initWords() {
    FILE *file = fopen("words.txt", "r");
    char line[MAX_CONSPIRACY_LENGTH];
    int count = 0;

    while (fgets(line, MAX_CONSPIRACY_LENGTH, file)!= NULL) {
        words[count].word = strdup(line);
        words[count].length = strlen(line);
        count++;
    }

    fclose(file);
}

void generateConspiracy(int length) {
    srand(time(NULL));

    char conspiracy[MAX_CONSPIRACY_LENGTH];
    conspiracy[0] = '\0';

    for (int i = 0; i < length; i++) {
        int wordIndex = rand() % MAX_WORDS;
        strcat(conspiracy, words[wordIndex].word);
        strcat(conspiracy, " ");
    }

    printf("%s\n", conspiracy);
}

int main() {
    initWords();

    int length;
    printf("Enter the length of the conspiracy theory: ");
    scanf("%d", &length);

    generateConspiracy(length);

    return 0;
}