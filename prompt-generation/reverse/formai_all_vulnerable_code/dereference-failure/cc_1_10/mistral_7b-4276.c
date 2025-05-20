//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define FLOWER_NAME_LENGTH 50
#define FLOWER_COLOR_LENGTH 10
#define MIN_FLOWERS 10
#define MAX_FLOWERS 100

typedef struct Flower {
    char name[FLOWER_NAME_LENGTH];
    char color[FLOWER_COLOR_LENGTH];
    int height;
    struct Flower *next;
} Flower;

void initFlowers(Flower **flowers, int numFlowers) {
    *flowers = (Flower *) calloc(numFlowers, sizeof(Flower));

    for (int i = 0; i < numFlowers; ++i) {
        sprintf((*flowers)[i].name, "Flower %d", i + 1);
        srand(time(NULL));
        (*flowers)[i].height = rand() % 10 + 1;
    }
}

void printFlowers(Flower *flowers, int numFlowers) {
    for (int i = 0; i < numFlowers; ++i) {
        printf("\nName: %s, Color: %s, Height: %d", flowers[i].name, flowers[i].color, flowers[i].height);
    }
}

void freeFlowers(Flower *flowers, int numFlowers) {
    for (int i = 0; i < numFlowers; ++i) {
        free(&flowers[i]);
    }
    free(flowers);
}

int main() {
    Flower *flowers = NULL;
    int numFlowers;

    printf("Enter the number of flowers to be planted (min: %d, max: %d): ", MIN_FLOWERS, MAX_FLOWERS);
    scanf("%d", &numFlowers);

    initFlowers(&flowers, numFlowers);

    printf("\nPeaceful Garden:\n");
    printFlowers(flowers, numFlowers);

    usleep(100000); // Give a moment to enjoy the garden

    freeFlowers(flowers, numFlowers);
    printf("\nFlowers have been harvested and returned to nature.\n");

    return 0;
}