//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_PLAYERS 10
#define BUFFER_SIZE 256

pthread_mutex_t lock;
float temperatures[MAX_PLAYERS];
int player_count = 0;

void* report_temperature(void* arg) {
    int player_id = *(int*)arg;
    char buffer[BUFFER_SIZE];
    
    printf("Player %d, please enter your temperature reading: ", player_id);
    fgets(buffer, BUFFER_SIZE, stdin);
    float temp = atof(buffer);
    
    pthread_mutex_lock(&lock);
    temperatures[player_id] = temp;
    player_count++;
    printf("Player %d reported temperature: %.2f\n", player_id, temp);
    pthread_mutex_unlock(&lock);
    
    pthread_exit(NULL);
}

void display_results() {
    pthread_mutex_lock(&lock);
    
    if (player_count == 0) {
        printf("No temperatures reported.\n");
        pthread_mutex_unlock(&lock);
        return;
    }
    
    float min_temp = temperatures[0];
    float max_temp = temperatures[0];
    for (int i = 0; i < player_count; i++) {
        if (temperatures[i] < min_temp) {
            min_temp = temperatures[i];
        }
        if (temperatures[i] > max_temp) {
            max_temp = temperatures[i];
        }
    }
    
    printf("Minimum Temperature Reported: %.2f\n", min_temp);
    printf("Maximum Temperature Reported: %.2f\n", max_temp);
    
    pthread_mutex_unlock(&lock);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <number_of_players>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int num_players = atoi(argv[1]);
    if (num_players <= 0 || num_players > MAX_PLAYERS) {
        fprintf(stderr, "Please enter a valid number of players (1-%d).\n", MAX_PLAYERS);
        exit(EXIT_FAILURE);
    }
    
    pthread_t threads[MAX_PLAYERS];
    int player_ids[MAX_PLAYERS];
    
    pthread_mutex_init(&lock, NULL);
    
    for (int i = 0; i < num_players; i++) {
        player_ids[i] = i;
        if (pthread_create(&threads[i], NULL, report_temperature, (void*)&player_ids[i]) != 0) {
            fprintf(stderr, "Error creating thread for player %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < num_players; i++) {
        pthread_join(threads[i], NULL);
    }

    display_results();

    pthread_mutex_destroy(&lock);
    return 0;
}