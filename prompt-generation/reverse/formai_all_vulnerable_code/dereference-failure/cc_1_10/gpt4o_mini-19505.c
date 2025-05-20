//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a player
typedef struct Player {
    int id;
    char name[50];
    int score;
    struct Player *next;
} Player;

// Head of the linked list
Player *head = NULL;

// Function declarations
void addPlayer(int id, const char *name, int score);
void listPlayers();
Player* searchPlayerById(int id);
Player* searchPlayerByName(const char *name);
void freeMemory();

// Main Function
int main() {
    int choice, id, score;
    char name[50];
    
    while (1) {
        printf("\n--- Multiplayer Game Database ---\n");
        printf("1. Add Player\n");
        printf("2. List Players\n");
        printf("3. Search Player by ID\n");
        printf("4. Search Player by Name\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter Player ID: ");
                scanf("%d", &id);
                printf("Enter Player Name: ");
                scanf("%s", name);
                printf("Enter Player Score: ");
                scanf("%d", &score);
                addPlayer(id, name, score);
                break;
            case 2:
                listPlayers();
                break;
            case 3:
                printf("Enter Player ID to search: ");
                scanf("%d", &id);
                Player *playerById = searchPlayerById(id);
                if (playerById) {
                    printf("Player Found: ID = %d, Name = %s, Score = %d\n", playerById->id, playerById->name, playerById->score);
                } else {
                    printf("Player not found!\n");
                }
                break;
            case 4:
                printf("Enter Player Name to search: ");
                scanf("%s", name);
                Player *playerByName = searchPlayerByName(name);
                if (playerByName) {
                    printf("Player Found: ID = %d, Name = %s, Score = %d\n", playerByName->id, playerByName->name, playerByName->score);
                } else {
                    printf("Player not found!\n");
                }
                break;
            case 5:
                freeMemory();
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}

// Function to add a player to the list
void addPlayer(int id, const char *name, int score) {
    Player *newPlayer = (Player *) malloc(sizeof(Player));
    newPlayer->id = id;
    strcpy(newPlayer->name, name);
    newPlayer->score = score;
    newPlayer->next = head;
    head = newPlayer;
    printf("Player added successfully!\n");
}

// Function to list all players
void listPlayers() {
    if (head == NULL) {
        printf("No players in the database.\n");
        return;
    }
    
    Player *temp = head;
    printf("\nList of Players:\n");
    while (temp) {
        printf("ID: %d, Name: %s, Score: %d\n", temp->id, temp->name, temp->score);
        temp = temp->next;
    }
}

// Function to search player by ID
Player* searchPlayerById(int id) {
    Player *temp = head;
    while (temp) {
        if (temp->id == id) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to search player by Name
Player* searchPlayerByName(const char *name) {
    Player *temp = head;
    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to free allocated memory
void freeMemory() {
    Player *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("Memory freed successfully!\n");
}