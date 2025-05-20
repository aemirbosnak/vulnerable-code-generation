//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char *name;
    int age;
} Person;

typedef struct {
    int id;
    char *name;
    int capacity;
    Person **people;
} Room;

typedef struct {
    int id;
    char *name;
    Room **rooms;
} Building;

int main() {
    // Create a new building
    Building *building = malloc(sizeof(Building));
    building->id = 1;
    building->name = "Main Building";
    building->rooms = malloc(sizeof(Room *) * 10);

    // Create a new room in the building
    Room *room = malloc(sizeof(Room));
    room->id = 1;
    room->name = "Room 1";
    room->capacity = 10;
    room->people = malloc(sizeof(Person *) * 10);

    // Create a new person and add them to the room
    Person *person = malloc(sizeof(Person));
    person->id = 1;
    person->name = "John Doe";
    person->age = 20;
    room->people[0] = person;

    // Print the information about the building, room, and person
    printf("Building:\n");
    printf("  ID: %d\n", building->id);
    printf("  Name: %s\n", building->name);
    printf("\n");
    printf("Room:\n");
    printf("  ID: %d\n", room->id);
    printf("  Name: %s\n", room->name);
    printf("  Capacity: %d\n", room->capacity);
    printf("\n");
    printf("Person:\n");
    printf("  ID: %d\n", person->id);
    printf("  Name: %s\n", person->name);
    printf("  Age: %d\n", person->age);

    // Free the allocated memory
    free(person);
    free(room);
    free(building);

    return 0;
}