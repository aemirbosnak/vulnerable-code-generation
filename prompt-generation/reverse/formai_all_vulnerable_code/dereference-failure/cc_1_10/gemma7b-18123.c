//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_CARS 5

typedef struct Car {
    char model[20];
    int year;
    int mileage;
    struct Car* next;
} Car;

Car* createCar(char* model, int year, int mileage) {
    Car* newCar = malloc(sizeof(Car));
    strcpy(newCar->model, model);
    newCar->year = year;
    newCar->mileage = mileage;
    newCar->next = NULL;
    return newCar;
}

void addCar(Car* head, char* model, int year, int mileage) {
    Car* newCar = createCar(model, year, mileage);
    if (head == NULL) {
        head = newCar;
    } else {
        head->next = newCar;
    }
    head = newCar;
}

void playGame(Car* head) {
    int round = 1;
    while (head) {
        printf("Round %d:\n", round);
        printf("Car model: %s\n", head->model);
        printf("Year: %d\n", head->year);
        printf("Mileage: %d\n", head->mileage);
        printf("\n");
        round++;
        head = head->next;
    }
}

int main() {
    Car* head = NULL;
    addCar(head, "Ford Mustang", 1965, 20);
    addCar(head, "Chevrolet Corvette", 1955, 15);
    addCar(head, "Ferrari 488", 2015, 12);
    addCar(head, "Lamborghini Huracan", 2020, 9);
    addCar(head, "Porsche 911", 1990, 18);

    playGame(head);

    return 0;
}