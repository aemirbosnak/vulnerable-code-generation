//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for sleep
#include <ncurses.h> // for visual representation in terminal

void draw_fibonacci(int n);
void print_fibonacci(int n);
void visualize_fibonacci(int *fib, int n);

int main() {
    int n;

    // Initialize ncurses
    initscr();
    noecho();
    curs_set(FALSE);

    // Get user input for Fibonacci sequence length
    printw("Enter the number of Fibonacci terms to visualize: ");
    scanw("%d", &n);

    // Validate input
    if (n <= 0) {
        printw("Please enter a positive integer.\n");
        refresh();
        sleep(2);
        endwin();
        return 1;
    }

    draw_fibonacci(n);

    // Cleanup ncurses
    endwin();
    return 0;
}

void draw_fibonacci(int n) {
    int *fib = (int*)malloc(n * sizeof(int));

    // Generate Fibonacci terms
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Print Fibonacci numbers to console
    print_fibonacci(n);

    // Visualize Fibonacci sequence in terminal
    visualize_fibonacci(fib, n);

    // Free allocated memory
    free(fib);
}

void print_fibonacci(int n) {
    printw("\nFibonacci sequence:\n");
    for (int i = 0; i < n; i++) {
        printw("%d ", i == 0 ? 0 : (i == 1 ? 1 : i));
        if (i % 10 == 9) {
            printw("\n"); // Print newline every 10 terms
        }
    }
    printw("\n");
    refresh();
    sleep(2);
}

void visualize_fibonacci(int *fib, int n) {
    clear();
    printw("Visualizing the Fibonacci Sequence:\n\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < fib[i]; j++) {
            printw("*");
        }
        printw(" (%d)\n", fib[i]);
        refresh();
        sleep(1); // Slow down the visualization for better viewing
    }

    printw("\nEnd of visualization. Press any key to exit.");
    refresh();
    getch();
}