//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Movie rating system data
struct MovieRating {
    char title[50];
    int rating;
};

// Queue for movie ratings
struct MovieRatingQueue {
    struct MovieRating *ratings;
    int head;
    int tail;
    int size;
};

// Mutex for queue access
pthread_mutex_t queue_mutex = PTHREAD_MUTEX_INITIALIZER;

// Condition variable for queue availability
pthread_cond_t queue_cond = PTHREAD_COND_INITIALIZER;

// Initialize movie rating queue
void init_queue(struct MovieRatingQueue *queue, int size) {
    queue->ratings = malloc(sizeof(struct MovieRating) * size);
    queue->head = 0;
    queue->tail = 0;
    queue->size = size;
}

// Enqueue a movie rating
void enqueue(struct MovieRatingQueue *queue, struct MovieRating rating) {
    // Lock the queue
    pthread_mutex_lock(&queue_mutex);

    // Wait if the queue is full
    while (queue->size == (queue->tail - queue->head + queue->size) % queue->size) {
        pthread_cond_wait(&queue_cond, &queue_mutex);
    }

    // Add the rating to the queue
    queue->ratings[queue->tail] = rating;
    queue->tail = (queue->tail + 1) % queue->size;

    // Signal that the queue is not empty
    pthread_cond_signal(&queue_cond);

    // Unlock the queue
    pthread_mutex_unlock(&queue_mutex);
}

// Dequeue a movie rating
struct MovieRating dequeue(struct MovieRatingQueue *queue) {
    // Lock the queue
    pthread_mutex_lock(&queue_mutex);

    // Wait if the queue is empty
    while (queue->head == queue->tail) {
        pthread_cond_wait(&queue_cond, &queue_mutex);
    }

    // Get the rating from the queue
    struct MovieRating rating = queue->ratings[queue->head];
    queue->head = (queue->head + 1) % queue->size;

    // Signal that the queue is not full
    pthread_cond_signal(&queue_cond);

    // Unlock the queue
    pthread_mutex_unlock(&queue_mutex);

    return rating;
}

// Thread function for movie rating
void *movie_rating_thread(void *arg) {
    struct MovieRatingQueue *queue = (struct MovieRatingQueue *)arg;

    // Get a random movie rating
    struct MovieRating rating;
    rating.rating = rand() % 10 + 1;
    sprintf(rating.title, "Movie %d", rating.rating);

    // Enqueue the rating
    enqueue(queue, rating);

    return NULL;
}

int main() {
    // Create a movie rating queue
    struct MovieRatingQueue queue;
    init_queue(&queue, 10);

    // Create a pool of threads
    pthread_t threads[10];

    // Start the threads
    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, movie_rating_thread, &queue);
    }

    // Join the threads
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the movie ratings
    struct MovieRating rating;
    while ((rating = dequeue(&queue)).rating != 0) {
        printf("%s: %d\n", rating.title, rating.rating);
    }

    return 0;
}