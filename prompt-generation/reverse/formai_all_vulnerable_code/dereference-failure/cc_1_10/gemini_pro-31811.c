//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

typedef struct {
    char *title;
    char *artist;
    int year;
} Song;

typedef struct {
    Song *song;
    bool is_playing;
} Player;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
Player *player = NULL;

void *player_thread(void *arg) {
    while (true) {
        pthread_mutex_lock(&mutex);
        while (!player->is_playing) {
            pthread_cond_wait(&cond, &mutex);
        }
        printf("Now playing: %s by %s (%d)\n", player->song->title, player->song->artist, player->song->year);
        sleep(1);
        player->is_playing = false;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void play_song(Song *song) {
    pthread_mutex_lock(&mutex);
    player->song = song;
    player->is_playing = true;
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);
}

int main() {
    player = malloc(sizeof(Player));
    player->is_playing = false;

    pthread_t tid;
    pthread_create(&tid, NULL, player_thread, NULL);

    Song song1 = {"Bohemian Rhapsody", "Queen", 1975};
    Song song2 = {"Stairway to Heaven", "Led Zeppelin", 1971};
    Song song3 = {"Hotel California", "Eagles", 1976};

    play_song(&song1);
    sleep(3);
    play_song(&song2);
    sleep(3);
    play_song(&song3);

    pthread_join(tid, NULL);

    free(player);

    return 0;
}