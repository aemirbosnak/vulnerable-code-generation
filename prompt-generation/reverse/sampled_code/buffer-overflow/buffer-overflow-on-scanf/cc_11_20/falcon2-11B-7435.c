//Falcon2-11B DATASET v1.0 Category: Pathfinding algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int grid[10][10];
    int x, y, dx, dy;
    bool found;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    printf("Enter starting coordinates: ");
    scanf("%d %d", &x, &y);

    printf("Enter destination coordinates: ");
    scanf("%d %d", &dx, &dy);

    found = false;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (grid[i][j] == 0) {
                if (i == x && j == y) {
                    found = true;
                    break;
                }
                grid[i][j] = -1;
                if (i + dx >= 0 && i + dx < 10 && j + dy >= 0 && j + dy < 10) {
                    if (grid[i + dx][j + dy] == 0) {
                        grid[i + dx][j + dy] = -1;
                    } else if (grid[i + dx][j + dy] == -1) {
                        found = true;
                        break;
                    }
                }
            }
        }
        if (found) {
            break;
        }
    }

    if (found) {
        printf("Path found!\n");
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No path found.\n");
    }

    return 0;
}