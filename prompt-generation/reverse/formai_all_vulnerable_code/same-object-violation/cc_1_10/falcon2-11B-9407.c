//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Album {
    char name[100];
    char artist[100];
    char genre[100];
    int year;
    int length;
};

struct Library {
    int num_albums;
    struct Album* albums;
};

struct Library create_library(int num_albums) {
    struct Library library;
    library.num_albums = num_albums;
    library.albums = malloc(num_albums * sizeof(struct Album));
    if (library.albums == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for library.\n");
        exit(1);
    }
    return library;
}

void add_album(struct Library* library, const char* name, const char* artist, const char* genre, int year, int length) {
    if (library->num_albums >= library->albums) {
        fprintf(stderr, "Error: Library is full.\n");
        exit(1);
    }
    struct Album* album = &library->albums[library->num_albums];
    strcpy(album->name, name);
    strcpy(album->artist, artist);
    strcpy(album->genre, genre);
    album->year = year;
    album->length = length;
    library->num_albums++;
}

void print_library(const struct Library* library) {
    int i;
    printf("Music Library\n");
    printf("----------------\n");
    printf("Number of albums: %d\n", library->num_albums);
    for (i = 0; i < library->num_albums; i++) {
        printf("Album %d:\n", i+1);
        printf("Name: %s\n", library->albums[i].name);
        printf("Artist: %s\n", library->albums[i].artist);
        printf("Genre: %s\n", library->albums[i].genre);
        printf("Year: %d\n", library->albums[i].year);
        printf("Length: %d\n", library->albums[i].length);
        printf("\n");
    }
}

void free_library(struct Library* library) {
    free(library->albums);
    library->albums = NULL;
}

int main() {
    int num_albums = 10;
    struct Library library = create_library(num_albums);
    add_album(&library, "The Dark Side of the Moon", "Pink Floyd", "Progressive rock", 1973, 42);
    add_album(&library, "Thriller", "Michael Jackson", "Pop", 1982, 47);
    add_album(&library, "Rumours", "Fleetwood Mac", "Rock", 1977, 44);
    add_album(&library, "Nevermind", "Nirvana", "Grunge", 1991, 37);
    add_album(&library, "Licensed to Ill", "Beastie Boys", "Hip-hop", 1986, 43);
    add_album(&library, "Reign in Blood", "Slayer", "Thrash metal", 1986, 27);
    add_album(&library, "The Chronic", "Dr. Dre", "Gangsta rap", 1992, 74);
    add_album(&library, "OK Computer", "Radiohead", "Art rock", 1997, 68);
    add_album(&library, "The Blueprint", "Jay-Z", "Hip-hop", 2001, 65);
    add_album(&library, "Illmatic", "Nas", "Hip-hop", 1994, 38);
    print_library(&library);
    free_library(&library);
    return 0;
}