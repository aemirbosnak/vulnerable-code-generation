//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Coordinate {
    float lat;
    float lon;
};

struct Node {
    struct Coordinate coord;
    struct Node* next;
};

void displayCoordinates(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%.2f, %.2f\n", current->coord.lat, current->coord.lon);
        current = current->next;
    }
}

struct Node* generateRoute(int numCoordinates) {
    struct Node* head = NULL;
    struct Node* current = NULL;
    srand(time(NULL));
    for (int i = 0; i < numCoordinates; i++) {
        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
        struct Coordinate newCoord;
        newCoord.lat = ((float) rand() / RAND_MAX) * 180 - 90;
        newCoord.lon = ((float) rand() / RAND_MAX) * 360 - 180;
        newNode->coord = newCoord;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            current = current->next;
        }
    }
    return head;
}

int main() {
    struct Node* route = generateRoute(10);
    printf("Generated route:\n");
    displayCoordinates(route);
    printf("Done.\n");
    return 0;
}