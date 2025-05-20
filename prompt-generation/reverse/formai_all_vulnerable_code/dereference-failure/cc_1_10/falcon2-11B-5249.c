//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int *arr, int size) {
    int i, j, temp;
    for (i = size - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int isSame(int *arr1, int *arr2, int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr1[i]!= arr2[i]) {
            return 0;
        }
    }
    return 1;
}

int winGame(int *arr1, int *arr2, int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (isSame(arr1, arr2, size)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int n, m, i;
    srand(time(NULL));
    n = rand() % 10 + 1;
    m = rand() % 10 + 1;
    int *arr1, *arr2;
    arr1 = (int *)malloc(n * sizeof(int));
    arr2 = (int *)malloc(m * sizeof(int));
    for (i = 0; i < n; i++) {
        arr1[i] = rand() % 100;
    }
    for (i = 0; i < m; i++) {
        arr2[i] = rand() % 100;
    }
    shuffle(arr1, n);
    shuffle(arr2, m);
    printf("Pair 1: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\nPair 2: ");
    for (i = 0; i < m; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");
    if (winGame(arr1, arr2, n)) {
        printf("Congratulations! You have won the game!\n");
    } else {
        printf("Sorry, you have lost the game.\n");
    }
    return 0;
}