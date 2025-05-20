//FormAI DATASET v1.0 Category: Error handling ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void error(int code) {
    switch (code) {
        case 0:
            printf("Error code 0: Cooldown exhausted.\n");
            break;
        case 1:
            printf("Error code 1: Insufficient funds.\n");
            break;
        case 2:
            printf("Error code 2: Invalid input detected.\n");
            break;
        case 3:
            printf("Error code 3: Connection lost.\n");
            break;
        case 4:
            printf("Error code 4: Resource not found.\n");
            break;
        default:
            printf("Unknown error code.\n");
            break;
    }
}

int main() {
    int input, result;
    char *buffer;

    buffer = (char *) malloc(sizeof(char) * 10);

    printf("Enter a number: ");
    fgets(buffer, 10, stdin);
    input = atoi(buffer);

    if (input < 0) {
        fprintf(stderr, "Error: Input must be positive.\n");
        exit(1);
    }

    printf("Calculating factorial of %d...\n", input);

    result = 1;
    for (int i = 2; i <= input; i++) {
        result *= i;

        if (result <= 0) {
            perror("Error");
            error(errno);
            exit(1);
        }
    }

    printf("Factorial of %d is %d\n", input, result);

    free(buffer);

    return 0;
}