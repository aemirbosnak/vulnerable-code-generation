//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

// Function to generate a maze
void generate_maze(int maze[10][10]) {
    // Start at the top left of the maze
    int i = 0;
    int j = 0;
    
    // Traverse the maze
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            // Add walls to the maze
            maze[i][j] = 1;
            
            // Randomly choose a direction to walk
            int choice = rand() % 4;
            switch (choice) {
                case 0:
                    j++;
                    break;
                case 1:
                    i++;
                    break;
                case 2:
                    j--;
                    break;
                case 3:
                    i--;
                    break;
            }
        }
    }
}

// Function to print the maze
void print_maze(int maze[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (maze[i][j] == 1) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int maze[10][10];
    
    // Generate the maze
    generate_maze(maze);
    
    // Print the maze
    printf("Maze:\n");
    print_maze(maze);
    
    return 0;
}