//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 10
#define START_X 0
#define START_Y 0
#define END_X 9
#define END_Y 9

// Struct to represent each cell on the map
typedef struct {
    int x, y;
    int isObstacle;
    int gScore, hScore;
    int totalScore;
    struct Cell* parent;
} Cell;

// Function to initialize a new cell
Cell* initCell(int x, int y) {
    Cell* cell = malloc(sizeof(Cell));
    cell->x = x;
    cell->y = y;
    cell->isObstacle = 0;
    cell->gScore = 0;
    cell->hScore = 0;
    cell->totalScore = 0;
    cell->parent = NULL;
    return cell;
}

// Global map representing the game world
Cell* map[MAP_HEIGHT][MAP_WIDTH];

// Function to calculate the Manhattan distance between two cells
int ManhattanDistance(int x1, int y1, int x2, int y2) {
    return abs(x2 - x1) + abs(y2 - y1);
}

// Function to calculate the total score of a cell based on its gScore and hScore
int calculateTotalScore(Cell* cell) {
    return cell->gScore + cell->hScore;
}

// Function to print the path from start to end, given the final destination
void printPath(Cell* endCell) {
    Cell* currentCell = endCell;
    while (currentCell != NULL) {
        printf("-> (%d,%d)", currentCell->x, currentCell->y);
        currentCell = currentCell->parent;
    }
}

// Function to run the A* pathfinding algorithm
void AStarPathfinding(Cell* start, Cell* end) {
    // Set up the open and closed lists
    Cell* openList[MAP_WIDTH * MAP_HEIGHT] = {NULL};
    Cell* closedList[MAP_WIDTH * MAP_HEIGHT] = {NULL};

    // Add the start cell to the open list
    openList[0] = start;

    // Keep track of the current cell being examined
    Cell* currentCell = NULL;

    // Keep track of the score of the cell with the lowest total score
    int lowestScore = 0;
    
    while (openList[0] != NULL) {
        // Find the cell with the lowest total score in the open list
        for (int i = 0; openList[i] != NULL; i++) {
            if (openList[i]->totalScore < openList[lowestScore]->totalScore) {
                lowestScore = i;
            }
        }

        // Set the current cell to the cell with the lowest score and add it to the closed list
        currentCell = openList[lowestScore];
        closedList[currentCell->y * MAP_WIDTH + currentCell->x] = currentCell;

        // Remove the current cell from the open list
        for (int i = lowestScore; openList[i] != NULL; i++) {
            openList[i] = openList[i + 1];
        }

        // If the current cell is the end cell, print the path and return
        if (currentCell == end) {
            printf("Found path:");
            printPath(currentCell);
            return;
        }

        // Loop through neighboring cells
        for (int x = currentCell->x - 1; x <= currentCell->x + 1; x++) {
            for (int y = currentCell->y - 1; y <= currentCell->y + 1; y++) {
                if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
                    if (x == currentCell->x && y == currentCell->y) {
                        // Skip over the current cell (itself)
                        continue;
                    }

                    Cell* neighbor = map[y][x];
                    if (neighbor->isObstacle) {
                        // If the neighbor is an obstacle, skip it
                        continue;
                    }

                    // Calculate tentative gScore for the neighbor
                    int tentativeGScore = currentCell->gScore + ManhattanDistance(currentCell->x, currentCell->y, neighbor->x, neighbor->y);

                    // Check if the neighbor is already in the closed list and has a higher score
                    if (closedList[y * MAP_WIDTH + x] != NULL && tentativeGScore >= closedList[y * MAP_WIDTH + x]->gScore) {
                        continue;
                    }

                    // Check if the neighbor is already in the open list and has a higher score
                    int neighborInOpenList = 0;
                    for (int i = 0; openList[i] != NULL; i++) {
                        if (openList[i] == neighbor) {
                            neighborInOpenList = 1;
                            if (tentativeGScore < neighbor->gScore) {
                                // Update the neighbor's gScore and totalScore
                                neighbor->gScore = tentativeGScore;
                                neighbor->totalScore = calculateTotalScore(neighbor);
                                neighbor->parent = currentCell;
                            }
                            break;
                        }
                    }

                    // If the neighbor is not in the open list, add it
                    if (!neighborInOpenList) {
                        neighbor->gScore = tentativeGScore;
                        neighbor->hScore = ManhattanDistance(neighbor->x, neighbor->y, end->x, end->y);
                        neighbor->totalScore = calculateTotalScore(neighbor);
                        neighbor->parent = currentCell;
                        for (int i = 0; openList[i] != NULL; i++) {
                            if (openList[i]->totalScore > neighbor->totalScore) {
                                // Insert the new neighbor into the open list in sorted order by total score
                                for (int j = MAP_WIDTH * MAP_HEIGHT - 1; j > i; j--) {
                                    openList[j] = openList[j - 1];
                                }
                                openList[i] = neighbor;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    printf("No path found.");
}

// Function to print the current state of the map (obstacles and path, if applicable)
void printMap(Cell* start, Cell* end) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (map[y][x]->isObstacle) {
                printf("# ");
            } else if (map[y][x] == start) {
                printf("S ");
            } else if (map[y][x] == end) {
                printf("E ");
            } else if (map[y][x]->parent != NULL) {
                printf(". ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

// Main function to set up the game world and run the pathfinding algorithm
int main() {
    // Initialize map with cells
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            map[y][x] = initCell(x, y);
        }
    }

    // Add obstacles to the map
    map[3][3]->isObstacle = 1;
    map[3][4]->isObstacle = 1;
    map[4][3]->isObstacle = 1;
    map[4][4]->isObstacle = 1;
    map[5][5]->isObstacle = 1;
    map[6][4]->isObstacle = 1;
    map[6][5]->isObstacle = 1;

    // Set start and end cells
    Cell* start = map[START_Y][START_X];
    Cell* end = map[END_Y][END_X];

    // Run the pathfinding algorithm
    AStarPathfinding(start, end);

    // Print the final state of the map
    printf("\nFinal map:\n");
    printMap(start, end);

    return 0;
}