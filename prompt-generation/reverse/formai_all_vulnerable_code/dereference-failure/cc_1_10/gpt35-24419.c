//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

void print_fibonacci(int);

int main(int argc, char **argv){

    if(argc != 2){
        printf("Usage: ./fibonacci <n>\n"); // command line argument is incorrect
        exit(EXIT_FAILURE);
    }

    int n = atoi(argv[1]);

    if(n <= 0){
        printf("n must be a positive integer.\n"); // n is not a positive integer
        exit(EXIT_FAILURE);
    }

    printf("Fibonacci sequence up to %d:\n", n);

    print_fibonacci(n);

    return 0;
}

void print_fibonacci(int n){

    int a = 0, b = 1, c;

    if(n == 1){ // print first fibonacci term if n == 1
        printf("%d", a);
        return;
    }

    if(n == 2){ // print first two fibonacci terms if n == 2
        printf("%d %d", a, b);
        return;
    }

    printf("%d %d ", a, b); // print first two fibonacci terms

    for(int i=3; i<=n; i++){ // calculate and print rest of fibonacci sequence
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }

    printf("\n");
}