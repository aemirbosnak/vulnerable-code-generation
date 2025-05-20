//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

struct Room {
    char* name;
    char* description;
    struct Room* next;
};

struct House {
    struct Room* first_room;
};

void add_room(struct Room** rooms, char* name, char* description) {
    struct Room* new_room = (struct Room*) malloc(sizeof(struct Room));
    new_room->name = name;
    new_room->description = description;
    new_room->next = (*rooms);
    (*rooms) = new_room;
}

void add_house(struct House** houses, char* name) {
    struct House* new_house = (struct House*) malloc(sizeof(struct House));
    new_house->first_room = NULL;
    (*houses) = new_house;
}

void print_house(struct House* house) {
    struct Room* current_room = house->first_room;
    while (current_room!= NULL) {
        printf("%s\n", current_room->name);
        current_room = current_room->next;
    }
}

int main() {
    struct House* house = NULL;
    add_house(&house, "Haunted House");

    struct Room* hall = NULL;
    add_room(&hall, "Hall", "A dark and eerie hall");
    add_room(&hall, "Stairs", "A set of stairs leading down");

    struct Room* living_room = NULL;
    add_room(&living_room, "Living Room", "A cozy and comfortable living room");

    struct Room* kitchen = NULL;
    add_room(&kitchen, "Kitchen", "A well-equipped kitchen");

    struct Room* dining_room = NULL;
    add_room(&dining_room, "Dining Room", "A formal dining room");

    struct Room* bathroom = NULL;
    add_room(&bathroom, "Bathroom", "A spooky bathroom");

    struct Room* bedroom = NULL;
    add_room(&bedroom, "Bedroom", "A dark and creepy bedroom");

    struct Room* basement = NULL;
    add_room(&basement, "Basement", "A musty and damp basement");

    struct Room* attic = NULL;
    add_room(&attic, "Attic", "A dusty and cobweb-filled attic");

    struct Room* end_room = NULL;
    add_room(&end_room, "End", "The end of the house");

    hall->next = living_room;
    living_room->next = kitchen;
    kitchen->next = dining_room;
    dining_room->next = bathroom;
    bathroom->next = bedroom;
    bedroom->next = basement;
    basement->next = attic;
    attic->next = end_room;

    print_house(house);

    return 0;
}