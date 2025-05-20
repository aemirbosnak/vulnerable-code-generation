//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define NUM_ROOMS 4
#define NUM_BEDROOMS 2
#define NUM_BATHROOMS 1
#define NUM_KITCHENS 1
#define NUM_HALLWAYS 1

struct Room {
    int num;
    char type[50];
};

struct House {
    struct Room rooms[NUM_ROOMS];
};

struct Bed {
    char type[50];
};

struct BedRoom {
    struct Bed beds[NUM_BEDROOMS];
};

struct Bathroom {
    char type[50];
};

struct Kitchen {
    char type[50];
};

struct Hallway {
    char type[50];
};

struct House* createHouse() {
    struct House* house = (struct House*) malloc(sizeof(struct House));
    for (int i = 0; i < NUM_ROOMS; i++) {
        house->rooms[i].num = i + 1;
        house->rooms[i].type[0] = '\0';
    }
    return house;
}

struct BedRoom* createBedRoom() {
    struct BedRoom* bedRoom = (struct BedRoom*) malloc(sizeof(struct BedRoom));
    for (int i = 0; i < NUM_BEDROOMS; i++) {
        bedRoom->beds[i].type[0] = '\0';
    }
    return bedRoom;
}

struct Bathroom* createBathroom() {
    struct Bathroom* bathroom = (struct Bathroom*) malloc(sizeof(struct Bathroom));
    bathroom->type[0] = '\0';
    return bathroom;
}

struct Kitchen* createKitchen() {
    struct Kitchen* kitchen = (struct Kitchen*) malloc(sizeof(struct Kitchen));
    kitchen->type[0] = '\0';
    return kitchen;
}

struct Hallway* createHallway() {
    struct Hallway* hallway = (struct Hallway*) malloc(sizeof(struct Hallway));
    hallway->type[0] = '\0';
    return hallway;
}

int main() {
    struct House* house = createHouse();
    struct BedRoom* bedRoom = createBedRoom();
    struct Bathroom* bathroom = createBathroom();
    struct Kitchen* kitchen = createKitchen();
    struct Hallway* hallway = createHallway();

    printf("The house has %d rooms.\n", house->rooms[0].num);
    printf("The house has %d bedrooms.\n", bedRoom->beds[0].type[0]);
    printf("The house has %d bathrooms.\n", bathroom->type[0]);
    printf("The house has %d kitchens.\n", kitchen->type[0]);
    printf("The house has %d hallways.\n", hallway->type[0]);

    free(house);
    free(bedRoom);
    free(bathroom);
    free(kitchen);
    free(hallway);

    return 0;
}