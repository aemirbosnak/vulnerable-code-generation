//GPT-4o-mini DATASET v1.0 Category: Image Classification system ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_PLAYERS 5
#define IMAGE_COUNT 3
#define MAX_NAME_LENGTH 20

// Simulated images and their classifications
const char *images[IMAGE_COUNT] = {"Image1", "Image2", "Image3"};
const char *classifications[IMAGE_COUNT] = {"Cat", "Dog", "Bird"};

typedef struct {
    char name[MAX_NAME_LENGTH];
    int player_id;
    int image_index; // What image they are trying to classify
} Player;

Player players[MAX_PLAYERS];
int player_count = 0;
pthread_mutex_t lock;

void *classify_image(void *arg) {
    Player *player = (Player *)arg;

    printf("%s (Player %d) is classifying %s...\n", player->name, player->player_id, images[player->image_index]);
    sleep(1); // Simulate time taken to classify

    // Simulate classification by choosing a classification
    int classification_index = rand() % IMAGE_COUNT;
    printf("%s (Player %d) classified %s as %s!\n", player->name, player->player_id, images[player->image_index], classifications[classification_index]);

    pthread_mutex_lock(&lock);
    player_count++; // Increment the count of classified images
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_mutex_init(&lock, NULL);
    pthread_t threads[MAX_PLAYERS];
    int image_index;

    // Adding players and assigning images to classify
    while (player_count < MAX_PLAYERS) {
        Player player;
        printf("Enter your name (or type 'exit' to quit): ");
        fgets(player.name, MAX_NAME_LENGTH, stdin);
        player.name[strcspn(player.name, "\n")] = 0; // Remove newline character

        if (strcmp(player.name, "exit") == 0) {
            break;
        }

        player.player_id = player_count;
        player.image_index = rand() % IMAGE_COUNT; // Each player gets a random image to classify

        // Create a thread for the player
        if (pthread_create(&threads[player_count], NULL, classify_image, (void *)&player) != 0) {
            fprintf(stderr, "Error creating thread for player %s\n", player.name);
        }

        player_count++;
    }

    // Wait for all threads to finish
    for (int i = 0; i < player_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All images classified by %d players!\n", player_count);
    pthread_mutex_destroy(&lock);
    return 0;
}