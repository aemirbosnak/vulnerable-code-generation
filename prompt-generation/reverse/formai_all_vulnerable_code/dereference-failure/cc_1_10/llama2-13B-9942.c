//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_STRlen 1024
#define MAX_DEPTH 10

// Define a struct for a recursive function
typedef struct {
    int depth;
    int (*func)(struct recursion *, int);
} recursion;

// Define a function to calculate the factorial of a number
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Define a function to calculate the fibonacci sequence
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Define a function to calculate the golden ratio
double golden_ratio(int n) {
    if (n == 0) {
        return 0;
    } else {
        return (sqrt(n * (n + 1)) + n) / (n * (n + 1));
    }
}

// Define a function to print a tree of recursive calls
void print_tree(int depth, recursion *rec) {
    if (depth == 0) {
        printf("NULL\n");
        return;
    }

    printf("%d ", depth);

    if (rec->depth > depth) {
        printf("Recursion depth exceeded\n");
        return;
    }

    if (rec->func) {
        print_tree(depth - 1, rec->func(rec, rec->depth));
    }

    printf(" %p\n", rec);
}

int main() {
    int depth;
    recursion *rec;

    // Create a recursive function struct
    rec = malloc(sizeof(recursion));
    rec->depth = 0;
    rec->func = NULL;

    // Set the maximum depth and function pointers
    depth = MAX_DEPTH;
    rec->func = factorial;

    // Call the recursive function
    print_tree(depth, rec);

    // Set the maximum depth and function pointers
    depth = MAX_DEPTH;
    rec->func = fibonacci;

    // Call the recursive function
    print_tree(depth, rec);

    // Set the maximum depth and function pointers
    depth = MAX_DEPTH;
    rec->func = golden_ratio;

    // Call the recursive function
    print_tree(depth, rec);

    return 0;
}