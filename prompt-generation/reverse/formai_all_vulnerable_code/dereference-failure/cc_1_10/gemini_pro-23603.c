//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>

#define MAX_PLAYERS 4
#define MAX_CPU_USAGE 100

struct player {
    int id;
    int cpu_usage;
    int wins;
    int losses;
};

struct player players[MAX_PLAYERS];

pthread_mutex_t mutex;

void print_usage() {
    printf("Usage: cpu_usage_monitor <num_players> <duration>\n");
    printf("num_players must be between 1 and %d\n", MAX_PLAYERS);
    printf("duration must be a positive integer\n");
}

void handle_sigint(int signal) {
    pthread_mutex_lock(&mutex);
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Player %d:\n", players[i].id);
        printf("CPU usage: %d%%\n", players[i].cpu_usage);
        printf("Wins: %d\n", players[i].wins);
        printf("Losses: %d\n", players[i].losses);
    }
    pthread_mutex_unlock(&mutex);
    exit(0);
}

void *player_thread(void *arg) {
    int player_id = *(int *)arg;
    free(arg);

    while (1) {
        // Get the CPU usage for this player
        int cpu_usage = rand() % MAX_CPU_USAGE;

        pthread_mutex_lock(&mutex);
        players[player_id].cpu_usage = cpu_usage;
        pthread_mutex_unlock(&mutex);

        // Sleep for a random amount of time
        sleep(rand() % 5);
    }
    
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return 1;
    }

    int num_players = atoi(argv[1]);
    if (num_players < 1 || num_players > MAX_PLAYERS) {
        print_usage();
        return 1;
    }

    int duration = atoi(argv[2]);
    if (duration <= 0) {
        print_usage();
        return 1;
    }

    // Create a mutex to protect the players array
    pthread_mutex_init(&mutex, NULL);

    // Create a thread for each player
    pthread_t threads[MAX_PLAYERS];
    for (int i = 0; i < num_players; i++) {
        int *player_id = malloc(sizeof(int));
        *player_id = i;
        pthread_create(&threads[i], NULL, player_thread, player_id);
    }

    // Register a signal handler for SIGINT
    signal(SIGINT, handle_sigint);

    // Sleep for the duration of the game
    sleep(duration);

    // Cancel all the player threads
    for (int i = 0; i < num_players; i++) {
        pthread_cancel(threads[i]);
    }

    // Wait for all the player threads to terminate
    for (int i = 0; i < num_players; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}