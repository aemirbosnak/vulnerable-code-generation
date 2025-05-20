//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: optimized
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5000

void generate_random_string(char *str, int length) {
    int i;
    for (i = 0; i < length; i++) {
        str[i] = 'A' + (rand() % 26);
    }
    str[length] = '\0';
}

int main() {
    int i, j, k, l, m, n, o, p;
    int *arr = (int *) malloc(SIZE * sizeof(int));
    char str1[SIZE], str2[SIZE];
    clock_t start, end;

    srand(time(NULL));

    start = clock();

    for (i = 0; i < SIZE; i++) {
        arr[i] = i;
    }

    generate_random_string(str1, SIZE);
    generate_random_string(str2, SIZE);

    for (i = 0; i < SIZE; i++) {
        for (j = i + 1; j < SIZE; j++) {
            if (str1[i] == str2[j]) {
                arr[i] = -1;
                arr[j] = -1;
                break;
            }
        }
    }

    for (i = 0; i < SIZE; i++) {
        if (arr[i] != -1) {
            for (j = i + 1; j < SIZE; j++) {
                if (arr[j] != -1 && str1[arr[i]] == str2[arr[j]]) {
                    arr[i] = -1;
                    arr[j] = -1;
                }
            }
        }
    }

    for (i = 0, n = 0; i < SIZE; i++) {
        if (arr[i] != -1) {
            for (j = 0; j < i; j++) {
                if (arr[j] != -1 && str1[arr[i]] == str1[arr[j]]) {
                    arr[i] = -1;
                    arr[j] = -1;
                    i--;
                    break;
                }
            }
            strcpy(str2, str1 + arr[i]);
            for (k = 0, m = 0; k < strlen(str2); k++, m++) {
                if (arr[m] != -1 && str1[arr[m]] == str2[k]) {
                    arr[i] = -1;
                    arr[m] = -1;
                    i--;
                    break;
                }
            }
            n++;
        }
    }

    end = clock();

    printf("Time taken: %.10f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("Number of unique pairs: %d\n", n);

    free(arr);

    return 0;
}