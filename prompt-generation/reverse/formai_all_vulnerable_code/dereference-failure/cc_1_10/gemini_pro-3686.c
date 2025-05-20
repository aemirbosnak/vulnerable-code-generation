//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct {
    char *name;
    char *artist;
    char *album;
    int year;
    int rating;
} Song;

typedef struct {
    char *username;
    char *password;
    Song *library[100];
    int num_songs;
} User;

typedef struct {
    User *users[100];
    int num_users;
} Library;

Library *create_library() {
    Library *library = malloc(sizeof(Library));
    library->num_users = 0;
    return library;
}

void add_user(Library *library, User *user) {
    library->users[library->num_users++] = user;
}

User *create_user(char *username, char *password) {
    User *user = malloc(sizeof(User));
    user->username = strdup(username);
    user->password = strdup(password);
    user->num_songs = 0;
    return user;
}

void add_song(User *user, Song *song) {
    user->library[user->num_songs++] = song;
}

Song *create_song(char *name, char *artist, char *album, int year, int rating) {
    Song *song = malloc(sizeof(Song));
    song->name = strdup(name);
    song->artist = strdup(artist);
    song->album = strdup(album);
    song->year = year;
    song->rating = rating;
    return song;
}

void print_library(Library *library) {
    for (int i = 0; i < library->num_users; i++) {
        User *user = library->users[i];
        printf("%s's library:\n", user->username);
        for (int j = 0; j < user->num_songs; j++) {
            Song *song = user->library[j];
            printf("  %s by %s (%d)\n", song->name, song->artist, song->year);
        }
    }
}

int main() {
    Library *library = create_library();

    User *alice = create_user("alice", "password");
    add_user(library, alice);
    add_song(alice, create_song("Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 5));
    add_song(alice, create_song("Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 5));
    add_song(alice, create_song("Hotel California", "Eagles", "Hotel California", 1976, 5));

    User *bob = create_user("bob", "password");
    add_user(library, bob);
    add_song(bob, create_song("Thriller", "Michael Jackson", "Thriller", 1982, 5));
    add_song(bob, create_song("Billie Jean", "Michael Jackson", "Thriller", 1982, 5));
    add_song(bob, create_song("Beat It", "Michael Jackson", "Thriller", 1982, 5));

    print_library(library);

    return 0;
}