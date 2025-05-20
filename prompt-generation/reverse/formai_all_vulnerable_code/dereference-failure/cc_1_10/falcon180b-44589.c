//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int n, i, search_val;
    int rand_num;
    srand(time(NULL));

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number you want to search: ");
    scanf("%d", &search_val);

    rand_num = rand() % n;
    if (binary_search(arr, n, search_val)) {
        printf("%d found at position %d\n", search_val, rand_num + 1);
    } else {
        printf("%d not found\n", search_val);
    }

    return 0;
}

int binary_search(int arr[], int n, int val) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == val) {
            return 1;
        } else if (arr[mid] < val) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return 0;
}