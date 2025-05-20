//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: random
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 100
#define NUM_STRINGS 5

void generateRandomString(char *str, int length) {
    int i;
    for (i = 0; i < length; i++) {
        str[i] = rand() % 26 + 'a';
    }
    str[length] = '\0';
}

void printStrings(char **strings, int numStrings) {
    int i;
    for (i = 0; i < numStrings; i++) {
        printf("%s\n", strings[i]);
    }
}

int main() {
    srand(time(NULL));
    char **strings = (char **)calloc(NUM_STRINGS, sizeof(char *));

    int i, j, k;
    for (i = 0; i < NUM_STRINGS; i++) {
        strings[i] = (char *)calloc(MAX_LENGTH, sizeof(char));
        generateRandomString(strings[i], rand() % MAX_LENGTH + 1);
    }

    printf("Initial strings:\n");
    printStrings(strings, NUM_STRINGS);

    for (i = 0; i < NUM_STRINGS; i++) {
        for (j = i + 1; j < NUM_STRINGS; j++) {
            if (strcmp(strings[i], strings[j]) < 0) {
                char *temp = strings[i];
                strings[i] = strings[j];
                strings[j] = temp;
            }
        }
    }

    printf("\nSorted strings:\n");
    printStrings(strings, NUM_STRINGS);

    for (i = 0; i < NUM_STRINGS; i++) {
        for (j = 0; j < strlen(strings[i]); j++) {
            if (strings[i][j] > 'z') {
                strings[i][j] = strings[i][j] - 'z' + 'a' - 1;
            }
        }
    }

    printf("\nStrings in reverse alphabetical order:\n");
    printStrings(strings, NUM_STRINGS);

    for (i = 0; i < NUM_STRINGS; i++) {
        free(strings[i]);
    }
    free(strings);

    return 0;
}