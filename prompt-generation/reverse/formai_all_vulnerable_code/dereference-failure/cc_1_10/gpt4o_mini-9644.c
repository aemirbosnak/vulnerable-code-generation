//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define ROOMS 6
#define MAX_GHOSTS 3

typedef struct {
    int id;
    char *name;
    char *description;
} Ghost;

typedef struct {
    char *name;
    char *description;
    Ghost *ghosts[MAX_GHOSTS];
    int ghostCount;
} Room;

Room hauntedRooms[ROOMS];

void initializeRooms() {
    hauntedRooms[0] = (Room){"Abandoned Library", "Dusty shelves, flickering lights."};
    hauntedRooms[1] = (Room){"Creepy Basement", "Chilling sounds echo in the darkness."};
    hauntedRooms[2] = (Room){"Eerie Attic", "Scattered old toys and oddities."};
    hauntedRooms[3] = (Room){"Dark Corridor", "Shadows dance along the walls."};
    hauntedRooms[4] = (Room){"Spooky Kitchen", "Faint whispers around the stove."};
    hauntedRooms[5] = (Room){"Ghostly Garden", "Wildflowers sway with no wind."};

    // Initialize ghosts
    hauntedRooms[0].ghosts[0] = &(Ghost){1, "Librarian Ghost", "She guards the secrets of unwritten books!"};
    hauntedRooms[1].ghosts[0] = &(Ghost){2, "Basement Spirit", "A shiver runs down your spine as you feel its presence."};
    hauntedRooms[2].ghosts[0] = &(Ghost){3, "Attic Child", "Lost and lonely, looking for a friend."};
    
    for (int i = 0; i < ROOMS; i++) {
        hauntedRooms[i].ghostCount = 0; // Initialize ghost count
        switch (i) {
            case 0: hauntedRooms[i].ghostCount = 1; break; // Room 1
            case 1: hauntedRooms[i].ghostCount = 1; break; // Room 2
            case 2: hauntedRooms[i].ghostCount = 1; break; // Room 3
            case 3: hauntedRooms[i].ghostCount = 0; break; // Room 4
            case 4: hauntedRooms[i].ghostCount = 0; break; // Room 5
            case 5: hauntedRooms[i].ghostCount = 0; break; // Room 6
        }
    }
}

void enterRoom(int roomIndex) {
    printf("\nYou have entered the %s.\n", hauntedRooms[roomIndex].name);
    printf("%s\n", hauntedRooms[roomIndex].description);
    
    if (hauntedRooms[roomIndex].ghostCount > 0) {
        for (int j = 0; j < hauntedRooms[roomIndex].ghostCount; j++) {
            printf("You sense a presence: %s - %s\n", hauntedRooms[roomIndex].ghosts[j]->name, hauntedRooms[roomIndex].ghosts[j]->description);
        }
    } else {
        printf("It's eerily quiet here... too quiet.\n");
    }
    sleep(2);
}

void soundTheBell() {
    printf("\nA large bell tolls in the distance...\n");
    sleep(1);
}

int main() {
    srand(time(NULL));
    initializeRooms();
    
    int choice;
    while (1) {
        printf("\nWelcome to the Haunted House Simulator!\n");
        printf("Choose a room to explore (1-6) or 0 to exit:\n");
        for (int i = 0; i < ROOMS; i++) {
            printf("%d. %s\n", i + 1, hauntedRooms[i].name);
        }
        printf("0. Exit\n");

        scanf("%d", &choice);
        if (choice == 0) {
            printf("Goodbye!\n");
            break;
        } else if (choice < 1 || choice > 6) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        soundTheBell();
        enterRoom(choice - 1);
    }
    return 0;
}