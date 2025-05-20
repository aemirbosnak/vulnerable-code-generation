//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

// Haunted house state
enum {
    HOUSE_EMPTY,
    HOUSE_OCCUPIED,
    HOUSE_HAUNTED
};

// Visitor states
enum {
    VISITOR_OUTSIDE,
    VISITOR_INSIDE
};

// Thread data
struct thread_data {
    int id;
    int state;
    pthread_mutex_t *lock;
    pthread_cond_t *cond;
};

// Haunted house
int house_state = HOUSE_EMPTY;

// Visitors
pthread_t *visitors;
int num_visitors;

// Mutex and condition variable
pthread_mutex_t lock;
pthread_cond_t cond;

// Initialize the haunted house
void init_house() {
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);
}

// Destroy the haunted house
void destroy_house() {
    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);
}

// Visitor thread
void *visitor(void *arg) {
    struct thread_data *data = (struct thread_data *)arg;

    // Wait outside the house until it is haunted
    pthread_mutex_lock(&lock);
    while (house_state != HOUSE_HAUNTED) {
        pthread_cond_wait(&cond, &lock);
    }
    pthread_mutex_unlock(&lock);

    // Enter the house
    pthread_mutex_lock(&lock);
    data->state = VISITOR_INSIDE;
    pthread_mutex_unlock(&lock);

    // Explore the house
    sleep(rand() % 10);

    // Leave the house
    pthread_mutex_lock(&lock);
    data->state = VISITOR_OUTSIDE;
    pthread_mutex_unlock(&lock);

    return NULL;
}

// Ghost thread
void *ghost(void *arg) {
    // Wait until there are at least 3 visitors inside the house
    pthread_mutex_lock(&lock);
    while (num_visitors < 3) {
        pthread_cond_wait(&cond, &lock);
    }
    pthread_mutex_unlock(&lock);

    // Haunt the house
    pthread_mutex_lock(&lock);
    house_state = HOUSE_HAUNTED;
    pthread_cond_broadcast(&cond);
    pthread_mutex_unlock(&lock);

    // Wait until all visitors have left the house
    pthread_mutex_lock(&lock);
    while (num_visitors > 0) {
        pthread_cond_wait(&cond, &lock);
    }
    pthread_mutex_unlock(&lock);

    // Leave the house
    pthread_mutex_lock(&lock);
    house_state = HOUSE_EMPTY;
    pthread_cond_broadcast(&cond);
    pthread_mutex_unlock(&lock);

    return NULL;
}

// Main function
int main(int argc, char **argv) {
    // Parse command line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <num_visitors>\n", argv[0]);
        return 1;
    }
    num_visitors = atoi(argv[1]);

    // Initialize the haunted house
    init_house();

    // Create visitor threads
    visitors = malloc(sizeof(pthread_t) * num_visitors);
    for (int i = 0; i < num_visitors; i++) {
        struct thread_data *data = malloc(sizeof(struct thread_data));
        data->id = i;
        data->state = VISITOR_OUTSIDE;
        data->lock = &lock;
        data->cond = &cond;
        pthread_create(&visitors[i], NULL, visitor, data);
    }

    // Create ghost thread
    pthread_t ghost_thread;
    pthread_create(&ghost_thread, NULL, ghost, NULL);

    // Join visitor threads
    for (int i = 0; i < num_visitors; i++) {
        pthread_join(visitors[i], NULL);
    }

    // Join ghost thread
    pthread_join(ghost_thread, NULL);

    // Destroy the haunted house
    destroy_house();

    return 0;
}