//Gemma-7B DATASET v1.0 Category: GPS Navigation Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WAYPOINTS 10
#define WAYPOINT_DISTANCE 100

typedef struct waypoint {
    char name[20];
    int x, y;
    struct waypoint* next;
} waypoint;

waypoint* waypoint_create(char* name, int x, int y) {
    waypoint* wp = malloc(sizeof(waypoint));
    strcpy(wp->name, name);
    wp->x = x;
    wp->y = y;
    wp->next = NULL;
    return wp;
}

void waypoint_list(waypoint* wp) {
    while (wp) {
        printf("%s (%d, %d)\n", wp->name, wp->x, wp->y);
        wp = wp->next;
    }
}

int main() {
    waypoint* waypoints = NULL;
    waypoints = waypoint_create("Home", 10, 10);
    waypoints = waypoint_create("Work", 10, 50);
    waypoints = waypoint_create("School", 20, 10);

    waypoint_list(waypoints);

    time_t t = time(NULL);
    srand(t);

    int current_x = waypoints->x;
    int current_y = waypoints->y;
    int destination_x = waypoints->next->x;
    int destination_y = waypoints->next->y;

    int distance = WAYPOINT_DISTANCE;

    while (distance > 0) {
        int direction = rand() % 4;
        switch (direction) {
            case 0:
                current_x++;
                break;
            case 1:
                current_x--;
                break;
            case 2:
                current_y++;
                break;
            case 3:
                current_y--;
                break;
        }

        distance--;
    }

    printf("You have reached your destination!\n");

    return 0;
}