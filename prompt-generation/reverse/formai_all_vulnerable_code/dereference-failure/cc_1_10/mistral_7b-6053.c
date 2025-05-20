//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_LENGTH 100
#define MAX_LENGTH 1000
#define N_STRINGS 5

void generate_string(char *str, int len) {
    int i;
    for (i = 0; i < len; i++)
        str[i] = 'x' + rand() % 26;
    str[len] = '\0';
}

int main() {
    int i, j, k, len, best_len = MIN_LENGTH, elapsed;
    clock_t start, end;
    char *strings[N_STRINGS], best_string[MIN_LENGTH];

    srand(time(NULL));

    for (i = 0; i < N_STRINGS; i++) {
        strings[i] = malloc(len = rand() % (MAX_LENGTH - MIN_LENGTH + 1) + MIN_LENGTH);
        generate_string(strings[i], len);
    }

    for (i = 0; i < N_STRINGS; i++) {
        start = clock();
        for (j = k = 0; strings[i][k]; j++) {
            if (getchar() != strings[i][j]) {
                printf("\nIncorrect character at position %d of string %d.\n", j, i + 1);
                break;
            }
        }
        if (strings[i][k]) {
            end = clock();
            elapsed = (end - start) * 1000 / CLOCKS_PER_SEC;
            if (elapsed < (float)best_len / 10 * 9 / 10) {
                best_len = len;
                memcpy(best_string, strings[i], len);
            }
        }
        free(strings[i]);
    }

    printf("\nBest string length: %d\n", best_len);
    printf("Best string: ");
    putchar('\n');
    for (i = 0; i < best_len; i++)
        putchar(best_string[i]);
    putchar('\n');

    return 0;
}