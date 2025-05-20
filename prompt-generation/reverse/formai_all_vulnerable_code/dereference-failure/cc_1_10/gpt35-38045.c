//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void drawLine(int n, char c) {
    for (int i = 0; i < n; i++) {
        printf("%c", c);
    }
    printf("\n");
}

void drawFibonacci(int n) {
    int prev = 0, curr = 1, next;
    for (int i = 0; i < n; i++) {
        printf("%d ", curr);
        next = prev + curr;
        prev = curr;
        curr = next;
    }
    printf("\n");
}

void drawFibonacciSpiral(int n) {
    int prevX = 1, prevY = 0, currX = 1, currY = 0, nextX, nextY;
    for (int i = 0; i < n; i++) {
        nextX = currX + prevX;
        nextY = currY + prevY;
        printf("(%d, %d)\n", currX, currY);
        prevX = currX;
        prevY = currY;
        currX = nextX;
        currY = nextY;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: ./fib <option>\n");
        printf("Options:\n 1. Draw Fibonacci Sequence\n 2. Draw Fibonacci Spiral\n");
        return 0;
    }

    int option = atoi(argv[1]);

    switch(option) {
        case 1:
            {
            printf("Enter the number of terms to display: ");
            int n;
            scanf("%d", &n);
            drawLine(50, '*');
            printf("FIBONACCI SEQUENCE\n");
            drawLine(50, '*');
            drawFibonacci(n);
            drawLine(50, '*');
            break;
            }
        case 2:
            {
            printf("Enter the number of terms to display: ");
            int n;
            scanf("%d", &n);
            drawLine(50, '*');
            printf("FIBONACCI SPIRAL\n");
            drawLine(50, '*');
            drawFibonacciSpiral(n);
            break;
            }
        default:
            printf("Invalid option!\n");
            break;
    }

    return 0;
}