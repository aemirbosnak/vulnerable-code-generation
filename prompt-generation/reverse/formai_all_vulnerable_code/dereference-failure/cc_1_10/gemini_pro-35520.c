//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int genre;
} Song;

Song* lib;
int lib_size = 0;

void add_song(char* title, char* artist, char* album, int year, int genre) {
    if (lib_size == 0) {
        lib = malloc(sizeof(Song));
    } else {
        lib = realloc(lib, sizeof(Song) * (lib_size + 1));
    }
    strcpy(lib[lib_size].title, title);
    strcpy(lib[lib_size].artist, artist);
    strcpy(lib[lib_size].album, album);
    lib[lib_size].year = year;
    lib[lib_size].genre = genre;
    lib_size++;
}

void print_lib() {
    for (int i = 0; i < lib_size; i++) {
        printf("%s\n", lib[i].title);
        printf("%s\n", lib[i].artist);
        printf("%s\n", lib[i].album);
        printf("%d\n", lib[i].year);
        printf("%d\n", lib[i].genre);
        printf("\n");
    }
}

void search_lib(char* query) {
    for (int i = 0; i < lib_size; i++) {
        if (strstr(lib[i].title, query) != NULL) {
            printf("%s\n", lib[i].title);
        }
        if (strstr(lib[i].artist, query) != NULL) {
            printf("%s\n", lib[i].artist);
        }
        if (strstr(lib[i].album, query) != NULL) {
            printf("%s\n", lib[i].album);
        }
    }
}

int main() {
    add_song("Paranoid", "Black Sabbath", "Paranoid", 1970, 1);
    add_song("Master of Puppets", "Metallica", "Master of Puppets", 1986, 1);
    add_song("Dark Side of the Moon", "Pink Floyd", "Dark Side of the Moon", 1973, 2);
    add_song("The Wall", "Pink Floyd", "The Wall", 1979, 2);
    add_song("Led Zeppelin IV", "Led Zeppelin", "Led Zeppelin IV", 1971, 1);
    add_song("Sgt. Pepper's Lonely Hearts Club Band", "The Beatles", "Sgt. Pepper's Lonely Hearts Club Band", 1967, 2);
    add_song("Revolver", "The Beatles", "Revolver", 1966, 2);
    add_song("Abbey Road", "The Beatles", "Abbey Road", 1969, 2);
    add_song("Rubber Soul", "The Beatles", "Rubber Soul", 1965, 2);
    add_song("Help!", "The Beatles", "Help!", 1965, 2);
    print_lib();
    search_lib("Metallica");
    return 0;
}