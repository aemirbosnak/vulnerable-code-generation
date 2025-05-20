//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 1000
#define LEN 100
#define SEED 1337

void generate_string(char *str) {
    int i;
    for (i = 0; i < LEN; i++)
        str[i] = 'a' + (rand() % 26);
    str[LEN] = '\0';
}

int main() {
    int i, j, k;
    char *str1, *str2;
    clock_t start, end;

    srand(SEED);

    str1 = (char *) malloc(LEN * sizeof(char));
    str2 = (char *) malloc(LEN * sizeof(char));

    generate_string(str1);
    generate_string(str2);

    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);

    start = clock();

    for (i = 0; i < N; i++) {
        for (j = 0; j < LEN; j++) {
            if (str1[j] != str2[j]) {
                k = i;
                goto mismatch;
            }
        }
    }

    printf("Strings are identical.\n");

mismatch:
    end = clock();
    free(str1);
    free(str2);

    printf("Time elapsed: %.6f milliseconds\n",
        (end - start) * 1000 / CLOCKS_PER_SEC);

    return 0;
}