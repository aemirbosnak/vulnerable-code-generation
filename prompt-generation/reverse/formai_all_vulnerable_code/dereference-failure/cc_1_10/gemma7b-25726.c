//Gemma-7B DATASET v1.0 Category: Table Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_CARS 5

typedef struct Car {
    char name[20];
    int speed;
    int position;
    struct Car* next;
} Car;

Car* createCar(char* name, int speed, int position) {
    Car* car = (Car*)malloc(sizeof(Car));
    strcpy(car->name, name);
    car->speed = speed;
    car->position = position;
    car->next = NULL;
    return car;
}

void moveCar(Car* car, int direction) {
    switch (direction) {
        case 1:
            car->position++;
            break;
        case 2:
            car->position--;
            break;
    }
}

void printCars(Car* head) {
    while (head) {
        printf("%s is at position %d, going %d.\n", head->name, head->position, head->speed);
        head = head->next;
    }
}

int main() {
    Car* head = createCar("Ford", 50, 0);
    Car* second = createCar("Mustang", 60, 1);
    Car* third = createCar("Chevy", 40, 2);

    head->next = second;
    second->next = third;

    printCars(head);

    moveCar(head, 1);
    moveCar(second, 2);

    printCars(head);

    return 0;
}