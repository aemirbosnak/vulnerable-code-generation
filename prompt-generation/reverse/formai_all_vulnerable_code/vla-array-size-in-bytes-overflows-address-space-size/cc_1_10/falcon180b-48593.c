//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int i, j, k, n, m, sum = 0;
    float avg, num;
    char ch;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &ch);

    switch (ch) {
        case '+':
            for (i = 0; i < n; i++) {
                sum += arr[i];
            }
            printf("Sum: %d\n", sum);
            break;
        case '-':
            for (i = 0; i < n; i++) {
                sum -= arr[i];
            }
            printf("Sum: %d\n", sum);
            break;
        case '*':
            for (i = 0; i < n; i++) {
                sum *= arr[i];
            }
            printf("Product: %d\n", sum);
            break;
        case '/':
            for (i = 0; i < n; i++) {
                sum += arr[i];
            }
            avg = (float) sum / n;
            printf("Average: %.2f\n", avg);
            break;
        default:
            printf("Invalid operation.\n");
            break;
    }

    return 0;
}