//FormAI DATASET v1.0 Category: Error handling ; Style: Cryptic
#include <stdio.h>

#define ERROR_DIVISION_BY_ZERO -1
#define ERROR_OUT_OF_BOUNDS -2
#define ERROR_NULL_POINTER -3
#define ERROR_UNKNOWN -4

void handle_error(int error_code) {
    switch (error_code) {
        case ERROR_DIVISION_BY_ZERO:
            printf("Error: Division by zero.\n");
            exit(1);
        case ERROR_OUT_OF_BOUNDS:
            printf("Error: Index out of bounds.\n");
            abort();
        case ERROR_NULL_POINTER:
            printf("Error: Null pointer.\n");
            exit(1);
        default:
            printf("Error: Unknown error.\n");
            exit(1);
    }
}

int safe_divide(int a, int b) {
    if (b == 0) {
        handle_error(ERROR_DIVISION_BY_ZERO);
    }

    return a / b;
}

int safe_get(int* arr, int index) {
    if (index < 0 || index >= sizeof(arr) / sizeof(int)) {
        handle_error(ERROR_OUT_OF_BOUNDS);
    }

    int res = *(arr + index);

    if (res == NULL) {
        handle_error(ERROR_NULL_POINTER);
    }

    return res;
}

int main() {
    int a = 5, b = 0;
    int* arr = malloc(sizeof(int) * 5);

    int res = safe_divide(a, b);

    for (int i = 0; i < 10; i++) {
        safe_get(arr, i);
    }

    return 0;
}