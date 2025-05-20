//Gemma-7B DATASET v1.0 Category: GPS Navigation Simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAP_WIDTH 1024
#define MAP_HEIGHT 1024

#define MAX_WAYPOINTS 10

typedef struct waypoint {
    int x;
    int y;
    struct waypoint* next;
} waypoint;

waypoint* createWaypoints(int numWaypoints) {
    waypoint* head = malloc(sizeof(waypoint));
    head->x = 0;
    head->y = 0;
    head->next = NULL;

    for (int i = 1; i < numWaypoints; i++) {
        waypoint* newWaypoint = malloc(sizeof(waypoint));
        newWaypoint->x = rand() % MAP_WIDTH;
        newWaypoint->y = rand() % MAP_HEIGHT;
        newWaypoint->next = head;
        head = newWaypoint;
    }

    return head;
}

void drawMap(waypoint* waypoints) {
    for (int x = 0; x < MAP_WIDTH; x++) {
        for (int y = 0; y < MAP_HEIGHT; y++) {
            int isWayPoint = 0;
            for (waypoint* currentWaypoint = waypoints; currentWaypoint; currentWaypoint = currentWaypoint->next) {
                if (currentWaypoint->x == x && currentWaypoint->y == y) {
                    isWayPoint = 1;
                }
            }

            if (isWayPoint) {
                printf("X");
            } else {
                printf(".");
            }
        }

        printf("\n");
    }
}

int main() {
    waypoint* waypoints = createWaypoints(MAX_WAYPOINTS);
    drawMap(waypoints);

    return 0;
}