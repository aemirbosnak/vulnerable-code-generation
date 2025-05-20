//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    int height;
    int weight;
    char *occupation;
} person;

typedef struct {
    char *name;
    int num_rooms;
    int num_floors;
    int num_doors;
    int num_windows;
    char *address;
} house;

typedef struct {
    person *owner;
    house *house;
    int num_ghosts;
    char *description;
} haunted_house;

int main() {
    person *owner = malloc(sizeof(person));
    strcpy(owner->name, "John Doe");
    owner->age = 30;
    owner->height = 6;
    owner->weight = 180;
    strcpy(owner->occupation, "Software Engineer");

    house *house = malloc(sizeof(house));
    strcpy(house->name, "Haunted House");
    house->num_rooms = 10;
    house->num_floors = 2;
    house->num_doors = 5;
    house->num_windows = 10;
    strcpy(house->address, "123 Main Street");

    haunted_house *haunted_house = malloc(sizeof(haunted_house));
    haunted_house->owner = owner;
    haunted_house->house = house;
    haunted_house->num_ghosts = 3;
    strcpy(haunted_house->description, "Spooky");

    printf("The haunted house is owned by %s, who is %d years old, %d feet tall, and weighs %d pounds. The house has %d rooms, %d floors, %d doors, and %d windows. It is located at %s and is described as %s.\n", haunted_house->owner->name, haunted_house->owner->age, haunted_house->owner->height, haunted_house->owner->weight, haunted_house->house->num_rooms, haunted_house->house->num_floors, haunted_house->house->num_doors, haunted_house->house->num_windows, haunted_house->house->address, haunted_house->description);

    return 0;
}