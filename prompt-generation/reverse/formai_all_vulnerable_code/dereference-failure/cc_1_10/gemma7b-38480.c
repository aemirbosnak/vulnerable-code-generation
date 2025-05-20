//Gemma-7B DATASET v1.0 Category: Weather simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CLOUDS 100

typedef struct Cloud {
    int x, y;
    double size, speed, direction;
    struct Cloud* next;
} Cloud;

Cloud* createCloud(int x, int y, double size, double speed, double direction) {
    Cloud* cloud = malloc(sizeof(Cloud));
    cloud->x = x;
    cloud->y = y;
    cloud->size = size;
    cloud->speed = speed;
    cloud->direction = direction;
    cloud->next = NULL;
    return cloud;
}

void simulateWeather() {
    srand(time(NULL));

    Cloud* head = NULL;
    for (int i = 0; i < MAX_CLOUDS; i++) {
        head = createCloud(rand() % 1000, rand() % 1000, rand() % 10, rand() % 10, rand() % 360);
        head->next = head;
    }

    while (head) {
        head->x += head->speed * sin(head->direction) * 0.01 * time(NULL);
        head->y += head->speed * cos(head->direction) * 0.01 * time(NULL);
        head->size += rand() % 2 - 1;

        if (head->size < 0) {
            free(head);
            head = NULL;
        } else if (head->size > MAX_CLOUDS) {
            free(head);
            head = NULL;
        }

        head = head->next;
    }
}

int main() {
    simulateWeather();
    return 0;
}