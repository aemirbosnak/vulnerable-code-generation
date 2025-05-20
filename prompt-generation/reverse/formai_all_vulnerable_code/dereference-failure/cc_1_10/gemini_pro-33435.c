//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A twisted maze of memory cells, each holding a tantalizing secret.
struct MemoryCell {
    int value;
    struct MemoryCell *next;
    struct MemoryCell *prev;
};

// A labyrinthine journey through the depths of memory.
struct MemoryMaze {
    struct MemoryCell *head;
    struct MemoryCell *tail;
    int size;
};

// Creates a new memory cell and assigns a random value to it.
struct MemoryCell *create_memory_cell() {
    struct MemoryCell *cell = malloc(sizeof(struct MemoryCell));
    cell->value = rand() % 100;
    cell->next = NULL;
    cell->prev = NULL;
    return cell;
}

// Initializes a new memory maze with a random number of cells.
struct MemoryMaze *create_memory_maze() {
    struct MemoryMaze *maze = malloc(sizeof(struct MemoryMaze));
    maze->head = NULL;
    maze->tail = NULL;
    maze->size = 0;
    
    // Randomly generate a number of cells between 10 and 20.
    int num_cells = 10 + rand() % 11;
    
    for (int i = 0; i < num_cells; i++) {
        struct MemoryCell *cell = create_memory_cell();
        
        // Append the new cell to the end of the maze.
        if (maze->head == NULL) {
            maze->head = cell;
            maze->tail = cell;
        } else {
            maze->tail->next = cell;
            cell->prev = maze->tail;
            maze->tail = cell;
        }
        
        maze->size++;
    }
    
    return maze;
}

// Prints the values of all the cells in the maze, from head to tail.
void print_memory_maze(struct MemoryMaze *maze) {
    struct MemoryCell *cell = maze->head;
    
    printf("Memory Maze:\n");
    while (cell != NULL) {
        printf("%d ", cell->value);
        cell = cell->next;
    }
    
    printf("\n");
}

// The enigmatic game of memory begins.
void play_memory_game(struct MemoryMaze *maze) {
    // Randomly select two cells from the maze.
    int cell_1_index = rand() % maze->size;
    int cell_2_index = rand() % maze->size;
    
    // Ensure that the two cells are different.
    while (cell_1_index == cell_2_index) {
        cell_2_index = rand() % maze->size;
    }
    
    // Find the first cell.
    struct MemoryCell *cell_1 = maze->head;
    for (int i = 0; i < cell_1_index; i++) {
        cell_1 = cell_1->next;
    }
    
    // Find the second cell.
    struct MemoryCell *cell_2 = maze->head;
    for (int i = 0; i < cell_2_index; i++) {
        cell_2 = cell_2->next;
    }
    
    // Reveal the values of the two cells.
    printf("Cell 1: %d\n", cell_1->value);
    printf("Cell 2: %d\n", cell_2->value);
    
    // Check if the player guessed correctly.
    int guess;
    printf("Are the two cells the same? (1 for yes, 0 for no): ");
    scanf("%d", &guess);
    
    if (guess == (cell_1->value == cell_2->value)) {
        printf("Congratulations! You matched the cells.\n");
    } else {
        printf("Oops! You didn't match the cells.\n");
    }
}

int main() {
    srand(time(NULL));
    
    // Create a new memory maze.
    struct MemoryMaze *maze = create_memory_maze();
    
    // Print the memory maze.
    print_memory_maze(maze);
    
    // Play the memory game.
    play_memory_game(maze);
    
    return 0;
}