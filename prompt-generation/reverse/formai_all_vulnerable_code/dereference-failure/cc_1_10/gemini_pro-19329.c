//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Surprise #1: Use a dynamic array to store the songs!
struct song {
    char *title;
    char *artist;
    int year;
};

struct song_library {
    struct song *songs;
    int num_songs;
};

// Surprise #2: Use macros for error handling!
#define CHECK_ERROR(condition, error_message) \
    if (condition) { \
        fprintf(stderr, "%s", error_message); \
        exit(1); \
    }

// Surprise #3: Use a custom memory allocation function!
void *my_malloc(size_t size) {
    void *ptr = malloc(size);
    CHECK_ERROR(ptr == NULL, "Out of memory!");
    return ptr;
}

// Surprise #4: Use a custom reallocation function!
void *my_realloc(void *ptr, size_t size) {
    void *new_ptr = realloc(ptr, size);
    CHECK_ERROR(new_ptr == NULL, "Out of memory!");
    return new_ptr;
}

// Surprise #5: Use a custom string duplication function!
char *my_strdup(const char *str) {
    char *new_str = my_malloc(strlen(str) + 1);
    strcpy(new_str, str);
    return new_str;
}

// Surprise #6: Use a custom function to compare songs by title!
int compare_songs_by_title(const void *a, const void *b) {
    const struct song *song1 = a;
    const struct song *song2 = b;
    return strcmp(song1->title, song2->title);
}

// Surprise #7: Use a custom function to print a song!
void print_song(const struct song *song) {
    printf("%s\t%s\t%d\n", song->title, song->artist, song->year);
}

int main() {
    // Surprise #8: Use a custom function to create a song library!
    struct song_library *library = my_malloc(sizeof(struct song_library));
    library->songs = NULL;
    library->num_songs = 0;

    // Surprise #9: Use a loop to read songs from a file!
    FILE *fp = fopen("songs.txt", "r");
    CHECK_ERROR(fp == NULL, "Could not open file!");
    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        // Surprise #10: Use a custom function to parse a song from a line!
        struct song song;
        char *title = strtok(line, "\t");
        char *artist = strtok(NULL, "\t");
        char *year_str = strtok(NULL, "\n");
        int year = atoi(year_str);
        song.title = my_strdup(title);
        song.artist = my_strdup(artist);
        song.year = year;

        // Surprise #11: Use a custom function to add a song to the library!
        library->songs = my_realloc(library->songs, (library->num_songs + 1) * sizeof(struct song));
        library->songs[library->num_songs] = song;
        library->num_songs++;
    }
    fclose(fp);

    // Surprise #12: Use a custom function to sort the songs by title!
    qsort(library->songs, library->num_songs, sizeof(struct song), compare_songs_by_title);

    // Surprise #13: Use a loop to print the songs!
    for (int i = 0; i < library->num_songs; i++) {
        print_song(&library->songs[i]);
    }

    // Surprise #14: Use a custom function to free the song library!
    for (int i = 0; i < library->num_songs; i++) {
        free(library->songs[i].title);
        free(library->songs[i].artist);
    }
    free(library->songs);
    free(library);

    return 0;
}