//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the player's stats
struct Player {
    int health;
    int ammo;
    int hunger;
    int thirst;
};

// Define the game world
struct World {
    int num_rooms;
    int current_room;
    struct Room *rooms;
};

// Define a room
struct Room {
    int num_doors;
    int *doors;
    int has_monster;
    int has_food;
    int has_water;
};

// Create a new player
struct Player *create_player() {
    struct Player *player = malloc(sizeof(struct Player));
    player->health = 100;
    player->ammo = 10;
    player->hunger = 0;
    player->thirst = 0;
    return player;
}

// Create a new world
struct World *create_world() {
    struct World *world = malloc(sizeof(struct World));
    world->num_rooms = 10;
    world->current_room = 0;

    // Create the rooms
    world->rooms = malloc(sizeof(struct Room) * world->num_rooms);
    for (int i = 0; i < world->num_rooms; i++) {
        world->rooms[i].num_doors = rand() % 4 + 1;
        world->rooms[i].doors = malloc(sizeof(int) * world->rooms[i].num_doors);
        for (int j = 0; j < world->rooms[i].num_doors; j++) {
            world->rooms[i].doors[j] = rand() % world->num_rooms;
        }
        world->rooms[i].has_monster = rand() % 2;
        world->rooms[i].has_food = rand() % 2;
        world->rooms[i].has_water = rand() % 2;
    }

    return world;
}

// Print the current room
void print_room(struct World *world) {
    struct Room *room = &world->rooms[world->current_room];

    printf("You are in a room with %d doors.\n", room->num_doors);
    for (int i = 0; i < room->num_doors; i++) {
        printf("Door %d leads to room %d.\n", i + 1, room->doors[i]);
    }
    if (room->has_monster) {
        printf("There is a monster in the room!\n");
    }
    if (room->has_food) {
        printf("There is food in the room.\n");
    }
    if (room->has_water) {
        printf("There is water in the room.\n");
    }
}

// Handle the player's input
void handle_input(struct World *world, struct Player *player) {
    char input[80];

    printf("> ");
    fgets(input, 80, stdin);

    if (strcmp(input, "n\n") == 0) {
        // Go north
        world->current_room = world->rooms[world->current_room].doors[0];
    } else if (strcmp(input, "e\n") == 0) {
        // Go east
        world->current_room = world->rooms[world->current_room].doors[1];
    } else if (strcmp(input, "s\n") == 0) {
        // Go south
        world->current_room = world->rooms[world->current_room].doors[2];
    } else if (strcmp(input, "w\n") == 0) {
        // Go west
        world->current_room = world->rooms[world->current_room].doors[3];
    } else if (strcmp(input, "look\n") == 0) {
        // Look around the current room
        print_room(world);
    } else if (strcmp(input, "shoot\n") == 0) {
        // Shoot the monster
        if (world->rooms[world->current_room].has_monster) {
            world->rooms[world->current_room].has_monster = 0;
            player->ammo--;
            printf("You killed the monster!\n");
        } else {
            printf("There is no monster to shoot.\n");
        }
    } else if (strcmp(input, "eat\n") == 0) {
        // Eat the food
        if (world->rooms[world->current_room].has_food) {
            world->rooms[world->current_room].has_food = 0;
            player->hunger--;
            printf("You ate the food.\n");
        } else {
            printf("There is no food to eat.\n");
        }
    } else if (strcmp(input, "drink\n") == 0) {
        // Drink the water
        if (world->rooms[world->current_room].has_water) {
            world->rooms[world->current_room].has_water = 0;
            player->thirst--;
            printf("You drank the water.\n");
        } else {
            printf("There is no water to drink.\n");
        }
    } else {
        printf("Invalid input.\n");
    }
}

// Update the player's stats
void update_player(struct Player *player) {
    // Decrement the player's hunger and thirst
    player->hunger++;
    player->thirst++;

    // If the player's hunger or thirst reaches 100, they die
    if (player->hunger >= 100 || player->thirst >= 100) {
        printf("You died of starvation or thirst.\n");
        exit(0);
    }
}

// Main game loop
int main() {
    // Create the player and the world
    struct Player *player = create_player();
    struct World *world = create_world();

    // Print the starting room
    print_room(world);

    // Game loop
    while (1) {
        // Handle the player's input
        handle_input(world, player);

        // Update the player's stats
        update_player(player);
    }

    return 0;
}