//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_INPUT_SIZE 100
#define MIN_NUMBER 1

int main() {
    int num1, num2, result;
    char str[MAX_INPUT_SIZE];

    printf("Enter first number: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        perror("Error reading input");
        exit(EXIT_FAILURE);
    }

    errno = 0;
    num1 = strtol(str, NULL, 10);

    if (errno == ERANGE || errno == EINVAL) {
        fprintf(stderr, "Invalid number: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("Enter second number: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        perror("Error reading input");
        exit(EXIT_FAILURE);
    }

    errno = 0;
    num2 = strtol(str, NULL, 10);

    if (errno == ERANGE || errno == EINVAL) {
        fprintf(stderr, "Invalid number: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (num2 == 0) {
        fprintf(stderr, "Error: Division by zero\n");
        exit(EXIT_FAILURE);
    }

    result = num1 / num2;

    printf("The result is: %d\n", result);

    return EXIT_SUCCESS;
}