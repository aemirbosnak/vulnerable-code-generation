//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

void shocker_search(int **arr, int n, int target) {
    int i = 0, j = n - 1;
    int found = 0;

    while (i <= j) {
        int mid = (i + j) / 2;

        if (arr[mid] == target) {
            found = 1;
            break;
        } else if (arr[mid] < target) {
            i = mid + 1;
        } else {
            j = mid - 1;
        }
    }

    if (found) {
        printf("Target found!\n");
    } else {
        printf("Target not found.\n");
    }
}

int main() {
    int n = 10;
    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    arr[0][0] = 10;
    arr[0][1] = 20;
    arr[0][2] = 30;
    arr[0][3] = 40;
    arr[0][4] = 50;
    arr[1][0] = 60;
    arr[1][1] = 70;
    arr[1][2] = 80;
    arr[1][3] = 90;
    arr[1][4] = 100;

    int target = 80;

    shocker_search(arr, n, target);

    return 0;
}