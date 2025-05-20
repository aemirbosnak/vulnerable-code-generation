//Falcon2-11B DATASET v1.0 Category: Traffic Flow Simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point start;
    Point end;
} Line;

typedef struct {
    Line* lines;
    int numLines;
    int numVehicles;
} TrafficSystem;

TrafficSystem createTrafficSystem(int numLines, int numVehicles) {
    TrafficSystem system;
    system.numLines = numLines;
    system.numVehicles = numVehicles;
    system.lines = (Line*)malloc(sizeof(Line) * numLines);
    return system;
}

void freeTrafficSystem(TrafficSystem* system) {
    free(system->lines);
    free(system);
}

void addLine(TrafficSystem* system, int startX, int startY, int endX, int endY) {
    Line* newLine = (Line*)malloc(sizeof(Line));
    newLine->start.x = startX;
    newLine->start.y = startY;
    newLine->end.x = endX;
    newLine->end.y = endY;
    system->lines[system->numLines++] = *newLine;
}

void simulateTrafficFlow(TrafficSystem* system, int numVehicles) {
    srand(time(NULL));

    for (int i = 0; i < numVehicles; i++) {
        int startX = rand() % system->numLines;
        int startY = rand() % system->numLines;
        int endX = rand() % system->numLines;
        int endY = rand() % system->numLines;

        Line* line = &system->lines[startX];
        while (line->end.x == endX && line->end.y == endY) {
            endX = rand() % system->numLines;
            endY = rand() % system->numLines;
            line = &system->lines[startX];
        }

        system->lines[startX].end.x = endX;
        system->lines[startX].end.y = endY;
    }

    printf("Traffic simulation complete.\n");
}

int main() {
    TrafficSystem system = createTrafficSystem(5, 10);

    addLine(&system, 0, 0, 4, 4);
    addLine(&system, 0, 4, 4, 8);
    addLine(&system, 4, 4, 8, 8);
    addLine(&system, 4, 8, 8, 12);
    addLine(&system, 8, 8, 12, 12);
    addLine(&system, 8, 12, 12, 16);
    addLine(&system, 12, 12, 16, 16);
    addLine(&system, 12, 16, 16, 20);
    addLine(&system, 16, 16, 20, 20);
    addLine(&system, 16, 20, 20, 24);
    addLine(&system, 20, 20, 24, 24);
    addLine(&system, 20, 24, 24, 28);
    addLine(&system, 24, 24, 28, 28);

    simulateTrafficFlow(&system, 10);

    freeTrafficSystem(&system);

    return 0;
}