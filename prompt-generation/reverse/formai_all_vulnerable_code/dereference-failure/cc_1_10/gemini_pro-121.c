//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: visionary
// Embark on a celestial odyssey through the enigmatic labyrinth of possibilities.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the celestial expanse as a grid of shimmering stars.
typedef struct Star {
    int x, y;
    bool visited;
} Star;

// Envision a star chart that guides our ethereal journey.
typedef struct StarChart {
    Star* stars;
    int width, height;
} StarChart;

// Create a celestial tapestry adorned with twinkling stars.
StarChart* createStarChart(int width, int height) {
    StarChart* chart = malloc(sizeof(StarChart));
    chart->width = width;
    chart->height = height;
    chart->stars = malloc(sizeof(Star) * width * height);
    for (int i = 0; i < width * height; i++) {
        chart->stars[i].x = i % width;
        chart->stars[i].y = i / width;
        chart->stars[i].visited = false;
    }
    return chart;
}

// Seek the cosmic origin, the interstellar birthplace.
int findOrigin(StarChart* chart) {
    int origin = 0;
    for (int i = 0; i < chart->width * chart->height; i++) {
        if (!chart->stars[i].visited) {
            origin = i;
            break;
        }
    }
    return origin;
}

// Traverse the labyrinth, illuminating each celestial body we touch.
void traverseLabyrinth(StarChart* chart, int current) {
    if (current >= chart->width * chart->height) {
        return;
    }
    Star* star = &chart->stars[current];
    if (star->visited) {
        return;
    }
    star->visited = true;
    // Celestial whispers guide us to the next interstellar haven.
    int up = current - chart->width;
    if (up >= 0) {
        traverseLabyrinth(chart, up);
    }
    int down = current + chart->width;
    if (down < chart->width * chart->height) {
        traverseLabyrinth(chart, down);
    }
    int left = current - 1;
    if (current % chart->width != 0) {
        traverseLabyrinth(chart, left);
    }
    int right = current + 1;
    if ((current + 1) % chart->width != 0) {
        traverseLabyrinth(chart, right);
    }
}

// Behold the enchantment of our celestial tapestry.
void printStarChart(StarChart* chart) {
    for (int i = 0; i < chart->width * chart->height; i++) {
        if (chart->stars[i].visited) {
            printf("*");
        } else {
            printf(" ");
        }
        if ((i + 1) % chart->width == 0) {
            printf("\n");
        }
    }
}

// Weave the ethereal tapestry of our cosmic adventure.
int main() {
    printf("Enter the dimensions of your celestial expanse (width height): ");
    int width, height;
    scanf("%d %d", &width, &height);
    StarChart* chart = createStarChart(width, height);
    int origin = findOrigin(chart);
    traverseLabyrinth(chart, origin);
    printf("Behold the celestial labyrinth we have traversed:\n");
    printStarChart(chart);
    return 0;
}