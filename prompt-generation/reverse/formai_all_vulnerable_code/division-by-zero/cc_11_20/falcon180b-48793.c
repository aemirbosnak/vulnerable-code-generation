//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Point;

void generateMap(int width, int height, char map[height][width]) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            map[i][j] = rand() % 2? '*' : '.';
        }
    }
}

int main() {
    srand(time(NULL));
    int width, height, playerX, playerY, score = 0;
    char map[100][100];

    printf("Enter the width of the map: ");
    scanf("%d", &width);

    printf("Enter the height of the map: ");
    scanf("%d", &height);

    generateMap(width, height, map);

    playerX = rand() % width;
    playerY = rand() % height;

    while (1) {
        system("clear");
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (i == playerX && j == playerY) {
                    printf("\033[1;32m*\033[0m");
                } else {
                    printf("%c", map[i][j]);
                }
            }
        }
        printf("\nScore: %d", score);
        fflush(stdout);

        char input;
        scanf("%c", &input);

        switch (input) {
            case 'w':
                if (playerY > 0 && map[playerY - 1][playerX]!= '*') {
                    playerY--;
                }
                break;
            case's':
                if (playerY < height - 1 && map[playerY + 1][playerX]!= '*') {
                    playerY++;
                }
                break;
            case 'a':
                if (playerX > 0 && map[playerY][playerX - 1]!= '*') {
                    playerX--;
                }
                break;
            case 'd':
                if (playerX < width - 1 && map[playerY][playerX + 1]!= '*') {
                    playerX++;
                }
                break;
            default:
                break;
        }

        if (map[playerY][playerX] == '*') {
            score++;
            generateMap(width, height, map);
            playerX = rand() % width;
            playerY = rand() % height;
        }
    }

    return 0;
}