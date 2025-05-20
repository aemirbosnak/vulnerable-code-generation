//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void print_binary(int num) {
    char binary[33];
    int i = 0;
    while (num > 0) {
        binary[i++] = (num & 1) + '0';
        num >>= 1;
    }
    binary[i] = '\0';
    printf("%s\n", binary);
}

int main() {
    int size;
    printf("Enter the size of the array (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    printf("Sum of array elements: %d\n", sum);

    int product = 1;
    for (int i = 0; i < size; i++) {
        product *= arr[i];
    }

    printf("Product of array elements: %d\n", product);

    int num1, num2;
    printf("Enter two integers to perform bitwise operations:\n");
    scanf("%d %d", &num1, &num2);

    int and_result = num1 & num2;
    int or_result = num1 | num2;
    int xor_result = num1 ^ num2;
    int not_result = ~num1;
    int left_shift_result = num1 << 2;
    int right_shift_result = num1 >> 2;

    printf("Bitwise operations:\n");
    printf("AND result: %d\n", and_result);
    printf("OR result: %d\n", or_result);
    printf("XOR result: %d\n", xor_result);
    printf("NOT result: %d\n", not_result);
    printf("Left shift result: %d\n", left_shift_result);
    printf("Right shift result: %d\n", right_shift_result);

    return 0;
}