//GPT-4o-mini DATASET v1.0 Category: Game of Life ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define WIDTH 50
#define HEIGHT 20

// Function prototypes
void initGrid(int **grid);
void printGrid(int **grid);
void updateGrid(int **current, int **next);
int countNeighbors(int **grid, int x, int y);
int kbhit();
char getch();

// Main function
int main() {
    int **currentGrid = malloc(HEIGHT * sizeof(int *));
    int **nextGrid = malloc(HEIGHT * sizeof(int *));

    for (int i = 0; i < HEIGHT; i++) {
        currentGrid[i] = calloc(WIDTH, sizeof(int));
        nextGrid[i] = calloc(WIDTH, sizeof(int));
    }

    initGrid(currentGrid);
    
    char control;
    printf("Conway's Game of Life\n");
    printf("Press 'p' to pause, 'r' to resume, and 'q' to quit.\n");

    while (1) {
        printGrid(currentGrid);
        updateGrid(currentGrid, nextGrid);
        
        // Swap grids
        int **temp = currentGrid;
        currentGrid = nextGrid;
        nextGrid = temp;

        if (kbhit()) {
            control = getch();
            if (control == 'q') break;        // Quit
            else if (control == 'p') {         // Pause
                while (1) {
                    if (kbhit()) {
                        if (getch() == 'r') break;  // Resume
                    }
                    usleep(100000);  // Wait
                }
            }
        }
        usleep(200000); // Game speed adjust
        printf("\e[H\e[2J"); // Clear screen
    }

    for (int i = 0; i < HEIGHT; i++) {
        free(currentGrid[i]);
        free(nextGrid[i]);
    }
    free(currentGrid);
    free(nextGrid);
    
    return 0;
}

// Initialize grid with a random pattern
void initGrid(int **grid) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            grid[i][j] = rand() % 2; // Randomly assign 0 or 1
        }
    }
}

// Print the current state of the grid
void printGrid(int **grid) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf(grid[i][j] ? "█" : " ");
        }
        printf("\n");
    }
}

// Update the grid according to the rules of the game
void updateGrid(int **current, int **next) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int aliveNeighbors = countNeighbors(current, i, j);
            if (current[i][j]) {
                next[i][j] = (aliveNeighbors == 2 || aliveNeighbors == 3) ? 1 : 0;
            } else {
                next[i][j] = (aliveNeighbors == 3) ? 1 : 0;
            }
        }
    }
}

// Count the number of alive neighbors
int countNeighbors(int **grid, int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue; // Skip current cell
            int ni = (x + i + HEIGHT) % HEIGHT; // Wrap around vertically
            int nj = (y + j + WIDTH) % WIDTH; // Wrap around horizontally
            count += grid[ni][nj];
        }
    }
    return count;
}

// Check if a key has been pressed
int kbhit() {
    struct termios oldt, newt;
    int oldf;

    tcgetattr(0, &oldt); // Get current terminal settings
    newt = oldt; // Copy current settings
    newt.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
    tcsetattr(0, TCSANOW, &newt); // Set new settings
    oldf = fcntl(0, F_GETFL, 0); // Get current flags
    fcntl(0, F_SETFL, oldf | O_NONBLOCK); // Set non-blocking mode

    int c = getchar();
    tcsetattr(0, TCSANOW, &oldt); // Restore old settings
    fcntl(0, F_SETFL, oldf); // Restore old flags

    if(c != EOF) {
        ungetc(c, stdin); // Put the character back
        return 1; // Key is pressed
    }
    return 0; // No key pressed
}

// Get character without waiting for Enter
char getch() {
    char buf = 0;
    struct termios old = {0};

    if (tcgetattr(0, &old) < 0)
        perror ("tcsetattr()");
    old.c_lflag &= ~ICANON; // Disable canonical mode
    old.c_lflag &= ~ECHO; // Disable echo
    tcsetattr(0, TCSANOW, &old);
    if (read(0, &buf, 1) < 0)
        perror ("read()");
    
    old.c_lflag |= ICANON; // Re-enable canonical mode
    old.c_lflag |= ECHO; // Re-enable echo 
    tcsetattr(0, TCSADRAIN, &old);

    return (buf);
}