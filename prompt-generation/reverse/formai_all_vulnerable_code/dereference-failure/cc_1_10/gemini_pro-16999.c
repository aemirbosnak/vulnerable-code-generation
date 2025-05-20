//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Define the maximum number of players
#define MAX_PLAYERS 4

// Define the maximum number of rooms
#define MAX_ROOMS 10

// Define the hotel room struct
typedef struct {
    int room_number;
    int is_occupied;
    int num_occupants;
    char occupants[MAX_PLAYERS][20];
} room_t;

// Define the hotel struct
typedef struct {
    room_t rooms[MAX_ROOMS];
    int num_rooms;
} hotel_t;

// Create a new hotel
hotel_t *create_hotel() {
    hotel_t *hotel = (hotel_t *)malloc(sizeof(hotel_t));
    hotel->num_rooms = MAX_ROOMS;
    for (int i = 0; i < MAX_ROOMS; i++) {
        hotel->rooms[i].room_number = i + 1;
        hotel->rooms[i].is_occupied = 0;
        hotel->rooms[i].num_occupants = 0;
    }
    return hotel;
}

// Check if a room is available
int is_room_available(hotel_t *hotel, int room_number) {
    return !hotel->rooms[room_number - 1].is_occupied;
}

// Book a room
int book_room(hotel_t *hotel, int room_number, char *occupants[], int num_occupants) {
    if (!is_room_available(hotel, room_number)) {
        return -1;
    }
    hotel->rooms[room_number - 1].is_occupied = 1;
    hotel->rooms[room_number - 1].num_occupants = num_occupants;
    for (int i = 0; i < num_occupants; i++) {
        strcpy(hotel->rooms[room_number - 1].occupants[i], occupants[i]);
    }
    return 0;
}

// Check out of a room
int check_out(hotel_t *hotel, int room_number) {
    if (!hotel->rooms[room_number - 1].is_occupied) {
        return -1;
    }
    hotel->rooms[room_number - 1].is_occupied = 0;
    hotel->rooms[room_number - 1].num_occupants = 0;
    for (int i = 0; i < MAX_PLAYERS; i++) {
        hotel->rooms[room_number - 1].occupants[i][0] = '\0';
    }
    return 0;
}

// Print the hotel status
void print_hotel_status(hotel_t *hotel) {
    printf("Hotel Status:\n");
    for (int i = 0; i < MAX_ROOMS; i++) {
        printf("Room %d: ", hotel->rooms[i].room_number);
        if (hotel->rooms[i].is_occupied) {
            printf("Occupied by ");
            for (int j = 0; j < hotel->rooms[i].num_occupants; j++) {
                printf("%s ", hotel->rooms[i].occupants[j]);
            }
            printf("\n");
        } else {
            printf("Available\n");
        }
    }
}

// Define the player struct
typedef struct {
    int player_id;
    int room_number;
} player_t;

// Create a new player
player_t *create_player(int player_id) {
    player_t *player = (player_t *)malloc(sizeof(player_t));
    player->player_id = player_id;
    player->room_number = -1;
    return player;
}

// Join a room
int join_room(hotel_t *hotel, player_t *player, int room_number) {
    if (!is_room_available(hotel, room_number)) {
        return -1;
    }
    player->room_number = room_number;
    hotel->rooms[room_number - 1].num_occupants++;
    strcpy(hotel->rooms[room_number - 1].occupants[hotel->rooms[room_number - 1].num_occupants - 1], player->player_id);
    return 0;
}

// Leave a room
int leave_room(hotel_t *hotel, player_t *player) {
    if (player->room_number == -1) {
        return -1;
    }
    int room_number = player->room_number;
    hotel->rooms[room_number - 1].num_occupants--;
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (strcmp(hotel->rooms[room_number - 1].occupants[i], player->player_id) == 0) {
            hotel->rooms[room_number - 1].occupants[i][0] = '\0';
            break;
        }
    }
    player->room_number = -1;
    return 0;
}

// Send a message to a room
int send_message(hotel_t *hotel, player_t *player, char *message) {
    if (player->room_number == -1) {
        return -1;
    }
    int room_number = player->room_number;
    for (int i = 0; i < hotel->rooms[room_number - 1].num_occupants; i++) {
        if (strcmp(hotel->rooms[room_number - 1].occupants[i], player->player_id) == 0) {
            continue;
        }
        printf("%s: %s\n", player->player_id, message);
    }
    return 0;
}

// Main function
int main() {
    // Create a new hotel
    hotel_t *hotel = create_hotel();

    // Create a new player
    player_t *player1 = create_player(1);
    player_t *player2 = create_player(2);
    player_t *player3 = create_player(3);
    player_t *player4 = create_player(4);

    // Join a room
    join_room(hotel, player1, 1);
    join_room(hotel, player2, 1);
    join_room(hotel, player3, 2);
    join_room(hotel, player4, 2);

    // Send a message to a room
    send_message(hotel, player1, "Hello everyone!");
    send_message(hotel, player3, "Hi there!");

    // Leave a room
    leave_room(hotel, player2);

    // Print the hotel status
    print_hotel_status(hotel);

    return 0;
}