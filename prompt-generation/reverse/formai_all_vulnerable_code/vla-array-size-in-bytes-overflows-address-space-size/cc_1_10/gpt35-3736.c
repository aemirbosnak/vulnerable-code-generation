//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: optimized
#include <stdio.h>

int fibonacci(int num);
void display(int n, int arr[]);

int main() {
    int n, i;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    int fib[n];

    for(i=0; i<n; i++) {
        fib[i] = fibonacci(i);
    }

    display(n, fib);

    return 0;
}

// Fibonacci sequence function
int fibonacci(int num) {
    if(num == 0) {
        return 0;
    } else if(num == 1) {
        return 1;
    } else {
        return fibonacci(num-1) + fibonacci(num-2);
    }
}

// Function to display the sequence in a visually appealing way
void display(int n, int arr[]) {
    int i, j, k, max;
    int num_width = 5;   // width of each number
    max = arr[n-1];      // largest number in the sequence
    
    // Display each number in the sequence
    for(i=0; i<n; i++) {

        // center the number in each row
        for(j=0; j<(max/2)-(arr[i]/2); j++) {
            printf(" ");
        }

        // Display the number
        printf("%d\n", arr[i]);

        // Display the bars beneath the number
        for(k=0; k<arr[i]*num_width; k++) {
            printf("-");
        }
        printf("\n\n");
    }

    // Display the legend
    printf("\nLegend:\n");
    printf("- = 1\n");
    printf("-- = 2\n");
    printf("--- = 3\n");
    printf("etc...\n");
}