//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int num_players, num_ghosts;
    printf("Welcome to Haunted House Simulator!\n");
    printf("How many players will be playing? ");
    scanf("%d", &num_players);
    printf("How many ghosts will be in the house? ");
    scanf("%d", &num_ghosts);
    printf("\n");

    // Initialize random seed for ghost placement
    srand(time(NULL));

    // Initialize player locations
    int player_locs[num_players];
    for (int i = 0; i < num_players; i++) {
        player_locs[i] = 0;
    }

    // Initialize ghost locations
    int ghost_locs[num_ghosts];
    for (int i = 0; i < num_ghosts; i++) {
        // Ghosts can appear in any room except the starting room
        ghost_locs[i] = rand() % 10 + 1;
    }

    // Game loop
    int round_num = 1;
    while (1) {
        printf("Round %d:\n", round_num);

        // Print player locations
        printf("Player locations: ");
        for (int i = 0; i < num_players; i++) {
            if (player_locs[i] == 0) {
                printf("Player %d is in the starting room. ", i+1);
            } else {
                printf("Player %d is in Room %d. ", i+1, player_locs[i]);
            }
        }
        printf("\n");

        // Print ghost locations
        printf("Ghost locations: ");
        for (int i = 0; i < num_ghosts; i++) {
            printf("Ghost %d is in Room %d. ", i+1, ghost_locs[i]);
        }
        printf("\n");

        // Check if any players have encountered a ghost
        for (int i = 0; i < num_players; i++) {
            for (int j = 0; j < num_ghosts; j++) {
                if (player_locs[i] == ghost_locs[j]) {
                    printf("Player %d has encountered a ghost!\n", i+1);
                }
            }
        }

        // Move players to a random adjacent room
        for (int i = 0; i < num_players; i++) {
            int adj_rooms[4];
            int num_adj_rooms = 0;

            // Check left door
            if (player_locs[i] % 2 == 0 && player_locs[i] != 0) {
                adj_rooms[num_adj_rooms] = player_locs[i] - 1;
                num_adj_rooms++;
            }

            // Check right door
            if (player_locs[i] % 2 == 1 && player_locs[i] != 9) {
                adj_rooms[num_adj_rooms] = player_locs[i] + 1;
                num_adj_rooms++;
            }

            // Check bottom door
            if (player_locs[i] < 6) {
                adj_rooms[num_adj_rooms] = player_locs[i] + 4;
                num_adj_rooms++;
            }

            // Check top door
            if (player_locs[i] > 3) {
                adj_rooms[num_adj_rooms] = player_locs[i] - 4;
                num_adj_rooms++;
            }

            player_locs[i] = adj_rooms[rand() % num_adj_rooms];
        }

        round_num++;

        // Check if all players have reached the end room
        int all_at_end = 1;
        for (int i = 0; i < num_players; i++) {
            if (player_locs[i] != 9) {
                all_at_end = 0;
            }
        }
        if (all_at_end) {
            printf("All players have reached the end room! Game over.\n");
            break;
        }

        printf("\n");
    }

    return 0;
}