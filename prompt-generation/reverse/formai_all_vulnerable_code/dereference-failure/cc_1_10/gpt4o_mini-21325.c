//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ncurses.h>

#define MAX_LENGTH 60
#define DELAY 300000 // 300ms

void draw_fibonacci_sequence(int n);
void print_sequence(int *seq, int count);
void draw_visualization(int *seq, int count);

int main() {
    int n;

    // Initialize the screen
    initscr();
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    
    // Title Screen
    attron(COLOR_PAIR(3));
    mvprintw(1, 1, "=== Fibonacci Sequence Visualizer ===");
    attroff(COLOR_PAIR(3));

    // User Input
    mvprintw(4, 1, "Enter the length of Fibonacci sequence (max %d): ", MAX_LENGTH);
    scanw("%d", &n);
    if(n > MAX_LENGTH) n = MAX_LENGTH; // Limit to maximum allowed length

    // Draw Fibonacci sequence
    draw_fibonacci_sequence(n);

    // End ncurses session
    getch(); // Wait for the user to press a key
    endwin(); // End the ncurses mode
    return 0;
}

void draw_fibonacci_sequence(int n) {
    int *sequence = malloc(n * sizeof(int));
    sequence[0] = 0;
    if (n > 1) sequence[1] = 1;

    for (int i = 2; i < n; i++) {
        sequence[i] = sequence[i-1] + sequence[i-2]; // Fibonacci logic
    }

    // Print the sequence
    print_sequence(sequence, n);

    // Visualize the sequence
    draw_visualization(sequence, n);
    
    free(sequence);
}

void print_sequence(int *seq, int count) {
    attron(COLOR_PAIR(1));
    mvprintw(6, 1, "Fibonacci Sequence: ");
    for (int i = 0; i < count; i++) {
        printw("%d ", seq[i]);
    }
    printw("\n");
    attroff(COLOR_PAIR(1));
}

void draw_visualization(int *seq, int count) {
    attron(COLOR_PAIR(2));
    for (int i = 0; i < count; i++) {
        // Simulate growth of Fibonacci numbers in a visual way
        mvprintw(10 + i, 1, "F(%d)", i);
        for (int j = 0; j < seq[i]; j++) {
            printw("#");
            refresh(); // Update the screen
            usleep(DELAY); // Add delay for visual effect
        }
        printw("\n");
    }
    attroff(COLOR_PAIR(2));
}