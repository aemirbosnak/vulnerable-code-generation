//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a music piece
typedef struct music_piece {
    char *title;
    char *composer;
    char *genre;
    int year;
} music_piece;

// Function to create a new music piece
music_piece *create_music_piece(char *title, char *composer, char *genre, int year) {
    music_piece *piece = malloc(sizeof(music_piece));
    piece->title = strdup(title);
    piece->composer = strdup(composer);
    piece->genre = strdup(genre);
    piece->year = year;
    return piece;
}

// Function to print a music piece
void print_music_piece(music_piece *piece) {
    printf("Title: %s\n", piece->title);
    printf("Composer: %s\n", piece->composer);
    printf("Genre: %s\n", piece->genre);
    printf("Year: %d\n", piece->year);
}

// Function to compare two music pieces by title
int compare_music_pieces_by_title(const void *a, const void *b) {
    music_piece *piece1 = (music_piece *)a;
    music_piece *piece2 = (music_piece *)b;
    return strcmp(piece1->title, piece2->title);
}

// Function to compare two music pieces by composer
int compare_music_pieces_by_composer(const void *a, const void *b) {
    music_piece *piece1 = (music_piece *)a;
    music_piece *piece2 = (music_piece *)b;
    return strcmp(piece1->composer, piece2->composer);
}

// Function to compare two music pieces by genre
int compare_music_pieces_by_genre(const void *a, const void *b) {
    music_piece *piece1 = (music_piece *)a;
    music_piece *piece2 = (music_piece *)b;
    return strcmp(piece1->genre, piece2->genre);
}

// Function to compare two music pieces by year
int compare_music_pieces_by_year(const void *a, const void *b) {
    music_piece *piece1 = (music_piece *)a;
    music_piece *piece2 = (music_piece *)b;
    return piece1->year - piece2->year;
}

// Main function
int main() {
    // Create an array of music pieces
    music_piece *pieces[] = {
        create_music_piece("Toccata and Fugue in D Minor", "Johann Sebastian Bach", "Baroque", 1703),
        create_music_piece("Moonlight Sonata", "Ludwig van Beethoven", "Classical", 1801),
        create_music_piece("Symphony No. 5", "Ludwig van Beethoven", "Classical", 1808),
        create_music_piece("The Four Seasons", "Antonio Vivaldi", "Baroque", 1725),
        create_music_piece("Eine kleine Nachtmusik", "Wolfgang Amadeus Mozart", "Classical", 1787),
        create_music_piece("Clair de Lune", "Claude Debussy", "Impressionist", 1890)
    };

    // Sort the array of music pieces by title
    qsort(pieces, sizeof(pieces) / sizeof(music_piece *), sizeof(music_piece *), compare_music_pieces_by_title);

    // Print the sorted array of music pieces
    printf("Music pieces sorted by title:\n");
    for (int i = 0; i < sizeof(pieces) / sizeof(music_piece *); i++) {
        print_music_piece(pieces[i]);
        printf("\n");
    }

    // Sort the array of music pieces by composer
    qsort(pieces, sizeof(pieces) / sizeof(music_piece *), sizeof(music_piece *), compare_music_pieces_by_composer);

    // Print the sorted array of music pieces
    printf("Music pieces sorted by composer:\n");
    for (int i = 0; i < sizeof(pieces) / sizeof(music_piece *); i++) {
        print_music_piece(pieces[i]);
        printf("\n");
    }

    // Sort the array of music pieces by genre
    qsort(pieces, sizeof(pieces) / sizeof(music_piece *), sizeof(music_piece *), compare_music_pieces_by_genre);

    // Print the sorted array of music pieces
    printf("Music pieces sorted by genre:\n");
    for (int i = 0; i < sizeof(pieces) / sizeof(music_piece *); i++) {
        print_music_piece(pieces[i]);
        printf("\n");
    }

    // Sort the array of music pieces by year
    qsort(pieces, sizeof(pieces) / sizeof(music_piece *), sizeof(music_piece *), compare_music_pieces_by_year);

    // Print the sorted array of music pieces
    printf("Music pieces sorted by year:\n");
    for (int i = 0; i < sizeof(pieces) / sizeof(music_piece *); i++) {
        print_music_piece(pieces[i]);
        printf("\n");
    }

    // Free the allocated memory
    for (int i = 0; i < sizeof(pieces) / sizeof(music_piece *); i++) {
        free(pieces[i]->title);
        free(pieces[i]->composer);
        free(pieces[i]->genre);
        free(pieces[i]);
    }

    return 0;
}