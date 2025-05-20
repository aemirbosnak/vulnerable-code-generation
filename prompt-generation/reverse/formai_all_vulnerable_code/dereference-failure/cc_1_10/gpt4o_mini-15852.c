//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_PLAYERS 4
#define MAX_LENGTH 100
#define BOOST_THRESHOLD 10

typedef struct {
    int player_id;
    int boot_time;
} Player;

void* optimize_boot(void* arg) {
    Player* player = (Player*)arg;
    printf("Player %d is optimizing boot time...\n", player->player_id);
    
    // Simulating boot optimization process
    sleep(player->boot_time);
    
    // Check if the player has met the boost threshold
    if (player->boot_time < BOOST_THRESHOLD) {
        printf("Player %d has successfully optimized the boot time to %d seconds!\n", player->player_id, player->boot_time);
    } else {
        printf("Player %d's boot time of %d seconds exceeds the threshold. No optimization done.\n", player->player_id, player->boot_time);
    }
    
    // Free allocated memory for player
    free(player);
    return NULL;
}

int main(int argc, char* argv[]) {
    int i;
    pthread_t threads[MAX_PLAYERS];

    // Welcome message
    printf("Welcome to the Multiplayer System Boot Optimizer!\n");
    printf("Maximum players allowed: %d\n", MAX_PLAYERS);

    // Loop to create players
    for (i = 0; i < MAX_PLAYERS; i++) {
        Player* player = (Player*)malloc(sizeof(Player));
        if (player == NULL) {
            fprintf(stderr, "Error allocating memory for player\n");
            exit(EXIT_FAILURE);
        }

        // Assign player ID and random boot time
        player->player_id = i + 1;
        player->boot_time = rand() % 20; // Boot time between 0 and 19

        // Create a thread for each player
        if (pthread_create(&threads[i], NULL, optimize_boot, (void*)player) != 0) {
            fprintf(stderr, "Error creating thread for player %d\n", player->player_id);
            free(player);
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all threads to finish
    for (i = 0; i < MAX_PLAYERS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Final message
    printf("All players have completed their boot optimization.\n");
    return 0;
}