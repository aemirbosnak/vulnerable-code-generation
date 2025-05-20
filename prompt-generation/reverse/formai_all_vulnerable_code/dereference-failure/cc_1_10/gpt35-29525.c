//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: unmistakable
#include <stdio.h>

void fibonacci(int n) {
    int a = 0, b = 1, c, i;
    printf("Fibonacci sequence: \n");

    if (n == 0)
        printf("Empty sequence.\n");

    else if (n == 1)
        printf("%d", a);

    else if (n == 2)
        printf("%d %d", a, b);

    else {
        printf("%d %d ", a, b);
        for (i = 2; i < n; ++i) {
            c = a + b;
            a = b;
            b = c;
            printf("%d ", c);
        }
    }
    printf("\n");
}

void printBars(int num) {
    for (int i = 1; i <= num; i++) {
        printf("-----");
    }
    printf("\n");
}

void printFibonacciBars(int arr[], int n) {
    int max_val = arr[n-1], i, count;
    printf("Fibonacci sequence visualization\n");

    for (i = 0; i < n; ++i) {
        count = (arr[i] * 49) / max_val;
        printf("%d -> ", arr[i]);
        for (int j = 0; j < count; j++) {
            printf("|");
        }
        printf("\n");
    }
    printBars(n);
}

int main() {
    int n;
    printf("Enter the number of elements in the Fibonacci sequence: ");
    scanf("%d", &n);
    fibonacci(n);

    int sequence[n];

    if (n > 0) {
        sequence[0] = 0;
    }

    if (n > 1) {
        sequence[1] = 1;
    }

    for (int i = 2; i < n; i++) {
        sequence[i] = sequence[i-1] + sequence[i-2];
    }

    printFibonacciBars(sequence, n);

    return 0;
}