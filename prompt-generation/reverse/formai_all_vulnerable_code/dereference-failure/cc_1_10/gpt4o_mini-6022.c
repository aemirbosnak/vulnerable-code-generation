//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>

// Function to calculate Fibonacci numbers
void generate_fibonacci(int n, int *fib) {
    fib[0] = 0;
    if (n > 1) {
        fib[1] = 1;
    }
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

// Function to visualize Fibonacci Sequence
void visualize_fibonacci(int n, int *fib) {
    int max_length = 0;

    // Find maximum length of Fibonacci number for formatting
    for (int i = 0; i < n; i++) {
        char str[20];
        sprintf(str, "%d", fib[i]);
        int len = strlen(str);
        if (len > max_length) {
            max_length = len;
        }
    }

    // Start ncurses for visualization
    initscr(); // Initialize the ncurses screen
    start_color(); // Start using colors
    init_pair(1, COLOR_GREEN, COLOR_BLACK); // Create a color pair
    attron(COLOR_PAIR(1)); // Turn on color

    // Visualize each Fibonacci number
    for (int i = 0; i < n; i++) {
        mvprintw(i, 0, "%-*d", max_length, fib[i]); // Print Fibonacci number
        refresh(); // Refresh to show output
        sleep(1); // Pause for effect
    }

    // Wait for user input to exit
    attroff(COLOR_PAIR(1)); // Turn off color
    mvprintw(n + 1, 0, "Press any key to exit...");
    refresh();
    getch(); // Wait for user input

    endwin(); // End ncurses mode
}

int main(int argc, char *argv[]) {
    int n;

    // Check for user input in command line
    if (argc < 2) {
        printf("Usage: %s <number_of_terms>\n", argv[0]);
        return EXIT_FAILURE; // Exit if no argument is provided
    }

    // Convert command line argument to integer
    n = atoi(argv[1]);
    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return EXIT_FAILURE; // Exit if argument is invalid
    }

    int *fib = malloc(n * sizeof(int)); // Allocate memory for Fibonacci numbers
    if (fib == NULL) {
        printf("Memory allocation failed.\n");
        return EXIT_FAILURE; // Exit if memory allocation fails
    }

    generate_fibonacci(n, fib); // Generate Fibonacci numbers
    visualize_fibonacci(n, fib); // Visualize them

    free(fib); // Free allocated memory
    return EXIT_SUCCESS; // Exit the program successfully
}