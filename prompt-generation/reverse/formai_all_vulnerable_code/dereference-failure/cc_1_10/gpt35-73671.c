//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROOMS 10 // Maximum number of rooms in the haunted house
#define MAX_MONSTERS 3 // Maximum number of monsters in a room
#define MAX_ITEM_LEN 20 // Maximum length of an item name

// Function to print the welcome message and game instructions
void printInstructions(){

    printf("Welcome to the Haunted House Simulator Game!\n\n");
    printf("You have entered a haunted house and your objective is to find the treasure and escape alive.\n");
    printf("The house has multiple rooms, some of which are empty and some of which have monsters lurking in them.\n");
    printf("To move to another room, type 'north' to go to the next room or 'south' to go back to the previous room.\n");
    printf("To search a room for treasure, type 'search'.\n");
    printf("To pick up an item, type 'take' followed by the item name.\n");
    printf("To view your inventory, type 'inventory'.\n");
    printf("To use an item, type 'use' followed by the item name.\n");
    printf("Beware of the monsters, they may attack you!\n\n");
}

// Function to get a random integer between min and max (inclusive)
int getRandom(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

// Function to generate a random item name
void generateItemName(char *itemName){
    char *items[] = {"key", "lantern", "map", "potion", "rope", "silver", "sword", "torch"};
    strcpy(itemName, items[getRandom(0, 7)]);
}

// Function to generate a random monster name
void generateMonsterName(char *monsterName){
    char *monsters[] = {"ghost", "skeleton", "vampire", "werewolf", "zombie"};
    strcpy(monsterName, monsters[getRandom(0, 4)]);
}

// Structure to represent an item
typedef struct Item{
    char name[MAX_ITEM_LEN + 1]; // Name of the item
    int uses; // Number of uses left (if applicable)
    struct Item *next; // Pointer to next item in linked list
} Item;

// Function to create a new item and add it to the player's inventory
Item *createItem(Item *inventory, char *itemName){
    Item *newItem = malloc(sizeof(Item));
    strcpy(newItem->name, itemName);
    newItem->uses = 1;
    newItem->next = NULL;

    if(inventory == NULL){
        inventory = newItem;
    }
    else{
        Item *curr = inventory;

        while(curr->next != NULL){
            curr = curr->next;
        }

        curr->next = newItem;
    }

    printf("You picked up a %s.\n", newItem->name);
    return inventory;
}

// Function to print the player's inventory
void printInventory(Item *inventory){
    if(inventory == NULL){
        printf("You have no items in your inventory.\n");
    }
    else{
        printf("Inventory:\n");

        Item *curr = inventory;
        while(curr != NULL){
            printf("- %s", curr->name);

            if(strcmp(curr->name, "map") == 0){
                printf(" (shows all rooms)");
            }
            else if(strcmp(curr->name, "lantern") == 0){
                printf(" (illuminates dark rooms)");
            }

            if(curr->uses > 1){
                printf(" (%d uses left)", curr->uses);
            }

            printf("\n");
            curr = curr->next;
        }
    }
}

// Function to use an item from the player's inventory
Item *useItem(Item *inventory, char *itemName){
    Item *curr = inventory;
    Item *prev = NULL;

    while(curr != NULL && strcmp(curr->name, itemName) != 0){
        prev = curr;
        curr = curr->next;
    }

    if(curr == NULL){
        printf("Item '%s' not found in inventory.\n", itemName);
    }
    else{
        if(strcmp(itemName, "map") == 0){
            printf("You use the map. You can now see all rooms in the house.\n");
        }
        else if(strcmp(itemName, "lantern") == 0){
            printf("You use the lantern. The room is now illuminated.\n");
        }
        else{
            printf("You use the %s.\n", itemName);
        }

        curr->uses--;
        if(curr->uses == 0){
            if(prev == NULL){
                inventory = curr->next;
            }
            else{
                prev->next = curr->next;
            }
            free(curr);
        }
    }

    return inventory;
}

// Structure to represent a monster
typedef struct Monster{
    char name[11]; // Name of the monster
    int health; // Health of the monster (0-100)
} Monster;

// Structure to represent a room in the haunted house
typedef struct Room{
    int id; // ID of the room
    char name[21]; // Name of the room
    int isDark; // Indicates if the room is dark (0 = not dark, 1 = dark)
    char description[101]; // Description of the room
    Item *items; // Inventory of the room
    Monster monsters[MAX_MONSTERS]; // Monsters in the room
    struct Room *next; // Pointer to next room in linked list
} Room;

// Function to create a new room and add it to the house
Room *createRoom(Room *house, int currId){
    Room *newRoom = malloc(sizeof(Room));
    newRoom->id = currId;
    generateItemName(newRoom->name);
    newRoom->isDark = getRandom(0, 1);
    strcpy(newRoom->description, "You enter a");
    if(newRoom->isDark){
        strcat(newRoom->description, " dark");
    }
    strcat(newRoom->description, " room. It contains:");

    newRoom->items = NULL;
    if(getRandom(0, 1)){
        char itemName[MAX_ITEM_LEN + 1];
        generateItemName(itemName);
        newRoom->items = createItem(newRoom->items, itemName);
    }

    int numMonsters = getRandom(0, MAX_MONSTERS);
    for(int i = 0; i < numMonsters; i++){
        char monsterName[11];
        generateMonsterName(monsterName);
        newRoom->monsters[i].health = getRandom(50, 100);
        strcpy(newRoom->monsters[i].name, monsterName);
    }

    newRoom->next = NULL;

    if(house == NULL){
        house = newRoom;
    }
    else{
        Room *curr = house;

        while(curr->next != NULL){
            curr = curr->next;
        }

        curr->next = newRoom;
    }

    return house;
}

// Function to print the name and description of a room
void printRoom(Room *room){
    printf("%s [%d]\n", room->name, room->id);
    printf("%s\n", room->description);

    if(room->items != NULL){
        printf("Items:");
        Item *curr = room->items;
        while(curr != NULL){
            printf(" %s", curr->name);

            if(strcmp(curr->name, "map") == 0){
                printf(" (shows all rooms)");
            }
            else if(strcmp(curr->name, "lantern") == 0){
                printf(" (illuminates dark rooms)");
            }

            printf(",");
            curr = curr->next;
        }
        printf("\n");
    }

    int numMonsters = 0;
    for(int i = 0; i < MAX_MONSTERS; i++){
        if(room->monsters[i].health > 0){
            numMonsters++;
        }
    }

    if(numMonsters > 0){
        printf("Monsters: ");
        for(int i = 0; i < MAX_MONSTERS; i++){
            if(room->monsters[i].health > 0){
                printf("%s (%d health)", room->monsters[i].name, room->monsters[i].health);
                numMonsters--;
                if(numMonsters > 0){
                    printf(", ");
                }
            }
        }
        printf("\n");
    }

    printf("\n");
}

int main(){
    srand(time(NULL)); // Seed the random number generator

    Room *house = NULL;
    int currId = 1;
    int maxRooms = getRandom(5, MAX_ROOMS);

    // Generate the house
    for(int i = 0; i < maxRooms; i++){
        house = createRoom(house, currId++);
    }

    printInstructions(); // Print the instructions

    // Start the game
    Room *currRoom = house;
    Item *inventory = NULL;

    while(1){

        printRoom(currRoom); // Print the current room

        // Check if the player has found the treasure
        if(currRoom->id == maxRooms && strcmp(currRoom->name, "treasure") == 0){
            printf("Congratulations! You found the treasure and escaped the haunted house alive!\n");
            break;
        }

        // Check if the player is dead
        if(getRandom(0, 10) < 3){ // 30% chance of getting attacked by a monster
            int numMonsters = 0;
            for(int i = 0; i < MAX_MONSTERS; i++){
                if(currRoom->monsters[i].health > 0){
                    numMonsters++;
                }
            }

            if(numMonsters > 0){
                int monsterIndex = getRandom(0, numMonsters - 1);
                Monster *monster = &currRoom->monsters[monsterIndex];
                int damage = getRandom(10, 30);
                monster->health -= damage;

                printf("You are attacked by a %s and take %d damage!\n", monster->name, damage);

                if(monster->health <= 0){
                    printf("You defeated the %s!\n", monster->name);
                    inventory = createItem(inventory, "silver");
                }
                else{
                    printf("The %s has %d health left.\n", monster->name, monster->health);

                    if(getRandom(0, 10) < 5){ // 50% chance of being killed by the monster
                        printf("The %s has killed you. Game over.\n", monster->name);
                        break;
                    }
                }
            }
        }

        // Get user input
        char input[100];
        printf("> ");
        fgets(input, 100, stdin);
        sscanf(input, "%s", input);

        // Process user input
        if(strcmp(input, "north") == 0){
            if(currRoom->next != NULL){
                currRoom = currRoom->next;
            }
            else{
                printf("There is no room to the north.\n");
            }
        }
        else if(strcmp(input, "south") == 0){
            Room *prevRoom = house;
            while(prevRoom->next != currRoom){
                prevRoom = prevRoom->next;
            }

            if(prevRoom != NULL){
                currRoom = prevRoom;
            }
            else{
                printf("There is no room to the south.\n");
            }
        }
        else if(strcmp(input, "search") == 0){
            if(getRandom(0, 10) < 5){ // 50% chance of finding an item
                char itemName[MAX_ITEM_LEN + 1];
                generateItemName(itemName);
                currRoom->items = createItem(currRoom->items, itemName);
            }
            else{
                printf("You search the room but find nothing.\n");
            }
        }
        else if(strcmp(input, "take") == 0){
            char itemName[MAX_ITEM_LEN + 1];
            sscanf(input, "%*s %s", itemName);
            inventory = createItem(inventory, itemName);
            Item *curr = currRoom->items;
            Item *prev = NULL;
            while(curr != NULL && strcmp(curr->name, itemName) != 0){
                prev = curr;
                curr = curr->next;
            }
            if(curr != NULL){
                if(prev == NULL){
                    currRoom->items = curr->next;
                }
                else{
                    prev->next = curr->next;
                }
                free(curr);
            }
        }
        else if(strcmp(input, "inventory") == 0){
            printInventory(inventory);
        }
        else if(strcmp(input, "use") == 0){
            char itemName[MAX_ITEM_LEN + 1];
            sscanf(input, "%*s %s", itemName);
            inventory = useItem(inventory, itemName);
        }
        else{
            printf("Invalid command.\n");
        }
    }

    return 0;
}