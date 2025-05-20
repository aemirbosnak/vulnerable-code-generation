//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MIN_VALUE 1
#define MAX_VALUE 100

int main() {
    int arr[MAX_SIZE];
    int size;
    int sum = 0;
    int avg;
    int i;
    int j;
    int k;
    int l;
    int m;
    int n;
    int o;
    int p;
    int q;
    int r;
    int s;
    int t;
    int u;
    int v;
    int w;
    int x;
    int y;
    int z;

    printf("Enter the size of the array (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    srand(time(NULL));

    for (i = 0; i < size; i++) {
        arr[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }

    for (j = 0; j < size; j++) {
        sum += arr[j];
    }

    avg = sum / size;

    printf("The array is: ");
    for (k = 0; k < size; k++) {
        printf("%d ", arr[k]);
    }
    printf("\n");

    printf("The sum of the array is: %d\n", sum);
    printf("The average of the array is: %.2f\n", avg);

    return 0;
}