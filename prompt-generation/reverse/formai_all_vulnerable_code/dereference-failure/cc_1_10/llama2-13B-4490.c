//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int x = 5;
    int y = 10;

    // Oh no! Division by zero! 😱
    if (y == 0) {
        printf("Whoa, you tried to divide by zero! 😲\n");
        return 1;
    }

    // Oh no! Input error! 😱
    if (scanf("%d", &x) != 1) {
        printf("Uh oh, there was an input error! 😱\n");
        return 2;
    }

    // Oh no! Memory allocation failed! 😱
    if (malloc(10 * sizeof(int)) == NULL) {
        printf("Oops, memory allocation failed! 😱\n");
        return 3;
    }

    // Oh no! Array index out of bounds! 😱
    if (x < 0 || x >= 10) {
        printf("Oops, array index out of bounds! 😱\n");
        return 4;
    }

    // Oh no! Pointer points to null! 😱
    if (x == NULL) {
        printf("Uh oh, pointer points to null! 😱\n");
        return 5;
    }

    // Oh no! Division by non-integer! 😱
    if (x / 2.5 != 0) {
        printf("Whoa, division by non-integer! 😱\n");
        return 6;
    }

    // Oh no! Logic error! 😱
    if (x > y) {
        printf("Oops, logic error! 😱\n");
        return 7;
    }

    return 0;
}