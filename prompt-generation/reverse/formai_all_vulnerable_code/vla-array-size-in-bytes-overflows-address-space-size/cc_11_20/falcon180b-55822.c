//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_ROWS 4
#define NUM_COLS 3
#define RED_LIGHT 1
#define YELLOW_LIGHT 2
#define GREEN_LIGHT 3
#define PEDESTRIAN 4
#define BLANK 5

int main() {
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int traffic_lights[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            traffic_lights[i][j] = BLANK;
        }
    }

    int row = 0;
    int col = 0;
    int direction = 1;

    while (true) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (traffic_lights[i][j] == RED_LIGHT) {
                    if (direction == 1) {
                        traffic_lights[i][j] = YELLOW_LIGHT;
                    } else {
                        traffic_lights[i][j] = GREEN_LIGHT;
                    }
                } else if (traffic_lights[i][j] == YELLOW_LIGHT) {
                    if (direction == 1) {
                        traffic_lights[i][j] = RED_LIGHT;
                    } else {
                        traffic_lights[i][j] = GREEN_LIGHT;
                    }
                } else if (traffic_lights[i][j] == GREEN_LIGHT) {
                    if (direction == 1) {
                        traffic_lights[i][j] = YELLOW_LIGHT;
                    } else {
                        traffic_lights[i][j] = RED_LIGHT;
                    }
                }
            }
        }

        row += direction;
        if (row >= rows) {
            direction = -1;
        } else if (row <= 0) {
            direction = 1;
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%d ", traffic_lights[i][j]);
            }
            printf("\n");
        }

        usleep(100000);
    }

    return 0;
}