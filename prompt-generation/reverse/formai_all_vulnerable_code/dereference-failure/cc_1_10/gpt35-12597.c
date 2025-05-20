//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define G 6.67e-11

//defining the structure for planets
typedef struct planet{
    char name[20];
    double mass;
    double x;
    double y;
    double vx;
    double vy;
    struct planet *next;
} planet;

//function to add new planet
void addPlanet(planet **head, char name[], double mass, double x, double y, double vx, double vy){
    planet *newPlanet = (planet*) malloc(sizeof(planet));
    strcpy(newPlanet->name, name);
    newPlanet->mass = mass;
    newPlanet->x = x;
    newPlanet->y = y;
    newPlanet->vx = vx;
    newPlanet->vy = vy;
    newPlanet->next = NULL;
    if(*head == NULL){
        *head = newPlanet;
    }
    else{
        planet *temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newPlanet;
    }
}

//function to calculate gravity between two planets
void gravity(planet *p1, planet *p2){
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double distance = sqrt(dx*dx + dy*dy);
    double force = (G*p1->mass*p2->mass)/(distance*distance);
    double acceleration1 = force/p1->mass;
    double acceleration2 = force/p2->mass;
    p1->vx -= acceleration1*(dx/distance);
    p1->vy -= acceleration1*(dy/distance);
    p2->vx += acceleration2*(dx/distance);
    p2->vy += acceleration2*(dy/distance);
}

//function to update the positions of the planets
void updatePositions(planet **head, double timeStep){
    planet *temp1 = *head;
    while(temp1 != NULL){
        planet *temp2 = temp1->next;
        while(temp2 != NULL){
            gravity(temp1, temp2);
            temp2 = temp2->next;
        }
        temp1->x += temp1->vx*timeStep;
        temp1->y += temp1->vy*timeStep;
        temp1 = temp1->next;
    }
}

//function to print the positions of the planets
void printPositions(planet *head){
    planet *temp = head;
    while(temp != NULL){
        printf("%s:\t x=%lf\t y=%lf\n", temp->name, temp->x, temp->y);
        temp = temp->next;
    }
}

int main(){
    planet *head = NULL;
    addPlanet(&head, "Sun", 1.989e30, 0, 0, 0, 0);
    addPlanet(&head, "Mercury", 3.285e23, 5.791e10, 0, 0, 4.789e4);
    addPlanet(&head, "Venus", 4.867e24, 1.082e11, 0, 0, 3.502e4);
    addPlanet(&head, "Earth", 5.972e24, 1.496e11, 0, 0, 2.978e4);
    addPlanet(&head, "Mars", 6.39e23, 2.279e11, 0, 0, 2.407e4);
    addPlanet(&head, "Jupiter", 1.898e27, 7.785e11, 0, 0, 1.307e4);
    addPlanet(&head, "Saturn", 5.683e26, 1.427e12, 0, 0, 9.69e3);
    addPlanet(&head, "Uranus", 8.681e25, 2.871e12, 0, 0, 6.81e3);
    addPlanet(&head, "Neptune", 1.024e26, 4.498e12, 0, 0, 5.43e3);
    double timeStep = 86400;
    int i;
    for(i=0; i<365; i++){
        updatePositions(&head, timeStep);
    }
    printPositions(head);
    return 0;
}