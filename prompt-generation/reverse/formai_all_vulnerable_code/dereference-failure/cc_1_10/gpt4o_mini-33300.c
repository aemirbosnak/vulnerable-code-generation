//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

void display_fibonacci(int n) {
    int *fib = (int *)malloc(n * sizeof(int));
    if (fib == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    fib[0] = 0;
    fib[1] = 1;

    printf("Fibonacci Sequence up to %d terms:\n", n);
    printf("   +---------------------------------------+\n");
    printf("   | Term | Value                         |\n");
    printf("   +---------------------------------------+\n");
    printf("   |  1   | %d                            |\n", fib[0]);
    printf("   |  2   | %d                            |\n", fib[1]);

    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        printf("   |  %2d  | %d                            |\n", i + 1, fib[i]);
    }
    printf("   +---------------------------------------+\n");

    free(fib);
}

void analyze_fibonacci(int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (i < 2) ? i : (i - 1) + (i - 2);
    }
    printf("The sum of the first %d Fibonacci terms is: %d\n", n, sum);
}

void inscribe_my_deduction() {
    printf("\nElementary, my dear Watson!\n");
    printf("The Fibonacci sequence offers us a glimpse into the mathematical harmony of nature.\n");
    printf("We shall unravel its secrets and see the beauty it beholds.\n");
}

int main() {
    int terms;

    printf("Dear user, I implore you to specify the number of terms you wish to visualize in the Fibonacci sequence: ");
    if (scanf("%d", &terms) != 1 || terms <= 0) {
        fprintf(stderr, "Alas, a valid number of terms must be greater than zero!\n");
        return EXIT_FAILURE;
    }

    inscribe_my_deduction();
    display_fibonacci(terms);
    analyze_fibonacci(terms);

    printf("And thus, we conclude our mathematical investigation.\n");
    return EXIT_SUCCESS;
}