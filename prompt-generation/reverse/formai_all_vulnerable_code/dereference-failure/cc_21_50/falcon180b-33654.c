//Falcon-180B DATASET v1.0 Category: Table Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int width = rand() % 10 + 5;
    int height = rand() % 10 + 5;
    int **table = (int **)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        table[i] = (int *)malloc(width * sizeof(int));
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            table[i][j] = rand() % 9 + 1;
        }
    }
    int playerX = rand() % width;
    int playerY = rand() % height;
    int playerDirection = rand() % 4;
    int score = 0;
    while (1) {
        system("clear");
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                printf("%d ", table[i][j]);
            }
            printf("\n");
        }
        printf("Score: %d\n", score);
        printf("Player at (%d,%d) facing %s\n", playerX, playerY, (playerDirection == 0)? "up" : (playerDirection == 1)? "right" : (playerDirection == 2)? "down" : "left");
        int key = getchar();
        if (key == 'w' && playerDirection!= 2) {
            playerY--;
        } else if (key =='s' && playerDirection!= 0) {
            playerY++;
        } else if (key == 'a' && playerDirection!= 3) {
            playerX--;
        } else if (key == 'd' && playerDirection!= 1) {
            playerX++;
        }
        if (table[playerY][playerX] == 0) {
            score++;
        }
        if (score == width * height) {
            printf("You win!\n");
            break;
        }
    }
    for (int i = 0; i < height; i++) {
        free(table[i]);
    }
    free(table);
    return 0;
}