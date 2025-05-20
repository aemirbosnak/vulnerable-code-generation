//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, i, j, k;
    float x, y, z, sum = 0, avg;
    char op;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    float arr[n];

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%f", &arr[i]);
    }

    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &op);

    switch(op) {
        case '+':
            for (i = 0; i < n; i++) {
                sum += arr[i];
            }
            printf("Sum = %.2f\n", sum);
            break;
        case '-':
            for (i = 0; i < n; i++) {
                sum -= arr[i];
            }
            printf("Sum = %.2f\n", sum);
            break;
        case '*':
            for (i = 0; i < n; i++) {
                sum *= arr[i];
            }
            printf("Product = %.2f\n", sum);
            break;
        case '/':
            for (i = 0; i < n; i++) {
                sum += arr[i];
            }
            avg = sum / n;
            printf("Average = %.2f\n", avg);
            break;
        default:
            printf("Invalid operation!");
    }

    return 0;
}