//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point position;
    int type;
} Room;

typedef struct {
    Room rooms[MAX_ROOMS];
    int num_rooms;
} House;

// Function to generate a random number between min and max
int random_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to create a new house
House* create_house() {
    House* house = malloc(sizeof(House));
    house->num_rooms = random_range(1, MAX_ROOMS);

    for (int i = 0; i < house->num_rooms; i++) {
        house->rooms[i].position.x = random_range(0, 10);
        house->rooms[i].position.y = random_range(0, 10);
        house->rooms[i].type = random_range(0, 3);
    }

    return house;
}

// Function to print the house
void print_house(House* house) {
    for (int i = 0; i < house->num_rooms; i++) {
        printf("Room %d: (%d, %d), Type: %d\n", i + 1, house->rooms[i].position.x, house->rooms[i].position.y, house->rooms[i].type);
    }
}

// Function to simulate the player exploring the house
void explore_house(House* house) {
    Point player_position = {0, 0};

    while (1) {
        // Get the player's input
        char input;
        printf("Enter a direction to move (n/s/e/w): ");
        scanf(" %c", &input);

        // Update the player's position
        switch (input) {
            case 'n':
                player_position.y++;
                break;
            case 's':
                player_position.y--;
                break;
            case 'e':
                player_position.x++;
                break;
            case 'w':
                player_position.x--;
                break;
            default:
                printf("Invalid input\n");
                continue;
        }

        // Check if the player is in a room
        for (int i = 0; i < house->num_rooms; i++) {
            if (player_position.x == house->rooms[i].position.x && player_position.y == house->rooms[i].position.y) {
                // The player is in a room
                printf("You are in room %d\n", i + 1);

                // Check the type of room
                switch (house->rooms[i].type) {
                    case 0:
                        printf("This room is empty.\n");
                        break;
                    case 1:
                        printf("This room has a bed.\n");
                        break;
                    case 2:
                        printf("This room has a closet.\n");
                        break;
                    case 3:
                        printf("This room has a ghost!\n");
                        break;
                }

                // Give the player the option to leave the room
                printf("Do you want to leave the room? (y/n): ");
                scanf(" %c", &input);

                if (input == 'y') {
                    // The player wants to leave the room
                    break;
                } else {
                    // The player wants to stay in the room
                    continue;
                }
            }
        }

        // Check if the player is outside the house
        if (player_position.x < 0 || player_position.x > 10 || player_position.y < 0 || player_position.y > 10) {
            // The player is outside the house
            printf("You are outside the house.\n");
            break;
        }
    }
}

// Main function
int main() {
    // Set the random seed
    srand(time(NULL));

    // Create a new house
    House* house = create_house();

    // Print the house
    print_house(house);

    // Explore the house
    explore_house(house);

    // Free the house
    free(house);

    return 0;
}