//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/* Struct to represent a cell in the grid */
typedef struct {
    int row, col;
    double f, g, h;
    bool is_obstacle;
    struct Cell* parent;
} Cell;

/* Struct to represent the grid */
typedef struct {
    int rows, cols;
    Cell* cells;
} Grid;

/* Function to create a new grid and initialize all the cells */
Grid* create_grid(int rows, int cols, Cell* cells) {
    Grid* grid = (Grid*) malloc(sizeof(Grid));
    grid->rows = rows;
    grid->cols = cols;
    grid->cells = cells;
    return grid;
}

/* Function to create a new cell with the specified row and column */
Cell* create_cell(int row, int col) {
    Cell* cell = (Cell*) malloc(sizeof(Cell));
    cell->row = row;
    cell->col = col;
    cell->f = cell->g = cell->h = 0;
    cell->is_obstacle = false;
    cell->parent = NULL;
    return cell;
}

/* Function to get the index of a cell in the grid */
int get_index(Grid* grid, int row, int col) {
    return row * grid->cols + col;
}

/* Function to get the cell at the specified row and column */
Cell* get_cell(Grid* grid, int row, int col) {
    int index = get_index(grid, row, col);
    return &grid->cells[index];
}

/* Function to check if a cell is a valid neighbor */
bool is_valid_neighbor(Grid* grid, int row, int col) {
    return (row >= 0 && row < grid->rows && col >= 0 && col < grid->cols);
}

/* Function to check if a cell is an obstacle */
bool is_obstacle(Cell* cell) {
    return cell->is_obstacle;
}

/* Function to calculate the manhattan distance between two cells */
double manhattan_distance(Cell* cell1, Cell* cell2) {
    return fabs(cell1->row - cell2->row) + fabs(cell1->col - cell2->col);
}

/* Function to calculate the euclidean distance between two cells */
double euclidean_distance(Cell* cell1, Cell* cell2) {
    int dx = cell1->row - cell2->row;
    int dy = cell1->col - cell2->col;
    return sqrt(dx * dx + dy * dy);
}

/* Function to calculate the diagonal distance between two cells */
double diagonal_distance(Cell* cell1, Cell* cell2) {
    int dx = fabs(cell1->row - cell2->row);
    int dy = fabs(cell1->col - cell2->col);
    return fmax(dx, dy);
}

/* Function to calculate the cost from the start cell to the current cell */
double calculate_g(Cell* current, Cell* start) {
    double dx = fabs(current->row - start->row);
    double dy = fabs(current->col - start->col);
    if (dx > dy) {
        return 1.414 * dy + 1.0 * (dx - dy);
    }
    return 1.414 * dx + 1.0 * (dy - dx);
}

/* Function to calculate the heuristic estimate from the current cell to the end cell*/
double calculate_h(Cell* current, Cell* end, int heuristic) {
    switch(heuristic) {
        case 1: return manhattan_distance(current, end);
        case 2: return euclidean_distance(current, end);
        case 3: return diagonal_distance(current, end);
        default: return 0;
    }
}

/* Function to find the cell with the lowest f value in the open set */
Cell* get_lowest_f_cost(Grid* grid, Cell* start, Cell* end, int heuristic) {
    double min_f_cost = INFINITY;
    Cell* lowest_cell = NULL;
    for (int i = 0; i < grid->rows; i++) {
        for (int j = 0; j < grid->cols; j++) {
            Cell* current = get_cell(grid, i, j);
            if (!is_obstacle(current) && !current->parent) {
                current->g = calculate_g(current, start);
                current->h = calculate_h(current, end, heuristic);
                current->f = current->g + current->h;
                if (current->f < min_f_cost) {
                    min_f_cost = current->f;
                    lowest_cell = current;
                }
            }
        }
    }
    return lowest_cell;
}

/* Function to find the path from the start cell to the end cell */
void find_path(Grid* grid, Cell* start, Cell* end, int heuristic) {
    start->g = start->h = start->f = 0;
    Cell* open_set[grid->rows][grid->cols];
    for (int i = 0; i < grid->rows; i++) {
        for (int j = 0; j < grid->cols; j++) {
            open_set[i][j] = NULL;
        }
    }
    open_set[start->row][start->col] = start;
    while (open_set[end->row][end->col] == NULL) {
        Cell* current = get_lowest_f_cost(grid, start, end, heuristic);
        if (current == NULL) {
            printf("No path found.\n");
            return;
        }
        open_set[current->row][current->col] = NULL;
        if (current == end) {
            printf("Path found!\n");
            while (current) {
                printf("(%d,%d) ", current->row, current->col);
                current = current->parent;
            }
            printf("\n");
            return;
        }
        Cell* neighbors[] = {
            is_valid_neighbor(grid, current->row + 1, current->col) ? get_cell(grid, current->row + 1, current->col) : NULL,
            is_valid_neighbor(grid, current->row - 1, current->col) ? get_cell(grid, current->row - 1, current->col) : NULL,
            is_valid_neighbor(grid, current->row, current->col + 1) ? get_cell(grid, current->row, current->col + 1) : NULL,
            is_valid_neighbor(grid, current->row, current->col - 1) ? get_cell(grid, current->row, current->col - 1) : NULL,
            is_valid_neighbor(grid, current->row - 1, current->col - 1) ? get_cell(grid, current->row - 1, current->col - 1) : NULL,
            is_valid_neighbor(grid, current->row - 1, current->col + 1) ? get_cell(grid, current->row - 1, current->col + 1) : NULL,
            is_valid_neighbor(grid, current->row + 1, current->col - 1) ? get_cell(grid, current->row + 1, current->col - 1) : NULL,
            is_valid_neighbor(grid, current->row + 1, current->col + 1) ? get_cell(grid, current->row + 1, current->col + 1) : NULL
        };
        for (int i = 0; i < 8; i++) {
            Cell* neighbor = neighbors[i];
            if (neighbor && !is_obstacle(neighbor)) {
                double temp_g = calculate_g(neighbor, start);
                if (temp_g < neighbor->g || !open_set[neighbor->row][neighbor->col]) {
                    neighbor->parent = current;
                    neighbor->g = temp_g;
                    neighbor->h = calculate_h(neighbor, end, heuristic);
                    neighbor->f = neighbor->g + neighbor->h;
                    if (!open_set[neighbor->row][neighbor->col]) {
                        open_set[neighbor->row][neighbor->col] = neighbor;
                    }
                }
            }
        }
    }
}

/* Main function */
int main() {
    // Create the grid
    int rows = 5, cols = 5;
    Cell* cells = (Cell*) malloc(rows * cols * sizeof(Cell));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cells[get_index(cells, i, j)] = *create_cell(i, j);
        }
    }
    // Add obstacles
    get_cell(cells, 1, 1)->is_obstacle = true;
    get_cell(cells, 2, 1)->is_obstacle = true;
    get_cell(cells, 3, 1)->is_obstacle = true;
    // Create the grid and run the algorithm
    Grid* grid = create_grid(rows, cols, cells);
    Cell* start = get_cell(grid, 0, 0);
    Cell* end = get_cell(grid, rows - 1, cols - 1);
    int heuristic = 2; // 1 = manhattan distance, 2 = euclidean distance, 3 = diagonal distance
    find_path(grid, start, end, heuristic);
    // Free memory
    free(grid->cells);
    free(grid);
    return 0;
}