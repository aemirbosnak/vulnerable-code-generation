//Falcon2-11B DATASET v1.0 Category: Simulation of the Solar System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Planet {
    char name[50];
    float mass;
    float radius;
    int distance;
    struct Planet *next;
};

typedef struct Planet Planet;

Planet* createPlanet(char* name, float mass, float radius) {
    Planet* newPlanet = (Planet*) malloc(sizeof(Planet));
    strcpy(newPlanet->name, name);
    newPlanet->mass = mass;
    newPlanet->radius = radius;
    newPlanet->distance = 0;
    newPlanet->next = NULL;
    return newPlanet;
}

void addPlanet(Planet* list, char* name, float mass, float radius) {
    Planet* newPlanet = createPlanet(name, mass, radius);
    if (list == NULL) {
        list = newPlanet;
    } else {
        Planet* current = list;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newPlanet;
    }
}

void displayPlanets(Planet* list) {
    if (list == NULL) {
        printf("The Solar System is empty.\n");
    } else {
        Planet* current = list;
        while (current!= NULL) {
            printf("%s is %f light years away.\n", current->name, current->distance);
            current = current->next;
        }
    }
}

void movePlanet(Planet* list, char* name, float distance) {
    Planet* current = list;
    while (current!= NULL) {
        if (strcmp(current->name, name) == 0) {
            current->distance += distance;
            break;
        }
        current = current->next;
    }
}

int main() {
    srand(time(NULL));
    
    Planet* earth = createPlanet("Earth", 5.972e24, 1.0);
    Planet* mars = createPlanet("Mars", 6.4186e23, 0.53);
    Planet* venus = createPlanet("Venus", 4.8685e24, 0.72);
    Planet* jupiter = createPlanet("Jupiter", 1.8981e27, 1.0);
    
    addPlanet(earth, "Venus", 0.5, 0.72);
    addPlanet(mars, "Jupiter", 1.5, 1.0);
    addPlanet(jupiter, "Earth", 1.0, 1.0);
    
    displayPlanets(earth);
    displayPlanets(mars);
    displayPlanets(venus);
    displayPlanets(jupiter);
    
    movePlanet(earth, "Mars", 0.1);
    movePlanet(earth, "Jupiter", 0.2);
    movePlanet(earth, "Venus", 0.3);
    
    printf("\n");
    displayPlanets(earth);
    displayPlanets(mars);
    displayPlanets(venus);
    displayPlanets(jupiter);
    
    return 0;
}