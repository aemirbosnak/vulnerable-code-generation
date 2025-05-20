//FormAI DATASET v1.0 Category: Password management ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PLAYERS 5  // Maximal number of players
#define MAX_PASSWORDS 10  // Maximal number of passwords for each player
#define MAX_PASSWORD_LENGTH 20  // Maximal length of password

// Player struct
typedef struct {
    char name[50];
    char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH];
    int num_passwords;
} Player;

// Function prototypes
int menu();
void add_password(Player *player);
void remove_password(Player *player);
void view_passwords(Player *player);
Player *add_player(Player *players, int *num_players);
Player *remove_player(Player *players, int *num_players);
void view_players(Player *players, int num_players);
void clear_input();
void clear_screen();

int main() {
    Player players[MAX_PLAYERS];
    int num_players = 0;
    int choice;

    do {
        choice = menu();

        switch (choice) {
            case 1:  // Add player
                add_player(players, &num_players);
                break;
            case 2:  // Remove player
                remove_player(players, &num_players);
                break;
            case 3:  // View all players
                view_players(players, num_players);
                break;
            case 4:  // Add password
                add_password(players);
                break;
            case 5:  // Remove password
                remove_password(players);
                break;
            case 6:  // View passwords
                view_passwords(players);
                break;
            case 7:  // Exit
                printf("Thank you for using Password Manager!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }

        clear_input();
        printf("Press ENTER to continue...");
        getchar();
        clear_screen();

    } while (choice != 7);

    return 0;
}

// Display menu and prompt user for choice
int menu() {
    int choice;

    printf("Password Manager\n");
    printf("================\n");
    printf("1. Add player\n");
    printf("2. Remove player\n");
    printf("3. View all players\n");
    printf("4. Add password\n");
    printf("5. Remove password\n");
    printf("6. View passwords\n");
    printf("7. Exit\n");

    printf("Please enter your choice: ");
    scanf("%d", &choice);

    return choice;
}

// Add password for a player
void add_password(Player *players) {
    char name[50];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter player name: ");
    scanf("%s", name);

    int player_found = 0;
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (strcmp(players[i].name, name) == 0) {
            printf("Enter password: ");
            scanf("%s", password);

            // Check if password already exists
            for (int j = 0; j < players[i].num_passwords; j++) {
                if (strcmp(players[i].passwords[j], password) == 0) {
                    printf("Password already exists for this player.\n");
                    return;
                }
            }

            // Check if player has reached maximal number of passwords
            if (players[i].num_passwords == MAX_PASSWORDS) {
                printf("Maximum number of passwords reached for this player.\n");
                return;
            }

            // Add password to player
            strcpy(players[i].passwords[players[i].num_passwords], password);
            players[i].num_passwords++;

            printf("Password successfully added for player %s.\n", name);
            player_found = 1;
            break;
        }
    }

    if (!player_found) {
        printf("Player not found.\n");
    }
}

// Remove password for a player
void remove_password(Player *players) {
    char name[50];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter player name: ");
    scanf("%s", name);

    int player_found = 0;
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (strcmp(players[i].name, name) == 0) {
            printf("Enter password to remove: ");
            scanf("%s", password);

            for (int j = 0; j < players[i].num_passwords; j++) {
                if (strcmp(players[i].passwords[j], password) == 0) {
                    // Remove password from player
                    for (int k = j+1; k < players[i].num_passwords; k++) {
                        strcpy(players[i].passwords[k-1], players[i].passwords[k]);
                    }
                    players[i].num_passwords--;

                    printf("Password successfully removed for player %s.\n", name);
                    player_found = 1;
                    break;
                }
            }

            if (!player_found) {
                printf("Password not found for this player.\n");
            }

            break;
        }
    }

    if (!player_found) {
        printf("Player not found.\n");
    }
}

// View all passwords for a player
void view_passwords(Player *players) {
    char name[50];

    printf("Enter player name: ");
    scanf("%s", name);

    int player_found = 0;
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (strcmp(players[i].name, name) == 0) {
            printf("Passwords for player %s:\n", name);

            for (int j = 0; j < players[i].num_passwords; j++) {
                printf("- %s\n", players[i].passwords[j]);
            }

            player_found = 1;
            break;
        }
    }

    if (!player_found) {
        printf("Player not found.\n");
    }
}

// Add a new player
Player *add_player(Player *players, int *num_players) {
    if (*num_players == MAX_PLAYERS) {
        printf("Maximum number of players reached.\n");
        return players;
    }

    printf("Enter player name: ");
    scanf("%s", players[*num_players].name);

    printf("Player %s added.\n", players[*num_players].name);

    (*num_players)++;

    return players;
}

// Remove an existing player
Player *remove_player(Player *players, int *num_players) {
    char name[50];

    printf("Enter player name: ");
    scanf("%s", name);

    int player_found = 0;
    for (int i = 0; i < *num_players; i++) {
        if (strcmp(players[i].name, name) == 0) {
            // Remove player
            for (int j = i+1; j < *num_players; j++) {
                strcpy(players[j-1].name, players[j].name);
                players[j-1].num_passwords = players[j].num_passwords;
                for (int k = 0; k < players[j].num_passwords; k++) {
                    strcpy(players[j-1].passwords[k], players[j].passwords[k]);
                }
            }
            (*num_players)--;
            printf("Player %s removed.\n", name);
            player_found = 1;
            break;
        }
    }

    if (!player_found) {
        printf("Player not found.\n");
    }

    return players;
}

// View all existing players
void view_players(Player *players, int num_players) {
    printf("Players in the system:\n");

    if (num_players == 0) {
        printf("No players found.\n");
    } else {
        for (int i = 0; i < num_players; i++) {
            printf("- %s\n", players[i].name);
        }
    }
}

// Clear the input buffer
void clear_input() {
    int c;
    while ((c = getchar()) != EOF && c != '\n') {}
}

// Clear the screen
void clear_screen() {
    printf("\033[2J\033[1;1H");
}