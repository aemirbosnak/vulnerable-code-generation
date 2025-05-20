//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INVENTORY 5
#define MAX_LOCATION_DESC 256

typedef struct {
    char *name;
    char *description;
} Item;

typedef struct {
    char *name;
    char description[MAX_LOCATION_DESC];
    Item *items[MAX_INVENTORY];
    int item_count;
} Location;

typedef struct {
    Item *inventory[MAX_INVENTORY];
    int inventory_count;
} Player;

void initialize_items(Item *items) {
    items[0].name = "Flashlight";
    items[0].description = "A dim flashlight, but it's better than nothing.";
    
    items[1].name = "Key";
    items[1].description = "A rusty key that seems to lead somewhere.";
    
    items[2].name = "Map";
    items[2].description = "A torn map of the house with several scribbles.";
    
    items[3].name = "Note";
    items[3].description = "A crumpled note that warns you to leave immediately.";
    
    items[4].name = "Knife";
    items[4].description = "A small kitchen knife, possibly for defense.";
}

void initialize_locations(Location *locations, Item *items) {
    // Location 1: Living Room
    strcpy(locations[0].name, "Living Room");
    strcpy(locations[0].description, "A dark living room filled with dusty old furniture. Something feels off.");
    locations[0].items[0] = &items[0]; // Flashlight
    locations[0].items[1] = NULL; // No more items
    locations[0].item_count = 1;

    // Location 2: Kitchen
    strcpy(locations[1].name, "Kitchen");
    strcpy(locations[1].description, "The kitchen smells of decay. All the cabinets are closed tightly.");
    locations[1].items[0] = &items[1]; // Key
    locations[1].items[1] = &items[4]; // Knife
    locations[1].item_count = 2;

    // Location 3: Bedroom
    strcpy(locations[2].name, "Bedroom");
    strcpy(locations[2].description, "A dimly lit bedroom where shadows seem to linger.");
    locations[2].items[0] = &items[2]; // Map
    locations[2].items[1] = &items[3]; // Note
    locations[2].item_count = 2;
}

void print_inventory(Player *player) {
    printf("Inventory: \n");
    for (int i = 0; i < player->inventory_count; i++) {
        printf("- %s: %s\n", player->inventory[i]->name, player->inventory[i]->description);
    }
}

void take_item(Player *player, Location *location, int item_index) {
    if (player->inventory_count < MAX_INVENTORY) {
        player->inventory[player->inventory_count] = location->items[item_index];
        player->inventory_count++;
        location->item_count--;
        printf("You took the %s.\n", location->items[item_index]->name);
        location->items[item_index] = NULL; // Remove from location
    } else {
        printf("Your inventory is full!\n");
    }
}

void explore(Player *player, Location *locations, int *current_location) {
    int choice;
    printf("\nYou are in the %s\n", locations[*current_location].name);
    printf("%s\n", locations[*current_location].description);
    
    if (locations[*current_location].item_count > 0) {
        printf("Items in this room:\n");
        for (int i = 0; i < locations[*current_location].item_count; i++) {
            if (locations[*current_location].items[i] != NULL) {
                printf("%d. %s\n", i + 1, locations[*current_location].items[i]->name);
            }
        }
    }
    
    printf("What would you like to do?\n");
    printf("1. Take an item\n");
    printf("2. Move to another room\n");
    printf("3. Check inventory\n");
    printf("4. Investigate paranoia\n");
    printf("0. Exit game\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1: {
            int item_choice;
            printf("Which item would you like to take? (1-%d): ", locations[*current_location].item_count);
            scanf("%d", &item_choice);
            if (item_choice < 1 || item_choice > locations[*current_location].item_count) {
                printf("Invalid choice.\n");
            } else {
                take_item(player, &locations[*current_location], item_choice - 1);
            }
            break;
        }
        case 2: {
            // Simplified game with only three locations.
            int new_location;
            printf("Where would you like to go? (1. Living Room, 2. Kitchen, 3. Bedroom): ");
            scanf("%d", &new_location);
            if (new_location < 1 || new_location > 3) {
                printf("Invalid location.\n");
            } else {
                *current_location = new_location - 1;
            }
            break;
        }
        case 3:
            print_inventory(player);
            break;
        case 4:
            printf("You feel someone is watching you... paranoia grips your mind!\n");
            break;
        case 0:
            printf("Exiting game...\n");
            exit(0);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
}

int main() {
    Item items[5];
    Location locations[3] = {{"", ""}, {"", ""}, {"", ""}};
    Player player = { .inventory_count = 0 };
    int current_location = 0;

    initialize_items(items);
    initialize_locations(locations, items);
    
    printf("Welcome to the Paranoid Adventure!\n");
    
    while (1) {
        explore(&player, locations, &current_location);
    }

    return 0;
}