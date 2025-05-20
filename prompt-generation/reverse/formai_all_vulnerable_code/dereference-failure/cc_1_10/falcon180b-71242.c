//Falcon-180B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Point;

void generate_map(int width, int height, char **map) {
    srand(time(NULL));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (rand() % 2 == 0) {
                map[i][j] = '#';
            } else {
                map[i][j] = '.';
            }
        }
    }
}

int main() {
    int width, height;

    printf("Enter the width of the map: ");
    scanf("%d", &width);

    printf("Enter the height of the map: ");
    scanf("%d", &height);

    char **map = (char **)malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        map[i] = (char *)malloc(width * sizeof(char));
    }

    generate_map(width, height, map);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < height; i++) {
        free(map[i]);
    }
    free(map);

    return 0;
}