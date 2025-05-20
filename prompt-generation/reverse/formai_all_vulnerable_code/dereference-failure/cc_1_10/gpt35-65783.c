//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 1000
#define SHA1_LEN 20

// Define a structure to store the player information.
typedef struct {
    int player_id;
    char player_name[STR_LEN];
    char md5_hash[SHA1_LEN];
} Player;

// Generate a random MD5 hash value.
void generate_md5_hash(char* md5_hash) {
    int i;
    for (i = 0; i < SHA1_LEN; i++) {
        md5_hash[i] = (char)(rand() % 256);
    }
}

// Create a new player object.
Player* create_player(int player_id, char* player_name) {
    Player* player = malloc(sizeof(Player));
    player->player_id = player_id;
    strcpy(player->player_name, player_name);
    generate_md5_hash(player->md5_hash);
    return player;
}

int main() {
    // Define an array of players.
    Player* players[4];
    players[0] = create_player(1, "John");
    players[1] = create_player(2, "Jane");
    players[2] = create_player(3, "Peter");
    players[3] = create_player(4, "Mary");

    // Print out the player information and their MD5 hash values.
    int i;
    for (i = 0; i < 4; i++) {
        printf("Player %d: %s\n", players[i]->player_id, players[i]->player_name);
        printf("MD5 Hash value: ");
        int j;
        for (j = 0; j < SHA1_LEN; j++) {
            printf("%02x", (unsigned char)players[i]->md5_hash[j]);
        }
        printf("\n\n");
    }

    return 0;
}