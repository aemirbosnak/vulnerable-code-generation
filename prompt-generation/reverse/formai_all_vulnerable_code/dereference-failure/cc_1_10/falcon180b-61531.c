//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char* name;
    int rating;
    struct movie* next;
} movie;

movie* createMovie(char* name, int rating) {
    movie* newMovie = (movie*)malloc(sizeof(movie));
    newMovie->name = name;
    newMovie->rating = rating;
    newMovie->next = NULL;
    return newMovie;
}

void addMovie(movie** head, char* name, int rating) {
    movie* newMovie = createMovie(name, rating);
    if (*head == NULL) {
        *head = newMovie;
    } else {
        movie* temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newMovie;
    }
}

void printMovies(movie* movies) {
    while (movies!= NULL) {
        printf("%s: %d\n", movies->name, movies->rating);
        movies = movies->next;
    }
}

int main() {
    movie* movies = NULL;
    addMovie(&movies, "The Godfather", 9);
    addMovie(&movies, "The Shawshank Redemption", 9);
    addMovie(&movies, "The Dark Knight", 8);
    addMovie(&movies, "Forrest Gump", 8);
    addMovie(&movies, "Pulp Fiction", 8);
    addMovie(&movies, "The Matrix", 7);
    addMovie(&movies, "Star Wars", 7);
    addMovie(&movies, "Fight Club", 7);
    addMovie(&movies, "The Silence of the Lambs", 7);
    addMovie(&movies, "Goodfellas", 7);
    printMovies(movies);
    return 0;
}