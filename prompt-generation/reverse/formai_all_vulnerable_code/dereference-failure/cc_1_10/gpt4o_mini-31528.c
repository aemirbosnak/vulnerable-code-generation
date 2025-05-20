//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_OPTION 3
#define MAX_ITEM 5

typedef struct {
    char *item_name;
    int can_use;
} Item;

typedef struct {
    char *room_name;
    char *description;
    Item items[MAX_ITEM];
    int item_count;
} Room;

Room create_room(char *name, char *desc) {
    Room r;
    r.room_name = name;
    r.description = desc;
    r.item_count = 0;
    return r;
}

void add_item(Room *room, char *item_name) {
    if (room->item_count < MAX_ITEM) {
        room->items[room->item_count].item_name = item_name;
        room->items[room->item_count].can_use = 0; // Not usable initially
        room->item_count++;
    }
}

void print_room(Room *room) {
    printf("\nYou are in the %s\n", room->room_name);
    printf("%s\n", room->description);
    if (room->item_count > 0) {
        printf("Items available:\n");
        for (int i = 0; i < room->item_count; i++) {
            printf(" - %s\n", room->items[i].item_name);
        }
    }
}

int main() {
    srand(time(NULL));
    Room rooms[3];
    
    rooms[0] = create_room("Creepy Hall", "The hall is dark and damp, filled with shadows. A sense of dread fills the air.");
    add_item(&rooms[0], "Old Key");
    add_item(&rooms[0], "Strange Map");
    
    rooms[1] = create_room("Eerie Library", "Books are scattered everywhere, and the air is thick with dust. Whispers seem to come from the shelves.");
    add_item(&rooms[1], "Ancient Book");
    
    rooms[2] = create_room("Haunted Laboratory", "Equipment is broken, and strange noises echo. The air smells of chemicals and something unidentifiable.");
    add_item(&rooms[2], "Potion Bottle");
    
    int current_room_index = 0;
    char command[50];
    
    printf("Welcome to the Haunted House Simulator!\n");
    
    while (1) {
        print_room(&rooms[current_room_index]);
        printf("\nWhat would you like to do? (explore, take, use, exit): ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove trailing newline
        
        if (strcmp(command, "explore") == 0) {
            current_room_index = (current_room_index + 1) % 3; // Loop through rooms
        } else if (strcmp(command, "take") == 0) {
            if (rooms[current_room_index].item_count > 0) {
                printf("Which item do you want to take? ");
                fgets(command, sizeof(command), stdin);
                command[strcspn(command, "\n")] = 0; // Remove trailing newline
                
                int found = 0;
                for (int i = 0; i < rooms[current_room_index].item_count; i++) {
                    if (strcmp(command, rooms[current_room_index].items[i].item_name) == 0) {
                        printf("You picked up the %s!\n", rooms[current_room_index].items[i].item_name);
                        rooms[current_room_index].items[i].can_use = 1; // Mark as usable
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Item not found!\n");
                }
            } else {
                printf("There are no items to take.\n");
            }
        } else if (strcmp(command, "use") == 0) {
            if (rooms[current_room_index].item_count > 0) {
                printf("Which item do you want to use? ");
                fgets(command, sizeof(command), stdin);
                command[strcspn(command, "\n")] = 0; // Remove trailing newline
                
                int used = 0;
                for (int i = 0; i < rooms[current_room_index].item_count; i++) {
                    if (strcmp(command, rooms[current_room_index].items[i].item_name) == 0 && rooms[current_room_index].items[i].can_use) {
                        printf("You use the %s...\n", rooms[current_room_index].items[i].item_name);
                        if (strcmp(command, "Old Key") == 0) {
                            printf("A hidden door opens, and you escape!\n");
                            exit(0);
                        }
                        // Additional item effects can be added here
                        used = 1;
                        break;
                    }
                }
                if (!used) {
                    printf("Item not usable or does not exist!\n");
                }
            } else {
                printf("You have no items to use.\n");
            }
        } else if (strcmp(command, "exit") == 0) {
            printf("Thanks for playing! Goodbye!\n");
            break;
        } else {
            printf("Invalid command. Try again!\n");
        }
    }

    return 0;
}