//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

// Function to generate Fibonacci sequence
void generateFibonacci(int n, long long fib[]) {
    fib[0] = 0; 
    fib[1] = 1; 
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

// Function to visualize the Fibonacci sequence
void visualizeFibonacci(int n, long long fib[]) {
    printf("\n\n-- SHOCKING FIBONACCI SEQUENCE VISUALIZER --\n");
    printf("And they thought it was all just a game...\n\n");
    
    for (int i = 0; i < n; i++) {
        printf("Fibonacci[%d]: ", i);
        if (fib[i] < 10) {
            printf("  %lld ---> ", fib[i]);
            for (int j = 0; j < fib[i]; j++) {
                printf("!");
            }
        } else if (fib[i] < 100) {
            printf(" %lld ---> ", fib[i]);
            for (int j = 0; j < fib[i] / 10; j++) {
                printf("!!!");
            }
        } else {
            printf("%lld ---> ", fib[i]);
            for (int j = 0; j < fib[i] / 100; j++) {
                printf("!!");
            }
        }
        printf("\n");
        if (i % 5 == 0 && i != 0) {
            printf("\n** Is this too much for you?! I hope you can handle it! **\n");
        }
    }
    printf("\n* But wait, there's more...\n");
    printf("This sequence reveals what the universe doesn't want you to know...\n");
}

// Main function to interact with the user and run the program
int main() {
    int n;

    printf("Enter number of Fibonacci terms you desire (up to the limits of your sanity): ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Are you even serious? Give me a number greater than 0!\n");
        return 1;
    }
    if (n > 100) {
        printf("Whoa there! Too many terms! Let’s stick to 100 or less!\n");
        n = 100;
    }

    long long *fib = (long long *)malloc(n * sizeof(long long));
    if (fib == NULL) {
        printf("Mental breakdown! Could not allocate memory!\n");
        return 1;
    }
    
    generateFibonacci(n, fib);
    visualizeFibonacci(n, fib);
    
    free(fib);
    printf("\nAll done... or is it? Be careful next time...\n");
    return 0;
}