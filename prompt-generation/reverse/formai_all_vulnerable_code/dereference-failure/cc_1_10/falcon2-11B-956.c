//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: careful
#include <stdio.h>
#include <stdlib.h>

struct album {
    char artist[50];
    char album[50];
    int year;
};

struct library {
    struct album* albums;
    int num_albums;
};

void add_album(struct library* library, struct album* album) {
    library->num_albums++;
    library->albums = (struct album*)realloc(library->albums, sizeof(struct album) * library->num_albums);
    library->albums[library->num_albums - 1] = *album;
}

void delete_album(struct library* library, int index) {
    if (index < 0 || index >= library->num_albums) {
        printf("Invalid index\n");
        return;
    }
    for (int i = index; i < library->num_albums - 1; i++) {
        library->albums[i] = library->albums[i + 1];
    }
    library->num_albums--;
    library->albums = (struct album*)realloc(library->albums, sizeof(struct album) * library->num_albums);
}

void display_albums(struct library* library) {
    for (int i = 0; i < library->num_albums; i++) {
        printf("Artist: %s\n", library->albums[i].artist);
        printf("Album: %s\n", library->albums[i].album);
        printf("Year: %d\n", library->albums[i].year);
        printf("\n");
    }
}

int main() {
    struct library* library = (struct library*)malloc(sizeof(struct library));
    library->num_albums = 0;
    library->albums = NULL;

    struct album album1 = {
       .artist = "Beatles",
       .album = "Abbey Road",
       .year = 1969
    };

    struct album album2 = {
       .artist = "Led Zeppelin",
       .album = "Led Zeppelin II",
       .year = 1969
    };

    add_album(library, &album1);
    add_album(library, &album2);

    display_albums(library);

    delete_album(library, 1);

    display_albums(library);

    free(library->albums);
    free(library);

    return 0;
}