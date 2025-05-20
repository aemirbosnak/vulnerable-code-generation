//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct AlienWord {
    char *alien;
    char *earth;
} AlienWord;

void translate(AlienWord *word) {
    int i, j;
    int alienLength = strlen(word->alien);

    for (i = 0; i < alienLength; i++) {
        if (isalpha(word->alien[i])) {
            j = word->alien[i] - 'A';
            if (j < 0 || j > 25) {
                printf("Invalid alien character.\n");
                return;
            }
            word->earth[i] = 'E' + (3 * (j + 1)) % 26;
        } else {
            word->earth[i] = word->alien[i];
        }
    }
    word->earth[alienLength] = '\0';
}

void printWord(AlienWord *word) {
    printf("Alien: %s\n", word->alien);
    printf("Earth: %s\n", word->earth);
}

int main() {
    int numWords;
    int i;

    printf("Enter number of words to be translated: ");
    scanf("%d", &numWords);

    AlienWord *words = (AlienWord *)calloc(numWords, sizeof(AlienWord));

    for (i = 0; i < numWords; i++) {
        printf("Enter Alien word %d: ", i + 1);
        fgets(words[i].alien, sizeof(words[i].alien), stdin);
        words[i].alien[strlen(words[i].alien) - 1] = '\0';

        words[i].earth = (char *)calloc(strlen(words[i].alien) + 1, sizeof(char));

        translate(&words[i]);
    }

    for (i = 0; i < numWords; i++) {
        printWord(&words[i]);
    }

    for (i = 0; i < numWords; i++) {
        free(words[i].earth);
    }
    free(words);

    return 0;
}