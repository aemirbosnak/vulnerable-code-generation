//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100

typedef struct {
    char title[50];
    char path[100];
    size_t size;
} MusicFile;

int main() {
    MusicFile *library = malloc(MAX_SONGS * sizeof(MusicFile));
    int num_songs = 0;

    printf("Welcome to the Music Library Management System.\n");
    printf("This simple program allows you to add music files\n");
    printf("to a library, search for a file by title,\n");
    printf("and displays some basic statistics.\n\n");

    while (num_songs < MAX_SONGS && fgets(library[num_songs].path, sizeof(library[num_songs].path), stdin) != NULL) {
        sscanf(library[num_songs].path, "%s %s %ld", library[num_songs].title, &library[num_songs].size, NULL);
        num_songs++;
    }

    printf("\nTotal number of songs in the library: %d\n", num_songs);
    double total_size = 0;
    for (int i = 0; i < num_songs; i++) {
        total_size += library[i].size;
    }
    printf("Average file size: %.2f bytes\n", total_size / num_songs);

    char title[50];
    while (1) {
        printf("\nEnter a title to search for or type 'quit' to exit: ");
        scanf("%s", title);

        int found = 0;
        for (int i = 0; i < num_songs; i++) {
            if (strcmp(title, library[i].title) == 0) {
                printf("File '%s' with title '%s' was found.\n", library[i].path, library[i].title);
                found = 1;
                break;
            }
        }
        if (strcmp(title, "quit") == 0) {
            break;
        }
        if (!found) {
            printf("No file with title '%s' was found.\n", title);
        }
    }

    free(library);

    printf("\nThank you for using the Music Library Management System. Goodbye!\n");
    return 0;
}