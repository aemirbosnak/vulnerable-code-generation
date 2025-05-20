//FormAI DATASET v1.0 Category: Robot movement control ; Style: secure
#include <stdio.h>
#include <stdlib.h>

void move_forward(char **map, int rows, int cols, int *x, int *y) {
    if (*x < rows - 1 && map[*x + 1][*y] != '#') {
        *x += 1;
    }
}

void move_backward(char **map, int rows, int cols, int *x, int *y) {
    if (*x > 0 && map[*x - 1][*y] != '#') {
        *x -= 1;
    }
}

void move_left(char **map, int rows, int cols, int *x, int *y) {
    if (*y > 0 && map[*x][*y - 1] != '#') {
        *y -= 1;
    }
}

void move_right(char **map, int rows, int cols, int *x, int *y) {
    if (*y < cols - 1 && map[*x][*y + 1] != '#') {
        *y += 1;
    }
}

int main() {
    int rows = 5, cols = 5;
    char **map = (char **) malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        map[i] = (char *) malloc(cols * sizeof(char));
    }

    // Create a map of '#'s to represent walls and ' 's to represent open spaces
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            map[i][j] = ' ';
        }
    }

    map[0][0] = '#';
    map[0][2] = '#';
    map[1][0] = '#';
    map[2][3] = '#';
    map[3][1] = '#';
    map[3][3] = '#';
    map[4][1] = '#';

    int x = 2, y = 2;  // Start in the middle of the map
    printf("You are a robot in a 5x5 room. Use commands 'w', 'a', 's', 'd' to move.\n");
    printf("You cannot move through walls (represented by '#'). Get to the goal (represented by 'G')!\n");
    printf("Press 'q' to quit.\n");

    while (1) {
        // Print the map and current position of the robot
        printf("\n");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i == x && j == y) {
                    printf("R ");
                } else if (map[i][j] == '#') {
                    printf("# ");
                } else if (i == rows - 1 && j == cols - 1) {
                    printf("G ");
                } else {
                    printf("  ");  // open space
                }
            }
            printf("\n");
        }

        // Get user input
        char input;
        scanf(" %c", &input);
        switch (input) {
            case 'w':
                move_forward(map, rows, cols, &x, &y);
                break;
            case 'a':
                move_left(map, rows, cols, &x, &y);
                break;
            case 's':
                move_backward(map, rows, cols, &x, &y);
                break;
            case 'd':
                move_right(map, rows, cols, &x, &y);
                break;
            case 'q':
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid command. Please try again.\n");
        }

        // Check if the robot has reached the goal
        if (x == rows - 1 && y == cols - 1) {
            printf("Congratulations, you reached the goal!\n");
            break;
        }
    }

    // Free memory used by the map
    for (int i = 0; i < rows; i++) {
        free(map[i]);
    }
    free(map);

    return 0;
}