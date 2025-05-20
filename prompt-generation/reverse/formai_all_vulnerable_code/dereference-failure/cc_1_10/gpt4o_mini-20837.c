//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_PLAYERS 10
#define BUFFER_SIZE 256

typedef struct {
    int player_id;
    char player_name[50];
    float cpu_usage;
} Player;

Player players[MAX_PLAYERS];
int player_count = 0;

void* monitor_cpu_usage(void* arg) {
    int player_id = *((int*)arg);
    free(arg);

    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "top -b -n1 | grep 'Cpu(s)' | awk '{print $2 + $4}'");

    FILE* fp = popen(command, "r");
    if (fp == NULL) {
        perror("Failed to run command");
        return NULL;
    }

    while (1) {
        char result[BUFFER_SIZE];
        if (fgets(result, sizeof(result), fp) == NULL) {
            break; // end of data
        }
        players[player_id].cpu_usage = atof(result);
        printf("Player: %s (ID: %d) - Current CPU Usage: %.2f%%\n", players[player_id].player_name, players[player_id].player_id, players[player_id].cpu_usage);
        sleep(1); // Update every second
    }

    pclose(fp);
    return NULL;
}

void add_player(const char* name) {
    if (player_count < MAX_PLAYERS) {
        players[player_count].player_id = player_count;
        strcpy(players[player_count].player_name, name);
        players[player_count].cpu_usage = 0.0f;

        int* player_id = malloc(sizeof(int));
        *player_id = player_count;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, monitor_cpu_usage, player_id);
        pthread_detach(thread_id);

        player_count++;
    } else {
        printf("Maximum players reached!\n");
    }
}

void display_players() {
    printf("Current Players:\n");
    for (int i = 0; i < player_count; i++) {
        printf("ID: %d, Name: %s, CPU Usage: %.2f%%\n", players[i].player_id, players[i].player_name, players[i].cpu_usage);
    }
}

int main() {
    char name[50];
    char command[BUFFER_SIZE];

    printf("Welcome to the Multiplayer CPU Usage Monitor!\n");
    while (1) {
        printf("Enter player name (or type 'exit' to quit): ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0; // Remove newline

        if (strcmp(name, "exit") == 0) {
            break;
        }

        add_player(name);
        display_players();
    }

    printf("Exiting the CPU Usage Monitor. Goodbye!\n");

    return 0;
}