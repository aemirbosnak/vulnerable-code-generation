//MISTRAL-7B DATASET v1.0 Category: Bitwise operations ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

void display_usage() {
    printf("Usage: bitwise_operations number1 operation number2\n");
    printf("Valid operations:\n");
    printf("  & - Bitwise AND\n");
    printf("  | - Bitwise OR\n");
    printf("  ^ - Bitwise XOR\n");
    printf("  ~ - Bitwise NOT\n");
    printf("  << - Bitwise Left Shift\n");
}

int main(int argc, char *argv[]) {
    int num1, num2, result;
    char operation;

    if (argc != 4) {
        display_usage();
        return 1;
    }

    num1 = atoi(argv[1]);
    operation = argv[2][0];
    num2 = atoi(argv[3]);

    switch (operation) {
        case '&':
            result = num1 & num2;
            break;
        case '|':
            result = num1 | num2;
            break;
        case '^':
            result = num1 ^ num2;
            break;
        case '~':
            result = ~num1;
            num1 = result;
            result = num1 & num2;
            break;
        case '<':
            if (argc != 5) {
                printf("Error: Bitwise Left Shift requires an additional argument - the number of bits to shift.\n");
                return 1;
            }
            result = num1 << atoi(argv[4]);
            break;
        default:
            display_usage();
            return 1;
    }

    printf("Result of bitwise operation: %d\n", result);
    return 0;
}