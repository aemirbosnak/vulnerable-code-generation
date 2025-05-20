//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: statistical
#include <stdio.h>

// Function to calculate and print the Fibonacci sequence 
void fibonacci(int num) {
    int a = 0, b = 1, c;
    printf("\nFibonacci sequence:\n");
    printf("%d, %d, ", a, b);
    for (int i = 1; i <= num-2; i++) {
        c = a + b;
        a = b;
        b = c;
        printf("%d, ", c);
    }
}

// Function to calculate and print the average of the Fibonacci sequence
void fibonacciAverage(int num) {
    int a = 0, b = 1, c, sum = 0;
    for (int i = 1; i <= num-2; i++) {
        c = a + b;
        a = b;
        b = c;
        sum += c;
    }
    float avg = (float)sum / (num-2);
    printf("\n\nAverage of the Fibonacci sequence: %f\n", avg);
}

// Function to plot the Fibonacci sequence onto a graph
void fiboGraph(int num) {
    int a = 0, b = 1, c, maxVal = 0;
    int vals[num];
    for (int i = 1; i <= num-2; i++) {
        c = a + b;
        a = b;
        b = c;
        vals[i-1] = c;
        if (c > maxVal) {
            maxVal = c;
        }
    }
    printf("\n   Y-axis\n");
    for (int i = maxVal; i > 0; i--) {
        printf("     |");
        for (int j = 0; j < num-2; j++) {
            if (vals[j] >= i) {
                printf(" * ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
    printf("   |");
    for (int i = 0; i < num-2; i++) {
        printf("---");
    }
    printf("\n");
    printf("   |");
    for (int i = 0; i < num-2; i++) {
        printf(" %d ", vals[i]);
    }
    printf("\n   +");
    for (int i = 0; i < num-2; i++) {
        printf("---");
    }
    printf("> X-axis\n\n");
}

int main() {
    int num;
    printf("Enter the number of terms in the Fibonacci sequence: ");
    scanf("%d", &num);
    
    fibonacci(num);
    fibonacciAverage(num);
    fiboGraph(num);
    
    return 0;
}