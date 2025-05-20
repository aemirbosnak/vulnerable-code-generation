//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 4
#define MAX_REQUESTS 100

typedef struct {
    char title[50];
    int year;
    int rating;
} Request;

typedef struct {
    int id;
    Request request;
} Song;

void *playSong(void *thread_id);
void *requestSong(void *thread_id);

int main() {
    int numThreads = MAX_THREADS;
    int numRequests = MAX_REQUESTS;
    Song *songs = malloc(numThreads * sizeof(Song));
    Request *requests = malloc(numRequests * sizeof(Request));

    for (int i = 0; i < numThreads; i++) {
        songs[i].id = i;
    }

    for (int i = 0; i < numRequests; i++) {
        requests[i].title[0] = 'T';
        requests[i].title[1] = 'H';
        requests[i].title[2] = 'E';
        requests[i].title[3] = 'R';
        requests[i].title[4] = 0;
        requests[i].year = 0;
        requests[i].rating = 0;
    }

    pthread_t threads[numThreads];

    for (int i = 0; i < numThreads; i++) {
        pthread_create(&threads[i], NULL, playSong, (void *) &songs[i]);
    }

    for (int i = 0; i < numRequests; i++) {
        pthread_create(&threads[i % numThreads], NULL, requestSong, (void *) &requests[i]);
    }

    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < numRequests; i++) {
        printf("%s, %d, %d\n", requests[i].title, requests[i].year, requests[i].rating);
    }

    return 0;
}

void *playSong(void *thread_id) {
    Song *song = (Song *) thread_id;
    for (int i = 0; i < 10; i++) {
        printf("%s, %d, %d\n", song->request.title, song->request.year, song->request.rating);
        sleep(1);
    }
    return NULL;
}

void *requestSong(void *thread_id) {
    Request *request = (Request *) thread_id;
    printf("%s, %d, %d\n", request->title, request->year, request->rating);
    sleep(1);
    return NULL;
}