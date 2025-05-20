//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *title;
    char *artist;
    char *album;
    int year;
    int track;
    int length;
} music_t;

static music_t *db = NULL;
static int db_size = 0;

void add_music(const char *title, const char *artist, const char *album, int year, int track, int length) {
    db = realloc(db, (db_size + 1) * sizeof(music_t));
    music_t *new_music = &db[db_size++];
    new_music->title = strdup(title);
    new_music->artist = strdup(artist);
    new_music->album = strdup(album);
    new_music->year = year;
    new_music->track = track;
    new_music->length = length;
}

void print_db() {
    for (int i = 0; i < db_size; i++) {
        music_t *music = &db[i];
        printf("Title: %s\n", music->title);
        printf("Artist: %s\n", music->artist);
        printf("Album: %s\n", music->album);
        printf("Year: %d\n", music->year);
        printf("Track: %d\n", music->track);
        printf("Length: %d\n\n", music->length);
    }
}

void search_db(const char *query) {
    for (int i = 0; i < db_size; i++) {
        music_t *music = &db[i];
        if (strstr(music->title, query) || strstr(music->artist, query) || strstr(music->album, query)) {
            printf("Title: %s\n", music->title);
            printf("Artist: %s\n", music->artist);
            printf("Album: %s\n", music->album);
            printf("Year: %d\n", music->year);
            printf("Track: %d\n", music->track);
            printf("Length: %d\n\n", music->length);
        }
    }
}

int main() {
    add_music("Paranoid", "Black Sabbath", "Paranoid", 1970, 1, 245);
    add_music("War Pigs", "Black Sabbath", "Paranoid", 1970, 2, 762);
    add_music("Planet Caravan", "Black Sabbath", "Paranoid", 1970, 4, 425);
    add_music("Iron Man", "Black Sabbath", "Paranoid", 1970, 6, 331);
    add_music("Electric Funeral", "Black Sabbath", "Paranoid", 1970, 7, 452);

    print_db();

    search_db("Paranoid");

    return 0;
}