//FormAI DATASET v1.0 Category: Data recovery tool ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_PLAYERS 4
#define MAX_BLOCKS 128

struct Player {
    int id;
    char* data;
    int blocks[MAX_BLOCKS];
    int num_blocks;
};

struct Player players[MAX_PLAYERS];
int num_players = 0;

void add_player(int id, char* data) {
    if (num_players >= MAX_PLAYERS) {
        printf("Maximum number of players reached.\n");
        return;
    }

    struct Player new_player;
    new_player.id = id;
    new_player.data = data;
    new_player.num_blocks = 0;

    players[num_players++] = new_player;

    printf("Player %d added.\n", id);
}

void add_block(int player_id, int block_num) {
    for (int i = 0; i < num_players; i++) {
        if (players[i].id == player_id) {
            if (players[i].num_blocks >= MAX_BLOCKS) {
                printf("Maximum number of blocks reached for player %d.\n", player_id);
                return;
            }

            players[i].blocks[players[i].num_blocks++] = block_num;

            printf("Block %d added to player %d's list.\n", block_num, player_id);

            return;
        }
    }

    printf("Player with id %d not found.\n", player_id);
}

void recover_data() {
    int num_blocks_found[MAX_BLOCKS] = {0};
    char* recovered_data = (char*)malloc(MAX_BLOCKS * sizeof(char));

    for (int i = 0; i < num_players; i++) {
        for (int j = 0; j < players[i].num_blocks; j++) {
            int block_num = players[i].blocks[j];
            num_blocks_found[block_num]++;

            if (num_blocks_found[block_num] == 1) {
                // Block has not been recovered yet
                recovered_data[block_num] = players[i].data[block_num];
            }
        }
    }

    printf("Recovered data: %s\n", recovered_data);

    free(recovered_data);
}

int main() {
    char* data1 = "1a2b3c4d";
    char* data2 = "5e6f7g8h";
    char* data3 = "9i0j1k2l";
    char* data4 = "3m4n5o6p";

    add_player(1, data1);
    add_player(2, data2);
    add_player(3, data3);
    add_player(4, data4);

    add_block(1, 0);
    add_block(2, 2);
    add_block(2, 3);
    add_block(3, 1);
    add_block(4, 4);
    add_block(4, 5);
    add_block(4, 6);

    recover_data();

    return 0;
}