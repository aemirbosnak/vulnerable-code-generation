//Falcon2-11B DATASET v1.0 Category: Syntax parsing ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse(char *input);
int fibonacci(int n);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <n>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    parse(argv[1]);

    printf("The %dth Fibonacci number is %d\n", n, fibonacci(n));
    return 0;
}

void parse(char *input) {
    char *start = input;
    char *end = strchr(input, '}');

    if (end == NULL) {
        fprintf(stderr, "Invalid syntax: missing '}'\n");
        exit(1);
    }

    char *value = strndup(start, end - start + 1);
    int n = atoi(value);
    free(value);

    if (n <= 0) {
        fprintf(stderr, "Invalid syntax: %d is not a positive integer\n", n);
        exit(1);
    }

    if (n > 100) {
        fprintf(stderr, "Invalid syntax: %d is too large\n", n);
        exit(1);
    }

    if (n == 1) {
        printf("%d %d\n", 0, 1);
        return;
    }

    int prev = 0;
    int curr = 1;
    int i;
    for (i = 2; i <= n; i++) {
        int sum = prev + curr;
        printf("%d ", sum);
        prev = curr;
        curr = sum;
    }
}

int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}