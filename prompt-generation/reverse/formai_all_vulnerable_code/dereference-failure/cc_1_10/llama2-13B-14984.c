//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_DIVISION_RATE 1.05 // cells divide every 105 seconds on average
#define CELL_DEATH_RATE 0.05 // cells die at a rate of 5% per second
#define FOOD_SOURCE 10 // initial amount of food available
#define CELL_MAX_SIZE 100 // maximum size of a cell
#define CELL_MIN_SIZE 1 // minimum size of a cell
#define GENERATIONS 100 // number of generations to run the simulation for

// struct to store information about a cell
typedef struct cell {
    int size; // size of the cell
    int age; // age of the cell
} cell_t;

// function to initialize the simulation
void init_simulation(int num_cells) {
    cell_t *cells = malloc(num_cells * sizeof(cell_t));
    for (int i = 0; i < num_cells; i++) {
        cells[i].size = CELL_MIN_SIZE;
        cells[i].age = 0;
    }
}

// function to update the simulation
void update_simulation(cell_t *cells, int num_cells) {
    for (int i = 0; i < num_cells; i++) {
        // check if the cell has reached its maximum size
        if (cells[i].size >= CELL_MAX_SIZE) {
            cells[i].size = CELL_MAX_SIZE;
        }

        // check if the cell has died
        if (cells[i].age >= CELL_DEATH_RATE * 1000) {
            cells[i].size = CELL_MIN_SIZE;
        }

        // update the cell's age
        cells[i].age += 1;

        // check if the cell should divide
        if (rand() % 100 < CELL_DIVISION_RATE) {
            // divide the cell
            cell_t new_cell;
            new_cell.size = cells[i].size / 2;
            new_cell.age = cells[i].age;
            cells[i].size -= new_cell.size;
            cells = realloc(cells, (num_cells + 1) * sizeof(cell_t));
            cells[num_cells] = new_cell;
            num_cells++;
        }
    }
}

// function to print the final state of the simulation
void print_results(cell_t *cells, int num_cells) {
    for (int i = 0; i < num_cells; i++) {
        printf("%d %d\n", cells[i].size, cells[i].age);
    }
}

int main() {
    srand(time(NULL)); // seed the random number generator

    // initialize the simulation with 100 cells
    int num_cells = 100;
    cell_t *cells = malloc(num_cells * sizeof(cell_t));
    init_simulation(num_cells);

    // run the simulation for 100 generations
    for (int i = 0; i < GENERATIONS; i++) {
        update_simulation(cells, num_cells);
    }

    // print the final state of the simulation
    print_results(cells, num_cells);

    return 0;
}