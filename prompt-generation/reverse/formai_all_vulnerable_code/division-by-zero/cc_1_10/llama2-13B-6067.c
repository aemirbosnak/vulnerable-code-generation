//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define some happy functions
int add_happy(int a, int b) {
    return a + b;
}

int sub_happy(int a, int b) {
    return a - b;
}

int mul_happy(int a, int b) {
    return a * b;
}

int div_happy(int a, int b) {
    return a / b;
}

// Define some error handling functions
int handle_error(int errnum) {
    switch (errnum) {
        case 1:
            printf("Oops! It looks like you divided by zero! Better luck next time! 😅\n");
            break;
        case 2:
            printf("Whoops! It looks like you tried to add a negative number to a positive number! 😳\n");
            break;
        default:
            printf("Hmm... something went wrong! 🤔\n");
    }
    return 0;
}

int main() {
    int result;
    int a, b;

    // Try some happy calculations
    a = 5;
    b = 3;
    result = add_happy(a, b);
    printf("5 + 3 = %d\n", result);

    a = 10;
    b = 2;
    result = sub_happy(a, b);
    printf("10 - 2 = %d\n", result);

    a = 15;
    b = 4;
    result = mul_happy(a, b);
    printf("15 * 4 = %d\n", result);

    a = 20;
    b = 0;
    result = div_happy(a, b);
    handle_error(result);

    return 0;
}