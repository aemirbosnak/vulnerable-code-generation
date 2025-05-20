//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Define a castle structure for Knights
typedef struct {
    int id;
    int horses;
    int food;
    int quests_completed;
    pthread_mutex_t *lock;
} Knight;

// Function for the Knight to embark on a quest
void *embark_on_quest(void *arg) {
    Knight *knight = (Knight *)arg;

    printf("Knight %d, charging forth with %d horses and %d food!\n",
           knight->id, knight->horses, knight->food);

    // Simulating quest completion time
    sleep(rand() % 3 + 1);

    // Update the number of completed quests
    pthread_mutex_lock(knight->lock);
    knight->quests_completed++;
    pthread_mutex_unlock(knight->lock);

    printf("Knight %d has triumphed! Quests completed: %d\n",
           knight->id, knight->quests_completed);
    return NULL;
}

// Function to prepare food for the knights
void *prepare_food(void *arg) {
    Knight *knight = (Knight *)arg;
    
    int food_prepared = rand() % 10 + 1;
    printf("Preparing %d units of food for Knight %d...\n", food_prepared, knight->id);
    
    // Simulating food preparation time
    sleep(rand() % 2 + 1);
    
    // Update food supply
    pthread_mutex_lock(knight->lock);
    knight->food += food_prepared;
    printf("Knight %d is now stocked with %d food!\n", knight->id, knight->food);
    pthread_mutex_unlock(knight->lock);

    return NULL;
}

// Function to train horses for the knights
void *train_horses(void *arg) {
    Knight *knight = (Knight *)arg;
    
    int horses_trained = rand() % 3 + 1;
    printf("Training %d horses for Knight %d...\n", horses_trained, knight->id);
    
    // Simulating horse training time
    sleep(rand() % 2 + 1);
    
    // Update horse supply
    pthread_mutex_lock(knight->lock);
    knight->horses += horses_trained;
    printf("Knight %d now has %d horses ready!\n", knight->id, knight->horses);
    pthread_mutex_unlock(knight->lock);

    return NULL;
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    const int num_knights = 5;
    Knight knights[num_knights];
    pthread_t quest_threads[num_knights];
    pthread_t food_threads[num_knights];
    pthread_t horse_threads[num_knights];

    // Initialize knights and their mutex locks
    for (int i = 0; i < num_knights; i++) {
        knights[i].id = i + 1;
        knights[i].horses = 0;
        knights[i].food = 0;
        knights[i].quests_completed = 0;
        knights[i].lock = malloc(sizeof(pthread_mutex_t));
        pthread_mutex_init(knights[i].lock, NULL);
    }

    // Spawn threads for each knight to prepare food and train horses
    for (int i = 0; i < num_knights; i++) {
        pthread_create(&food_threads[i], NULL, prepare_food, (void *)&knights[i]);
        pthread_create(&horse_threads[i], NULL, train_horses, (void *)&knights[i]);
    }

    // Wait for food and horse training to complete before embarking on quests
    for (int i = 0; i < num_knights; i++) {
        pthread_join(food_threads[i], NULL);
        pthread_join(horse_threads[i], NULL);
    }

    // Now, each knight can embark on their grand adventure
    for (int i = 0; i < num_knights; i++) {
        pthread_create(&quest_threads[i], NULL, embark_on_quest, (void *)&knights[i]);
    }

    // Join quest threads to ensure all knights have completed their quests
    for (int i = 0; i < num_knights; i++) {
        pthread_join(quest_threads[i], NULL);
    }

    // Clean up
    for (int i = 0; i < num_knights; i++) {
        pthread_mutex_destroy(knights[i].lock);
        free(knights[i].lock);
    }

    printf("All knights have completed their quests!\nMay they return with glory!\n");

    return 0;
}