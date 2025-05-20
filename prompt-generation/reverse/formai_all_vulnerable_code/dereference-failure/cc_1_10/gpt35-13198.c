//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LEN 50
#define MAX_DESC_LEN 100
#define MAX_ITEMS 10

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESC_LEN];
    bool has_item;
} Room;

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESC_LEN];
} Item;

typedef struct _node {
    Item item;
    struct _node *next;
} Node;

typedef struct {
    Node *head;
    int num_items;
} Inventory;

void add_item(Inventory *inv, Item item) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->item = item;
    node->next = NULL;

    if (inv->head == NULL) {
        inv->head = node;
    } else {
        Node *current = inv->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }

    inv->num_items++;
}

void print_inventory(Inventory inv) {
    Node *current = inv.head;
    int i = 1;
    while (current != NULL) {
        printf("%d. %s\n", i, current->item.name);
        current = current->next;
        i++;
    }
}

Item get_item(Inventory *inv, char *name) {
    Node *current = inv->head;
    while (current != NULL) {
        if (strcmp(current->item.name, name) == 0) {
            Item item = current->item;
            // Remove item from list
            Node *prev = NULL;
            Node *temp = inv->head;
            while (temp != current) {
                prev = temp;
                temp = temp->next;
            }
            
            if (prev == NULL) {
                inv->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);

            inv->num_items--;
            return item;
        }
        current = current->next;
    }
    // Item not found
    Item item;
    memset(item.name, 0, MAX_NAME_LEN);
    memset(item.description, 0, MAX_DESC_LEN);
    return item;
}

int main() {
    // Define rooms
    Room rooms[] = {
        {"Bridge", "The control room of your starship", false},
        {"Engineering", "The heart of your starship's propulsion system", false},
        {"Medbay", "Where the injured are treated", false},
        {"Cargo Bay", "Where your starship's supplies are stored", false},
        {"Crew Quarters", "Where the crew sleeps", false},
        {"Mess Hall", "Where the crew eats", false},
        {"Armory", "Where weapons are stored", false},
        {"Security Station", "Monitors and controls access to key areas of the starship", false},
        {"Observatory", "Allows viewing of the cosmos", false},
        {"Lounge", "Where the crew relaxes", false}
    };

    // Define items
    Item items[] = {
        {"Laser Pistol", "A powerful weapon that emits a laser beam", false},
        {"Engine Part", "A crucial part for repairing the propulsion system", false},
        {"Medical Kit", "A kit containing medical supplies", false},
        {"Food Rations", "A pack of food for survival situations", false},
        {"Space Suit", "A suit that allows the wearer to survive in space", false},
        {"Antimatter Core", "A powerful and rare energy source", false},
        {"Cybernetic Implant", "A high-tech implant that enhances human abilities", false},
        {"Hacking Tool", "A device used to hack computer systems", false},
        {"Stun Grenade", "A grenade that stuns its target", false},
        {"Virtual Reality Headset", "A headset that immerses the wearer in a virtual world", false}
    };

    // Create inventory
    Inventory inventory;
    inventory.head = NULL;
    inventory.num_items = 0;

    // Add items to inventory
    add_item(&inventory, items[0]);
    add_item(&inventory, items[2]);

    // Current room and player input
    int current_room = 0;
    char input[MAX_NAME_LEN];
    bool quit = false;

    // Game loop
    while (!quit) {
        printf("\nYou are in the %s.\n%s\n", rooms[current_room].name, rooms[current_room].description);

        // Check if room has an item
        if (rooms[current_room].has_item) {
            printf("You see an item here.\n");
        }

        printf("> ");
        fgets(input, MAX_NAME_LEN, stdin);

        if (strcmp(input, "quit\n") == 0) {
            quit = true;
        } else if (strcmp(input, "look\n") == 0) {
            printf("%s\n", rooms[current_room].description);
        } else if (strcmp(input, "inventory\n") == 0) {
            printf("Inventory:\n");
            print_inventory(inventory);
        } else if (strncmp(input, "take ", 5) == 0) {
            Item item = get_item(&inventory, &input[5]);
            if (strlen(item.name) > 0) {
                printf("You take the %s.\n", item.name);
            } else {
                printf("Item not found.\n");
            }
        } else if (strncmp(input, "use ", 4) == 0) {
            char *item_name = &input[4];
            // Find item in inventory
            Node *current = inventory.head;
            bool found_item = false;
            while (current != NULL) {
                if (strcmp(current->item.name, item_name) == 0) {
                    found_item = true;
                    break;
                }
                current = current->next;
            }

            if (found_item) {
                if (strcmp(item_name, "Antimatter Core") == 0 && current_room == 1) {
                    printf("You insert the Antimatter Core into the propulsion system. The starship's engines roar to life!\n");
                    printf("Congratulations! You have saved humanity.\n");
                    quit = true;
                } else if (strcmp(item_name, "Engine Part") == 0 && current_room == 1) {
                    printf("You use the Engine Part to repair the propulsion system.\n");
                    printf("Now it's time to insert the Antimatter Core...\n");
                    Node *engine_part = current;
                    // Remove engine part from inventory
                    Node *prev = NULL;
                    Node *temp = inventory.head;
                    while (temp != engine_part) {
                        prev = temp;
                        temp = temp->next;
                    }
                    
                    if (prev == NULL) {
                        inventory.head = engine_part->next;
                    } else {
                        prev->next = engine_part->next;
                    }
                    free(engine_part);
                    inventory.num_items--;

                    // Set room to have Antimatter Core
                    rooms[1].has_item = true;
                } else if (strcmp(item_name, "Cybernetic Implant") == 0 && current_room == 7) {
                    printf("You use the Cybernetic Implant to hack the security system.\n");
                    printf("You can now access the Armory...\n");
                    // Set room to have Laser Pistol
                    rooms[6].has_item = true;
                } else if (strcmp(item_name, "Hacking Tool") == 0 && current_room == 7) {
                    printf("You use the Hacking Tool to hack the security system.\n");
                    printf("You can now access the Observatory...\n");
                    // Set room to have Virtual Reality Headset
                    rooms[8].has_item = true;

                } else {
                    printf("You can't use that here.\n");
                }
            } else {
                printf("You don't have that item.\n");
            }
        } else {
            printf("Command not recognized.\n");
        }
    }

    // Free memory
    Node *current = inventory.head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}