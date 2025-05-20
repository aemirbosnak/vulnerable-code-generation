//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the haunted house structure
typedef struct HauntedHouse {
    char name[20];
    int rooms;
    struct HauntedHouse* next;
} HauntedHouse;

// Create a haunted house
HauntedHouse* createHauntedHouse() {
    HauntedHouse* house = malloc(sizeof(HauntedHouse));
    house->name[0] = '\0';
    house->rooms = 0;
    house->next = NULL;
    return house;
}

// Add a room to a haunted house
void addRoom(HauntedHouse* house, int rooms) {
    house->rooms += rooms;
}

// Simulate a haunted house
void simulateHauntedHouse(HauntedHouse* house) {
    time_t t = time(NULL);
    int rand_num = rand() % 10;
    switch (rand_num) {
        case 0:
            printf("You hear a disembodied scream echo through the halls.\n");
            break;
        case 1:
            printf("The scent of decaying flesh fills the air.\n");
            break;
        case 2:
            printf("A cold wind whips through the house, carrying with it the scent of burning incense.\n");
            break;
        case 3:
            printf("You feel a cold hand brush against your skin.\n");
            break;
        case 4:
            printf("You hear a distant organ playing a mournful melody.\n");
            break;
        case 5:
            printf("A ghostly figure appears before you, its eyes burning with hatred.\n");
            break;
        case 6:
            printf("You hear a voice whispering secrets in your ear.\n");
            break;
        case 7:
            printf("The hairs on your arms stand on end as a sense of dread fills you.\n");
            break;
        case 8:
            printf("You feel a cold wind blowing through the house, carrying with it the scent of fresh blood.\n");
            break;
        case 9:
            printf("You hear a scream and rush to the source, but find nothing.\n");
            break;
    }
}

int main() {
    HauntedHouse* house = createHauntedHouse();
    addRoom(house, 10);
    simulateHauntedHouse(house);
    return 0;
}