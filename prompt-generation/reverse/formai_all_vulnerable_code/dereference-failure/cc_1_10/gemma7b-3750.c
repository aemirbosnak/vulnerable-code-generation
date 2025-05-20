//Gemma-7B DATASET v1.0 Category: Weather simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CLOUDS 100

typedef struct cloud {
    int x, y;
    int size;
    struct cloud* next;
} cloud;

cloud* createCloud(int x, int y, int size) {
    cloud* newCloud = malloc(sizeof(cloud));
    newCloud->x = x;
    newCloud->y = y;
    newCloud->size = size;
    newCloud->next = NULL;
    return newCloud;
}

void simulateWeather() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a list of clouds
    cloud* head = createCloud(rand() % MAX_CLOUDS, rand() % MAX_CLOUDS, rand() % 10);

    // Simulate the weather for a while
    int i = 0;
    for (i = 0; i < 1000; i++) {
        // Move the clouds
        head->x = rand() % MAX_CLOUDS;
        head->y = rand() % MAX_CLOUDS;

        // Grow the clouds
        head->size = rand() % 10;

        // Create new clouds
        if (rand() % 100 < 20) {
            createCloud(rand() % MAX_CLOUDS, rand() % MAX_CLOUDS, rand() % 10);
        }

        // Print the clouds
        cloud* currentCloud = head;
        while (currentCloud) {
            printf("(");
            printf("%d, %d)", currentCloud->x, currentCloud->y);
            printf(") size: %d\n", currentCloud->size);
            currentCloud = currentCloud->next;
        }

        // Sleep for a while
        sleep(1);
    }
}

int main() {
    simulateWeather();
    return 0;
}