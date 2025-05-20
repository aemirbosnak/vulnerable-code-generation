//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define NUM_ROOMS 5
#define NUM_CREEPY_SOUNDS 3

const char *rooms[NUM_ROOMS] = {
    "Dark Basement",
    "Creepy Attic",
    "Haunted Hallway",
    "Ghostly Living Room",
    "Mysterious Bedroom"
};

const char *sounds[NUM_CREEPY_SOUNDS] = {
    "A distant whisper...",
    "The sound of chains rattling...",
    "A loud bang, like something dropped..."
};

void* sound_effect(void* room_index) {
    int index = *(int*)room_index;
    free(room_index);

    srand(time(NULL) + index); // Seed with unique value for randomness
    int sound_index = rand() % NUM_CREEPY_SOUNDS;

    printf("In the %s: %s\n", rooms[index], sounds[sound_index]);
    return NULL;
}

void* explore_room(void* room_index) {
    int index = *(int*)room_index;

    printf("Entering %s...\n", rooms[index]);
    usleep((rand() % 3 + 1) * 1000000); // Simulate time spent in room

    pthread_t sound_thread;
    int *sound_room_index = malloc(sizeof(int));
    *sound_room_index = index;

    pthread_create(&sound_thread, NULL, sound_effect, sound_room_index);
    pthread_join(sound_thread, NULL); // Wait for sound effect to finish
    printf("Leaving %s...\n\n", rooms[index]);
    
    return NULL;
}

int main() {
    srand(time(NULL));
    pthread_t threads[NUM_ROOMS];

    printf("Welcome to the Haunted House Simulator!\n");
    printf("You will explore %d eerie rooms...\n", NUM_ROOMS);

    for (int i = 0; i < NUM_ROOMS; i++) {
        int *room_index = malloc(sizeof(int));
        *room_index = i;
        pthread_create(&threads[i], NULL, explore_room, room_index);
    }

    for (int i = 0; i < NUM_ROOMS; i++) {
        pthread_join(threads[i], NULL); // Wait for all rooms to be explored
    }

    printf("Thanks for visiting the Haunted House!\n");
    return 0;
}