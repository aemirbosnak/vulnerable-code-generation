//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a data struct for the movie with all the details
typedef struct Movie {
    char *title;
    char *genre;
    int year;
    float rating;
} Movie;

// Create a linked list of movies
typedef struct MovieList {
    Movie *movie;
    struct MovieList *next;
} MovieList;

// Create a new movie
Movie *new_movie(char *title, char *genre, int year, float rating) {
    Movie *movie = malloc(sizeof(Movie));
    movie->title = strdup(title);
    movie->genre = strdup(genre);
    movie->year = year;
    movie->rating = rating;
    return movie;
}

// Add a movie to the linked list
void add_movie(MovieList **head, Movie *movie) {
    MovieList *new_node = malloc(sizeof(MovieList));
    new_node->movie = movie;
    new_node->next = *head;
    *head = new_node;
}

// Print the linked list of movies
void print_movies(MovieList *head) {
    while (head != NULL) {
        printf("%s (%s, %d, %.1f)\n", head->movie->title, head->movie->genre, head->movie->year, head->movie->rating);
        head = head->next;
    }
}

// Free the memory allocated for the linked list of movies
void free_movies(MovieList *head) {
    while (head != NULL) {
        MovieList *next = head->next;
        free(head->movie->title);
        free(head->movie->genre);
        free(head->movie);
        free(head);
        head = next;
    }
}

// Main function
int main() {
    // Create a linked list of movies
    MovieList *head = NULL;

    // Add some movies to the linked list
    add_movie(&head, new_movie("The Shawshank Redemption", "Drama", 1994, 9.3));
    add_movie(&head, new_movie("The Godfather", "Crime", 1972, 9.2));
    add_movie(&head, new_movie("The Dark Knight", "Action", 2008, 9.0));
    add_movie(&head, new_movie("12 Angry Men", "Drama", 1957, 8.9));
    add_movie(&head, new_movie("Schindler's List", "Drama", 1993, 8.9));

    // Print the linked list of movies
    printf("Here are some classic movies:\n");
    print_movies(head);

    // Free the memory allocated for the linked list of movies
    free_movies(head);

    return 0;
}