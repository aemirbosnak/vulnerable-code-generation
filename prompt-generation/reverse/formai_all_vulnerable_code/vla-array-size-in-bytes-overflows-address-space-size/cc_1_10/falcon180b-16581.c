//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, m, sum = 0, i;
    float avg;
    char op;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    for(i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &op);

    switch(op) {
        case '+':
            for(i = 0; i < n; i++) {
                sum += arr[i];
            }
            printf("Sum of elements: %d\n", sum);
            break;
        case '-':
            for(i = 0; i < n; i++) {
                sum -= arr[i];
            }
            printf("Sum of elements: %d\n", sum);
            break;
        case '*':
            for(i = 0; i < n; i++) {
                sum *= arr[i];
            }
            printf("Product of elements: %d\n", sum);
            break;
        case '/':
            for(i = 0; i < n; i++) {
                sum += arr[i];
            }
            avg = (float)sum / n;
            printf("Average of elements: %.2f\n", avg);
            break;
        default:
            printf("Invalid operation!");
    }

    return 0;
}