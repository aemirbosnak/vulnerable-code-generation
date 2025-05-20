//MISTRAL-7B DATASET v1.0 Category: Benchmarking ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

typedef struct {
    char name[20];
    int (*func)(int);
} competitor;

int fib_recursive(int n) {
    if (n <= 1)
        return n;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

int fib_iterative(int n) {
    int first = 0, second = 1, next;

    while (n > 0) {
        next = first + second;
        first = second;
        second = next;
        n--;
    }

    return first;
}

double get_time_diff(struct timeval start, struct timeval end) {
    double sec = (end.tv_sec - start.tv_sec) +
                 (end.tv_usec - start.tv_usec) / 1000000.0;
    return sec;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <nth Fibonacci number>\n", argv[0]);
        exit(1);
    }

    int n = atoi(argv[1]);

    competitor competitors[2] = {
        {"Recursive Gorilla A", fib_recursive},
        {"Iterative Gorilla B", fib_iterative}
    };

    struct timeval start, end;
    int fib_result;

    gettimeofday(&start, NULL);
    fib_result = competitors[0].func(n);
    gettimeofday(&end, NULL);

    printf("\n%s found %dth Fibonacci number in %.6fs: %d\n\n",
           competitors[0].name, n, get_time_diff(start, end), fib_result);

    gettimeofday(&start, NULL);
    fib_result = competitors[1].func(n);
    gettimeofday(&end, NULL);

    printf("%s found %dth Fibonacci number in %.6fs: %d\n",
           competitors[1].name, n, get_time_diff(start, end), fib_result);

    if (fib_result == competitors[0].func(n))
        printf("\nBoth gorillas have the same answer!\n");
    else
        printf("\n%s found the %dth Fibonacci number faster!\n",
               (fib_result > competitors[0].func(n) ? competitors[1].name : competitors[0].name), n);

    return 0;
}