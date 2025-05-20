//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

#define MAX_PLAYERS 5
#define SHM_KEY 1234
#define SHM_SIZE (MAX_PLAYERS * sizeof(int))

int *scores;

void cleanup(int signum) {
    if (scores) {
        shmdt(scores);
        shmctl(SHM_KEY, IPC_RMID, NULL);
    }
    exit(0);
}

void show_scores() {
    printf("Current Scores:\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Player %d: %d\n", i + 1, scores[i]);
    }
    printf("\n");
}

int main() {
    signal(SIGINT, cleanup); // Clean up on Ctrl+C

    int shm_id = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shm_id < 0) {
        perror("shmget");
        exit(1);
    }

    scores = (int *)shmat(shm_id, NULL, 0);
    if (scores == (int *)(-1)) {
        perror("shmat");
        exit(1);
    }

    memset(scores, 0, SHM_SIZE); // Initialize scores to 0

    char command[10];
    int player_id;

    while (1) {
        printf("Enter command (increment <player_id> | show | exit): ");
        scanf("%s", command);

        if (strcmp(command, "exit") == 0) {
            cleanup(0);
        } else if (strcmp(command, "show") == 0) {
            show_scores();
        } else if (strcmp(command, "increment") == 0) {
            scanf("%d", &player_id);
            if (player_id < 1 || player_id > MAX_PLAYERS) {
                printf("Invalid player ID! Please enter a number between 1 and %d.\n", MAX_PLAYERS);
            } else {
                scores[player_id - 1]++;
                printf("Player %d score incremented!\n", player_id);
            }
        } else {
            printf("Unknown command: %s\n", command);
        }
    }

    return 0;
}