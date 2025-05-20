//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct music_info {
    char name[MAX_SIZE];
    int duration;
    char artist[MAX_SIZE];
    char genre[MAX_SIZE];
};

struct music_info* create_music_info(const char* name, int duration, const char* artist, const char* genre) {
    struct music_info* info = (struct music_info*)malloc(sizeof(struct music_info));
    strncpy(info->name, name, MAX_SIZE - 1);
    info->duration = duration;
    strncpy(info->artist, artist, MAX_SIZE - 1);
    strncpy(info->genre, genre, MAX_SIZE - 1);
    return info;
}

int main() {
    struct music_info* music_library[MAX_SIZE];
    int num_of_songs = 0;

    printf("Enter the number of songs to be added: ");
    scanf("%d", &num_of_songs);

    for (int i = 0; i < num_of_songs; i++) {
        printf("Enter song name: ");
        char name[MAX_SIZE];
        scanf("%s", name);

        printf("Enter song duration: ");
        int duration;
        scanf("%d", &duration);

        printf("Enter song artist: ");
        char artist[MAX_SIZE];
        scanf("%s", artist);

        printf("Enter song genre: ");
        char genre[MAX_SIZE];
        scanf("%s", genre);

        struct music_info* info = create_music_info(name, duration, artist, genre);
        music_library[num_of_songs] = info;
        num_of_songs++;
    }

    for (int i = 0; i < num_of_songs; i++) {
        struct music_info* info = music_library[i];
        printf("Song: %s\nArtist: %s\nDuration: %d\nGenre: %s\n", info->name, info->artist, info->duration, info->genre);
    }

    return 0;
}