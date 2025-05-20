//Gemma-7B DATASET v1.0 Category: Weather simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 20
#define MAP_HEIGHT 20

typedef struct WeatherCell {
    int x, y;
    int temp;
    int humidity;
    struct WeatherCell* next;
} WeatherCell;

WeatherCell* createWeatherCell(int x, int y, int temp, int humidity) {
    WeatherCell* cell = malloc(sizeof(WeatherCell));
    cell->x = x;
    cell->y = y;
    cell->temp = temp;
    cell->humidity = humidity;
    cell->next = NULL;
    return cell;
}

void simulateWeather(WeatherCell* cell) {
    int i, j;
    for (i = 0; i < MAP_WIDTH; i++) {
        for (j = 0; j < MAP_HEIGHT; j++) {
            if (cell->x == i && cell->y == j) {
                printf("%d ", cell->temp);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    time_t t;
    srand(time(&t));

    WeatherCell* head = createWeatherCell(10, 10, 25, 50);
    head->next = createWeatherCell(15, 15, 30, 60);
    head->next->next = createWeatherCell(20, 20, 20, 40);

    simulateWeather(head);

    return 0;
}