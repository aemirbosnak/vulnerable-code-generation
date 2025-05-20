//Gemma-7B DATASET v1.0 Category: Weather simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CLOUDS 100

typedef struct Cloud {
    int x;
    int y;
    int size;
    struct Cloud* next;
} Cloud;

Cloud* createCloud() {
    Cloud* newCloud = malloc(sizeof(Cloud));
    newCloud->x = rand() % 1000;
    newCloud->y = rand() % 1000;
    newCloud->size = rand() % 10;
    newCloud->next = NULL;
    return newCloud;
}

void simulateWeather() {
    Cloud* head = NULL;
    for (int i = 0; i < MAX_CLOUDS; i++) {
        Cloud* newCloud = createCloud();
        if (head == NULL) {
            head = newCloud;
        } else {
            newCloud->next = head;
            head = newCloud;
        }
    }

    time_t t = time(NULL);
    int hour = 0;
    while (hour < 24) {
        for (Cloud* currentCloud = head; currentCloud; currentCloud = currentCloud->next) {
            currentCloud->x += rand() % 5 - 2;
            currentCloud->y += rand() % 5 - 2;
            currentCloud->size += rand() % 3 - 1;
        }

        hour++;
        sleep(1);
    }

    free(head);
}

int main() {
    simulateWeather();
    return 0;
}