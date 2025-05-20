//MISTRAL-7B DATASET v1.0 Category: Benchmarking ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 10000
#define CHAR_PER_WORD 50

void create_random_string(char *str, int length) {
    int i;
    for (i = 0; i < length; i++) {
        str[i] = rand() % 26 + 'A';
    }
    str[length] = '\0';
}

int main() {
    clock_t start, end;
    double duration;
    char *strings[SIZE];
    int i;

    srand(time(NULL));

    start = clock();

    for (i = 0; i < SIZE; i++) {
        strings[i] = malloc(CHAR_PER_WORD * sizeof(char));
        create_random_string(strings[i], CHAR_PER_WORD);
    }

    for (i = 0; i < SIZE; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            int len1 = strlen(strings[i]);
            int len2 = strlen(strings[j]);
            int res = strcmp(strings[i], strings[j]);

            if (res < 0) {
                char *temp = strings[i];
                strings[i] = strings[j];
                strings[j] = temp;
            }
        }
    }

    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorting %d strings, each of length %d characters, took %.2f seconds.\n", SIZE, CHAR_PER_WORD, duration);

    for (i = 0; i < SIZE; i++) {
        free(strings[i]);
    }

    return 0;
}