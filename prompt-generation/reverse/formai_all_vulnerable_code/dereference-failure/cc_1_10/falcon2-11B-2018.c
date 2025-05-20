//Falcon2-11B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int fibonacci(int n, int start, int end) {
    int sum = 0;
    int prev_prev = 0;
    int prev = start;
    int curr = start;
    
    if (n == 0) {
        return start;
    }
    
    if (n == 1) {
        return start;
    }
    
    for (int i = 2; i <= n; i++) {
        sum = prev + curr;
        prev_prev = prev;
        prev = curr;
        curr = sum;
    }
    
    return sum;
}

int main(int argc, char *argv[]) {
    srand(time(NULL));
    
    int n = atoi(argv[1]);
    int start = atoi(argv[2]);
    int end = atoi(argv[3]);
    
    int fib_sum = fibonacci(n, start, end);
    
    printf("Fibonacci sequence from %d to %d: ", start, end);
    printf("%d, ", fib_sum);
    printf("%d, ", fib_sum);
    printf("%d, ", fib_sum);
    printf("%d, ", fib_sum);
    printf("%d, ", fib_sum);
    printf("%d, ", fib_sum);
    printf("%d, ", fib_sum);
    printf("%d, ", fib_sum);
    printf("%d, ", fib_sum);
    printf("%d, ", fib_sum);
    printf("%d, ", fib_sum);
    printf("%d, ", fib_sum);
    printf("%d, ", fib_sum);
    printf("%d, ", fib_sum);
    printf("%d\n", fib_sum);
    
    return 0;
}