//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>

struct music_library {
    pthread_mutex_t lock;
    pthread_cond_t cond;
    int num_songs;
    char **songs;
};

struct music_library *create_library() {
    struct music_library *library = malloc(sizeof(struct music_library));
    pthread_mutex_init(&library->lock, NULL);
    pthread_cond_init(&library->cond, NULL);
    library->num_songs = 0;
    library->songs = NULL;
    return library;
}

void add_song(struct music_library *library, char *song) {
    pthread_mutex_lock(&library->lock);
    library->songs = realloc(library->songs, sizeof(char *) * (library->num_songs + 1));
    library->songs[library->num_songs] = song;
    library->num_songs++;
    pthread_cond_signal(&library->cond);
    pthread_mutex_unlock(&library->lock);
}

void remove_song(struct music_library *library, char *song) {
    pthread_mutex_lock(&library->lock);
    int i;
    for (i = 0; i < library->num_songs; i++) {
        if (strcmp(library->songs[i], song) == 0) {
            break;
        }
    }
    if (i < library->num_songs) {
        library->num_songs--;
        for (int j = i + 1; j < library->num_songs; j++) {
            library->songs[j - 1] = library->songs[j];
        }
        library->songs = realloc(library->songs, sizeof(char *) * library->num_songs);
    }
    pthread_mutex_unlock(&library->lock);
}

void play_song(struct music_library *library, char *song) {
    pthread_mutex_lock(&library->lock);
    while (library->num_songs == 0) {
        pthread_cond_wait(&library->cond, &library->lock);
    }
    int i;
    for (i = 0; i < library->num_songs; i++) {
        if (strcmp(library->songs[i], song) == 0) {
            break;
        }
    }
    if (i < library->num_songs) {
        printf("Now playing: %s\n", song);
        sleep(1);
    } else {
        printf("Song not found: %s\n", song);
    }
    pthread_mutex_unlock(&library->lock);
}

int main() {
    struct music_library *library = create_library();
    char *songs[] = {"Song 1", "Song 2", "Song 3", "Song 4", "Song 5"};
    for (int i = 0; i < 5; i++) {
        add_song(library, songs[i]);
    }
    play_song(library, "Song 2");
    remove_song(library, "Song 3");
    play_song(library, "Song 4");
    return 0;
}