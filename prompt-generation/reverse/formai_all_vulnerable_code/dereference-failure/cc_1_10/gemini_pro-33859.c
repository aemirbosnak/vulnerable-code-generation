//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 4

// Define the hotel structure
typedef struct hotel {
    char name[50];
    int num_rooms;
    int num_occupied_rooms;
    int price_per_room;
} hotel_t;

// Define the player structure
typedef struct player {
    char name[50];
    int money;
    int num_hotels;
    hotel_t *hotels[MAX_PLAYERS];
} player_t;

// Create a new hotel
hotel_t *create_hotel(char *name, int num_rooms, int price_per_room) {
    hotel_t *hotel = malloc(sizeof(hotel_t));
    strcpy(hotel->name, name);
    hotel->num_rooms = num_rooms;
    hotel->num_occupied_rooms = 0;
    hotel->price_per_room = price_per_room;
    return hotel;
}

// Create a new player
player_t *create_player(char *name, int money) {
    player_t *player = malloc(sizeof(player_t));
    strcpy(player->name, name);
    player->money = money;
    player->num_hotels = 0;
    return player;
}

// Add a hotel to a player
void add_hotel_to_player(player_t *player, hotel_t *hotel) {
    player->hotels[player->num_hotels++] = hotel;
}

// Check if a player can afford a hotel
int can_afford_hotel(player_t *player, hotel_t *hotel) {
    return player->money >= hotel->price_per_room;
}

// Buy a hotel
void buy_hotel(player_t *player, hotel_t *hotel) {
    if (can_afford_hotel(player, hotel)) {
        player->money -= hotel->price_per_room;
        add_hotel_to_player(player, hotel);
    }
}

// Check if a player has won
int has_won(player_t *player) {
    return player->num_hotels == MAX_PLAYERS;
}

// Play the game
void play_game() {
    // Create the players
    player_t *players[MAX_PLAYERS];
    players[0] = create_player("Player 1", 1000);
    players[1] = create_player("Player 2", 1000);
    players[2] = create_player("Player 3", 1000);
    players[3] = create_player("Player 4", 1000);

    // Create the hotels
    hotel_t *hotels[MAX_PLAYERS];
    hotels[0] = create_hotel("Hotel 1", 10, 100);
    hotels[1] = create_hotel("Hotel 2", 15, 150);
    hotels[2] = create_hotel("Hotel 3", 20, 200);
    hotels[3] = create_hotel("Hotel 4", 25, 250);

    // Play the game until a player wins
    while (!has_won(players[0]) && !has_won(players[1]) && !has_won(players[2]) && !has_won(players[3])) {
        // Get the current player
        player_t *player = players[rand() % MAX_PLAYERS];

        // Get the current hotel
        hotel_t *hotel = hotels[rand() % MAX_PLAYERS];

        // Buy the hotel if the player can afford it
        buy_hotel(player, hotel);

        // Print the game state
        printf("\n%s has %d hotels and %d money.\n", player->name, player->num_hotels, player->money);
        for (int i = 0; i < MAX_PLAYERS; i++) {
            printf("%s has %d hotels.\n", players[i]->name, players[i]->num_hotels);
        }
    }

    // Print the winner
    player_t *winner = players[0];
    for (int i = 1; i < MAX_PLAYERS; i++) {
        if (players[i]->num_hotels > winner->num_hotels) {
            winner = players[i];
        }
    }
    printf("\n%s has won the game!\n", winner->name);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Play the game
    play_game();

    return 0;
}